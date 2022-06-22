// https://leetcode.com/problems/implement-queue-using-stacks

class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {
    }
    
    void push(int x) {
        st1.push(x);
        if(st2.size()==0){
            st2.push(x);
        }
    }
    
    int pop() {
        int t;
        int t1;
        bool flag = false;
        st2.pop();
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        t = st2.top();
        st2.pop();
        if(!st2.empty()){
            flag = true;
            t1 = st2.top();
        }
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        if(flag == true){
            st2.push(t1);
        }
        return t;
    }
    
    int peek() {
        return st2.top();
    }
    
    bool empty() {
        return st1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */