// https://leetcode.com/problems/design-circular-queue

class MyCircularQueue {
public:
    deque<int> dq;
    int siz;
    MyCircularQueue(int k) {
        siz=k;
    }
    
    bool enQueue(int value) {
        if(isFull()==true){
            return false;
        }
        dq.push_back(value);
        return true;
    }
    
    bool deQueue() {
        dq.pop_back();
        return true;
    }
    
    int Front() {
        return dq.front();
    }
    
    int Rear() {
        return dq.back();
    }
    
    bool isEmpty() {
        return dq.empty();
    }
    
    bool isFull() {
        return dq.size()==siz? true:false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */