#pragma once
#include "OperatorNode.h"

class EeNode : public TreeNode
{
public: 
		EeNode (Token token) : TreeNode(nullptr,nullptr){ 
			this->token = token;
		}

		Token getToken() {
			return this->token;
		}
private: 
		Token token;

};