#include "Parser.h"
#include "Definitions.h"
#include <iostream>
//01090003254
using namespace std;

//<program>       -> <type-specifier> ID OPENP <params> CLOSEP OPENB <declaration-list> <compound-statement> CLOSEB
Treenode* Parser::parseProgram()
{
  Treenode* node;

  Treenode* entryNode = new DummyNode("ENTRY");
  entryNode->right = new DummyNode("PROGRAM_SIG");
  entryNode->left = parseTypeSpecifier();

  node = entryNode->right;

  node->left = new IdentifierNode(token);
  match(TokenType::ID);
  node->right = new DummyNode("PROGRAM_PARAMS");
  node = node->right;



  match(TokenType::OPENP);

  node->left = parseParams();
  match(TokenType::CLOSEP);
  node->right = new DummyNode("PROGRAM_START");
  node = node->right;

  match(TokenType::OPENB);
  node->left = parseDeclarationList();
  node->right = new DummyNode("PROGRAM_EXEC");
  node = node->right;

  node->right = new DummyNode("END_OF_PROG");
  node->left = parseCompoundStmt();
  
  match(TokenType::CLOSEB);
  node = node->right;
  //cout << "LEXEME "  << token.lexeme << endl;
  return entryNode;

}

//<declaration-list>  -> <declaration> { <declaration> }
Treenode* Parser::parseDeclarationList(){

  Treenode* left;
  Treenode* node;

  if (token.getType() == TokenType ::INT || token.getType() == TokenType ::FLOAT ||token.getType() == TokenType ::VOID ){
    node = new DummyNode("DECLARATION");
    node->right = parseDeclaration();
    node->left=new DummyNode("DECLARATION");
    left = node;
    node = node->left;
  }

  while (token.getType() == TokenType ::INT || token.getType() == TokenType ::FLOAT ||token.getType() == TokenType ::VOID ){

    node->right = parseDeclaration();
    node->left=new DummyNode("DECLARATION");
    node = node->left;

  }
  return left;

}


Treenode* Parser::parseDeclaration()
{
  return parsevarDeclaration();
}

//<var-declaration> -> <type-specifier> ID [ OPENSB NUM CLOSESB ] DELIM
Treenode* Parser::parsevarDeclaration(){

  Treenode* node;
  Treenode* left;
  left = parseTypeSpecifier();
  if (token.getType() == TokenType::ID)
    node = new IdentifierNode(token);
  match(TokenType::ID);

  node->left = left;

  if (token.getType()==TokenType::OPENSB){
    node->right = new DummyNode("ARRAY_DECLARATION");
    match(TokenType::OPENSB);
    if (token.getType() == TokenType::NUM)
    {
      node->right->left = new ArrayNode(token);
    }
    match(TokenType::NUM);
    match(TokenType::CLOSESB);

    if (token.getType() == TokenType::DELIM)
        node->right->right = new DelimNode(token);
      match(TokenType::DELIM);
  }
  else{
      if (token.getType() == TokenType::DELIM)
        node->right = new DelimNode(token);
      match(TokenType::DELIM);
  }

  return node;


}

//--<type-specifier>  -> INT | VOID | FLOAT
Treenode* Parser::parseTypeSpecifier(){
	Treenode* node;
  if (token.getType() == TokenType ::INT || token.getType() == TokenType ::FLOAT ||token.getType() == TokenType ::VOID ){
     node = new TypeSpecifierNode(token);
  }
  match(token.getType());
  return node;
}

//<params>        -> <param-list> | VOID
Treenode* Parser::parseParams(){

  // TODO
	Treenode* node;
	Token t;
  if ( scanner.peakToken(t)){
	 if ( t.getType() == TokenType::ID)
     node = parseParamList();
  else{
    node = new TypeSpecifierNode(token);
    match(TokenType::VOID);
  }
}
  return node;
}

