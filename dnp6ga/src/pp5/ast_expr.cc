/* File: ast_expr.cc
 * -----------------
 * Implementation of expression node classes.
 */
#include "ast_expr.h"
#include "ast_type.h"
#include "ast_decl.h"
#include "errors.h"
#include <string.h>

int count = 0;
int leftInClass = 0;
//extern int isInClass;
IntConstant::IntConstant(yyltype loc, int val) : Expr(loc) {
    value = val;
}

DoubleConstant::DoubleConstant(yyltype loc, double val) : Expr(loc) {
    value = val;
}

BoolConstant::BoolConstant(yyltype loc, bool val) : Expr(loc) {
    value = val;
}

StringConstant::StringConstant(yyltype loc, const char *val) : Expr(loc) {
    Assert(val != NULL);
    value = strdup(val);
}

Operator::Operator(yyltype loc, const char *tok) : Node(loc) {
    Assert(tok != NULL);
    strncpy(tokenString, tok, sizeof(tokenString));
}
CompoundExpr::CompoundExpr(Expr *l, Operator *o, Expr *r) 
  : Expr(Join(l->GetLocation(), r->GetLocation())) {
    Assert(l != NULL && o != NULL && r != NULL);
    (op=o)->SetParent(this);
    (left=l)->SetParent(this); 
    (right=r)->SetParent(this);
}

CompoundExpr::CompoundExpr(Operator *o, Expr *r) 
  : Expr(Join(o->GetLocation(), r->GetLocation())) {
    Assert(o != NULL && r != NULL);
    left = NULL; 
    (op=o)->SetParent(this);
    (right=r)->SetParent(this);
}
   
  
ArrayAccess::ArrayAccess(yyltype loc, Expr *b, Expr *s) : LValue(loc) {
    (base=b)->SetParent(this); 
    (subscript=s)->SetParent(this);
}
     
FieldAccess::FieldAccess(Expr *b, Identifier *f) 
  : LValue(b? Join(b->GetLocation(), f->GetLocation()) : *f->GetLocation()) {
    Assert(f != NULL); // b can be be NULL (just means no explicit base)
    base = b; 
    if (base) base->SetParent(this); 
    (field=f)->SetParent(this);
}


Call::Call(yyltype loc, Expr *b, Identifier *f, List<Expr*> *a) : Expr(loc)  {
    Assert(f != NULL && a != NULL); // b can be be NULL (just means no explicit base)
    base = b;
    if (base) base->SetParent(this);
    (field=f)->SetParent(this);
    (actuals=a)->SetParentAll(this);
}
 

NewExpr::NewExpr(yyltype loc, NamedType *c) : Expr(loc) { 
  Assert(c != NULL);
  (cType=c)->SetParent(this);
}


NewArrayExpr::NewArrayExpr(yyltype loc, Expr *sz, Type *et) : Expr(loc) {
    Assert(sz != NULL && et != NULL);
    (size=sz)->SetParent(this); 
    (elemType=et)->SetParent(this);
}

