#pragma once
#include "OperatorNode.h"

class NumNode : public OperatorNode
{
public: 
		NumNode (Token token) : OperatorNode(nullptr,nullptr){ 
			this->token = token;
		}

private: 
};