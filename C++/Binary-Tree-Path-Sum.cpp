Problem: http://www.lintcode.com/en/problem/binary-tree-path-sum/

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
public:
     void getRootToLeaf(TreeNode* root, vector<int>* v,vector<vector<int>> *result, int sum){
        if(!root) return;
        sum = sum-root->val;
        if (!root->left && !root->right && sum==0) {
            vector<int> temp = vector<int>(*v);
            temp.emplace_back(root->val);
            result->emplace_back(temp);
        }

        if (root->left) {
            v->emplace_back(root->val);
            getRootToLeaf(root->left, v, result, sum);
            v->pop_back();
        }

        if (root->right) {
            v->emplace_back(root->val);
            getRootToLeaf(root->right, v, result, sum);
            v->pop_back();
        }
    }
    
    /**
     * @param root the root of binary tree
     * @param target an integer
     * @return all valid paths
     */
    vector<vector<int>> binaryTreePathSum(TreeNode *root, int target) {
        // Write your code here
        vector<vector<int>> result;
        vector<int> v;
        
        getRootToLeaf(root, &v, &result, target);
        return result;
    }
};