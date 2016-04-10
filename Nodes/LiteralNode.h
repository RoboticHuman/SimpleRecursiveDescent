#pragma once
#include "Treenode.h"
#include "Token.h"
#include "LiteralTable.h"
#include <string>
using namespace std;
class LiteralNode : public Treenode
{
public:
  LiteralNode(Token token): Treenode(nullptr,nullptr){
    LiteralTableEntry* literalTableEntry;
    LiteralTable* literalTable = LiteralTable::getInstance();
    literalTableEntry = literalTable->lookup(token.getLexeme());
  }
  virtual void generateCode() = 0;
  virtual ~LiteralNode();
};
