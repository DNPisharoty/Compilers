/*
* File: ast_decl.cc
 * -----------------
 * Implementation of Decl node classes.
 */
#include "ast_decl.h"
#include "ast_type.h"
#include "ast_stmt.h"
#include "hashtable.h"        
#include "ast.h"
#include "errors.h"        
 
Decl::Decl(Identifier *n) : Node(*n->GetLocation()) {
    Assert(n != NULL);
    (id=n)->SetParent(this); 
}

void Decl::CheckNamedType(int level, List<Hashtable<MySymTb*>*> *head)
{}

VarDecl::VarDecl(Identifier *n, Type *t) : Decl(n) {
    Assert(n != NULL && t != NULL);
    (type=t)->SetParent(this);
}
  
void VarDecl::CheckChildren(int level, List<Hashtable<MySymTb*>*> *head){
     
 

     Hashtable<MySymTb*> *st    = head->Nth(0);
//lookup
    char ty[] = "var";

    if(st->Lookup(id->name)==NULL)
	st->Enter(id->name,new MySymTb(id,level,ty,this),false);
    else
  	ReportError::DeclConflict(this,st->Lookup(id->name)->child);

}

ClassDecl::ClassDecl(Identifier *n, NamedType *ex, List<NamedType*> *imp, List<Decl*> *m) : Decl(n) {
    // extends can be NULL, impl & mem may be empty lists but cannot be NULL
    Assert(n != NULL && imp != NULL && m != NULL);     
    extends = ex;
    if (extends) extends->SetParent(this);
    (implements=imp)->SetParentAll(this);
    (members=m)->SetParentAll(this);
}

void ClassDecl::CheckChildren(int level, List<Hashtable<MySymTb*>*> *head){
    
           
           Hashtable<MySymTb*> *st    = head->Nth(0);
           
           char ty[]= "class";
	   if(st->Lookup(id->name)==NULL)
           	st->Enter(id->name,new MySymTb(id,level,ty,this),false);
	   else
	   {
		 ReportError::DeclConflict(this,st->Lookup(id->name)->child);

           }	
           
           //implements->CheckAll(level,head);
          // if(extends)  extends->CheckChildren(level,head); 
           if(members!=NULL)
           {
           head->InsertAt(new Hashtable<MySymTb*>(),0);
           level++;
           members->CheckAll(level,head);
          
           head->RemoveAt(0);
	   level--;
 
           }
}

InterfaceDecl::InterfaceDecl(Identifier *n, List<Decl*> *m) : Decl(n) {
    Assert(n != NULL && m != NULL);
    (members=m)->SetParentAll(this);
}

void InterfaceDecl::CheckChildren(int level, List<Hashtable<MySymTb*>*> *head)
{
           
           Hashtable<MySymTb*> *st = head->Nth(0);
          char ty[] = "interface";
           if(st->Lookup(id->name)==NULL)
          {
                st->Enter(id->name,new MySymTb(id,level,ty,this),false);
           
            }
          else
           {
                 ReportError::DeclConflict(this,st->Lookup(id->name)->child);

           }
           if(members!= NULL)
             {
           head->InsertAt(new Hashtable<MySymTb*>(),0);
           level++;

           members->CheckAll(level,head);
            head->RemoveAt(0);
	   level--;
		}
}

	
FnDecl::FnDecl(Identifier *n, Type *r, List<VarDecl*> *d) : Decl(n) {
    Assert(n != NULL && r!= NULL && d != NULL);
    (returnType=r)->SetParent(this);
    (formals=d)->SetParentAll(this);
    body = NULL;
}

void FnDecl::CheckChildren(int level, List<Hashtable<MySymTb*>*> *head){

 
           Hashtable<MySymTb*> *tb = head->Nth(0);
           char ty[] = "fn";
            
           if(tb->Lookup(id->name)!=NULL)
           {
                ReportError::DeclConflict(this,tb->Lookup(id->name)->child);

           }
          	  
           tb->Enter(id->name,new MySymTb(id,level,ty,this),false);

        
           if(formals!=NULL)
        {   head->InsertAt(new Hashtable<MySymTb*>(),0);
           level++;
           formals->CheckAll(level,head); 
	 }  
           

           if(body!= NULL)
           {      

		head->InsertAt(new Hashtable<MySymTb*>(),0);
                level++;
		 body->CheckChildren(level,head);
           
 	 
           head->RemoveAt(0);
           level--;
          }
          if(formals!=NULL)
		{
          head->RemoveAt(0);
	  level--;    
          }
}

void FnDecl::SetFunctionBody(Stmt *b) { 
    (body=b)->SetParent(this);
}

