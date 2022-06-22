// https://leetcode.com/problems/snapshot-array

class SnapshotArray {
public:
    vector<unordered_map<int,int>> arr;
    SnapshotArray(int length) {
        arr.emplace_back(unordered_map<int,int>());
    }
    
    void set(int index, int val) {
        (arr.back())[index]=val;
    }
    
    int snap() {
        arr.emplace_back(arr.back());
        return arr.size()-2;
    }
    
    int get(int index, int snap_id) {
        if(arr[index].find(index)==arr[index].end()){
            return 0;
        }
        else{
            return arr[index][snap_id];
        }
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */