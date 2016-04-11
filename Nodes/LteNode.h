#pragma once
#include "OperatorNode.h"

class LteNode : public OperatorNode
{
public: 
		LteNode (Token token) : OperatorNode(nullptr,nullptr){ 
			this->token = token;
		}

private: 
};