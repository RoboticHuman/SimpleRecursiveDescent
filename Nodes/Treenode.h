#pragma once
#include <cstdint>
//#include "../Includes.h"
#include "../Definitions.h"

using namespace std;



class Treenode
{
public:
  Treenode * left, *right;
  Treenode(Treenode* left, Treenode* right){
    this->left = left;
    this->right = right;
  }
  Treenode (){
	  this->left = nullptr;
	  this->right = nullptr;
  }
  Token getToken() {
      return this->token;
    }
  virtual ~Treenode(){}
protected:
  Token token;
};