//<param-list>    -> <param> { COMMA <param> }
Treenode* Parser::parseParamList(){

  Treenode* left, *node;
  left = parseParam();
  while(token.getType()==TokenType::COMMA)
  {
    node = new DelimNode(token);
    match(TokenType::COMMA);
    node->left = left;
    node->right = parseParam();
    left = node;
  }
  return left;

}
//--<param>     -> <type-specifier> ID [ OPENSB CLOSESB ]
Treenode* Parser::parseParam(){
  Treenode* left = parseTypeSpecifier();
  Treenode* node = new IdentifierNode(token);
  match(TokenType::ID);

  node->left = left;

  node->right = new DummyNode("END_PARAM");


  if (token.getType() == TokenType :: OPENSB){
      match(TokenType::OPENSB);
      match(TokenType::CLOSESB);
      node->right = new ArrayNode(token);

  }

  left = node;
  return left;
}


//--<compound-stmt>   -> OPENB <statement-list> CLOSEB
Treenode* Parser::parseCompoundStmt(){

  Treenode* node;
  match(TokenType::OPENB);
  node = parseStmtList();
  match (TokenType::CLOSEB);

  return node;
}

//<statement-list>  -> { <statement> }
Treenode* Parser::parseStmtList()
{
  Treenode *node = new DummyNode("STMT");
  Treenode* left = node;
  while(
    token.getType() == TokenType::ID
    || token.getType() == TokenType::OPENB
    || token.getType() == TokenType::IF
    || token.getType() == TokenType::WHILE
  )
  {
    node->right = parseStmt();
    node->left = new DummyNode("STMT");
    node = node->left;
  }

  return left;
}

//<statement>   -> <assignment-stmt> | <compound-stmt> | <selection-stmt> | <iteration-stmt>
Treenode* Parser::parseStmt()
{
  Treenode* node;
  if(token.getType() == TokenType::ID)
  {
    node = parseAssignmentStmt();
    return node;
  }
  else if(token.getType() == TokenType::OPENB)
  {
    node = parseCompoundStmt();
    return node;
  }
  else if(token.getType() == TokenType::IF)
  {
    node = parseSelectionStmt();
    return node;
  }
  else if(token.getType() == TokenType::WHILE)
  {
    node = parseIterationStmt();
    return node;
  }
  else
    throwError();
}

//<selection-stmt>  -> IF OPENP <expression> CLOSEP <statement> [ ELSE <statement> ]
Treenode* Parser::parseSelectionStmt()
{
  Treenode* left, *Ifnode;
  Ifnode = new IfNode(token);
  match(TokenType::IF);
  match(TokenType::OPENP);
  left = parseExpression();
  match(TokenType::CLOSEP);
  Ifnode->left = left;
  Treenode* node = parseStmt();
  if(token.getType() == TokenType::ELSE)
  {
    Ifnode->right = new ElseNode(token);
    match(TokenType::ELSE);
    Ifnode->right->left = node;
    Ifnode->right->right = parseStmt();
  }
  else{

    Ifnode->right = node;
  }
  left = Ifnode;
  return left;
}

//<iteration-stmt>    -> WHILE OPENP <expression> CLOSEP <statement>
Treenode* Parser::parseIterationStmt()
{
  Treenode* left, *node;
  node = new WhileNode(token);
  match(TokenType::WHILE);
  match(TokenType::OPENP);
  left = parseExpression();
  match(TokenType::CLOSEP);
  node ->left = left;
  node->right = parseStmt();
  left = node;
  return left;
}

//<assignment-stmt>   -> <var> ASSIGNOP <expression>
Treenode* Parser::parseAssignmentStmt()
{
  Treenode* left, *node;
  left = parseVar();
  node = new AssignNode(token);
  match(TokenType::ASSIGN);
  node->left = left;
  node->right = parseExpression();
  left = node;
  return left;
}

//<var>         -> ID [ OPENSB <expression> CLOSESB ]
Treenode* Parser::parseVar()
{

  Treenode* left, *node;
  left = new IdentifierNode(token);
  match(TokenType::ID);
  if(token.getType() == TokenType::OPENSB)
  {
    node = new ArrayNode(token);
    match(TokenType::OPENSB);
    node->left = left;
    node->right = parseExpression();
    match(TokenType::CLOSESB);
    left = node;
  }

  return left;
}

