Problem: http://www.lintcode.com/en/problem/binary-tree-level-order-traversal/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
 
 
class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int>> v;
        queue<TreeNode*> q;
        if(root) q.emplace(root);
        
        while(!q.empty()){
            vector<int> level;
            int size = q.size();
            while(size>0){
                auto x = q.front();
                q.pop();
                level.push_back(x->val);
                
                if(x->left) q.emplace(x->left);
                if(x->right) q.emplace(x->right);
                size--;
            }
            v.push_back(level);
        }
        
        return v;
    }
};
