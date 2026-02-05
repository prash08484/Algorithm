// Morris Inorder and Preorder 
// T.C. : O(2*n)
vector<int> Morris(TreeNode* root) {
    TreeNode *curr=root;  
    vector<int>ans; 

    while(curr!=nullptr){

        // CASE 1
        if(curr->left==nullptr){
            // process curr node
            ans.emplace_back(curr->val); 
            // move to right; 
            curr=curr->right; 
        }

        // CASE 2 & 3
        else{
            
            // left!=nullptr 
            // find inorder-predecessor 
            // right-most node in left subtree
            // unprocessed prev->right!=curr

            TreeNode* prev=curr->left; 
            while(prev->right and prev->right!=curr){
                prev=prev->right; 
            }
             
            // CASE 2
            if(prev->right==nullptr){
                // make temporary link to curr
                prev->right=curr;

                // ----------- PRE-ORDER --------------
                // ans.emplace_back(curr->val);

                // move to left
                  curr=curr->left; 
            }

            // CASE 3
            else{ 
                // already linked so remove the link 
                prev->right=nullptr; 
              
                // ------------- IN-ORDER ---------------
                //  ans.emplace_back(curr->val); 

                // move to right
                curr=curr->right;
            }
        }
    }
return ans;
}
