// https://leetcode.com/problems/check-array-formation-through-concatenation

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int,vector<int>> map;
        for(int i=0;i<pieces.size();i++){
            map[pieces[i][0]]=pieces[i];
        }
        for(int i=0;i<arr.size();){
            auto iter=map.find(arr[i]);
            if(iter==map.end()) return false;
            else{
                int i1=i;
                for(int j=0;j<(*iter).second.size();j++){
                    if(arr[i]!=((*iter).second)[j]) return false;
                    else{
                        i++;
                    }
                }
            }
        }
        return true;
    }
};