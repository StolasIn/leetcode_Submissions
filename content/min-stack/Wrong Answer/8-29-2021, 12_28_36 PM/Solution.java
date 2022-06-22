// https://leetcode.com/problems/min-stack

class MinStack {

    /** initialize your data structure here. */
    Stack st1 = new Stack();
    Stack st2 = new Stack();
    public MinStack() {
        
    }
    
    public void push(int val) {
        st1.push(val);
        if(st2.size()==0 || val<=(int)st2.peek()){
            st2.push(val);
        }
    }
    
    public void pop() {
        if(st1.peek()==st2.peek()){
            st1.pop();
            st2.pop();
        }
    }
    
    public int top() {
        return (int)st1.peek();
    }
    
    public int getMin() {
        return (int)st2.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */