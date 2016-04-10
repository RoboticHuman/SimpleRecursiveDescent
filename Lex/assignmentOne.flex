%top{
	#include <vector>
	#include <iostream>
	using namespace std;
}

%{
	/************************/
	/*	Global Variables	*/
	/************************/

	struct Error
	{
		string errorSentence;
		int lineIdx;
		int charIdx;
	};
	
	struct Token
	{
		string tokenName;		
	};

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
NOTALPHA	[^a-zA-Z0-9_!=<>.{}()\[\]*+\-;#$ \t\n\r/]
ELSE		[Ee][Ll][Ss][Ee]
IF			[Ii][Ff]
INT 		[Ii][Nn][Tt]
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
OPENCURLY 	"{"
CLOSECURLY	"}"
OPENSQUARE	"["
CLOSESQUARE	"]"
OPENBRACKET	"("
CLOSBRACKET	")"

ADDOP		 "+"|"-"
MULOP		 "*"|"/"
CMPOP		 "<"|">"|"<="|">="
ASSOP		 =


%%
			/*	OTHER	*/
\n			{yylineno++; charCnt = 1;}
{COMMENT}	{}
[ \t]		{charCnt++;}

			/*	TOKENS	*/

{ELSE}		{if(!doesHaveBadComment) {token.tokenName="ELSE"; tokens.push_back(token);} charCnt+=strlen(yytext);}
{IF}		{if(!doesHaveBadComment) {token.tokenName="IF"; tokens.push_back(token);} charCnt+=strlen(yytext);}
{INT}		{if(!doesHaveBadComment) {token.tokenName="INT"; tokens.push_back(token);} charCnt+=strlen(yytext);}
{RETURN}		{if(!doesHaveBadComment) {token.tokenName="RETURN"; tokens.push_back(token);} charCnt+=strlen(yytext);}
{VOID}		{if(!doesHaveBadComment) {token.tokenName="VOID"; tokens.push_back(token);} charCnt+=strlen(yytext);}
{WHILE}		{if(!doesHaveBadComment) {token.tokenName="WHILE"; tokens.push_back(token);} charCnt+=strlen(yytext);}
{NUM}		{if(!doesHaveBadComment) {token.tokenName="NUM"; tokens.push_back(token);} charCnt+=strlen(yytext);}
{ID}		{if(!doesHaveBadComment) {token.tokenName="ID"; tokens.push_back(token);} charCnt+=strlen(yytext);}
{COMMA}		{if(!doesHaveBadComment) {token.tokenName="COMMA"; tokens.push_back(token);} charCnt+=strlen(yytext);}
{DELIM}		{if(!doesHaveBadComment) {token.tokenName="DELIM"; tokens.push_back(token);} charCnt+=strlen(yytext);}
{OPENCURLY}		{if(!doesHaveBadComment) {token.tokenName="OPENCURLY"; tokens.push_back(token);} charCnt+=strlen(yytext);}
{CLOSECURLY}		{if(!doesHaveBadComment) {token.tokenName="CLOSECURLY"; tokens.push_back(token);} charCnt+=strlen(yytext);}
{OPENSQUARE}		{if(!doesHaveBadComment) {token.tokenName="OPENSQUARE"; tokens.push_back(token);} charCnt+=strlen(yytext);}
{CLOSESQUARE}		{if(!doesHaveBadComment) {token.tokenName="CLOSESQUARE"; tokens.push_back(token);} charCnt+=strlen(yytext);}
{OPENBRACKET}		{if(!doesHaveBadComment) {token.tokenName="OPENBRACKET"; tokens.push_back(token);} charCnt+=strlen(yytext);}
{CLOSBRACKET}		{if(!doesHaveBadComment) {token.tokenName="CLOSBRACKET"; tokens.push_back(token);} charCnt+=strlen(yytext);}
{ADDOP}		{if(!doesHaveBadComment) {token.tokenName="ADDOP"; tokens.push_back(token);} charCnt+=strlen(yytext);}
{MULOP}		{if(!doesHaveBadComment) {token.tokenName="MULOP"; tokens.push_back(token);} charCnt+=strlen(yytext);}
{CMPOP}		{if(!doesHaveBadComment) {token.tokenName="CMPOP"; tokens.push_back(token); } charCnt+=strlen(yytext);}
{ASSOP}		{if(!doesHaveBadComment) {token.tokenName="ASSOP"; tokens.push_back(token); } charCnt+=strlen(yytext);}

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
	

	return 0;
}




/*cout <<"----------------------------------------------------------------"<<endl;
	cout <<"----------------------------------------------------------------"<<endl;
	cout <<"----------------------------------------------------------------"<<endl;
	for (int i=0; i<tokens.size(); i++){
		cout <<tokens[i].tokenName << endl;
	}
	cout <<"----------------------------------------------------------------"<<endl;
	cout <<"----------------------------------------------------------------"<<endl;
	cout <<"----------------------------------------------------------------"<<endl;
	cout <<"Errors: " <<"("<<errors.size()<<")"<< endl;
	for (int i=0; i<errors.size(); i++){
		cout <<errors[i].errorSentence<<" AT LINE: " << errors[i].lineIdx << "- IDX: " << errors[i].charIdx<<endl;
		cout << endl << endl;
	}*/




