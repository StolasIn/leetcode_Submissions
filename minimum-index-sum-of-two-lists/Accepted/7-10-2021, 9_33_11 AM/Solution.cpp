// https://leetcode.com/problems/minimum-index-sum-of-two-lists

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> map;
        vector<string> ans;
        for(int i=0;i<list1.size();i++){
            map[list1[i]]=i;
        }
        int mi=INT_MAX;
        for(int i=0;i<list2.size();i++){
            if(map.find(list2[i])!=map.end()){
                mi=min(mi,map[list2[i]]+i);
            }
        }
        for(int i=0;i<list2.size();i++){
            if(map.find(list2[i])!=map.end() && map[list2[i]]+i==mi){
                ans.emplace_back(list2[i]);
            }
        }
        return ans;
    }
};