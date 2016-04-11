#pragma once
#include <string>
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

  TokenType getType () {
  	return tok;
  }

};

struct Error
{
	string errorSentence;
	int lineIdx;
	int charIdx;
};