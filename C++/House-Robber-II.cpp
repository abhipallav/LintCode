Problem: http://www.lintcode.com/en/problem/house-robber-ii/

class Solution {
public:
    /**
     * @param nums: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    int houseRobber2(vector<int>& nums) {
        // write your code here
        int n=nums.size();
        vector<int>dp(n,0);
        vector<int>dp1(n,0);
        if(n==1) return nums[0];
        dp[0]=nums[0];
        dp[1]=nums[1];
        dp1[0]=0;
        dp1[1]=nums[1];
        dp1[2]=nums[2];
        int max_elem = max(dp[0],dp[1]);
        
        for(int i=2;i<n-1;i++){
            if(dp[i]<dp[i-2]+nums[i]) dp[i]=dp[i-2]+nums[i];
            if(i-3>=0 && dp[i]<dp[i-3]+nums[i]) dp[i]=dp[i-3]+nums[i];
            
            if(max_elem<dp[i])
                max_elem=dp[i];
        }
        
        for(int i=3;i<n;i++){
            if(dp1[i]<dp1[i-2]+nums[i]) dp1[i]=dp1[i-2]+nums[i];
            if(i-3>=1 && dp1[i]<dp1[i-3]+nums[i]) dp1[i]=dp1[i-3]+nums[i];
            
            if(max_elem<dp1[i])
                max_elem=dp1[i];
        }
        
        return max_elem;
    }
};