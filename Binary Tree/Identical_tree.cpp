
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // base case
        if(p==nullptr && q == nullptr) return true;

        // if only any one of it is null 
        if(p==nullptr || q==nullptr) return false;

        bool left = isSameTree(p->left, q->left);

        bool right = isSameTree(p->right, q->right);

        bool yes = ( p->val ) == ( q->val );

        if(left && right && yes){
            return true;
        }

        return false;

    }
};