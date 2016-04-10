#include <string>
using namespace std;

#include "Nodes/LteNode.h"
#include "Nodes/LtNode.h"
#include "Nodes/GteNode.h"
#include "Nodes/GtNode.h"
#include "Nodes/EeNode.h"
#include "Nodes/NeNode.h"
#include "Nodes/PlusNode.h"
#include "Nodes/MinusNode.h"
#include "Nodes/TimesNode.h"
#include "Nodes/DivideNode.h"
#include "Nodes/IdentifierNode.h"
#include "Nodes/TypeSpecifierNode.h"
#include "Nodes/ArrayNode.h"
#include "Nodes/DelimNode.h"
#include "Nodes/CommaNode.h"
#include "Nodes/NumNode.h"
#include "Nodes/AssignNode.h"
#include "Nodes/IfNode.h"
#include "Nodes/WhileNode.h"
#include "Nodes/ElseNode.h"
#include "Nodes/DummyNode.h"


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