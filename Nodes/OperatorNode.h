#pragma once
#include "Treenode.h"

class OperatorNode : public Treenode
{
public:
  OperatorNode(Treenode* left, Treenode* right) : Treenode(left,right) { 
  
  }
  virtual ~OperatorNode(){}
  //virtual void generateCode() = 0; //TODO
};
