#include "Parser.h"

Parser::Parser(string filePath): scanner(filePath)
{

}

Parser::parseProgram()
{

}

void Parser::match(Token expectedToken)
{
  if(token==expectedToken)
    token = Scanner.getNextToken();
  else
    return SyntaxError();
}

Treenode* Parser::parseIterationStmt()
{
  Treenode* left;
  match(TokenType::WHILE);
  match(TokenType::OPENP);
  left = parseExpression();
  match(TokenType::CLOSEP);

}

Treenode* Parser::parseAssignmentStmt()
{
  Treenode* left, *node;
  left = parseVar();
  node = new AssignmentOperator(token);
  match(TokenType::ASSIGN);
  node->left = left;
  node->right = parseExpression();
  left = node;
  return left;
}

//--<var>     -> ID [ OPENSB <expression> CLOSESB ]
Treenode* Parser::parseVar()
{

  Treenode* left, *node; node = new ArrayAccess();
  left = new IdentifierNode(token);
  match(TokenType::ID);
  if(token.getType() == TokenType::OPENSB)
  {
    match(TokenType::OPENSB);
    node->left = left;
    node->right = parseExpression();
    match(TokenType::CLOSESB);
    left = node;
  }
  return left;
}

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

Treenode* Parser::parseFactor()
{
  if(token.getType() == TokenType::OPENP)
  {
    Treenode* exprTree;
    match(TokenType::OPENP);
    exprTree =  parseExpression();
    return exprTree;
  }
  else if(token.getType() == TokenType::ID)
  {
    Treenode* varTree;
    match(TokenType::ID)
    varTree = parseVar();
    return varTree;
  }
  else if(token.getType() == TokenType::NUM)
  {
    Treenode *literalNode =  new literalNode(token);
    match(TokenType::NUM);
    return literalNode;
  }
  else
    return SyntaxTree();
}


//<relop>			-> LTE | LT | GT | GTE | EE | NE
Treenode* Parser::parseRelop()
{
  Treenode* node;
  if(token.getType() == TokenType::LTE)
  {
    node = new LTENode;
    match(TokenType::LTE);
  }
  else if(token.getType() == TokenType::LT)
  {
    node = new LTNode;
    match(TokenType::LT);
  }
  else if(token.getType() == TokenType::GT)
  {
    node = new GTNode;
    match(TokenType::GT);
  }
  else if(token.getType() == TokenType::GTE)
  {
    node = new GTENode;
    match(TokenType::GTE);
  }
  else if(token.getType() == TokenType::EE)
  {
    node = new EENode;
    match(TokenType::EE);
  }
  else if(token.getType() == TokenType::NE)
  {
    node = new NENode;
    match(TokenType::NE);
  }
  else return SyntaxError();
  return node;
}

Treenode* Parser::parseAddop()
{
  Treenode* node;
  if(token.getType() == TokenType::PLUS){
    node = new AdditionNode;
    match(TokenType::PLUS);
  }
  else if(token.getType() == TokenType::MINUS)
  {
    node = new SubtractionNode;
    match(TokenType::MINUS);
  }
  else
    return SyntaxTree;
  return node;
}

Treenode* Parser::parseMulop()
{
  Treenode* node;
  if(token.getType() == TokenType::TIMES)
  {
    node =  new MultiplicationNode;
    match(TokenType::TIMES);
  }
  else if(token.getType() == TokenType::DIVIDE){
      node =  new DivideNode;
      match(TokenType::DIVIDE);
  }
  else
    return SyntaxError();
  return node;
}

Treenode* Parser::parseDeclaration()
{
  return parsevarDeclaration();
}








Treenode* Parser::parseTypeSpecifier(){

  if (token.getType() == TokenType ::INT || token.getType() == TokenType ::FLOAT ||token.getType() == TokenType ::VOID ){
    Treenode* literalNode = new literalNode(token);
    match(token.getType);
    return literalNode;
  }
}

//<params>    -> <param-list> | VOID
Treenode* Parser::parseParams(){

  // to be done later
}


//<param-list>    -> <param> { COMMA <param> }
Treenode* Parser::parseParamList(){

  Treenode* left, *node;
  left = parseParam():
  while (token.getType == TokenType::COMMA){
    match(token.getType);
    node = delimOperator();
    node->left = left;
    node -> right = parseParam();
    left = node;
  }
  return left;

}

//<param>     -> <type-specifier> ID [ OPENSB CLOSESB ]
Treenode* Parser::parseParam(){
  Treenode* left = parseTypeSpecifier();
  Treenode* node = new IdentifierNode(token);
  match(TokenType::ID);

  node->left = left;
  node->right = nullptr;


  if (token.getType == TokenType :: OPENSB){
      match(TokenType::OPENSB);
      match(TokenType::CLOSESB);

  }

  left = node;
  return left;
}

/*

--<additive-expression> -> <term> { <addop> <term> }
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

*/


