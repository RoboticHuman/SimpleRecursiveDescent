#pragma once
#include "OperatorNode.h"

class ElseNode : public OperatorNode
{
public: 
		ElseNode (Token token) : OperatorNode(nullptr,nullptr){ 
			this->token = token;
		}

		Token getToken() {
			return this->token;
		}
private: 
		Token token;

};