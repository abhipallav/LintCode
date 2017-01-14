Problem: http://www.lintcode.com/en/problem/min-stack/

#include<stack>
class MinStack {
    stack<int> stack1;
    stack<int> stack2;
public:
    MinStack() {
        // do initialization if necessary
    }

    void push(int number) {
        // write your code here
        stack1.push(number);
        if(stack2.empty()||stack2.top()>=number){
            stack2.push(number);
        }
    }

    int pop() {
        // write your code here
        int num = stack1.top();
        stack1.pop();
        if(stack2.top()==num){
            stack2.pop();
        }
        return num;
    }

    int min() {
        // write your code here
        return stack2.top();
    }
};
