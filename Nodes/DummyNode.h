#pragma once
#include "OperatorNode.h"

class DummyNode : public OperatorNode
{
public: 
		DummyNode (Token token) : OperatorNode(nullptr,nullptr){ 
			this->token = token;
		}

		Token getToken() {
			return this->token;
		}
private: 
		Token token;

};