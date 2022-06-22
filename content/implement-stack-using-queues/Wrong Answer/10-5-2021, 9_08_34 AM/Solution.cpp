// https://leetcode.com/problems/implement-stack-using-queues

class MyStack {
public:
    queue<int> q;
    int t;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        t=x;
    }
    
    int pop() {
        int t1=t;
        if(q.size()==1){
            q.pop();
            return t1;
        }
        else if(q.size()==2){
            q.pop();
            t=q.front();
            return t1;
        }
        else{
            for(int i=0;i<q.size()-2;i++){
                q.push(q.front());
                q.pop();
            }
            t=q.front();
            q.push(q.front());
            q.pop();
            q.pop();
            return t1;
        }
    }
    
    int top() {
        return t;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */