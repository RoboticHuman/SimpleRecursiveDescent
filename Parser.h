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
  void match(Token expectedToken);

public:
  void parse();
  Parser (const vector<Token>& tokens, const vector<Error>& errors ) : scanner (tokens,errors){
    
  }

  Parser(string filePath);
  ~Parser();
};
