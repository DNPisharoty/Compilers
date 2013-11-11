/* File: ast_type.h
 * ----------------
 * In our parse tree, Type nodes are used to represent and
 * store type information. The base Type class is used
 * for built-in types, the NamedType for classes and interfaces,
 * and the ArrayType for arrays of other types.  
 */
 
#ifndef _H_ast_type
#define _H_ast_type

#include "ast.h"
#include "list.h"
#include <iostream>


class Type : public Node 
{
  protected:
    char *typeName;

  public :
    static Type *intType, *doubleType, *boolType, *voidType,
                *nullType, *stringType, *errorType;

    Type(yyltype loc) : Node(loc) {}
    Type(const char *str);
    virtual bool IsArrayType(){return false;}
    virtual bool IsNamedType(){return false;}
    
    virtual void PrintToStream(std::ostream& out) { out << typeName; }
    friend std::ostream& operator<<(std::ostream& out, Type *t) { t->PrintToStream(out); return out; }
    virtual bool IsEquivalentTo(Type *other) { return this == other; }
};

class NamedType : public Type 
{
  protected:
    Identifier *id;
    Decl *cachedDecl; // either class or inteface
    bool isError;
    
  public:
    NamedType(Identifier *i);
    
    void PrintToStream(std::ostream& out) { out << id; }
    void Check();
    Decl *GetDeclForType();
    bool IsInterface();
    bool IsClass();
    bool IsNamedType(){ return true;}
    Identifier *GetId() { return id; }
    bool IsEquivalentTo(Type *other);
};

class ArrayType : public Type 
{
  protected:
    Type *elemType;

  public:
    ArrayType(yyltype loc, Type *elemType);
    bool IsArrayType(){ return true;}  
    void PrintToStream(std::ostream& out) { out << elemType << "[]"; }
    void Check();
    bool IsEquivalentTo(Type *other);
   Type* getElemType(){ return elemType;}
};

 
#endif
