/* File: ast_decl.cc
 * -----------------
 * Implementation of Decl node classes.
 */
#include "ast_decl.h"
#include "ast_type.h"
#include "ast_stmt.h"
#include "ast_expr.h"
#include "scope.h"
#include "errors.h"
#include "tac.h"        
#include "codegen.h"
        
extern int tcount;         
extern int hasMain;
//int isInClass = 0;
Decl::Decl(Identifier *n) : Node(*n->GetLocation()) {
    Assert(n != NULL);
    (id=n)->SetParent(this); 
}

bool Decl::ConflictsWithPrevious(Decl *prev) {
    ReportError::DeclConflict(this, prev);
    return true;
}

VarDecl::VarDecl(Identifier *n, Type *t) : Decl(n) {
    Assert(n != NULL && t != NULL);
    (type=t)->SetParent(this);
}
  
void VarDecl::Check() { type->Check(); }

ClassDecl::ClassDecl(Identifier *n, NamedType *ex, List<NamedType*> *imp, List<Decl*> *m) : Decl(n) {
    // extends can be NULL, impl & mem may be empty lists but cannot be NULL
    Assert(n != NULL && imp != NULL && m != NULL);     
    extends = ex;
    if (extends) extends->SetParent(this);
    (implements=imp)->SetParentAll(this);
    (members=m)->SetParentAll(this);
    cType = new NamedType(n);
    cType->SetParent(this);
    convImp = NULL;
}

void ClassDecl::Check() {

    if (extends && !extends->IsClass()) {
        ReportError::IdentifierNotDeclared(extends->GetId(), LookingForClass);
        extends = NULL;
    }
    for (int i = 0; i < implements->NumElements(); i++) {
        NamedType *in = implements->Nth(i);
         if(in == NULL)
	{
            //ReportError::IdentifierNotDeclared(in->GetId(), LookingForInterface);
            implements->RemoveAt(i--);

		}	
           else{
 		Decl *d= in->FindDecl(in->GetId(),kShallow);
                 if(d == NULL)
	        { 
                 Node* tmp = this;
                 int flag = 0; 
                 while(tmp->GetParent())
		{
                            Decl *ft = dynamic_cast<Decl*>(tmp); 
			if(ft->IsInterfaceDecl())
			{	 flag = 1; break;}
                        tmp = tmp->GetParent();
                }
                
	 	 	Decl *fd =   tmp->FindDecl(in->GetId(),kShallow);
                        if(fd == NULL ){
                           
               		ReportError::IdentifierNotDeclared(in->GetId(), LookingForInterface);
            		implements->RemoveAt(i--);
          		}
                         else if(!fd->IsInterfaceDecl())
                              {
                                ReportError::IdentifierNotDeclared(in->GetId(), LookingForInterface);
                               implements->RemoveAt(i--);

                          }

                  }//if
                
	   //   }
                  }//else 
	        	
  /*      else if (!in->IsInterface()) {
            ReportError::IdentifierNotDeclared(in->GetId(), LookingForInterface);
            implements->RemoveAt(i--);
        }*/
     }//for

     
     PrepareScope();
     members->CheckAll();
 
   
}

// This is not done very cleanly. I should sit down and sort this out. Right now
// I was using the copy-in strategy from the old compiler, but I think the link to
// parent may be the better way now.
Scope *ClassDecl::PrepareScope()
{
    if (nodeScope) return nodeScope;
    nodeScope = new Scope();  
    if (extends) {
        ClassDecl *ext = dynamic_cast<ClassDecl*>(parent->FindDecl(extends->GetId())); 
        if (ext) nodeScope->CopyFromScope(ext->PrepareScope(), this);
    }
    convImp = new List<InterfaceDecl*>;
/*    members->DeclareAll(nodeScope);
     if(implements->NumElements() > 0 && implements != NULL)
        {
                  CheckIntf(implements);
      }
*/
    Scope* temp = new Scope();

    for (int i = 0; i < implements->NumElements(); i++) {
        NamedType *in = implements->Nth(i);
 
       InterfaceDecl *id = dynamic_cast<InterfaceDecl*>(in->FindDecl(in->GetId()));
  
        if (id) {

		temp->CopyFromScope(id->PrepareScope(), NULL);
            convImp->Append(id);
	  }
    }
    members->DeclareAll(temp);

   // nodeScope->CopyFromScope(temp,NULL);
    members->DeclareAll(nodeScope); 
    if(implements->NumElements() > 0 && implements != NULL)
        {
                  CheckIntf(implements);
      }

   
     for (int i = 0; i < implements->NumElements(); i++) {
        NamedType *in = implements->Nth(i);
         
       InterfaceDecl *id = dynamic_cast<InterfaceDecl*>(in->FindDecl(in->GetId()));

        if (id) {

                nodeScope->CopyFromScope(id->PrepareScope(), NULL);
            convImp->Append(id);
          }
    }
//     nodeScope->CopyFromScope(temp,NULL);
    return nodeScope;
}



InterfaceDecl::InterfaceDecl(Identifier *n, List<Decl*> *m) : Decl(n) {
    Assert(n != NULL && m != NULL);
    (members=m)->SetParentAll(this);
}

