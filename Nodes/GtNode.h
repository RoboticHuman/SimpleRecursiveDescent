#pragma once
#include "OperatorNode.h"

class GtNode : public TreeNode
{
public: 
		GtNode (Token token) : TreeNode(nullptr,nullptr){ 
			this->token = token;
		}

		Token getToken() {
			return this->token;
		}
private: 
		Token token;

};