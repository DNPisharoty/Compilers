/* File: ast_stmt.h
 * ----------------
 * The Stmt class and its subclasses are used to represent
 * statements in the parse tree.  For each statment in the
 * language (for, if, return, etc.) there is a corresponding
 * node class for that construct. 
 *
 * pp3: You will need to extend the Stmt classes to implement
 * semantic analysis for rules pertaining to statements.
 */


#ifndef _H_ast_stmt
#define _H_ast_stmt

#include "list.h"
#include "ast.h"

class Decl;
class VarDecl;
class Expr;
class Identifier;
class Type;
  

class Program : public Node
{
  protected:
     List<Decl*> *decls;
     
  public:
     Program(List<Decl*> *declList);
     void Check();
     void CheckChildren(int level, List<Hashtable<MySymTb*>*> *head);
     void CheckNamedType(int level, List<Hashtable<MySymTb*>*> *head);


};

class Stmt : public Node
{
  public:
     Stmt() : Node() {}
     Stmt(yyltype loc) : Node(loc) {}
   //void CheckNamedType(int level, List<Hashtable<MySymTb*>*> *head){}

};

class StmtBlock : public Stmt 
{
  protected:
    List<VarDecl*> *decls;
    List<Stmt*> *stmts;
    
  public:
    StmtBlock(List<VarDecl*> *variableDeclarations, List<Stmt*> *statements);
   void CheckChildren(int level, List<Hashtable<MySymTb*>*> *head);
   void CheckNamedType(int level, List<Hashtable<MySymTb*>*> *head);

};

  
class ConditionalStmt : public Stmt
{
  protected:
    Expr *test;
    Stmt *body;
  
  public:
    ConditionalStmt(Expr *testExpr, Stmt *body);
};

class LoopStmt : public ConditionalStmt 
{
  public:
    LoopStmt(Expr *testExpr, Stmt *body)
            : ConditionalStmt(testExpr, body) {}
};

class ForStmt : public LoopStmt 
{
  protected:
    Expr *init, *step;
  
  public:
    ForStmt(Expr *init, Expr *test, Expr *step, Stmt *body);
    void CheckChildren(int level, List<Hashtable<MySymTb*>*> *head);
    void CheckNamedType(int level, List<Hashtable<MySymTb*>*> *head);
 
};

class WhileStmt : public LoopStmt 
{
  public:
    WhileStmt(Expr *test, Stmt *body) : LoopStmt(test, body) {}
   void CheckChildren(int level, List<Hashtable<MySymTb*>*> *head);
   void CheckNamedType(int level, List<Hashtable<MySymTb*>*> *head);

};

class IfStmt : public ConditionalStmt 
{
  protected:
    Stmt *elseBody;
  
  public:
    IfStmt(Expr *test, Stmt *thenBody, Stmt *elseBody);
    void CheckChildren(int level, List<Hashtable<MySymTb*>*> *head);
    void CheckNamedType(int level, List<Hashtable<MySymTb*>*> *head);

};

class BreakStmt : public Stmt 
{
  public:
    BreakStmt(yyltype loc) : Stmt(loc) {}
    void CheckChildren(int level, List<Hashtable<MySymTb*>*> *head);
    void CheckNamedType(int level, List<Hashtable<MySymTb*>*> *head){}

};

class ReturnStmt : public Stmt  
{
  protected:
    Expr *expr;
  
  public:
    ReturnStmt(yyltype loc, Expr *expr);
    void CheckChildren(int level, List<Hashtable<MySymTb*>*> *head);
    void CheckNamedType(int level, List<Hashtable<MySymTb*>*> *head){}

};

class PrintStmt : public Stmt
{
  protected:
    List<Expr*> *args;
    
  public:
    PrintStmt(List<Expr*> *arguments);
    void CheckChildren(int level, List<Hashtable<MySymTb*>*> *head);
    void CheckNamedType(int level, List<Hashtable<MySymTb*>*> *head){}

};

class SwitchStmt : public Stmt
{

 protected:
   Expr *test;
   List<Stmt*> *stmts;
  public:
     SwitchStmt(Expr *testExpr , List<Stmt*> *body);
   // const char *GetPrintNameForNode() { return "SwitchStmt"; }
  /// void PrintChildren(int indentLevel);
  void CheckChildren(int level, List<Hashtable<MySymTb*>*> *head);
  void CheckNamedType(int level, List<Hashtable<MySymTb*>*> *head);


};

class CaseStmt: public Stmt
{
    protected:
   Expr *test;
   List<Stmt*> *stmts;


   public:
    CaseStmt(Expr *testExpr , List<Stmt*> *body);
   // const char *GetPrintNameForNode() { return "Case"; }
   // void PrintChildren(int indentLevel);
    void CheckChildren(int level, List<Hashtable<MySymTb*>*> *head);
    void CheckNamedType(int level, List<Hashtable<MySymTb*>*> *head){}


};
class DefaultStmt: public Stmt
{
    protected:
   Expr *test;
   List<Stmt*> *stmts;

   public:
    DefaultStmt(Expr *testExpr , List<Stmt*> *body);
//    const char *GetPrintNameForNode() { return "Default"; }
 //   void PrintChildren(int indentLevel);
    void CheckChildren(int level, List<Hashtable<MySymTb*>*> *head);
   void CheckNamedType(int level, List<Hashtable<MySymTb*>*> *head){}


};


#endif
