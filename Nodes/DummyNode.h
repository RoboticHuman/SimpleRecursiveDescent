#pragma once
#include "OperatorNode.h"

class DummyNode : public OperatorNode
{
public: 
		DummyNode () : OperatorNode(nullptr,nullptr){ 

			Token t;
			t.lexeme = "NODE";
			this->token = t;
		}

private: 
};