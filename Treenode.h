#pragma once
#include <cstdint>

enum class TokenType : std::uint8_t{
  LTE = 1,
  LT ,
  GTE,
  GT,
  EE,
  NE ,
  PLUS,
  MINUS,
  TIMES,
  DIVIDE
  ID,
  VOID,
  FLOAT,
  INT,
  OPENSB,
  CLOSESB,
  OPENP,
  CLOSEP,
  OPENB,
  CLOSEB,
  DELIM,
  COMMA,
  EPSILON,
  NUM,
  ASSIGN,
  WHILE
};

class Token
{
  TokenType tok;
  int line, pos;

};

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
