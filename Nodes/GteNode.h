#pragma once
#include "OperatorNode.h"

class GteNode : public OperatorNode
{
public: 
		GteNode (Token token) : OperatorNode(nullptr,nullptr){ 
			this->token = token;
		}

private: 
};