void CompoundExpr::Check()
{/*
     if(left!=NULL )
     	left->Check();
     if(right!=NULL )
	right->Check();
   //  std::cout<<"herew comp";
    if(left != NULL && right!= NULL)
     {
         const char* s = op->getOp();
          
            if(left->getExprType()->IsEquivalentTo(Type::nullType) || left->getExprType()->IsEquivalentTo(Type::errorType) || right->getExprType()->IsEquivalentTo(Type::errorType) || right->getExprType()->IsEquivalentTo(Type::nullType))
             {}     
           else if((left->getExprType()->IsEquivalentTo(Type::stringType) && right->getExprType()->IsEquivalentTo(Type::stringType)) && strcmp(s,"=") != 0 )
                   ReportError:: IncompatibleOperands(op,left->getExprType(),right->getExprType());

           else if( left->getExprType()->IsNamedType() && right ->getExprType()->IsNamedType())
              {
                    if(!left->getExprType()->IsEquivalentTo(right->getExprType()))
                          {
                                         NamedType* bt = dynamic_cast<NamedType*>(left->getExprType());
					NamedType* dt = dynamic_cast<NamedType*>(right->getExprType());
 
                                     Decl *bDecl = bt->FindDecl(bt->GetId());
                                     Decl *dDecl = dt->FindDecl(dt->GetId());
                                      int flag = 0;
                                    if(bDecl->IsClassDecl() && dDecl->IsInterfaceDecl())
					{
					// ReportError::IncompatibleOperands(op,left->getExprType(),right->getExprType());

				   } 
                                     if(dDecl->IsClassDecl())
                                   {
                                     List<NamedType*> *ilist = dynamic_cast<ClassDecl*>(dDecl)->getInterface();
                                     int i = 0;
					 for( i = 0; i< ilist->NumElements(); i++)
					{
						if(ilist->Nth(i)->IsEquivalentTo(bt))
							break;
					} 
                                  
                                      //Decl *bDecl = baset->FindDecl(baset->GetId());
                                       if( i >= ilist->NumElements())
                      			{flag = 1;}
                                    
                                    }
                                    else
            				{	//ReportError::IncompatibleOperands(op,left->getExprType(),right->getExprType());       }     
                                     //      }
                                      if(flag == 1){ 
                                    		NamedType *ext = dynamic_cast<ClassDecl*>(dDecl)->getBase();
						if(!ext->IsEquivalentTo(bt) && flag == 1)
						{					
					//		ReportError::IncompatibleOperands(op,left->getExprType(),right->getExprType());                                 
 						}
                                    }
                                }
                          
                    }
          }
           else if(!left->getExprType()->IsEquivalentTo(right->getExprType()))  
                   ReportError:: IncompatibleOperands(op,left->getExprType(),right->getExprType());
    }
    else
   {  
      const char* s = op->getOp();
    //      std::cout<<s;
        if(right->getExprType()->IsEquivalentTo(Type::errorType))
	{}  
        else if(strcmp(s,"!")==0)
       {            if(!right->getExprType()->IsEquivalentTo(Type::boolType))
                         ReportError::IncompatibleOperand(op,right->getExprType());
       }
        else if ( strcmp(s,"-")==0)
        {
             if(!right->getExprType()->IsEquivalentTo(Type::intType) && !right->getExprType()->IsEquivalentTo(Type::doubleType)) 
                        ReportError::IncompatibleOperand(op,right->getExprType());
 

           }
   }        

    */
}
void FieldAccess::Check()
{
//std::cout<<"FA check";
/*
  if(base != NULL)
  {
    

     Type *t = base->getExprType();
     if(!t->IsNamedType())
     {
        ReportError::FieldNotFoundInBase(field,t);
      }
     else
     {
	     NamedType *nt = dynamic_cast<NamedType*>(t);

     	    Decl *d = nt->FindDecl(nt->GetId());
     		if(!d->IsClassDecl() && d!=NULL)
	      	{          ReportError::FieldNotFoundInBase(field,nt);
	        	}
     		else
     		{
         // ClassDecl *cd = dynamic_cast<ClassDecl*>(d);
         //Decl *d = cd->FindDecl(field);

           		Node *tmp = this;
           		int flag = 0;
 	 		while(tmp->GetParent())
           		{
                	if(tmp->IsClassDecl())
                   	{	

                        flag = 1;
                        break;
                  	}
                	tmp = tmp->GetParent();
           		}
           		if(flag == 0)
            		{
                  	ClassDecl *cd = dynamic_cast<ClassDecl*>(d);
                  	Decl *fd = cd->FindDecl(field);

                 	if(fd == NULL)
                    		ReportError::FieldNotFoundInBase(field,nt);
              
 		 	else
                    		ReportError::InaccessibleField(field,nt);
           		}
	   		else
            		{
              			ClassDecl *cd = dynamic_cast<ClassDecl*>(tmp);
              			Decl *d = cd->FindDecl(field);

              			if(d == NULL)
		   			ReportError::FieldNotFoundInBase(field,nt);
            		}		

     		}//else			
    	}//else
   }//if
    else{
                //if not in scope: var undeclared
             Decl *fd = FindDecl(field);
      //        std::cout<<"undecl";
             if(fd == NULL)
 
	        {   ReportError::IdentifierNotDeclared(field,LookingForVariable);
//                    VarDecl *vd = new VarDecl(field,Type::errorType); 
 //                     std::cout<<"undecl-null";

    		}    
            else if(fd->IsFnDecl())
		ReportError::IdentifierNotDeclared(field,LookingForVariable);
	 
     }
*/
} 
void Call::Check()
{
/*
   if(base == NULL)
    {
          Decl *d = FindDecl(field,kDeep);
          //std::cout<<d->IsClassDecl()<<d->IsInterfaceDecl();
          if( d == NULL)
          {

                for(int i = 0; i < actuals->NumElements(); i++)
		{
			actuals->Nth(i)->Check();
		}
                 ReportError::IdentifierNotDeclared(field,LookingForFunction);

          }
          else if( ( d->IsClassDecl() or d->IsInterfaceDecl()))
          {

                      for(int i = 0; i < actuals->NumElements(); i++)
                {
                        actuals->Nth(i)->Check();
                }
                 ReportError::IdentifierNotDeclared(field,LookingForFunction);

          }
          else if( d->IsFnDecl() && d!= NULL)
          {
            
              (dynamic_cast<FnDecl*>(d))->MatchesDefinition(actuals,field);            
          }  
  }
  else{
    
     Type *t = base->getExprType();

//     std::cout<<"hddd";
     if(t->IsNamedType())
    {
     NamedType *nt = dynamic_cast<NamedType*>(t);

     Decl *d = nt->FindDecl(nt->GetId());
	 for(int i = 0; i < actuals->NumElements(); i++)
                {
                        actuals->Nth(i)->Check();
                    }

     if(t->IsEquivalentTo(Type::errorType))
            {}
     else if( d == NULL)
     {  
//		std::cout<<"in here";
//	     ReportError::FieldNotFoundInBase(field,nt);
     }
      else if(!d->IsClassDecl())
     {
                  ReportError::FieldNotFoundInBase(field,nt);
 	}
     else
     {
  	 
           ClassDecl *cd = dynamic_cast<ClassDecl*>(d);
              Decl *d = cd->FindDecl(field);
              if( d== NULL || !d->IsFnDecl() )//made change here
                         ReportError::FieldNotFoundInBase(field,nt);

     }
   }//if
    else if ( t->IsEquivalentTo(Type::errorType))
	{
  
}
  else if(t->IsArrayType() && strcmp(field->GetName(),"length") == 0)
   {
             //length 

   }
    else
    {	 ReportError::FieldNotFoundInBase(field,t);
		}	

    }*/
}


