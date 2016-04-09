#include "Parser.h"

Parser::Parser(string filePath): scanner(filePath)
{

}

Parser::parseProgram()
{

}

Treenode* Parser::parseDeclaration()
{
  return parsevarDeclaration();
}
