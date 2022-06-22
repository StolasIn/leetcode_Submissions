// https://leetcode.com/problems/check-if-n-and-its-double-exist

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;
        for(auto& i : arr){
            s.insert(i);
        }
        for(auto& i : s){
            if(s.find(i*2)!=s.end()){
                return true;
            }
        }
        return false;
    }
};