void NewExpr::Check()
{
/*
	Decl *d = cType->FindDecl(cType->GetId());
          if( d== NULL)
		ReportError::IdentifierNotDeclared(cType->GetId(),LookingForClass);		
	 else if(!d->IsClassDecl())
		ReportError::IdentifierNotDeclared(cType->GetId(),LookingForClass);
*/
}

void This::Check()
{
/*
 Node* tmp = this;   
 int flag = 0; 
  while(tmp->GetParent() )
      {
           if(tmp->IsClassDecl())
             {
                   flag = 1;
		   break;
             }
           tmp = tmp->GetParent();
           
      }
 
          if(flag == 0)
            { 
           ReportError::ThisOutsideClassScope(this);

      }*/
   }
   
Type* EmptyExpr::getExprType()
{
return Type::voidType;
}
Type* ArithmeticExpr::getExprType()
{
return right->getExprType();
}
Type* RelationalExpr::getExprType()
{
return Type::boolType;
}
Type* LogicalExpr::getExprType()
{
return Type::boolType;
}


void NewArrayExpr::Check()
{
/*
    if(!size->getExprType()->IsEquivalentTo(Type::intType))
        ReportError::SubscriptNotInteger(size);
  if(elemType->IsNamedType())
   {

          Decl *d = elemType->FindDecl(dynamic_cast<NamedType*>(elemType)->GetId());
  //        if(d == NULL)
//	  {	Decl *d = elemType->FindDecl(dynamic_cast<NamedType*>(elemType)->GetId());
	
	          if(d== NULL)
				ReportError::IdentifierNotDeclared(dynamic_cast<NamedType*>(elemType)->GetId(),LookingForType);
    //            }
   }*/
}

void ArrayAccess::Check()
{/*
 base->Check();
 subscript->Check(); 
  if(!base->getExprType()->IsArrayType())
	ReportError::BracketsOnNonArray(base);  
  if(!subscript->getExprType()->IsEquivalentTo(Type::intType)) 
          ReportError::SubscriptNotInteger(subscript);*/
}
Type* This::getExprType()
{

  Node* tmp = this;
 int flag = 0;
  while(tmp->GetParent() )
      {
           if(tmp->IsClassDecl())
             {
                   flag = 1;
                   break;
             }
             if(tmp!=NULL)
           	tmp = tmp->GetParent();

      }

          if(flag == 0)
            {
               return Type::errorType;

      }
       if(tmp == NULL)
	{ return Type::errorType;}  
          ClassDecl *cd = dynamic_cast<ClassDecl*>(tmp); 
            return cd->getType();
}
Type* EqualityExpr::getExprType()
{
return Type::boolType;
}
Type* NewExpr::getExprType()
{

  return cType;
}

Type* CompoundExpr::getExprType()
{
return right->getExprType();
}
Type* AssignExpr::getExprType()
{
   return left->getExprType();
}
Type* ArrayAccess::getExprType()
{
  
//Decl *d = FindDecl(dynamic_cast<NamedType*>(base->getExprType())->GetId());
//VarDecl *vd = dynamic_cast<VarDecl*>(d); 
if(base->getExprType()->IsArrayType())
	return dynamic_cast<ArrayType*>(base->getExprType())->getElemType();
else
	return Type::errorType;
} 
Type* FieldAccess::getExprType()
{
 //std::cout<<"FA get type";
  if(base == NULL)
  { 	Decl *d = FindDecl(field);
   //     std::cout<<"wrong";
         if(d == NULL ) 
		return Type::errorType;
       else if (d->IsFnDecl())
		 return Type::errorType;

         else
        	return dynamic_cast<VarDecl*>(d)->GetDeclaredType() ;
  }    //if d == null, var not declared
  else
  {
       Type *t = base->getExprType();
       if(!t->IsNamedType())
		return Type::errorType;

       NamedType *nt = dynamic_cast<NamedType*>(t);
    Decl *d = nt->FindDecl(nt->GetId());
    //std::cout<<d->IsVarDecl()<<d->IsClassDecl(); 
     if(!d->IsClassDecl())
                return Type::errorType;

     else
     {

           ClassDecl *cd = dynamic_cast<ClassDecl*>(d);
              Decl *d = cd->FindDecl(field);
            
              if(d == NULL )
                return Type::errorType;
              //else if (!d->IsVarDecl())
		// return Type::errorType;
              else
                return dynamic_cast<VarDecl*>(d)->GetDeclaredType();

     }
 
   }
}
Type* Call::getExprType()
{
  if(base == NULL)
   {
  		Decl *d = FindDecl(field);
                if(d == NULL)
			return Type::errorType;
	
 		else if(d != NULL && d->IsFnDecl())
			return dynamic_cast<FnDecl*>(d)->getReturnType() ;
                else
			return Type::errorType;
  } 
   else
  {
  		 Type *t = base->getExprType();
     if(t->IsNamedType())
   {
      NamedType *nt = dynamic_cast<NamedType*>(t);

      Decl *d = nt->FindDecl(nt->GetId());
       if(d == NULL)
		return Type::errorType;
       else if(!d->IsClassDecl())
       {
                 return Type::errorType;
        }
     else
     {

           ClassDecl *cd = dynamic_cast<ClassDecl*>(d);
              Decl *d = cd->FindDecl(field);
              if(d != NULL && d->IsFnDecl() )//made change here
		{

              		 return dynamic_cast<FnDecl*>(d)->getReturnType() ;
 
		}
	      else
		{
			return Type::errorType;
		}
     }
   }
       else
		return Type::errorType;



 }
 
}
Type* NewArrayExpr::getExprType()
{
   Type *t = new ArrayType(*location, elemType);
   return t;

}
Type* IntConstant::getExprType()
{
 return Type::intType;
}
Type* StringConstant::getExprType()
{
  return Type::stringType;

}

