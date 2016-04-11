/*
<program>       -> <type-specifier> ID OPENP <params> CLOSEP OPENB <declaration-list> <compound-statement> CLOSEB
<declaration-list>    -> <declaration> { <declaration> }
<declaration>     -> <var-declaration>
<var-declaration>   -> <type-specifier> ID [ OPENSB NUM CLOSESB ] DELIM
<type-specifier>    -> INT | VOID | FLOAT

<params>        -> <param-list> | VOID
<param-list>      -> <param> { COMMA <param> }
<param>         -> <type-specifier> ID [ OPENSB CLOSESB ]
<compound-stmt>     -> OPENB <statement-list> CLOSEB

<statement-list>    -> { <statement> }
<statement>       -> <assignment-stmt> | <compound-stmt> | <selection-stmt> | <iteration-stmt>

<selection-stmt>    -> IF OPENP <expression> CLOSEP <statement> [ ELSE <statement> ]
<iteration-stmt>    -> WHILE OPENP <expression> CLOSEP <statement>

<assignment-stmt>   -> <var> ASSIGNOP <expression>
<var>         -> ID [ OPENSB <expression> CLOSESB ]
<expression>      -> <additive-expression> { <relop> <additive-expression> }
<relop>         -> LTE | LT | GT | GTE | EE | NE
<additive-expression> -> <term> { <addop> <term> }
<addop>         -> PLUS | MINUS
<term>          -> <factor> { <mulop> <factor> }
<mulop>         -> TIMES | DIVIDE
<factor>        -> OPENP <expression> CLOSEP | <var> | NUM
*/


#include <string>
#include "Includes.h"
#include "Definitions.h"
#include "Scanner.h"
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
class Parser
{
private:
  Treenode * syntaxtreeRoot;
  Token token;
  Scanner scanner;
  Treenode * parseProgram(); // DON
  Treenode * parseDeclarationList();
  Treenode * parseDeclaration(); // DON
  Treenode * parsevarDeclaration();
  Treenode * parseTypeSpecifier(); // ZARE3
  Treenode * parseParams(); // ZARE3
  Treenode * parseParamList(); // ZARE3
  Treenode * parseParam();
  Treenode * parseCompoundStmt();
  Treenode * parseStmtList();
  Treenode * parseStmt();
  Treenode * parseSelectionStmt();
  Treenode * parseIterationStmt(); // DON
  Treenode * parseAssignmentStmt(); // DON
  Treenode * parseVar(); // DON
  Treenode * parseExpression(); // DON
  Treenode * parseRelop(); // DON
  Treenode * parseAdditiveExpr(); // DON
  Treenode * parseAddop(); // DON
  Treenode * parseTerm(); // DON
  Treenode * parseMulop(); // DON
  Treenode * parseFactor(); // DON
  void match(TokenType expectedToken);
  void privateDumpSyntaxTree(Treenode* root){

    if (root!=NULL){
      //if (root->getToken().lexeme!="DN")
      cout << root->getToken().lexeme<<"...";
      privateDumpSyntaxTree(root->left);
      privateDumpSyntaxTree(root->right);
    }
  }
  void outputTabs(int size){
    for (int i=0; i<size; i++){
      cout << '\t';
    }
  }
  void BFS(){
    int off =15;
    int lvl = 0;
    queue<pair<Treenode*,string> > q;
    q.push({syntaxtreeRoot,""});
    Treenode* curr;
    while (!q.empty()){
      int size = q.size();
      cout <<"LEVEL: " << lvl<<": " <<endl;
      for (int i=0; i<size; i++){
        Treenode* currNodeInLvl = q.front().first;
        string parent = q.front().second;
 
        cout << currNodeInLvl->getToken().lexeme;
        if (currNodeInLvl->left)
          q.push({currNodeInLvl->left,currNodeInLvl->getToken().lexeme});
        if (currNodeInLvl->right)
          q.push({currNodeInLvl->right,currNodeInLvl->getToken().lexeme});
        cout<<"(PARENT IS "<<parent<<")";
        cout <<"   ";
        q.pop();

      }
      cout << endl;
      cout << "----------------------------------------------------------------------------------------------------------------";
      cout << endl;
      lvl++;

    }


  }

public:
  void parse(){
    syntaxtreeRoot = parseProgram();
  }
  void dumpSyntaxTree(){
    privateDumpSyntaxTree(syntaxtreeRoot);
  }
  void dumpSyntaxTreeDrawed(){
    BFS();
  }
  Parser (const vector<Token>& tokens, const vector<Error>& errors ) : scanner (tokens,errors){
    Token t;
    if (scanner.getNextToken(t)){
        token = t;
    }

  }

  Scanner getScanner (){
    return scanner;
  }

  ~Parser(){}
};
