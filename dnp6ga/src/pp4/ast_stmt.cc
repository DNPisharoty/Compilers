/* File: ast_stmt.cc
 * -----------------
 * Implementation of statement node classes.
 */
#include "ast_stmt.h"
#include "ast_type.h"
#include "ast_decl.h"
#include "ast_expr.h"
#include "scope.h"
#include "errors.h"


Program::Program(List<Decl*> *d) {
    Assert(d != NULL);
    (decls=d)->SetParentAll(this);
}

void Program::Check() {
    nodeScope = new Scope();
    decls->DeclareAll(nodeScope);
    decls->CheckAll();
}

StmtBlock::StmtBlock(List<VarDecl*> *d, List<Stmt*> *s) {
    Assert(d != NULL && s != NULL);
    (decls=d)->SetParentAll(this);
    (stmts=s)->SetParentAll(this);
}
void StmtBlock::Check() {
    nodeScope = new Scope();
//     std::cout<<"sb"<<std::endl;
    decls->DeclareAll(nodeScope);
    decls->CheckAll();
    stmts->CheckAll();
}

ConditionalStmt::ConditionalStmt(Expr *t, Stmt *b) { 
    Assert(t != NULL && b != NULL);
    (test=t)->SetParent(this); 
    (body=b)->SetParent(this);
}

void ConditionalStmt::Check() {
    body->Check();
}

ForStmt::ForStmt(Expr *i, Expr *t, Expr *s, Stmt *b): LoopStmt(t, b) { 
    Assert(i != NULL && t != NULL && s != NULL && b != NULL);
    (init=i)->SetParent(this);
    (step=s)->SetParent(this);
}

IfStmt::IfStmt(Expr *t, Stmt *tb, Stmt *eb): ConditionalStmt(t, tb) { 
    Assert(t != NULL && tb != NULL); // else can be NULL
    elseBody = eb;
    if (elseBody) elseBody->SetParent(this);
}
void ForStmt::Check()
{
  if(init != NULL)
	init->Check();
 if(test!= NULL)
  test->Check();
 if(step!= NULL)
	step->Check();	
  if(!test->getExprType()->IsEquivalentTo(Type::boolType))
    {
           ReportError::TestNotBoolean(test);

    }
 body->Check();

}
void WhileStmt::Check()
{
  test->Check();
  if(!test->getExprType()->IsEquivalentTo(Type::boolType))
    {
           ReportError::TestNotBoolean(test);

   }
 body->Check();


}

void IfStmt::Check() {

     test->Check();
    if(!test->getExprType()->IsEquivalentTo(Type::boolType))
    {          
           ReportError::TestNotBoolean(test);    

    }
    ConditionalStmt::Check();

    if (elseBody) elseBody->Check();
}


ReturnStmt::ReturnStmt(yyltype loc, Expr *e) : Stmt(loc) { 
    Assert(e != NULL);
    (expr=e)->SetParent(this);
}
  
PrintStmt::PrintStmt(List<Expr*> *a) {    
    Assert(a != NULL);
    (args=a)->SetParentAll(this);
}
void PrintStmt::Check()
{
   for(int i = 0; i< args->NumElements(); i++)
   {
            args->Nth(i)->Check();
            if(args->Nth(i)->getExprType()->IsEquivalentTo(Type::errorType))
                    {   }
           else if(!(args->Nth(i)->getExprType())->IsEquivalentTo(Type::intType) && ! (args->Nth(i)->getExprType())->IsEquivalentTo(Type::stringType) &&  !(args->Nth(i)->getExprType())->IsEquivalentTo(Type::boolType))
                 ReportError::PrintArgMismatch(args->Nth(i),i+1,args->Nth(i)->getExprType());
                                

  }
}
void BreakStmt::Check()
{
   Node* tmp = this;
   int flag = 0;
   while(tmp->GetParent())
    {

     if(tmp->IsLoopStmt())
      {

         flag = 1;
         break;
       }
      tmp = tmp->GetParent();
 
  }
  if(flag == 0)
     ReportError::BreakOutsideLoop(this);


}
void ReturnStmt::Check()
{
    Node* tmp = this;
   int flag = 0;
   while(tmp->GetParent())
    {

     if(tmp->IsFnDecl())
      {

         flag = 1;
         break;
       }
      tmp = tmp->GetParent();

  }
  if(flag == 1)
  {
         FnDecl* fd = dynamic_cast<FnDecl*>(tmp);
         if(expr->getExprType()->IsEquivalentTo(Type::nullType))
         {
         //       if(!fd->getReturnType()->IsEquivalentTo(Type::nullType))
	 //		 ReportError::ReturnMismatch(this,Type::nullType,fd->getReturnType());

         }
        else{ 
              if(!expr->getExprType()->IsEquivalentTo(fd->getReturnType()))
             
                 ReportError::ReturnMismatch(this,expr->getExprType(),fd->getReturnType());   
  	} 
 }


}
