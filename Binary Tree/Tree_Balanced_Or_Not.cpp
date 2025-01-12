class Solution {
    
public:

    int height(TreeNode* root, bool &balanced){
        if(root == nullptr) return 0;

        int left = height(root->left, balanced);
        if(!balanced) return 0;


        int right  = height(root->right, balanced);
        if(!balanced) return 0;

a
        if(abs(left - right) > 1){
            balanced = false;
        }

        return max(left, right) + 1;
    }


    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        height(root, balanced);
        return balanced;
    }
};


time complexity :- O(N); N= no of nodes in binary tree