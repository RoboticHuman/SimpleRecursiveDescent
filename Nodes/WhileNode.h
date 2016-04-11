#pragma once
#include "OperatorNode.h"

class WhileNode : public OperatorNode
{
public: 
		WhileNode (Token token) : OperatorNode(nullptr,nullptr){ 
			this->token = token;
		}

		Token getToken() {
			return this->token;
		}
private: 
		Token token;

};