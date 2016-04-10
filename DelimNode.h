#pragma once
#include "OperatorNode.h"

class DelimNode : public TreeNode
{
public: 
		DelimNode (Token token) : TreeNode(nullptr,nullptr){ 
			this->token = token;
		}

		Token getToken() {
			return this->token;
		}
private: 
		Token token;

};