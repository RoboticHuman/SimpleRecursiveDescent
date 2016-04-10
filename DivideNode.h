#pragma once
#include "OperatorNode.h"

class DivideNode : public TreeNode
{
public: 
		DivideNode (Token token) : TreeNode(nullptr,nullptr){ 
			this->token = token;
		}

		Token getToken() {
			return this->token;
		}
private: 
		Token token;

};