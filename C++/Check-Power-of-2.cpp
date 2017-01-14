Problem: http://www.lintcode.com/en/problem/o1-check-power-of-2/

class Solution {
public:
    /*
     * @param n: An integer
     * @return: True or false
     */
    bool checkPowerOf2(int n) {
        // write your code here
        return n>0 && (n&(n-1))==0;
    }
};