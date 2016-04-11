
//#include "Includes.h"
#include "Definitions.h"
#include <vector>
using namespace std;

class Scanner

{

public:

	Scanner(const vector<Token>& tokens, const vector<Error>& errors){
			this->tokens = tokens;
			this->errors = errors;

			idx = 0;
	}

	bool getNextToken(Token& token){
		if (idx < tokens.size()){
			token = tokens[idx++];
			return true;
		}
		else return false;
	}

	bool peakToken (Token& token){
		if (idx < tokens.size()){
			token = tokens[idx];
			return true;
		}
		else return false;
	}

private:

	vector<Token> tokens;
	vector<Error> errors;

	int idx;


};