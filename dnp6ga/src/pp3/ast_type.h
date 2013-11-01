/* File: ast_type.h
 * ----------------
 * In our parse tree, Type nodes are used to represent and
 * store type information. The base Type class is used
 * for built-in types, the NamedType for classes and interfaces,
 * and the ArrayType for arrays of other types.  
 *
 * pp3: You will need to extend the Type classes to implement
 * the type system and rules for type equivalency and compatibility.
 */
 
#ifndef _H_ast_type
#define _H_ast_type

#include "ast.h"
#include "list.h"
#include <iostream>
#include "errors.h"

class NamedType;
class ArrayType;

class Type : public Node 
{
   protected:
 
   char *typeName;

 
   public:   
    static Type *intType, *doubleType, *boolType, *voidType,
                *nullType, *stringType, *errorType;

    
    Type(yyltype loc) : Node(loc) {}
    Type(const char *str);
    void CheckNamedType(int level, List<Hashtable<MySymTb*>*> *head){}
    char* getTypeName(){return typeName;}    
    void CheckChildren(int level, List<Hashtable<MySymTb*>*> *head);    
    virtual void PrintToStream(std::ostream& out) { out << typeName; }
    friend std::ostream& operator<<(std::ostream& out, Type *t) { t->PrintToStream(out); return out; }
    virtual bool IsEquivalentTo(Type *other) { return this == other; }
     virtual int checkT(Type *t);
    virtual int  checkT(NamedType *);
    virtual int checkT(ArrayType *);
    virtual int checkTT(ArrayType *);
    virtual int checkTT(NamedType *);
    virtual int  checkTT(Type *);

};

class NamedType : public Type 
{
  protected:
    Identifier *id;
    
  public:
    
    NamedType(Identifier *i);
   void CheckChildren(int level, List<Hashtable<MySymTb*>*> *head);
  
    Identifier* getId();
    void CheckNamedType(int level, List<Hashtable<MySymTb*>*> *head);
    void CheckNamedType(int level, List<Hashtable<MySymTb*>*> *head, reasonT t);
    void PrintToStream(std::ostream& out) { out << id; }
    int checkT(Type *t);
     int checkT(NamedType *);
     int checkT(ArrayType *);
     int checkTT(ArrayType *);
     int checkTT(NamedType *);
     int checkTT(Type *);




};

class ArrayType : public Type 
{
  protected:
    Type *elemType;

  public:
    ArrayType(yyltype loc, Type *elemType);
 void CheckChildren(int level, List<Hashtable<MySymTb*>*> *head);   
 void CheckNamedType(int level, List<Hashtable<MySymTb*>*> *head);
    void PrintToStream(std::ostream& out) { out << elemType << "[]"; }
int checkT(Type *t);
    int checkT(NamedType *);
     int checkT(ArrayType *);
     int checkTT(ArrayType *);
     int checkTT(NamedType *);
     int checkTT(Type *);


};

 
#endif