void InterfaceDecl::Check() {
    PrepareScope();
    members->CheckAll();
}
  
Scope *InterfaceDecl::PrepareScope() {
    if (nodeScope) return nodeScope;
    nodeScope = new Scope();  
    members->DeclareAll(nodeScope);
    return nodeScope;
}
	
FnDecl::FnDecl(Identifier *n, Type *r, List<VarDecl*> *d) : Decl(n) {
    Assert(n != NULL && r!= NULL && d != NULL);
    (returnType=r)->SetParent(this);
    (formals=d)->SetParentAll(this);
    body = NULL;
}

void FnDecl::SetFunctionBody(Stmt *b) { 
    (body=b)->SetParent(this);
}

void FnDecl::Check() {
    returnType->Check();
    if (body) {
        nodeScope = new Scope();
        formals->DeclareAll(nodeScope);
        formals->CheckAll();
	body->Check();
    }
}

bool FnDecl::ConflictsWithPrevious(Decl *prev) {
 // special case error for method override
    if (IsMethodDecl() && prev->IsMethodDecl() && parent != prev->GetParent()) { 
        if (!MatchesPrototype(dynamic_cast<FnDecl*>(prev))) {
            ReportError::OverrideMismatch(this);
            return true;
        }
        return false;
    }
    ReportError::DeclConflict(this, prev);
    return true;
}

bool FnDecl::IsMethodDecl() 
  { return dynamic_cast<ClassDecl*>(parent) != NULL || dynamic_cast<InterfaceDecl*>(parent) != NULL; }

bool FnDecl::MatchesPrototype(FnDecl *other) {
    if (!returnType->IsEquivalentTo(other->returnType)) return false;
    if (formals->NumElements() != other->formals->NumElements())
        return false;
    for (int i = 0; i < formals->NumElements(); i++)
        if (!formals->Nth(i)->GetDeclaredType()->IsEquivalentTo(other->formals->Nth(i)->GetDeclaredType()))
            return false;
    return true;
}


void FnDecl::MatchesDefinition(List<Expr*> *other, Identifier* f)
{

   if (formals->NumElements() != other->NumElements())
   {
            //ReportError::NumArgsMismatch(f,formals->NumElements(),other->NumElements());
    
   }
   else if(formals->NumElements() >0 && other->NumElements() > 0)
   {
       for (int i = 0; i < formals->NumElements(); i++)
           if (!formals->Nth(i)->GetDeclaredType()->IsEquivalentTo(other->Nth(i)->getExprType()))
           {
              //        ReportError::ArgMismatch(other->Nth(i),i+1,other->Nth(i)->getExprType(),formals->Nth(i)->GetDeclaredType());
           }   
  }
}

void ClassDecl::CheckIntf(List<NamedType*> *implements)
{

   int count = 0, k;
   for(int i  = 0; i< members->NumElements(); i++)
  {
        if(!members->Nth(i)->IsVarDecl())
		count++;
   }
   
  for(int i = 0; i < implements->NumElements(); i ++)
  {
        
       NamedType *id = implements->Nth(i);
       InterfaceDecl *in = dynamic_cast<InterfaceDecl*>(id->FindDecl(id->GetId()));

      if(count < in->getMembers()->NumElements())
      { //      ReportError::InterfaceNotImplemented(this,implements->Nth(i));   
          
      }
      else{
           
           for(k = 0 ; k < in->getMembers()->NumElements() ; k++)
          {
          
                    Decl *d = this->FindDecl(in->getMembers()->Nth(k)->GetId());
                   
                    if(d == NULL)
			break; 
          }
       }
          
           if(k < in->getMembers()->NumElements())
           {
   //           ReportError::InterfaceNotImplemented(this,implements->Nth(i));
            }
        } 
  }
Location* FnDecl::Emit(CodeGenerator *cg)
{
 tcount = 0;
  if(strcmp(id->GetName(),"main") == 0)
  {	cg->GenLabel(id->GetName());
 	hasMain++;
  }
  else
   {
     if(this->GetParent()->IsClassDecl())
       {
        const char * l2 = dynamic_cast<ClassDecl*>(this->GetParent())->GetId()->GetName() ;
        const char * l1 = "_";
        char *totalLine = (char*)malloc(strlen(l1) + strlen(l2) + 1);
        if (totalLine != NULL)
        {
        strcpy(totalLine, l1);
        strcat(totalLine, l2);
        }
        const char * l3 = ".";
        char *total1 = (char*)malloc(strlen(totalLine) + strlen(l3) + 1);
        if (total1 != NULL)
        {
        strcpy(total1, totalLine);
        strcat(total1, l3);
        }

        const char * l4 = id->GetName();
        char *total2 = (char*)malloc(strlen(total1) + strlen(l4) + 1);
        if (total2 != NULL)
        {
        strcpy(total2, total1);
        strcat(total2, l4);
        }
 
	 cg->GenLabel(total2); 

        }
     else{
     	const char * line1 = "_";
     	const char * line2 = id->GetName();
    	char *totalLine = (char*)malloc(strlen(line1) + strlen(line2) + 1);
  	if (totalLine != NULL)
  	{
     	strcpy(totalLine, line1);
     	strcat(totalLine, line2);
  	}
     	cg->GenLabel(totalLine);
       }
   
    }
   
  BeginFunc *fp = cg->GenBeginFunc();
  //char *s = NewLabel();
//-- Check if in class body
  Node *tmp = this;
  int inClass = 0;
  while(tmp!=NULL)
  {
     if(tmp->IsClassDecl())
	{
		inClass = 1;
                break;
       }
     tmp = tmp->GetParent();
 
 }

  if(inClass == 1)
   {
         formals->EmitAllParamsInClass(cg);
         inClass = 1;
   }
    else
    {
 	formals->EmitAllParams(cg);  
     }
    body->Emit(cg);
  //somehow set fp frame size
// isInClass = 0;
 fp->SetFrameSize(tcount*4);
 cg->GenEndFunc();
 tcount = 0;
// std::cout<<tcount;  
  return NULL;
}

