#pragma once
#include "OperatorNode.h"

class NeNode : public OperatorNode
{
public: 
		NeNode (Token token) : OperatorNode(nullptr,nullptr){ 
			this->token = token;
		}

		Token getToken() {
			return this->token;
		}
private: 
		Token token;

};