Type* DoubleConstant::getExprType()
{
   return Type::doubleType;

}

Type* BoolConstant::getExprType()
{
   return Type::boolType;

}

Type* NullConstant::getExprType()
{

  return Type::nullType;

}
Type* ReadIntegerExpr::getExprType()
{
  return Type::intType;
}
Type* ReadLineExpr::getExprType()
{
 return Type::stringType;
}

Location* CompoundExpr::Emit( CodeGenerator *cg)
{

//    Location *l = left->Emit(cg);
    Location *r= right->Emit(cg);
  
   if(left==NULL)
	{
              if(strcmp(op->GetOp(),"-") == 0)
		{
		  
                    if(r != NULL)
			std::cout<<"nn";	
		    return cg->GenBinaryOp("*",cg->GenLoadConstant(1),r);

		}
    }       

    Location *l = left->Emit(cg);
   Location *tmp=  cg->GenBinaryOp(op->GetOp(),l,r);  
    
  

    return tmp ;
}
  
Location* ArithmeticExpr::Emit(CodeGenerator *cg)
{
      Location *r= right->Emit(cg);
    
     if(left==NULL)
        {
              if(strcmp(op->GetOp(),"-") == 0)
                {
                    return cg->GenBinaryOp("*",cg->GenLoadConstant(-1),r);
                }
    }

    Location *l = left->Emit(cg);
    Location *tmp=  cg->GenBinaryOp(op->GetOp(),l,r);
    return tmp ;

}  

Location* RelationalExpr::Emit(CodeGenerator *cg)
{

  Location *l = left->Emit(cg);
  Location *r = right->Emit(cg);
   if(left->IsArrayAccessType())
		l = cg->GenLoad(l);
   if(right->IsArrayAccessType())
              r = cg->GenLoad(r);  
  if(strcmp(op->GetOp(),"<=") == 0)
  {	Location* t1 = cg->GenBinaryOp("<",l,r);
        Location* t2 = cg->GenBinaryOp("==",l,r);
        return cg->GenBinaryOp("||",t1,t2);

  }
  else if(strcmp(op->GetOp(),">") == 0)
  {     return cg->GenBinaryOp("<",r,l);
   }
  else if( strcmp(op->GetOp(),">=") == 0)
  {     Location* t1 = cg->GenBinaryOp("<",r,l);
        Location* t2 = cg->GenBinaryOp("==",r,l);
        return cg->GenBinaryOp("||",t1,t2);
 }
  else
	return cg->GenBinaryOp(op->GetOp(),l,r);

 
 return NULL;
}

Location* EqualityExpr::Emit(CodeGenerator *cg)
{
    Location *l = left->Emit(cg);
    Location *r= right->Emit(cg);
   
    if(left->getExprType()->IsEquivalentTo(Type::stringType))
   {
         if(left->IsArrayAccessType())
               l = cg->GenLoad(l);
         if(right->IsArrayAccessType())
	       r = cg->GenLoad(r);
         cg->GenPushParam(r);
         cg->GenPushParam(l);
         Location *t = cg->GenLCall("_StringEqual",true);     
         cg->GenPopParams(8);
         return t; 
         
                           

   }     
    else if(strcmp(op->GetOp(),"!=") == 0)
    {
             Location* t1 = cg->GenBinaryOp("==",l,r);
             return cg->GenBinaryOp("==",cg->GenLoadConstant(0),t1);
 
    }  
    return  cg->GenBinaryOp(op->GetOp(),l,r);
}

Location* LogicalExpr::Emit(CodeGenerator *cg)
{

    
    Location *r= right->Emit(cg);

   if(left==NULL)
        {
              if(strcmp(op->GetOp(),"!") == 0)
                {

                    return cg->GenBinaryOp("==",cg->GenLoadConstant(0),r);

                }
    }

    Location *l = left->Emit(cg);
   return  cg->GenBinaryOp(op->GetOp(),l,r);



}

Location* IntConstant::Emit(CodeGenerator *cg)
{
   count++;
   Location *l =  cg->GenLoadConstant(value);
   return l;
}  

Location* StringConstant::Emit(CodeGenerator *cg)
{
   count++;
   Location *l =  cg->GenLoadConstant(value);
   return l;
}
Location* BoolConstant::Emit(CodeGenerator *cg)
{
   count++;
   Location *l =  cg->GenLoadConstant(value);
   return l;
}


