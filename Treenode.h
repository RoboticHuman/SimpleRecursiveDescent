#pragma once
#include <cstdint>
#include "Includes.h"

using namespace std;





class Treenode
{
public:
  Treenode * left, *right;
  Treenode(Treenode* left, Treenode* right){
    this->left = left;
    this->right = right;
  }
  virtual ~Treenode();
};
