#pragma once
#include "OperatorNode.h"

class IfNode : public OperatorNode
{
public: 
		IfNode (Token token) : OperatorNode(nullptr,nullptr){ 
			this->token = token;
		}

		Token getToken() {
			return this->token;
		}
private: 
		Token token;

};