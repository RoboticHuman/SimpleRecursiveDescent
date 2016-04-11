#pragma once
#include "OperatorNode.h"

class EeNode : public OperatorNode
{
public: 
		EeNode (Token token) : OperatorNode(nullptr,nullptr){ 
			this->token = token;
		}

private: 
};