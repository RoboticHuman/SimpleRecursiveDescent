#pragma once
#include "OperatorNode.h"

class DummyNode : public TreeNode
{
public: 
		DummyNode (Token token) : TreeNode(nullptr,nullptr){ 
			this->token = token;
		}

		Token getToken() {
			return this->token;
		}
private: 
		Token token;

};