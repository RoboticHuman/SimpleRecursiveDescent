#pragma once
#include "OperatorNode.h"

class DummyNode : public OperatorNode
{
public: 
		DummyNode (string name="PIVOT") : OperatorNode(nullptr,nullptr){ 

			Token t;
			t.lexeme = name;
			this->token = t;
		}

private: 
};