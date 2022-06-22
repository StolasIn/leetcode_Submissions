// https://leetcode.com/problems/lru-cache

class LRUCache {
public:
    unordered_map<int,int> map;
    vector<int> recent;
    int s;
    LRUCache(int capacity) {
        s=capacity;
    }
    
    int get(int key) {
        if(map.find(key)==map.end()){
            return -1;
        }
        else{
            return map[key];
        }
    }
    
    void put(int key, int value) {
        if(map.find(key)==map.end()){
            if(map.size()<s){
                recent.emplace_back(key);
                map[key]=value;
            }
            else{
                auto i=recent.back();
                recent.pop_back();
                map.erase(i);
                map[key]=value;
            }
        }
        else{
            map[key]=value;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */