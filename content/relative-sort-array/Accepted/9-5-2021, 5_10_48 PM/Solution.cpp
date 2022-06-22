// https://leetcode.com/problems/relative-sort-array

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> map;
        int cnt=0;
        vector<int> ans;
        for(auto& i : arr1){
            map[i]++;
        }
        for(auto& i : arr2){
            if(map.find(i)!=map.end()){
                for(int j=0;j<map[i];j++){
                    ans.emplace_back(i);
                }
                cnt+=map[i];
                map.erase(map.find(i));
            }
        }
        for(auto i : map){
            for(int j=0;j<i.second;j++){
                ans.emplace_back(i.first);
            }
        }
        sort(ans.begin()+cnt,ans.end());
        return ans;
    }
};