Location* VarDecl::Emit(CodeGenerator *cg)
{

 Location *x = cg->StoreVar(id->GetName(),fpRelative);
 if(x != NULL)
  {
     Decl *d = FindDecl(id);  
   VarDecl *vd = dynamic_cast<VarDecl*>(d);
   vd->SetVarLoc(x);
 }
 return NULL;
}


Location* VarDecl::EmitGlobal(CodeGenerator *cg)
{

 Location *x = cg->StoreGlobalVar(id->GetName(),gpRelative);
 if(x != NULL)
  {
   Decl *d = FindDecl(id);
   VarDecl *vd = dynamic_cast<VarDecl*>(d);
   vd->SetVarLoc(x);
 }
 return NULL;
}

Location* VarDecl::EmitParam(CodeGenerator *cg)
{
  Location *x = cg->StoreParam(id->GetName(),fpRelative);
 if(x != NULL)
  {
   Decl *d = FindDecl(id);
   VarDecl *vd = dynamic_cast<VarDecl*>(d);
   vd->SetVarLoc(x);
 }
 return NULL;
}
Location* VarDecl::EmitParamInClass(CodeGenerator *cg)
{
  Location *x = cg->StoreParamInClass(id->GetName(),fpRelative);
 if(x != NULL)
  {
   Decl *d = FindDecl(id);
   VarDecl *vd = dynamic_cast<VarDecl*>(d);
   vd->SetVarLoc(x);
 }
 return NULL;
}


Location* ClassDecl::Emit(CodeGenerator *cg)
{
  List<const char*> *mem = new List<const char*>();
  members->EmitAll(cg);
  if(extends!=NULL)
  {
        Decl *d = FindDecl(extends->GetId());
        ClassDecl *cd = dynamic_cast<ClassDecl*>(d);
        List<Decl*> *members = cd->getMembers(); 
         for(int i = 0; i < members->NumElements(); i ++)
         {
     		if(members->Nth(i)->IsFnDecl())
      		{
        		const char * l2 = extends->GetId()->GetName();
        		const char * l1 = "_";


        		char *totalLine = (char*)malloc(strlen(l1) + strlen(l2) + 1);
        		if (totalLine != NULL)
        		{
        			strcpy(totalLine, l1);
        			strcat(totalLine, l2);
        		}
        		const char * l3 = ".";
        		char *total1 = (char*)malloc(strlen(totalLine) + strlen(l3) + 1);
        		if (total1 != NULL)
        		{
        			strcpy(total1, totalLine);
        			strcat(total1, l3);
        		}

        		const char * l4 = members->Nth(i)->GetId()->GetName();
        		char *total2 = (char*)malloc(strlen(total1) + strlen(l4) + 1);
        		if (total2 != NULL)
        		{
        		strcpy(total2, total1);
        		strcat(total2, l4);
        		}


            		mem->Append(total2);
		}
          }	
       

  }
  for(int i = 0; i < members->NumElements(); i ++)
   {
     if(members->Nth(i)->IsFnDecl())
      {
        const char * l2 = id->GetName();
        const char * l1 = "_";
        
	
        char *totalLine = (char*)malloc(strlen(l1) + strlen(l2) + 1);
        if (totalLine != NULL)
        {
        strcpy(totalLine, l1);
        strcat(totalLine, l2);
        }
        const char * l3 = ".";
        char *total1 = (char*)malloc(strlen(totalLine) + strlen(l3) + 1);
        if (total1 != NULL)
        {
        strcpy(total1, totalLine);
        strcat(total1, l3);
        }

        const char * l4 = members->Nth(i)->GetId()->GetName();
        char *total2 = (char*)malloc(strlen(total1) + strlen(l4) + 1);
        if (total2 != NULL)
        {
        strcpy(total2, total1);
        strcat(total2, l4);
        }


            mem->Append(total2);
 
    }
   } 
  // std::cout<<"yo"<<this->getId()->GetName(); 
   cg->GenVTable(getId()->GetName(),mem);
  return NULL;
}
