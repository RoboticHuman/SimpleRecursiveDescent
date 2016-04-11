#pragma once
#include "OperatorNode.h"

class LtNode : public OperatorNode
{
public: 
		LtNode (Token token) : OperatorNode(nullptr,nullptr){ 
			this->token = token;
		}

		Token getToken() {
			return this->token;
		}
private: 
		Token token;

};