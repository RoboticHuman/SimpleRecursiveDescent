#pragma once
#include "OperatorNode.h"

class DelimNode : public OperatorNode
{
public: 
		DelimNode (Token token) : OperatorNode(nullptr,nullptr){ 
			this->token = token;
		}

private: 
};