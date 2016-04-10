#pragma once
#include "OperatorNode.h"

class ArrayNode : public TreeNode
{
public: 
		ArrayNode (Token token) : TreeNode(nullptr,nullptr){ 
			this->token = token;
		}

		Token getToken() {
			return this->token;
		}
private: 
		Token token;

};