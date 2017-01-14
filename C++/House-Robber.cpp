Problem: http://www.lintcode.com/en/problem/house-robber/

class Solution {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> A) {
        // write your code here
        int n=A.size();
        vector<long long>dp(n,0);
        dp[0]=A[0];
        dp[1]=A[1];
        long long max_elem=max(dp[0],dp[1]);
        for(int i=2;i<n;i++){
            if(dp[i-2]+A[i]>dp[i]) dp[i]=dp[i-2]+A[i];
            if(i-3>0 && dp[i-3]+A[i]>dp[i]) dp[i]=dp[i-3]+A[i];
            if(dp[i]>max_elem) max_elem=dp[i];
        }
        
        return max_elem;
    }
};