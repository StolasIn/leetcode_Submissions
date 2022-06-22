// https://leetcode.com/problems/array-of-doubled-pairs

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_map<int,int> map;
        for(int i=0;i<arr.size();i++){
            map[arr[i]]++;
        }
        for(auto i : map){
            if(i.second>=1){
                if(map.find(2*i.first)==map.end()){
                    return false;
                }
                else{
                    if(map[2*i.first]<i.second){
                        return false;
                    }
                    else{
                        map[2*i.first]-=i.second;
                    }
                }
            }
        }
        return true;
    }
};