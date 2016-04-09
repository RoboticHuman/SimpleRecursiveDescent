/*
<program>		-> <type-specifier> ID OPENP <params> CLOSEP OPENB <declaration-list> <compound-statement> CLOSEB
<declaration-list>	-> <declaration> { <declaration> }
<declaration>		-> <var-declaration>
<var-declaration>	-> <type-specifier> ID [ OPENSB NUM CLOSESB ] DELIM
<type-specifier>	-> INT | VOID | FLOAT
<params>		-> <param-list> | VOID
<param-list>		-> <param> { COMMA <param> }
<param>			-> <type-specifier> ID [ OPENSB CLOSESB ]
<compound-stmt>		-> OPENB <statement-list> CLOSEB
<statement-list>	-> { <statement> }
<statement>		-> <assignment-stmt> | <compound-stmt> | <selection-stmt> | <iteration-stmt>
<selection-stmt>	-> IF OPENP <expression> CLOSEP <statement> [ ELSE <statement> ]
<iteration-stmt>	-> WHILE OPENP <expression> CLOSEP <statement>
<assignment-stmt>	-> <var> ASSIGNOP <expression>
<var>			-> ID [ OPENSB <expression> CLOSESB ]
<expression>		-> <additive-expression> { <relop> <additive-expression> }
<relop>			-> LTE | LT | GT | GTE | EE | NE
<additive-expression>	-> <term> { <addop> <term> }
<addop>			-> PLUS | MINUS
<term>			-> <factor> { <mulop> <factor> }
<mulop>			-> TIMES | DIVIDE
<factor>		-> OPENP <expression> CLOSEP | <var> | NUM
*/
#include "Scanner.h"
#include <string>
using namespace std;
class Parser
{
private:
  Treenode * syntaxtreeRoot;
  Scanner scanner;
  Treenode * parseProgram();
  Treenode * parseDeclarationList();
  Treenode * parseDeclaration();
  Treenode * parsevarDeclaration();
  Treenode * parseTypeSpecifier();
  Treenode * parseParams();
  Treenode * parseParamList();
  Treenode * parseParam();
  Treenode * parseCompoundStmt();
  Treenode * parseStmtList();
  Treenode * parseStmt();
  Treenode * parseSelectionStmt();
  Treenode * parseIterationStmt();
  Treenode * parseAssignmentStmt();
  Treenode * parseVar();
  Treenode * parseExpression();
  Treenode * parseRelop();
  Treenode * parseAdditiveExpr();
  Treenode * parseAddop();
  Treenode * parseTerm();
  Treenode * parseMulop();
  Treenode * parseFactor();

public:
  void parse();
  Parser(string filePath);
  ~Parser();
};
