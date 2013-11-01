/* File: ast_expr.cc
 * -----------------
 * Implementation of expression node classes.
 */
#include "ast_expr.h"
#include "ast_type.h"
#include "ast_decl.h"
#include <string.h>



IntConstant::IntConstant(yyltype loc, int val) : Expr(loc) {
    value = val;
}

void IntConstant::CheckChildren(int level, List<Hashtable<MySymTb*>*> *head)
{

}

DoubleConstant::DoubleConstant(yyltype loc, double val) : Expr(loc) {
    value = val;
}
void DoubleConstant::CheckChildren(int level, List<Hashtable<MySymTb*>*> *head)
{

}


BoolConstant::BoolConstant(yyltype loc, bool val) : Expr(loc) {
    value = val;
}

void BoolConstant::CheckChildren(int level, List<Hashtable<MySymTb*>*> *head)
{

}

StringConstant::StringConstant(yyltype loc, const char *val) : Expr(loc) {
    Assert(val != NULL);
    value = strdup(val);
}

void StringConstant::CheckChildren(int level, List<Hashtable<MySymTb*>*> *head)
{

}

Operator::Operator(yyltype loc, const char *tok) : Node(loc) {
    Assert(tok != NULL);
    strncpy(tokenString, tok, sizeof(tokenString));
}
void Operator::CheckChildren(int level, List<Hashtable<MySymTb*>*> *head)
{

}
void CompoundExpr::CheckChildren(int level, List<Hashtable<MySymTb*>*> *head)
{

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
   
CompoundExpr::CompoundExpr(Expr *l, Operator *o)
  : Expr(Join(l->GetLocation(), o->GetLocation())) {
    Assert(o != NULL && l != NULL);
    right = NULL;
   

     (op=o)->SetParent(this);
 
    (left=l)->SetParent(this);
    //(op=o)->SetParent(this);
}
void ArrayAccess::CheckChildren(int level, List<Hashtable<MySymTb*>*> *head)
{

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

void FieldAccess::CheckChildren(int level, List<Hashtable<MySymTb*>*> *head)
{

}


Call::Call(yyltype loc, Expr *b, Identifier *f, List<Expr*> *a) : Expr(loc)  {
    Assert(f != NULL && a != NULL); // b can be be NULL (just means no explicit base)
    base = b;
    if (base) base->SetParent(this);
    (field=f)->SetParent(this);
    (actuals=a)->SetParentAll(this);
}

void Call::CheckChildren(int level, List<Hashtable<MySymTb*>*> *head)
{

}

NewExpr::NewExpr(yyltype loc, NamedType *c) : Expr(loc) { 
  Assert(c != NULL);
  (cType=c)->SetParent(this);
}

void NewExpr::CheckChildren(int level, List<Hashtable<MySymTb*>*> *head)
{

}

NewArrayExpr::NewArrayExpr(yyltype loc, Expr *sz, Type *et) : Expr(loc) {
    Assert(sz != NULL && et != NULL);
    (size=sz)->SetParent(this); 
    (elemType=et)->SetParent(this);
}

void NewArrayExpr::CheckChildren(int level, List<Hashtable<MySymTb*>*> *head)
{

}

