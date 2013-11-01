/* File: ast_type.cc
 * -----------------
 * Implementation of type node classes.
 */
#include "ast_type.h"
#include "ast_decl.h"
#include <string.h>
#include "errors.h"
 
/* Class constants
 * ---------------
 * These are public constants for the built-in base types (int, double, etc.)
 * They can be accessed with the syntax Type::intType. This allows you to
 * directly access them and share the built-in types where needed rather that
 * creates lots of copies.
 */

Type *Type::intType    = new Type("int");
Type *Type::doubleType = new Type("double");
Type *Type::voidType   = new Type("void");
Type *Type::boolType   = new Type("bool");
Type *Type::nullType   = new Type("null");
Type *Type::stringType = new Type("string");
Type *Type::errorType  = new Type("error"); 

Type::Type(const char *n) {
    Assert(n);
    typeName = strdup(n);
}

Identifier * NamedType::getId()
{
 return id ;
}

void Type::CheckChildren(int level, List<Hashtable<MySymTb*>*> *head){}
void NamedType::CheckChildren(int level, List<Hashtable<MySymTb*>*> *head){
       Hashtable<MySymTb*> *tb = NULL;
 
        int flag = 0, i = 0;
        while( i < head->NumElements())
        {
		tb = head->Nth(i);
		MySymTb *temp = tb->Lookup(id->name);
                if(temp != NULL)
                {
			flag = 1;
			break;
		}
                i++;

        }
      
      if(flag == 0)
	{
                
		ReportError::IdentifierNotDeclared(id,LookingForClass);
	}
  
    
    

}
void ArrayType::CheckChildren(int level, List<Hashtable<MySymTb*>*> *head){}


NamedType::NamedType(Identifier *i) : Type(*i->GetLocation()) {
    Assert(i != NULL);
    (id=i)->SetParent(this);
} 


ArrayType::ArrayType(yyltype loc, Type *et) : Type(loc) {
    Assert(et != NULL);
    (elemType=et)->SetParent(this);
}

void NamedType::CheckNamedType(int level, List<Hashtable<MySymTb*>*> *head)
{

         Hashtable<MySymTb*> *tb = NULL;

         tb = head->Nth(0);
         MySymTb *temp = tb->Lookup(id->name);
            

      if(temp == NULL)
        {

                ReportError::IdentifierNotDeclared(id,LookingForType);
        }

}

void NamedType::CheckNamedType(int level, List<Hashtable<MySymTb*>*> *head, reasonT t)
{

  Hashtable<MySymTb*> *tb = NULL;

         tb = head->Nth(0);
         MySymTb *temp = tb->Lookup(id->name);


      if(temp == NULL)
        {

                ReportError::IdentifierNotDeclared(id,t);
        }
}

void ArrayType::CheckNamedType(int level, List<Hashtable<MySymTb*>*> *head)
{
         if(elemType != Type::intType  and elemType !=Type::doubleType and elemType != Type::nullType and elemType!= Type::boolType and elemType!= Type::stringType and elemType != Type::errorType and elemType!= Type::voidType)
        {
       
           //Hashtable<MySymTb*> *p = head->Nth(0);
                elemType->CheckNamedType(level,head);

        }
}

int Type::checkT(Type *f)
{
 return f->checkTT(this);
}
int Type::checkT(NamedType *f)
{
 return f->checkTT(this);
}

int Type::checkT(ArrayType *f)
{
return f->checkTT(this);
}







int ArrayType::checkT(Type *f)
{
   return f->checkTT(this);

}
int ArrayType::checkT(NamedType *f)
{
return f->checkTT(this);
}
int ArrayType::checkT(ArrayType *f)
{
  return f->checkTT(this);
}

int NamedType::checkT(Type *f)
{
  return f->checkTT(this);
}
int NamedType::checkT(NamedType *f)
{
 return f->checkTT(this);
}
int NamedType::checkT(ArrayType *f)
{
 return f->checkTT(this);
}







int Type::checkTT(ArrayType *t) {
return 1;
}

int Type::checkTT(Type *y)
{

 if(strcmp(this->getTypeName(),y->getTypeName())==0)
 {
     return 0;
  }
return 1;

}
int Type::checkTT(NamedType *t){
return 1;
}
 



int ArrayType::checkTT(ArrayType *t){

return elemType->checkT(t->elemType);

}

int ArrayType::checkTT(Type *t)
{
  return 1;
}

int ArrayType::checkTT(NamedType *t){
return 1;
}


int NamedType::checkTT(NamedType *t){

if(strcmp(this->getId()->name,t->getId()->name)==0)
{	return 0;}
return 1;
}

int NamedType::checkTT(ArrayType *t)
{return 1;
}
int NamedType::checkTT(Type *t)
{  return 1;
}
