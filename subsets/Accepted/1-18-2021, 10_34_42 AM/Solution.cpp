// https://leetcode.com/problems/subsets

class Solution {
public:
    vector<vector<int>> ans;
    int siz;
    void com(vector<int> num,int x,vector<int>& nums,int s){
        if(num.size()==s){
            ans.push_back(num);
            return;
        }
        for(int i=x;i<siz;i++){
            num.push_back(nums[i]);
            com(num,i+1,nums,s);
            num.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> num1;
        siz=nums.size();
        ans.push_back(vector<int>());
        for(int i=1;i<=siz;i++){
            com(num1,0,nums,i);
        }
        return ans;
    }
};