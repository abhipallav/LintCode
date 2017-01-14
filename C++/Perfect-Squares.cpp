Problem: http://www.lintcode.com/en/problem/perfect-squares/

class Solution {
public:
    bool isPerfectSqr(int n){
        return sqrt(n)==floor(sqrt(n));
    }
    
    /**
     * @param n a positive integer
     * @return an integer
     */
    int numSquares(int n) {
        // Write your code here
        vector<int>dp(n+1,INT_MAX);
        vector<int>perfect_square;
        dp[0]=0;
        for(int i=1;i<=n;i++){
            if(isPerfectSqr(i)) perfect_square.push_back(i);
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<perfect_square.size();j++){
                if(i-perfect_square[j]>=0 && dp[i]>dp[i-perfect_square[j]]+1) dp[i]=dp[i-perfect_square[j]]+1;
            }
        }
        
        return dp[n];
    }
};