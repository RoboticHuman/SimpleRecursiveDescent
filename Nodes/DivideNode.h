#pragma once
#include "OperatorNode.h"

class DivideNode : public OperatorNode
{
public: 
		DivideNode (Token token) : OperatorNode(nullptr,nullptr){ 
			this->token = token;
		}

		Token getToken() {
			return this->token;
		}
private: 
		Token token;

};