#include "TreeNode.h"

class NumNode

{
public:
	NumNode(Token token){
		this->token = token;
	}

	Token getToken(){
		return this->token;
	}


private:
	Token token;
}