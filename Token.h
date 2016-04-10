#pragma once

enum class TokenType : std::uint8_t{
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
  WHILE,
  ELSE
};

class Token
{
  TokenType tok;
  int line, pos;
};
