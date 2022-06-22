// https://leetcode.com/problems/design-hashset

class MyHashSet {
public:
    /** Initialize your data structure here. */
    bool arr[1000000];
    MyHashSet() {
        memset(arr,0,sizeof(arr));
    }
    
    void add(int key) {
        arr[key]=true;
    }
    
    void remove(int key) {
        arr[key]=false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return arr[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */