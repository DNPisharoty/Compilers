/* File: ast.cc
 * ------------
 */

#include "ast.h"
#include "ast_type.h"
#include "ast_decl.h"
#include <string.h> // strdup
#include <stdio.h>  // printf
#include "hashtable.h"
#include "list.h"


Node::Node(yyltype loc) {
    location = new yyltype(loc);
    parent = NULL;
}

Node::Node() {
    location = NULL;
    parent = NULL;
}
	 
Identifier::Identifier(yyltype loc, const char *n) : Node(loc) {
    name = strdup(n);
}
MySymTb::MySymTb(Identifier *i, int s, char *t)
{
   id = i;
   scope = s;
   type = strdup(t);
}
MySymTb::MySymTb()
{
  id = NULL;
  scope = 0;
  type = NULL;
  child = NULL;
}
MySymTb::MySymTb(Identifier *i, int s, char *t, Decl *n)
{
  id = i;
  scope = s;
  type = strdup(t);
  child = n;

}

void Node::Check(int l, List<Hashtable<MySymTb*>*> *head)
{
  //CheckChildren(l,head);  

} 
void Identifier::CheckChildren(int level, List<Hashtable<MySymTb*>*> *head)
{

}

