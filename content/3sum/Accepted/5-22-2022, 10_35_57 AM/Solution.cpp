// https://leetcode.com/problems/3sum

class Solution {
public:
    void twoSum(vector<vector<int>>& ans,vector<int>& v,int b,int e,int t){
        while(e>b){
            int target = v[e]+v[b];
            if(target==t){
                ans.push_back({b,e});
                b++;
                e--;
                while(e>b && v[e]==v[e+1]) e--;
                while(b<e && v[b]==v[b-1]) b++;
            }
            else if(target<t){
                b++;
            }
            else{
                e--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<vector<int>> tmp;
        for(int i=0;i<n;i++){
            if(i!=0 && nums[i]==nums[i-1]){
                continue;
            }
            tmp.clear();
            twoSum(tmp,nums,i+1,n-1,-nums[i]);
            for(auto v : tmp){
                ans.push_back({nums[i],nums[v[0]],nums[v[1]]});
            }
        }
        return ans;
    }
};