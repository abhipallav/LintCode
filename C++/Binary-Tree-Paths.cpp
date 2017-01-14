Problem: http://www.lintcode.com/en/problem/binary-tree-paths/

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
    void getRootToLeaf(TreeNode* root, vector<int>* v,vector<string> *result){
        if(!root) return;
        if (!root->left && !root->right) {
            string ans = "";
            for (const auto& n : *v) {
                ans.append(to_string(n).append("->"));
            }
            result->emplace_back(move(ans.append(to_string(root->val))));
        }

        if (root->left) {
            v->emplace_back(root->val);
            getRootToLeaf(root->left, v, result);
            v->pop_back();
        }

        if (root->right) {
            v->emplace_back(root->val);
            getRootToLeaf(root->right, v, result);
            v->pop_back();
        }
    }
    
    /**
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        // Write your code here
        vector<int>v;
        vector<string> result;
        getRootToLeaf(root, &v, &result);
        return result;
    }
};