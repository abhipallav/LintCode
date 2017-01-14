Problem: http://www.lintcode.com/en/problem/trailing-zeros/

class Solution {
 public:
    // param n : description of n
    // return: description of return 
    long long trailingZeros(long long n) {
        long long c=0;
        while(n!=0){
            n = floor(n/5);
            c += n;
        }
        return c;
    }
};
