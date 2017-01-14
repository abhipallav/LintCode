Problem: http://www.lintcode.com/en/problem/count-1-in-binary/

class Solution {
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        // write your code here
        int count = 0;
        for(int i=num; i!=0;i=i&(i-1)){
            count++;
        }
        return count;
    }
};