#include "Parser.h"

Parser::Parser(string filePath): scanner(filePath)
{

}

/*

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

  */
Parser::parseProgram()
{

}

Treenode* Parser::parseDeclarationList(){

  Treenode* left;
  Treenode* node;

  left =  parseDeclaration();

  while (token.getType() == TokenType ::INT || token.getType() == TokenType ::FLOAT ||token.getType() == TokenType ::VOID ){
    node =  new dummyNode();
    node->left = left;
    node->right = parseDeclaration();
    left = node;

  }
  return left;

}


Treenode* Parser::parseDeclaration()
{
  return parsevarDeclaration();
}

Treenode* Parser::parsevarDeclaration(){

  Treenode* node;
  Treenode* left;

  left = parseTypeSpecifier();
  if (token.getType() == TokenType::ID)
    node = new IdentifierNode(token);
  match(TokenType::ID);
  node->left = left;

  if (token.getType()==TokenType::OPENSB){
    node->right = new DummyNode();
    match(TokenType::OPENSB);
    if (token.getType() == TokenType::NUM)
      node->right->left = new ArrayAccessNode(token);
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

Treenode* Parser::parseTypeSpecifier(){

  if (token.getType() == TokenType ::INT || token.getType() == TokenType ::FLOAT ||token.getType() == TokenType ::VOID ){
    Treenode* literalNode = new literalNode(token);
    match(token.getType);
    return literalNode;
  }
}

Treenode* Parser::parseParams(){

  // TODO
}

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



Treenode* Parser::parseCompoundStatement(){

  Treenode* node;
  match(TokenType::OPENB);
  node = parseStmtList();
  match (TokenType::CLOSEB);

  return node;
}

Treenode* Parser::parseStmtList()
{
  Treenode *node = new DummyNode();
  Treenode* left = node;
  while(
    token.getType() == TokenType::ID
    || token.getType() == TokenType::OPENB
    || token.getType() == TokeType::IF
    || token.getType() == TokenType::WHILE
  )
  {
    node->right = parseStmt();
    node->left = new DummyNode();
    node = node->left;
  }

  return left;
}


Treenode* Parser::parseStmt()
{
  Treenode* node;
  if(token.getType() == TokenType::ID)
  {
    node = parseAssignmentStmt();
  }
  else if(token.getType() == TokenType::OPENB)
  {
    node = parseCompoundStmt();
  }
  else if(token.getType() == TokenType::IF)
  {
    node = parseSelectionStmt();
  }
  else if(token.getType() == TokenType::WHILE)
  {
    node = parseIterationStmt();
  }
  else
    return SyntaxError();
}


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
    Ifnode->right = new ThenElse(token);
    match(TokenType::ELSE);
    Ifnode->right->left = node;
    Ifnode->right->right = parseStmt();
  }
  left = Ifnode;
  return left;
}

Treenode* Parser::parseIterationStmt()
{
  Treenode* left, *node;
  node = new Whilenode(token);
  match(TokenType::WHILE);
  match(TokenType::OPENP);
  left = parseExpression();
  match(TokenType::CLOSEP);
  node ->left = left;
  node->right = parseStmt();
  left = node;
  return left;
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

//<relop>     -> LTE | LT | GT | GTE | EE | NE
Treenode* Parser::parseRelop()
{
  Treenode* node;
  if(token.getType() == TokenType::LTE)
  {
    node = new LteNode;
    match(TokenType::LTE);
  }
  else if(token.getType() == TokenType::LT)
  {
    node = new LtNode;
    match(TokenType::LT);
  }
  else if(token.getType() == TokenType::GT)
  {
    node = new GtNode;
    match(TokenType::GT);
  }
  else if(token.getType() == TokenType::GTE)
  {
    node = new GteNode;
    match(TokenType::GTE);
  }
  else if(token.getType() == TokenType::EE)
  {
    node = new EeNode;
    match(TokenType::EE);
  }
  else if(token.getType() == TokenType::NE)
  {
    node = new NeNode;
    match(TokenType::NE);
  }
  else return SyntaxError();
  return node;
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

Treenode* Parser::parseAddop()
{
  Treenode* node;
  if(token.getType() == TokenType::PLUS){
    node = new PlusNode;
    match(TokenType::PLUS);
  }
  else if(token.getType() == TokenType::MINUS)
  {
    node = new MinusNode;
    match(TokenType::MINUS);
  }
  else
    return SyntaxTree;
  return node;
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

Treenode* Parser::parseMulop()
{
  Treenode* node;
  if(token.getType() == TokenType::TIMES)
  {
    node =  new TimesNode;
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

void Parser::match(Token expectedToken)
{
  if(token==expectedToken)
    token = Scanner.getNextToken();
  else
    return SyntaxError();
}