Location* AssignExpr::Emit(CodeGenerator *cg)
{
    


     Location *l;    
     if(left->IsArrayAccessType())
	{
             Location *l = left->Emit(cg);
             Location *r = right->Emit(cg);
             if(right->IsArrayAccessType())  //NIGHTMARE
                r = cg->GenLoad(r);

              cg->GenStore(l,r,0);
             
 
              return NULL;
	}   
        
        Location *r = right->Emit(cg);
       if(right->IsArrayAccessType())
		r = cg->GenLoad(r);

     if(r == NULL)
                std::cout<<"ass";
    // if(!left->IsFieldAccess())
//     	     l = left->Emit(cg); 
     //Check if in class
     Node *tmp = this;
  int isInClass  = 0 ;
    while(tmp!=NULL)
   {
      if(tmp->IsClassDecl())
        {
                isInClass = 1;
                break;
       }
     tmp = tmp->GetParent();

   }
    //f(!isInClass or !left->IsFieldAccess())
    //
    //rintf("Here\n");
   	l = left->Emit(cg);
	//
  // printf("Made It!\n");
   if(isInClass == 1)
   {
       ClassDecl *cd = dynamic_cast<ClassDecl*>(tmp);
       List<Decl*> *mem = cd->getMembers();
       int index = -1;
        //check  if member
       
       for(int i = 0 ; i < mem->NumElements(); i++)
        {
                if(mem->Nth(i)->IsVarDecl())
                        {if(left->IsFieldAccess())
			{
                           FieldAccess *fa = dynamic_cast<FieldAccess*>(left);

                        if(strcmp(mem->Nth(i)->GetId()->GetName(),fa->GetField()->GetName()) == 0)
                                {
                                  index = i;
                                  break;
                                }
 			}
                      }
        }
           NamedType *bt = cd->GetExtends();

         if(bt != NULL)
       {
                Decl* tmp = FindDecl(bt->GetId());
            ClassDecl* ecd = dynamic_cast<ClassDecl*>(tmp);
            List<Decl*> *mem = ecd->getMembers();
            int numE = 0;
            for(int i = 0 ; i < mem->NumElements(); i++)
            {
                if(mem->Nth(i)->IsVarDecl())
                         numE++;
            }
             if(index != -1)
            	index = index + numE;

      }

        isInClass = 0;
        if(index == -1)
         {
               NamedType *bt = cd->GetExtends();
                if(bt!=NULL)
               {
		Decl* tmp = FindDecl(bt->GetId());
               ClassDecl* ecd = dynamic_cast<ClassDecl*>(tmp);
               List<Decl*> *mem = ecd->getMembers();

               for(int i = 0 ; i < mem->NumElements(); i++)
                 {
                        if(mem->Nth(i)->IsVarDecl())
                        {
                           if(left->IsFieldAccess())
                        	{
                           		FieldAccess *fa = dynamic_cast<FieldAccess*>(left);

                        		if(strcmp(mem->Nth(i)->GetId()->GetName(),fa->GetField()->GetName()) == 0)
                                	{
                                  		index = i;
                                  		break;
                                	}
				}
                        }
                  } 
               }
         }
        if(index != -1)
        { 
                 
               cg->GenStore(CodeGenerator::ThisPtr,r,(index+1)*4); //NOOOO
               return NULL;


        }

  }


     cg->GenAssign(l,r);
     
    return NULL;

}

Location* FieldAccess::Emit(CodeGenerator *cg)
{
 int isInClass = 0;
 Node *tmp = this;
  while(tmp!=NULL)
  {
     if(tmp->IsClassDecl())
        {
                isInClass = 1;
                break;
       }
     tmp = tmp->GetParent();

 }

    if(base == NULL && isInClass == 0)
    {
                                       

     Decl *d = this->FindDecl(field);

     VarDecl *vd = dynamic_cast<VarDecl*>(d);
     return vd->GetVarLoc();
      
    }
   else
   {

       ClassDecl *cd = dynamic_cast<ClassDecl*>(tmp);
       List<Decl*> *mem = cd->getMembers();
       int index = -1;
       for(int i = 0 ; i < mem->NumElements(); i++)
	{
		if(mem->Nth(i)->IsVarDecl())
			if(strcmp(mem->Nth(i)->GetId()->GetName(),field->GetName()) == 0)
				{
				  index = i;
                                  break;
				}
	} 
         //std::cout<<index<<field->GetName();
 
        NamedType *bt =   cd->GetExtends();
        if(bt != NULL)
       {
		Decl* tmp = FindDecl(bt->GetId());
            ClassDecl* ecd = dynamic_cast<ClassDecl*>(tmp);
            List<Decl*> *mem = ecd->getMembers();
            int numE = 0;
            for(int i = 0 ; i < mem->NumElements(); i++)
            {
                if(mem->Nth(i)->IsVarDecl())
                         numE++;
            }
            if(index != -1)
	    	index = index + numE;

      }
           
        if(index == -1)
        {
            if(bt!=NULL)
            {
            Decl* tmp = FindDecl(bt->GetId());
            ClassDecl* ecd = dynamic_cast<ClassDecl*>(tmp);
            List<Decl*> *mem = ecd->getMembers();
           
       	     
       	   
             for(int i = 0 ; i < mem->NumElements(); i++)
            {
                if(mem->Nth(i)->IsVarDecl())
                         {
            
                              if(strcmp(mem->Nth(i)->GetId()->GetName(),field->GetName()) == 0)
                                {
                                  index = i;
                                  break;
                                }
          		}
	    }
            }
    
         }
        if(index == -1)
             {
//                  std::cout<<"here"; 
                  Decl *d = this->FindDecl(field);

		  VarDecl *vd = dynamic_cast<VarDecl*>(d);
       //         std::cout<<vd->GetId()<<std::endl;         

		 return vd->GetVarLoc();


             } 
         
        //find correct offset
        Location *t =  cg->GenLoad(CodeGenerator::ThisPtr,(index+1)*4);
        isInClass = 0; 
        return t;
   //       std::cout<<t->GetName();
   }
 
  return NULL;


} 

