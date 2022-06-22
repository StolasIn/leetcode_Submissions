// https://leetcode.com/problems/majority-element-ii

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        unordered_map<int,int> mapa;
        int k=(nums.size()/3);
        vector<int> ans;
        int m=nums.size();
        for(int i=0;i<m;i++){
            map[nums[i]]++;
            if(map[nums[i]]>k){
                if(mapa.find(nums[i])==mapa.end()){
                    ans.emplace_back(nums[i]);
                    mapa[nums[i]]=1;
                }
            }
        }
        return ans;
    }
};