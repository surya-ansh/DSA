class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> mainAns;
        if (root == nullptr) return mainAns; 

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> ans;  // To store the current level's nodes.

            for (int i = 0; i < size; ++i) {
                TreeNode* curr = q.front();
                q.pop();

                ans.push_back(curr->val);  // Add current node's value.

                if (curr->left != nullptr) {
                    q.push(curr->left);  // Push left child.
                }
                if (curr->right != nullptr) {
                    q.push(curr->right);  // Push right child.
                }
            }

            mainAns.push_back(ans);  // Add the current level to the result.
        }

        return mainAns;
    }
};


// DFS
recursive calls 
inorder 
preOrder
PostOrder

