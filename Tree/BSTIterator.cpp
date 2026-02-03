
class BSTIterator {
private: 
    stack<TreeNode*> myStack;
    bool reverse;
    // moving forward (inorder) : False 
   // backward(reverse inorder) : True

public: 
    BSTIterator(TreeNode* root, bool isReverse=false) : reverse(isReverse) { 
        pushAll(root);
    }
 
    bool empty() { 
        return myStack.empty();
    }

    int top(){ 
        return myStack.top()->data;   
    }
     
    void pop(){ 
        TreeNode* tmpNode = myStack.top(); 
        myStack.pop();
        if (!reverse) // If not reverse mode, go right 
            pushAll(tmpNode->right);
        else // If reverse mode, go left 
            pushAll(tmpNode->left);
    }

    void pushAll(TreeNode* node) { 
        while (node != nullptr) { 
            myStack.push(node);
            if (reverse) // If reverse, move to right
                node = node->right;
            else // else, move to left
                node = node->left;
        }
    }
};