void FnDecl::CheckNamedType(int level, List<Hashtable<MySymTb*>*> *head)
{
     
     formals->CheckNamedTypeAll(level,head);
    if(body!=NULL)
  {
    body->CheckNamedType(level,head);
   }     

}
void VarDecl::CheckNamedType(int level, List<Hashtable<MySymTb*>*> *head)
{
    if(type != Type::intType  and type !=Type::doubleType and type != Type::nullType and type!= Type::boolType and type!= Type::stringType and type != Type::errorType and type!= Type::voidType)
	{
		//Hashtable<MySymTb*> *p = head->Nth(0);
                type->CheckNamedType(level,head);

	}
}


void ClassDecl::CheckNamedType(int level, List<Hashtable<MySymTb*>*> *head)
{
  if(extends != NULL)
  {
        extends->CheckNamedType(level,head,LookingForClass);
        Identifier *eId = extends->getId(); 
        Hashtable<MySymTb*> *tb  = head->Nth(0);
        MySymTb *temp = tb->Lookup(eId->name);
       
        if(temp != NULL) //Check Members!!
       {
            Decl *baseClass = temp->child;

           for(int i = 0 ; i < members->NumElements() ; i++)
           {

               members->Nth(i)->checkMembers(baseClass);
            } 

        }
 
	
   }

   if(implements->NumElements() > 0)
   {
     implements->CheckNamedTypeAll(level,head,LookingForInterface);
    
  for(int i = 0 ; i < implements->NumElements() ; i++)
           {
                Identifier *eId = implements->Nth(i)->getId();                   
                 MySymTb *temp = head->Nth(0)->Lookup(eId->name);
                    if(temp != NULL) //Check Members!!
                  {
                       Decl *baseClass = temp->child;
   
                        for(int i = 0 ; i < members->NumElements() ; i++)
                   {

                               members->Nth(i)->checkMembers(baseClass);
                       }

                      }


               }
           
   
   }  
}

void InterfaceDecl::CheckNamedType(int level, List<Hashtable<MySymTb*>*> *head)
{
     
  members->CheckNamedTypeAll(level,head);

}

void VarDecl::checkMembers(Decl* cl){

      cl->checkClass(this);


}

void InterfaceDecl::checkClass(VarDecl *d) {}
void InterfaceDecl::checkClass(FnDecl *d) 
{

   for(int i = 0; i < members->NumElements(); i++)
    {
             members->Nth(i)->checkF(d);
   }


}
void ClassDecl::checkClass(VarDecl *d)
{
  for(int i = 0; i < members->NumElements(); i++)

    {             members->Nth(i)->checkV(d);

   }


}

void ClassDecl::checkClass(FnDecl *d)
{
//THIS is base

    for(int i = 0; i < members->NumElements(); i++)
    {   
             members->Nth(i)->checkF(d);
   }
 
    
}

void VarDecl::checkV(VarDecl *t)
{
    if(strcmp(t->getId()->name,this->id->name) == 0)
    {
           ReportError::DeclConflict(t,this);

   }

}

void FnDecl::checkV(VarDecl *t){}
void VarDecl::checkF(FnDecl *t) {}
void FnDecl::checkMembers(Decl* cl){
   cl->checkClass(this);
 
}

void FnDecl::checkF(FnDecl *d)
{
if(strcmp(d->getId()->name,this->id->name) == 0)
{

   if(this->formals->NumElements() != d->formals->NumElements())
	{
		ReportError::OverrideMismatch(d);
		
	}

   else{
   for(int i = 0; i < this->formals->NumElements(); i++)
   {
          
          
         int x =  d->checkTypes(d->formals->Nth(i)->getType(),this->formals->Nth(i)->getType());
         if(x == 1){ break;}
        
   }  
 }
}

}


int FnDecl::checkTypes(Type *t, Type *f)
{
  int e = 0;
  e = t->checkT(f);
  if(e == 1)
     {   
          ReportError::OverrideMismatch(this);

      }
   return e;
}


void FnDecl::checkTypes(Type*t, NamedType *f)
{
 ReportError::OverrideMismatch(this);


}
void FnDecl::checkTypes(Type*t, ArrayType *f)
{
ReportError::OverrideMismatch(this);

}
void FnDecl::checkTypes(NamedType *t, NamedType *f)
{

  if(strcmp(t->getId()->name,f->getId()->name)!=0)
 {  
  //error
   ReportError::OverrideMismatch(this);
 
 }
}

void FnDecl::checkTypes(NamedType *t, Type *f)
{
   ReportError::OverrideMismatch(this);

}

void FnDecl::checkTypes(NamedType *t, ArrayType *f)
{
  ReportError::OverrideMismatch(this);

}

void FnDecl::checkTypes(ArrayType *t, NamedType *f)
{
  ReportError::OverrideMismatch(this);

}
void FnDecl::checkTypes(ArrayType *t, Type *f)
{
  ReportError::OverrideMismatch(this);

}
void FnDecl::checkTypes(ArrayType *t, ArrayType *f)
{
}


void Decl::checkMembers(Decl* cl){}

