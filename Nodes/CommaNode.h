#pragma once
#include "OperatorNode.h"

class CommaNode : public OperatorNode
{
public: 
		CommaNode (Token token) : OperatorNode(nullptr,nullptr){ 
			this->token = token;
		}

private: 
};