#pragma once
#include "OperatorNode.h"

class ArrayNode : public OperatorNode
{
public: 
		ArrayNode (Token token) : OperatorNode(nullptr,nullptr){ 
			this->token = token;
		}

private: 
};