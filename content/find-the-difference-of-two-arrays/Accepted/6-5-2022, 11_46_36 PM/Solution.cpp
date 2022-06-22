// https://leetcode.com/problems/find-the-difference-of-two-arrays

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1;
        unordered_set<int> s2;
        vector<int> ans1;
        vector<int> ans2;
        for(int i=0;i<nums1.size();i++){
            s1.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            s2.insert(nums2[i]);
        }
        for(auto i : s1){
            if(s2.find(i)==s2.end()){
                ans1.emplace_back(i);
            }
        }
        for(auto i : s2){
            if(s1.find(i)==s1.end()){
                ans2.emplace_back(i);
            }
        }
        return {ans1,ans2};
    }
};