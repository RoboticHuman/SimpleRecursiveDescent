#pragma once
#include "OperatorNode.h"

class MinusNode : public OperatorNode
{
public: 
		MinusNode (Token token) : OperatorNode(nullptr,nullptr){ 
			this->token = token;
		}

private: 
};