Location* Call::Emit(CodeGenerator *cg)
{
     Node *tmp = this;
      int inC = 0, flagS = 0;
     if(base == NULL)
    {
      while(tmp != NULL)
       {
           if(tmp->IsClassDecl())
                {
                 inC = 1;
                 break;
                 }
           tmp = tmp->GetParent();
       }
      if(inC == 1)
      {
      //      int flagS = 0;
          ClassDecl *cd = dynamic_cast<ClassDecl*>(tmp);
          List<Decl*> *md = cd->getMembers();
          for(int i = 0; i < md->NumElements(); i++)
          {
                if(md->Nth(i)->IsFnDecl())
                {
                        if(strcmp(md->Nth(i)->GetId()->GetName(),field->GetName())==0)
                          { flagS =1;
                            break;
                          }
                }
          }
            NamedType *nm = cd->GetExtends();
                if(nm!=NULL)
                {
                 Decl *d = FindDecl(nm->GetId());
                ClassDecl *ecd = dynamic_cast<ClassDecl*>(d);
                List<Decl*> *md = ecd->getMembers();
                for(int i = 0; i < md->NumElements(); i++)
                {
                      if(md->Nth(i)->IsFnDecl())
                        {
                           
                         if( strcmp(md->Nth(i)->GetId()->GetName(),field->GetName()) == 0)
                                {           
                                    flagS = 1 ;
                                    tmp = ecd;
                                     break;
                                 }
                        }

                }

               }// exten    
        }
     }
 
 if(base == NULL && flagS == 0)
  {
    
   for(int i =  actuals->NumElements()-1; i >= 0; i--)
     {
              Location *tmp = actuals->Nth(i)->Emit(cg); 
              if(actuals->Nth(i)->IsArrayAccessType())
	             if(actuals->Nth(i)->getExprType()->IsArrayType())
				tmp = cg->GenLoad(tmp);
              cg->GenPushParam(tmp); 

     }


      Decl *d = FindDecl(field);
      FnDecl *fd = dynamic_cast<FnDecl*>(d);
           //check if in class and is class member
      
   //-------------------------------------------
     
      const char * l2 = field->GetName();
      const char * l1 = "_";


       char *totalLine = (char*)malloc(strlen(l1) + strlen(l2) + 1);
        if (totalLine != NULL)
        {
        strcpy(totalLine, l1);
        strcat(totalLine, l2);
        }
    
     Location *t;
     if(  fd->getReturnType() != NULL)
       {  
          if( fd->getReturnType()->IsEquivalentTo(Type::nullType) || fd->getReturnType()->IsEquivalentTo(Type::voidType) || fd->getReturnType()->IsEquivalentTo(Type::errorType) ) 
           	
  	          cg->GenLCall(totalLine,false);
       
     	  else
       
		  t = cg->GenLCall(totalLine, true);
     }
     else

	cg->GenLCall(totalLine,false);	
     if(actuals->NumElements() > 0)
     	cg->GenPopParams((actuals->NumElements())*4);

    
    return t;
  }
   else{
              
             if(base!=NULL)
          {

           Type *t = base->getExprType(); ///Arrays length()
           if(t->IsArrayType() && strcmp(field->GetName(),"length") == 0)
	  {	
              Location *bt = base->Emit(cg);
              return cg->GenLoad(bt,-4); 

          }
          }
         
         //else  //class member fns
          {
                
               Decl *d;
               ClassDecl *cd;
                Location *t; 
                Location *t2;
               
               if(base != NULL)
               {  
  //               std::cout<<"here";
                 d = FindDecl(dynamic_cast<NamedType*>(base->getExprType())->GetId());
                  
                 cd = dynamic_cast<ClassDecl*>(d);
        //          std::cout<<cd->GetId();
                // t = base->Emit(cg);             
                // t2 = cg->GenLoad(t);
               }
               else
		{
                 //  std::cout<<"here";
                  cd = dynamic_cast<ClassDecl*>(tmp); 
                // t2 = cg->GenLoad(CodeGenerator::ThisPtr);    
                // t = CodeGenerator::ThisPtr;
                
		}



               List<Decl*> *md = cd->getMembers();
               int index = -1;
               int j = -1;
               for(int i = 0; i < md->NumElements(); i++)
               {
                      if(md->Nth(i)->IsFnDecl())
			{
			 j++;					
			 if( strcmp(md->Nth(i)->GetId()->GetName(),field->GetName()) == 0)
			{
                              index = j;   
                               break;
                                }
                        
                        }
 
             
		}
                //std::cout<<index<<cd->GetId()->GetName()<<field->GetName(); 
              if(index == -1)
              {

             ////  	Decl *d = FindDecl(dynamic_cast<NamedType*>(base->getExprType())->GetId());
             ////  	ClassDecl *cd = dynamic_cast<ClassDecl*>(d);
               	//Location *t = base->Emit(cg);
               	//Location *t2 = cg->GenLoad(t);

               	NamedType *nm = cd->GetExtends();
                int index1 = -1;
                j  = -1;
                if(nm!=NULL)
                {
                 d = FindDecl(nm->GetId());
                ClassDecl *ecd = dynamic_cast<ClassDecl*>(d);
                List<Decl*> *md = ecd->getMembers();
                   
               	for(int i = 0; i < md->NumElements(); i++)
               	{
                      if(md->Nth(i)->IsFnDecl())
                        {
                            index1++;
                         if( strcmp(md->Nth(i)->GetId()->GetName(),field->GetName()) == 0)
                                { 
					index1 = j;
                                        break;}
                        }

               	}
                                
               }// extends
             }
       
         
                 //    Location *t3 = cg->GenLoad(t2,(index)*4); //change to offset into vtable
                           
               
               List<Location*> *params = new List<Location*>();

               for(int i =  0; i < actuals->NumElements(); i++)
	     	{

		           Location *tmp = actuals->Nth(i)->Emit(cg);
                           if(actuals->Nth(i)->IsArrayAccessType())
                                        //if(actuals->Nth(i)->getExprType()->IsArrayType())
                                                tmp = cg->GenLoad(tmp);
              
		          params->Append(tmp);
                          //cg->GenPushParam(actuals->Nth(i)->Emit(cg));

     		}


                 if(base != NULL)
               {
       
                 t = base->Emit(cg);
           
                 if(base->IsArrayAccessType())
			t = cg->GenLoad(t);
                 t2 = cg->GenLoad(t);

               }
               else
                {
          
                 t2 = cg->GenLoad(CodeGenerator::ThisPtr);
                 t = CodeGenerator::ThisPtr;

           
                }
                Location *t3 = cg->GenLoad(t2,(index)*4); //change to offset into vtable



                for(int i =   params->NumElements()-1 ; i >=0 ; i--)
                {
                         // params->Append(actuals->Nth(i)->Emit(cg));
                          cg->GenPushParam(params->Nth(i));

                }


              
               cg->GenPushParam(t);

                
        
               Decl *f = cd->FindDecl(field);
               FnDecl *fd = dynamic_cast<FnDecl*>(f);
 
            if(fd == NULL)
		std::cout<<"NULL";
           if(  fd->getReturnType() != NULL)
          {
              if( fd->getReturnType()->IsEquivalentTo(Type::nullType) || fd->getReturnType()->IsEquivalentTo(Type::voidType) || fd->getReturnType()->IsEquivalentTo(Type::errorType) )

                  cg->GenACall(t3,false);

              else
                 { t = cg->GenACall(t3, true); cg->GenPopParams((actuals->NumElements()+1)*4); return t;}
            }
         else
                cg->GenACall(t3,false);
          cg->GenPopParams((actuals->NumElements()+1)*4);
            



         }
   }

  return NULL;
}

