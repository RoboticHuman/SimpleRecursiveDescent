#pragma once
#include "OperatorNode.h"

class PlusNode : public OperatorNode
{
public: 
		PlusNode (Token token) : OperatorNode(nullptr,nullptr){ 
			this->token = token;
		}

		Token getToken() {
			return this->token;
		}
private: 
		Token token;

};