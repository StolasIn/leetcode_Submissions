// https://leetcode.com/problems/intersection-of-two-arrays-ii

class Solution {
public:
    void insert_into(vector<int>& nums,unordered_map<int,int>& map){
        for(auto i : nums){
            map[i]++;
        }
    }
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map1;
        unordered_map<int,int> map2;
        vector<int> ans;
        insert_into(nums1,map1);
        insert_into(nums2,map2);
        for(auto i : map1){
            if(map2.find(i.first)!=map2.end()){
                int cnt = min(map1[i.first],map2[i.first]);
                for(int j=0;j<cnt;j++){
                    ans.emplace_back(i.first);
                }
            }
        }
        return ans;
    }
};