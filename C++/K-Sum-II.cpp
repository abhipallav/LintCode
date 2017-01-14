Problem: http://www.lintcode.com/en/problem/k-sum-ii/

class Solution {
public:

    void helper(vector<int> A, int k, int target, int start, vector<int>* curr, vector<vector<int>>* result){
        if(k<0||target<0) return;
        
        if(k==0&&target==0){
            vector<int> temp = vector<int>(*curr);
            result->emplace_back(temp);
            return;
        }
        
        for(int i=start; i<=A.size()-k;i++){
            curr->emplace_back(A[i]);
            helper(A,k-1,target-A[i],i+1,curr,result);
            curr->pop_back();
        }
    }
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer 
     */
    vector<vector<int> > kSumII(vector<int> A, int k, int target) {
        // write your code here
        vector<int> curr;
        vector<vector<int>> result;
        
        helper(A,k,target,0,&curr,&result);
        return result;
    }
};
