#pragma once
#include "OperatorNode.h"

class TypeSpecifierNode : public OperatorNode
{
public: 
		TypeSpecifierNode (Token token) : OperatorNode(nullptr,nullptr){ 
			this->token = token;
		}

private: 
};