Location* ReadIntegerExpr::Emit(CodeGenerator *cg)
{

  
               Location *r = cg->GenLCall("_ReadInteger",true);
               if(r == NULL)
			std::cout<<"NULL";
               return r; 
   
}
Location* ReadLineExpr::Emit(CodeGenerator *cg)
{


               Location *r = cg->GenLCall("_ReadLine",true);
               if(r == NULL)
                        std::cout<<"NULL";
               return r;

}

Location* NewArrayExpr::Emit(CodeGenerator *cg)
{

       Location *s = size->Emit(cg);
       Location *zero = cg->GenLoadConstant(0);
   
       Location *check = cg->GenBinaryOp("<",s,zero);
 
       char *s1 = cg->NewLabel();
       cg->GenIfZ(check,s1);
     
      
      cg->GenPushParam(cg->GenLoadConstant(err_arr_bad_size));
      cg->GenLCall("_PrintString",false);
      cg->GenPopParams(4);
  
      cg->GenLCall("_Halt",false);
      cg->GenLabel(s1);


     Location *one = cg->GenLoadConstant(1);
     Location *base = cg->GenBinaryOp("+",one,s);
     Location *four = cg->GenLoadConstant(4);
     Location *sbytes = cg->GenBinaryOp("*",base,four);
     Location *stmp = sbytes;
   /*if(elemType->IsArrayType())
  {
     
 	sbytes = cg->GenBinaryOp("*",sbytes,sbytes);
   }*/// Made change
     cg->GenPushParam(sbytes);
     Location *t = cg->GenLCall("_Alloc",true);
     cg->GenPopParams(4);
    

     cg->GenStore(t,s,0);
     if(elemType->IsArrayType())
  {

//          cg->GenStore(t,s,24);
   }

     Location *t3 = cg->GenBinaryOp("+",t,four);
      
    
     
          
     return t3;
}


