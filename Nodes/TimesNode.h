#pragma once
#include "OperatorNode.h"

class TimesNode : public OperatorNode
{
public: 
		TimesNode (Token token) : OperatorNode(nullptr,nullptr){ 
			this->token = token;
		}

private: 
};