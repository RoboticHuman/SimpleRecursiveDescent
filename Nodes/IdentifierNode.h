#pragma once
#include "OperatorNode.h"

class IdentifierNode : public OperatorNode
{
public: 
		IdentifierNode (Token token) : OperatorNode(nullptr,nullptr){ 
			this->token = token;
		}

private: 
};