Location* ArrayAccess::Emit(CodeGenerator *cg)
{
  static Location* size;
//    Location *l = base->Emit(cg);
   // Node *tmp = this->GetParent();
    Node *tmp = this->GetParent();
    if(!base->IsArrayAccessType()) // 1-D array
   {
//      std::cout<<"if";
     Location *l = base->Emit(cg);
 
    Location *itmp;
    itmp = l;
  
    
    Location *sub = subscript->Emit(cg); 
    if(subscript->IsArrayAccessType())
	sub = cg->GenLoad(sub);
    Location *zero = cg->GenLoadConstant(0);




    Location *c1 = cg->GenBinaryOp("<",sub,zero);
    size = cg->GenLoad(l,-4);              //FIX
    Location *c2 = cg->GenBinaryOp("<",sub,size);
    Location *c3 = cg->GenBinaryOp("==",c2,zero);
    Location *c4 = cg->GenBinaryOp("||",c1,c3);


    char *s1 = cg->NewLabel();
    cg->GenIfZ(c4,s1);
    Location *t1 = cg->GenLoadConstant(err_arr_out_of_bounds);
    cg->GenPushParam(t1);
    cg->GenLCall("_PrintString",false);
    cg->GenPopParams(4);
    cg->GenLCall("_Halt",false);
    cg->GenLabel(s1);

    
    Location *four = cg->GenLoadConstant(4);
    Location *loc = cg->GenBinaryOp("*",four,sub);
  
    Location *addr;
    if(tmp->IsArrayAccessType())
         {//do long calc
               ArrayAccess *aa = dynamic_cast<ArrayAccess*>(tmp);
               if(!aa->GetSubscript()->IsArrayAccessType())
              {
               Location *t1 = cg->GenBinaryOp("*",size,four);
               Location *t2 = cg->GenBinaryOp("*",sub,four);
               Location *t3 = cg->GenBinaryOp("+",t1,t2);
               addr = cg->GenBinaryOp("+",l,t3);
               }
               else
                {
                  if(!aa->GetBase()->IsArrayAccessType())
                     		 addr = cg->GenBinaryOp("+",itmp,loc);
                  else
			{
				 addr = cg->GenBinaryOp("+",itmp,loc);
				 addr = cg->GenLoad(addr);
			}

                }

     }




     else
           	addr = cg->GenBinaryOp("+",itmp,loc);
   
    
        
    return addr;
    }
    else
    {
//          std::cout<<"else";

	 Location *l = base->Emit(cg);
     
   

    	Location *sub = subscript->Emit(cg);
    	Location *zero = cg->GenLoadConstant(0);
//FIX
     //   size = cg->GenLoad(l,0);
	

    	Location *c1 = cg->GenBinaryOp("<",sub,zero);
//    	Location *size = cg->GenLoad(i,-4);
  	Location *c2 = cg->GenBinaryOp("<",sub,size);
    	Location *c3 = cg->GenBinaryOp("==",c2,zero);
    	Location *c4 = cg->GenBinaryOp("||",c1,c3);


    	char *s1 = cg->NewLabel();
    	cg->GenIfZ(c4,s1);
    	Location *t1 = cg->GenLoadConstant(err_arr_out_of_bounds);
    	cg->GenPushParam(t1);
    	cg->GenLCall("_PrintString",false);
    	cg->GenPopParams(4);
    	cg->GenLCall("_Halt",false);
    	cg->GenLabel(s1);


    	Location *four = cg->GenLoadConstant(4);
    	Location *loc = cg->GenBinaryOp("*",four,sub);

       

	     Location *addr = cg->GenBinaryOp("+",l,loc);

	     return addr;


     }
    return NULL;

}

Location* NewExpr::Emit(CodeGenerator *cg)
{
  Decl *cd = cType->GetDeclForType();
  cd = FindDecl(cType->GetId());
  List<Decl*> *md = dynamic_cast<ClassDecl*>(cd)->getMembers(); 

 
  NamedType* et = dynamic_cast<ClassDecl*>(cd)->GetExtends();
/* if(et!=NULL)
{
  Decl *ed =  FindDecl(et->GetId()); 
  List<Decl*> *emd = dynamic_cast<ClassDecl*>(ed)->getMembers();
}*/ //REMOVE
  
   



  int count1= 0, i ; 
   for(i = 0; i < md->NumElements(); i++)
     {
             if(md->Nth(i)->IsVarDecl())
			count1++;
     }
  //extends
 if(et!=NULL)
{
  Decl *ed =  FindDecl(et->GetId());
  List<Decl*> *emd = dynamic_cast<ClassDecl*>(ed)->getMembers();



  for(i = 0; i < emd->NumElements(); i++)
     {
             if(emd->Nth(i)->IsVarDecl())
                        count1++;
     }

}

   
  cg->GenPushParam(cg->GenLoadConstant((count1+1)*4));
  Location *t1 = cg->GenLCall("_Alloc",true);
  cg->GenPopParams(4);

  Location *t2 = cg->GenLoadLabel(cType->GetId()->GetName());
  
  cg->GenStore(t1,t2,0);

  return t1;
}
