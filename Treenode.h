#pragma once
#include <cstdint>

using namespace std;

enum class TokenType{
  LTE = 1,
  LT ,
  IF,
  GTE,
  GT,
  EE,
  NE ,
  PLUS,
  MINUS,
  TIMES,
  DIVIDE,
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
  WHILE,
  ELSE
};

class Token
{
public:
  TokenType tok;
  int line, pos;
  string lexeme;

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
