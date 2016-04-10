#pragma once
#include <string>
#include "TreeNode.h"

extern int   yylex();
extern char* yytext;
extern int   yyleng;

// Here is the interface to the lexer you set up above
extern void* setUpBuffer(char const* text);
extern void  tearDownBuffer(void* buffer);


class Lexer
{
    std::string         token;
    std::string         text;
    void*               buffer;
    public:
    Lexer(std::string const& t)
        : text(t)
    {
        // Use the interface to set up the buffer
        buffer  = setUpBuffer(text.c_str());
        hasNextToken(nextToken);
    }
    ~Lexer()
    {
        // Tear down your interface
        tearDownBuffer(buffer);
    }
    // Don't use RAW pointers
    // This is only a quick and dirty example.


    bool getNextToken(Token& t){

        currToken = nextToken;
        t = currToken;
        if (hasNextToken(nextToken)){
            return true;
        }
        else{
            return false;
        }   
    }

    Token peakToken(){
        return nextToken;
    }
    bool  hasNextToken(Token& t)
    {
        int val = yylex();
        if (val != 0)
        {
            token = std::string(yytext, yyleng);
            t.lexeme = token;
        }
        return val;
    }

    std::string const& theToken() const {return token;}
private:
    Token currToken,nextToken;
};
