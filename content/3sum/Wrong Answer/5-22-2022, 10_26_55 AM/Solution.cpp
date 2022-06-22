// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& v,int b,int e,int t){
        vector<vector<int>> ans;
        while(e>b){
            if(v[e]+v[b]==t){
                ans.push_back({b,e});
                b++;
                e--;
                while(b<v.size()-1 && v[b]==v[b+1]) b++;
                while(e>0 && v[e]==v[e-1]) e--;
            }
            else if(v[e]+v[b]<t){
                b++;
            }
            else{
                e--;
            }
        }
        return ans;
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
            tmp = twoSum(nums,i+1,n-1,-nums[i]);
            for(auto v : tmp){
                ans.push_back({nums[i],nums[v[0]],nums[v[1]]});
            }
        }
        return ans;
    }
};