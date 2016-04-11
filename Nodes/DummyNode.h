#pragma once
#include "OperatorNode.h"

class DummyNode : public OperatorNode
{
public: 
		DummyNode () : OperatorNode(nullptr,nullptr){ 

			Token t;
			t.lexeme = "DN";
			this->token = t;
		}

private: 
};