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
                    return cg->GenBinaryOp("*",cg->GenLoadConstant(1),r);
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

     Location *r = right->Emit(cg);

     if(r == NULL)
		std::cout<<"ass";
     Location *l = left->Emit(cg); 
     
     cg->GenAssign(l,r);
    return NULL;
}

Location* FieldAccess::Emit(CodeGenerator *cg)
{
 
    if(base == NULL)
    {
                                       

     Decl *d = this->FindDecl(field);

    VarDecl *vd = dynamic_cast<VarDecl*>(d);
   return vd->GetVarLoc();
      
    }
  return NULL;


} 

Location* ReadIntegerExpr::Emit(CodeGenerator *cg)
{

  
               Location *r = cg->GenLCall("ReadInteger",true);
               if(r == NULL)
			std::cout<<"NULL";
               return r; 
   
}
Location* ReadLineExpr::Emit(CodeGenerator *cg)
{


               Location *r = cg->GenLCall("ReadLine",true);
               if(r == NULL)
                        std::cout<<"NULL";
               return r;

}

