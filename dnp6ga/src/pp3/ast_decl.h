/* File: ast_decl.h
 * ----------------
 * In our parse tree, Decl nodes are used to represent and
 * manage declarations. There are 4 subclasses of the base class,
 * specialized for declarations of variables, functions, classes,
 * and interfaces.
 *
 * pp3: You will need to extend the Decl classes to implement 
 * semantic processing including detection of declaration conflicts 
 * and managing scoping issues.
 */

#ifndef _H_ast_decl
#define _H_ast_decl

#include "ast.h"
#include "list.h"

class Type;
class NamedType;
class Identifier;
class Stmt;
class ClassDecl;
class VarDecl;
class FnDecl;
class ArrayType;
class Decl : public Node 
{
  protected:
    Identifier *id;

  public:
    Decl(Identifier *name);
    virtual void checkMembers(Decl* cl);
    virtual void checkV(VarDecl *d){}
    virtual void checkF(FnDecl *d){}
    virtual void checkClass(VarDecl *d) {}
    virtual void checkClass(FnDecl *d) {}
 
    void CheckNamedType(int level, List<Hashtable<MySymTb*>*> *head);
    friend std::ostream& operator<<(std::ostream& out, Decl *d) { return out << d->id; }
};


class ClassDecl : public Decl
{
  protected:
    List<Decl*> *members;
    NamedType *extends;
    List<NamedType*> *implements;

  public:

    ClassDecl(Identifier *name, NamedType *extends,
              List<NamedType*> *implements, List<Decl*> *members);
    void CheckChildren(int level, List<Hashtable<MySymTb*>*> *head);
    void CheckNamedType(int level, List<Hashtable<MySymTb*>*> *head);
   void checkInheritedMembers(List<Decl*> m);
    void checkClass(VarDecl *d) ;
   void checkClass(FnDecl *d) ;
    

};



class VarDecl : public Decl 
{
  protected:
    Type *type;
    
  public:
    VarDecl(Identifier *name, Type *type);
    void CheckChildren(int level, List<Hashtable<MySymTb*>*> *head);
    void CheckNamedType(int level, List<Hashtable<MySymTb*>*> *head);
    friend void ClassDecl::CheckNamedType(int level, List<Hashtable<MySymTb*>*> *head);
    void checkMembers(Decl* cl);
    void checkV(VarDecl* d);
    void checkF(FnDecl* d);
    Type* getType(){return type;}
    Identifier* getId(){return id;}
};
/*
class ClassDecl : public Decl 
{
  protected:
    List<Decl*> *members;
    NamedType *extends;
    List<NamedType*> *implements;

  public:
    ClassDecl(Identifier *name, NamedType *extends, 
              List<NamedType*> *implements, List<Decl*> *members);
    void CheckChildren(int level, List<Hashtable<MySymTb*>*> *head);
    void CheckNamedType(int level, List<Hashtable<MySymTb*>*> *head);
    friend void checkInheritedMembers(List<Decl*> m, ClassDecl * c);

};*/

class InterfaceDecl : public Decl 
{
  protected:
    List<Decl*> *members;
    
  public:
    InterfaceDecl(Identifier *name, List<Decl*> *members);
    void CheckChildren(int level, List<Hashtable<MySymTb*>*> *head);
    void CheckNamedType(int level, List<Hashtable<MySymTb*>*> *head);
    void checkClass(VarDecl *d);
    void checkClass(FnDecl *d);


};

class FnDecl : public Decl 
{
  protected:
    List<VarDecl*> *formals;
    Type *returnType;
    Stmt *body;
    
  public:
    FnDecl(Identifier *name, Type *returnType, List<VarDecl*> *formals);
    void SetFunctionBody(Stmt *b);
    void CheckChildren(int level, List<Hashtable<MySymTb*>*> *head);
    void CheckNamedType(int level, List<Hashtable<MySymTb*>*> *head);
    friend void ClassDecl::CheckNamedType(int level, List<Hashtable<MySymTb*>*> *head);
    void checkMembers(Decl* cl);
    void checkV(VarDecl* d);
    void checkF(FnDecl* d);
    Identifier* getId(){return id;}
    int checkTypes(Type *t, Type *f);
    void checkTypes(Type*t, NamedType *f);
    void checkTypes(Type*t, ArrayType *f);
    void checkTypes(NamedType *t, NamedType *f);
    void checkTypes(NamedType *t, Type *f);
    void checkTypes(NamedType *t, ArrayType *f);
    void checkTypes(ArrayType *t, NamedType *f);
    void checkTypes(ArrayType *t, Type *f);
    void checkTypes(ArrayType *t, ArrayType *f);


};


#endif
