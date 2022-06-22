// https://leetcode.com/problems/insert-delete-getrandom-o1

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int,int> map;
    vector<int> n;
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(map.find(val)!=map.end()) return false;
        n.emplace_back(val);
        map[val]=n.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(map.find(val)==map.end()) return false;
        map[n[map[n.back()]]]=map[val];
        swap(n[map[val]],n.back());
        n.pop_back();
        map.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return n[rand()%n.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */