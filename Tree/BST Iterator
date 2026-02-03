
 
struct TreeNode { 
    int val; 
    TreeNode* left; 
    TreeNode* right; 
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class BSTIterator {
private: 
    stack<TreeNode*> myStack;
    // moving forward (inorder) or backward (reverse inorder)
    bool reverse;

public: 
    BSTIterator(TreeNode* root, bool isReverse) : reverse(isReverse) { 
        pushAll(root);
    }
 
    bool hasNext() { 
        return !myStack.empty();
    }

    //  returns next node’s value
    int next() { 
        TreeNode* tmpNode = myStack.top(); 
        myStack.pop();

        // If not reverse mode, go right 
        if (!reverse) {
            pushAll(tmpNode->right);
        }
        // If reverse mode, go left 
        else {
            pushAll(tmpNode->left);
        }
 
        return tmpNode->val;
    }

private:
    void pushAll(TreeNode* node) { 
        while (node != nullptr) { 
            myStack.push(node);

            // If reverse, move to right
            if (reverse) {
                node = node->right;
            }
            // else, move to left
            else {
                node = node->left;
            }
        }
    }
};

 
    // BSTIterator l(root, false); // for smallest-to-largest order
    // BSTIterator r(root, true); //  for largest-to-smallest

 
