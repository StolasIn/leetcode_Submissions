// https://leetcode.com/problems/check-if-n-and-its-double-exist

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;
        int z=0;
        for(auto& i : arr){
            s.insert(i);
            if(i==0) z++;
        }
        if(z>=2) return true;
        s.erase(0);
        for(auto& i : s){
            if(s.find(i*2)!=s.end()){
                return true;
            }
        }
        return false;
    }
};