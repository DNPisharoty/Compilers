/* File: ast_stmt.cc
 * -----------------
 * Implementation of statement node classes.
 */
#include "ast_stmt.h"
#include "ast_type.h"
#include "ast_decl.h"
#include "ast_expr.h"
#include "hashtable.h"

Program::Program(List<Decl*> *d) {
    Assert(d != NULL);
    (decls=d)->SetParentAll(this);
}

void Program::Check() {
    /* pp3: here is where the semantic analyzer is kicked off.
     *      The general idea is perform a tree traversal of the
     *      entire program, examining all constructs for compliance
     *      with the semantic rules.  Each node can have its own way of
     *      checking itself, which makes for a great use of inheritance
     *      and polymorphism in the node classes.
     */
    List<Hashtable<MySymTb*>*> *head = new List<Hashtable<MySymTb*>*>();
    int level = 1;   
    Hashtable<MySymTb*> *st = new Hashtable<MySymTb*>();
  
    head->InsertAt(st,0);
    
    CheckChildren(level,head);
//    std::cout<<head->NumElements(); 
    CheckNamedType(level,head);
}


void Program::CheckChildren(int level, List<Hashtable<MySymTb*>*> *head){
   
   
  decls->CheckAll(level,head);
 
}
void Program::CheckNamedType(int level, List<Hashtable<MySymTb*>*> *head)
{
   decls->CheckNamedTypeAll(level,head);

}


StmtBlock::StmtBlock(List<VarDecl*> *d, List<Stmt*> *s) {
    Assert(d != NULL && s != NULL);
    (decls=d)->SetParentAll(this);
    (stmts=s)->SetParentAll(this);
}

void StmtBlock::CheckChildren(int level, List<Hashtable<MySymTb*>*> *head){
      level++;
      head->InsertAt(new Hashtable<MySymTb*>(),0);
      decls->CheckAll(level,head);
      stmts->CheckAll(level,head);
      level--;
      head->RemoveAt(0);

}
void StmtBlock::CheckNamedType(int level, List<Hashtable<MySymTb*>*> *head){


       decls->CheckNamedTypeAll(level,head);
       stmts->CheckNamedTypeAll(level,head);
}



ConditionalStmt::ConditionalStmt(Expr *t, Stmt *b) { 
    Assert(t != NULL && b != NULL);
    (test=t)->SetParent(this); 
    (body=b)->SetParent(this);
}

ForStmt::ForStmt(Expr *i, Expr *t, Expr *s, Stmt *b): LoopStmt(t, b) { 
    Assert(i != NULL && t != NULL && s != NULL && b != NULL);
    (init=i)->SetParent(this);
    (step=s)->SetParent(this);
}
void ForStmt::CheckChildren(int level, List<Hashtable<MySymTb*>*> *head){
      level++;
      head->InsertAt(new Hashtable<MySymTb*>(),0);
      body->CheckChildren(level,head);
      level--;
      head->RemoveAt(0);


   }

void ForStmt::CheckNamedType(int level, List<Hashtable<MySymTb*>*> *head){

    body->CheckNamedType(level,head);

}

 
IfStmt::IfStmt(Expr *t, Stmt *tb, Stmt *eb): ConditionalStmt(t, tb) { 
    Assert(t != NULL && tb != NULL); // else can be NULL
    elseBody = eb;
    if (elseBody) elseBody->SetParent(this);
}

void IfStmt::CheckChildren(int level, List<Hashtable<MySymTb*>*> *head){

     level++;
     head->InsertAt(new Hashtable<MySymTb*>(),0);
     body->CheckChildren(level,head);
     level--;
     head->RemoveAt(0);
     if(elseBody!=NULL)
     {
        level++;
        head->InsertAt(new Hashtable<MySymTb*>(),0);
        body->CheckChildren(level,head);
        level--;
        head->RemoveAt(0);
 
     }
}
void IfStmt::CheckNamedType(int level, List<Hashtable<MySymTb*>*> *head){


    body->CheckNamedType(level,head);
    if(elseBody!=NULL){
  
            elseBody->CheckNamedType(level,head);
    }


}



ReturnStmt::ReturnStmt(yyltype loc, Expr *e) : Stmt(loc) { 
	    Assert(e != NULL);
	    (expr=e)->SetParent(this);
	}
	  
void ReturnStmt::CheckChildren(int level, List<Hashtable<MySymTb*>*> *head){}

PrintStmt::PrintStmt(List<Expr*> *a) {    
    Assert(a != NULL);
    (args=a)->SetParentAll(this);
}
void PrintStmt::CheckChildren(int level, List<Hashtable<MySymTb*>*> *head){}

SwitchStmt::SwitchStmt(Expr *t, List<Stmt*> *b)
{
  Assert(t != NULL && b!= NULL);
  (test=t)->SetParent(this);
    (stmts=b)->SetParentAll(this); 
}
void SwitchStmt::CheckChildren(int level, List<Hashtable<MySymTb*>*> *head){

     level++;
     head->InsertAt(new Hashtable<MySymTb*>(),0);
     stmts->CheckAll(level,head);
     level--;
     head->RemoveAt(0);



}

void SwitchStmt::CheckNamedType(int level, List<Hashtable<MySymTb*>*> *head){

    stmts->CheckNamedTypeAll(level,head);

}



DefaultStmt::DefaultStmt(Expr *t, List<Stmt*> *b)  {
   // Assert(t != NULL && b != NULL);
  //(test=t)->SetParent(this);
    (stmts=b)->SetParentAll(this);
}
void DefaultStmt::CheckChildren(int level, List<Hashtable<MySymTb*>*> *head){}

CaseStmt::CaseStmt(Expr *t, List<Stmt*> *b) {
   // Assert(t != NULL && b != NULL);
    (test=t)->SetParent(this);
    (stmts=b)->SetParentAll(this);
}
void CaseStmt::CheckChildren(int level, List<Hashtable<MySymTb*>*> *head){}
void WhileStmt::CheckChildren(int level, List<Hashtable<MySymTb*>*> *head){
     level++;
     head->InsertAt(new Hashtable<MySymTb*>(),0);
     body->CheckChildren(level,head);
     level--;
     head->RemoveAt(0);



}
void WhileStmt::CheckNamedType(int level, List<Hashtable<MySymTb*>*> *head){

    body->CheckNamedType(level,head);

}


void BreakStmt::CheckChildren(int level, List<Hashtable<MySymTb*>*> *head){}

