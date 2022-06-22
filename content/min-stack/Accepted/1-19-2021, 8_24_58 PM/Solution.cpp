// https://leetcode.com/problems/min-stack

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> nums; 
    stack<int> mins;
    
    MinStack() {
        // do nothing here
    }
    
    void push(int x) {
        if(mins.empty() || x <= mins.top()) mins.push(x);
        nums.push(x);
    }
    
    void pop() {
        if(mins.top() == nums.top()) mins.pop();
        nums.pop();
    }
    
    int top() {
        return nums.top();
    }
    
    int getMin() {
        return mins.top();  
    }
};