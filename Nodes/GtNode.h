#pragma once
#include "OperatorNode.h"

class GtNode : public OperatorNode
{
public: 
		GtNode (Token token) : OperatorNode(nullptr,nullptr){ 
			this->token = token;
		}

		Token getToken() {
			return this->token;
		}
private: 
		Token token;

};