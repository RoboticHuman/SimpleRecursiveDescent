%top{
	#include <vector>
	#include <iostream>
	#include "Parser.h"
	using namespace std;
}

%{
	/************************/
	/*	Global Variables	*/
	/************************/


	vector<Error> errors;
	vector<Token> tokens;
	Token token;
	Error error;
	bool doesHaveBadComment = false;
	int charCnt = 1;
%}

%option noyywrap

	/*	Regular Expressions Definition	*/

ALPHA		[a-zA-Z0-9_!=<>.{}()\[\]*+\-;#$ \t\n\r/]
LTE "<="
LT "<"
GTE ">="
GT ">"
EE "=="
NE "!="
ASSIGN "="
PLUS "+"
MINUS "-"
TIMES "*"
DIVIDE "/"
FLOAT		[Ff][Ll][Oo][Aa][Tt]
NOTALPHA	[^a-zA-Z0-9_!=<>.{}()\[\]*+\-;#$ \t\n\r/]
ELSE		[Ee][Ll][Ss][Ee]
IF			[Ii][Ff]
INT			[Ii][Nn][Tt]
RETURN		[Rr][Ee][Tt][Uu][Rr][Nn]
VOID		[Vv][Oo][Ii][Dd]
WHILE		[Ww][Hh][Ii][Ll][Ee]
LETTER		[a-zA-Z]
DIGIT		[0-9]
NUM			{DIGIT}+(\.{DIGIT}*)?((E|e)(\+|\-)?{DIGIT}+)?
WRONGNUM	{DIGIT}+(\.{DIGIT}*)?(E|e)(\+|\-)?
ID			{LETTER}({LETTER}|{DIGIT})*((\.|#|\$|_)?({LETTER}|{DIGIT})+)?
WRONGID		{LETTER}({LETTER}|{DIGIT})*(\.|#|\$|_)
OPENCOM		"/*"
CLOSECOM	"*/"
COMMENT		{OPENCOM}(.|[\n\r])*?{CLOSECOM}
COMMA 		,
DELIM 		;
OPENB 	"{"
CLOSEB	"}"
OPENSB	"["
CLOSESB	"]"
OPENP "("
CLOSEP	")"

%%
			/*	OTHER	*/
\n			{yylineno++; charCnt = 1;}
{COMMENT}	{}
[ \t]		{charCnt++;}

			/*	TOKENS	*/

{ELSE}		{if(!doesHaveBadComment) {token.lexeme="ELSE"; token.tok = TokenType::ELSE; token.line = yylineno; token.pos=charCnt; tokens.push_back(token);} charCnt+=strlen(yytext);}
{IF}		{if(!doesHaveBadComment) {token.lexeme="IF"; token.tok = TokenType::IF; token.line = yylineno; token.pos=charCnt; tokens.push_back(token);} charCnt+=strlen(yytext);}
{INT}		{if(!doesHaveBadComment) {token.lexeme="INT"; token.tok = TokenType::INT; token.line = yylineno; token.pos=charCnt; tokens.push_back(token);} charCnt+=strlen(yytext);}
{FLOAT}		{if(!doesHaveBadComment) {token.lexeme="FLOAT"; token.tok = TokenType::FLOAT; token.line = yylineno; token.pos=charCnt; tokens.push_back(token);} charCnt+=strlen(yytext);}
{VOID}		{if(!doesHaveBadComment) {token.lexeme="VOID"; token.tok = TokenType::VOID; token.line = yylineno; token.pos=charCnt; tokens.push_back(token);} charCnt+=strlen(yytext);}
{WHILE}		{if(!doesHaveBadComment) {token.lexeme="WHILE"; token.tok = TokenType::WHILE; token.line = yylineno; token.pos=charCnt; tokens.push_back(token);} charCnt+=strlen(yytext);}
{NUM}		{if(!doesHaveBadComment) {token.lexeme=yytext; token.tok = TokenType::NUM; token.line = yylineno; token.pos=charCnt; tokens.push_back(token);} charCnt+=strlen(yytext);}
{ID}		{if(!doesHaveBadComment) {token.lexeme="ID"; token.tok = TokenType::ID; token.line = yylineno; token.pos=charCnt; tokens.push_back(token);} charCnt+=strlen(yytext);}
{COMMA}		{if(!doesHaveBadComment) {token.lexeme=","; token.tok = TokenType::COMMA; token.line = yylineno; token.pos=charCnt; tokens.push_back(token);} charCnt+=strlen(yytext);}
{DELIM}		{if(!doesHaveBadComment) {token.lexeme=";"; token.tok = TokenType::DELIM; token.line = yylineno; token.pos=charCnt; tokens.push_back(token);} charCnt+=strlen(yytext);}
{OPENB}		{if(!doesHaveBadComment) {token.lexeme="{"; token.tok = TokenType::OPENB; token.line = yylineno; token.pos=charCnt; tokens.push_back(token);} charCnt+=strlen(yytext);}
{CLOSEB}		{if(!doesHaveBadComment) {token.lexeme="}"; token.tok = TokenType::CLOSEB; token.line = yylineno; token.pos=charCnt; tokens.push_back(token);} charCnt+=strlen(yytext);}
{OPENSB}		{if(!doesHaveBadComment) {token.lexeme="["; token.tok = TokenType::OPENSB; token.line = yylineno; token.pos=charCnt; tokens.push_back(token);} charCnt+=strlen(yytext);}
{CLOSESB}		{if(!doesHaveBadComment) {token.lexeme="]"; token.tok = TokenType::CLOSESB; token.line = yylineno; token.pos=charCnt; tokens.push_back(token);} charCnt+=strlen(yytext);}
{OPENP}		{if(!doesHaveBadComment) {token.lexeme="("; token.tok = TokenType::OPENP; token.line = yylineno; token.pos=charCnt; tokens.push_back(token);} charCnt+=strlen(yytext);}
{CLOSEP}		{if(!doesHaveBadComment) {token.lexeme=")"; token.tok = TokenType::CLOSEP; token.line = yylineno; token.pos=charCnt; tokens.push_back(token);} charCnt+=strlen(yytext);}
{PLUS}		{if(!doesHaveBadComment) {token.lexeme="+"; token.tok = TokenType::PLUS; token.line = yylineno; token.pos=charCnt; tokens.push_back(token);} charCnt+=strlen(yytext);}
{MINUS}		{if(!doesHaveBadComment) {token.lexeme="-"; token.tok = TokenType::MINUS; token.line = yylineno; token.pos=charCnt; tokens.push_back(token);} charCnt+=strlen(yytext);}
{TIMES}		{if(!doesHaveBadComment) {token.lexeme="*"; token.tok = TokenType::TIMES; token.line = yylineno; token.pos=charCnt; tokens.push_back(token);} charCnt+=strlen(yytext);}
{DIVIDE}		{if(!doesHaveBadComment) {token.lexeme="/"; token.tok = TokenType::DIVIDE; token.line = yylineno; token.pos=charCnt; tokens.push_back(token);} charCnt+=strlen(yytext);}
{LTE}		{if(!doesHaveBadComment) {token.lexeme="<="; token.tok = TokenType::LTE; token.line = yylineno; token.pos=charCnt; tokens.push_back(token);} charCnt+=strlen(yytext);}
{LT}		{if(!doesHaveBadComment) {token.lexeme="<"; token.tok = TokenType::LT; token.line = yylineno; token.pos=charCnt; tokens.push_back(token);} charCnt+=strlen(yytext);}
{GTE}		{if(!doesHaveBadComment) {token.lexeme=">="; token.tok = TokenType::GTE; token.line = yylineno; token.pos=charCnt; tokens.push_back(token);} charCnt+=strlen(yytext);}
{GT}		{if(!doesHaveBadComment) {token.lexeme=">"; token.tok = TokenType::GT; token.line = yylineno; token.pos=charCnt; tokens.push_back(token);} charCnt+=strlen(yytext);}
{EE}		{if(!doesHaveBadComment) {token.lexeme="=="; token.tok = TokenType::EE; token.line = yylineno; token.pos=charCnt; tokens.push_back(token);} charCnt+=strlen(yytext);}
{NE}		{if(!doesHaveBadComment) {token.lexeme="!="; token.tok = TokenType::NE; token.line = yylineno; token.pos=charCnt; tokens.push_back(token);} charCnt+=strlen(yytext);}
{ASSIGN}	{if(!doesHaveBadComment) {token.lexeme="="; token.tok = TokenType::ASSIGN; token.line = yylineno; token.pos=charCnt; tokens.push_back(token);} charCnt+=strlen(yytext);}
			
	/*	ERRORS	*/

{OPENCOM}		{


	if (!doesHaveBadComment){
	//cout <<"Open comment not closed .. Line " << yylineno << " at Idx: " << charCnt << endl;
	error.lineIdx = yylineno;
	error.charIdx = charCnt;
	error.errorSentence = "Open comment not closed";
	errors.push_back(error);
	}
	doesHaveBadComment = true;

}


{NOTALPHA}		{

	if (!doesHaveBadComment){
	//cout <<"Character "<<yytext<<" not part of the alpabet .. Line " << yylineno << " at Idx: " << charCnt << endl;
	error.lineIdx = yylineno;
	error.charIdx = charCnt;
	error.errorSentence = "Character not part of the alpabet";
	errors.push_back(error);
	}


}


{WRONGNUM}		{

	if (!doesHaveBadComment){
	//cout <<"Invalid number format " << yytext <<" .. Line " << yylineno << " at Idx: " << charCnt << endl;
	error.lineIdx = yylineno;
	error.charIdx = charCnt;
	error.errorSentence = "Invalid number format";
	errors.push_back(error);
	}


}



{WRONGID}		{

	if (!doesHaveBadComment){
	//cout <<"Invalid identifier format " << yytext << ".. Line " << yylineno << " at Idx: " << charCnt << endl;
	error.lineIdx = yylineno;
	error.charIdx = charCnt;
	error.errorSentence = "Invalid number format";
	errors.push_back(error);
	}

}

%%


int main()
{
	yylex();
	Parser parser (tokens,errors);
	Scanner scanner (tokens,errors);
	Token t;
	while (scanner.getNextToken(t)){
		cout << t.lexeme << endl;
	}
	return 0;
}





