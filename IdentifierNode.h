#pragma once
#include "Treenode.h"
#include "Token.h"
#include "SymbolTable.h"
#include <string>
using namespace std;
class IdentifierNode : public Treenode
{
public:
  IdentifierNode(Token token): Treenode(nullptr,nullptr){
    SymbolTableEntry* symbolTableEntry;
    SymbolTable* symbolTable = SymbolTable::getInstance();
    symbolTableEntry = symbolTable->lookup(token.getLexeme());
  }
  virtual void generateCode() = 0;
  virtual ~IdentifierNode();
};