//<expression>      -> <additive-expression> { <relop> <additive-expression> }

Treenode* Parser::parseExpression()
{
  Treenode* left, *node;
  left = parseAdditiveExpr();
  while(
    token.getType()==TokenType::LT
    || token.getType()==TokenType::LTE
    || token.getType()==TokenType::GT
    || token.getType()==TokenType::GTE
    || token.getType()==TokenType::EE
    || token.getType()==TokenType::NE
  )
  {
    node = parseRelop();
    node->left = left;
    node->right = parseAdditiveExpr();
    left = node;
  }
  return left;
}

//<relop>     -> LTE | LT | GT | GTE | EE | NE
Treenode* Parser::parseRelop()
{
  Treenode* node;
  if(token.getType() == TokenType::LTE)
  {
    node = new LteNode(token);
    match(TokenType::LTE);
  }
  else if(token.getType() == TokenType::LT)
  {
    node = new LtNode(token);
    match(TokenType::LT);
  }
  else if(token.getType() == TokenType::GT)
  {
    node = new GtNode(token);
    match(TokenType::GT);
  }
  else if(token.getType() == TokenType::GTE)
  {
    node = new GteNode(token);
    match(TokenType::GTE);
  }
  else if(token.getType() == TokenType::EE)
  {
    node = new EeNode(token);
    match(TokenType::EE);
  }
  else if(token.getType() == TokenType::NE)
  {
    node = new NeNode(token);
    match(TokenType::NE);
  }
  else throwError();
  return node;
}
//--<additive-expression> -> <term> { <addop> <term> }
Treenode* Parser::parseAdditiveExpr()
{
  Treenode* left, *node;
  left = parseTerm();
  while(token.getType()==TokenType::PLUS || token.getType()==TokenType::MINUS)
  {
    node = parseAddop();
    node->left = left;
    node->right = parseTerm();
    left = node;
  }
  return left;
}

//<addop>         -> PLUS | MINUS
Treenode* Parser::parseAddop()
{
  Treenode* node;
  if(token.getType() == TokenType::PLUS){
    node = new PlusNode(token);
    match(TokenType::PLUS);
  }
  else if(token.getType() == TokenType::MINUS)
  {
    node = new MinusNode(token);
    match(TokenType::MINUS);
  }
  else
    throwError();
  return node;
}

//<term>          -> <factor> { <mulop> <factor> }
Treenode* Parser::parseTerm()
{
  Treenode* left, *node;
  left = parseFactor();
  while(token.getType()==TokenType::TIMES || token.getType()==TokenType::DIVIDE)
  {
    node = parseMulop();
    node->left = left;
    node->right = parseFactor();
    left = node;
  }
  return left;
}
//<mulop>         -> TIMES | DIVIDE
Treenode* Parser::parseMulop()
{
  Treenode* node;
  if(token.getType() == TokenType::TIMES)
  {
    node =  new TimesNode(token);
    match(TokenType::TIMES);
  }
  else if(token.getType() == TokenType::DIVIDE){
      node =  new DivideNode(token);
      match(TokenType::DIVIDE);
  }
  else
    throwError();
  return node;
}
//<factor>        -> OPENP <expression> CLOSEP | <var> | NUM
Treenode* Parser::parseFactor()
{
  if(token.getType() == TokenType::OPENP)
  {
    Treenode* exprTree;
    match(TokenType::OPENP);
    exprTree =  parseExpression();
    match(TokenType::CLOSEP);
    return exprTree;
  }
  else if(token.getType() == TokenType::ID)
  {
    Treenode* varTree;
    varTree = parseVar();
    return varTree;
  }
  else if(token.getType() == TokenType::NUM)
  {
    Treenode *node =  new NumNode(token);
    match(TokenType::NUM);
    return node;
  }
  else
    throwError();
}

void Parser::match(TokenType expectedToken)
{
  if(token.getType()==expectedToken){
	  Token t;
	  if (scanner.getNextToken(t)){
		  token = t;
	  }
	  //else throw "END OF INPUT";
  }
  else{
    throwError();
  }
}
