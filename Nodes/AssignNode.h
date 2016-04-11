#pragma once
#include "OperatorNode.h"

class AssignNode : public OperatorNode
{
public: 
		AssignNode (Token token) : OperatorNode(nullptr,nullptr){ 
			this->token = token;
		}

		Token getToken() {
			return this->token;
		}
private: 
		Token token;

};