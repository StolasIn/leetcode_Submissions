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
        if(arr[snap_id].find(index)==arr[snap_id].end()){
            return 0;
        }
        else{
            return arr[snap_id][index];
        }
    }
};