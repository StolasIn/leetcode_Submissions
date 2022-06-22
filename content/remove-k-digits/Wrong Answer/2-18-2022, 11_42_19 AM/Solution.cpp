// https://leetcode.com/problems/remove-k-digits

class Solution {
public:
    string mi;
    string removeKdigits(string nums, int k) {
        string ans = "";
        string ans_z = "";
        if(nums.size()<=k){
            return "0";
        }
        for(int i=0;i<nums.size();i++){
            if(ans!=""){
                bool flag = false;
                while(ans.back()>nums[i] && k>0){
                    flag = true;
                    ans.pop_back();
                    k--;
                }
                ans+=nums[i];
            }
            else{
                ans+=nums[i];
            }
        }
        for(int i=0;i<ans.size();i++){
            if(ans_z=="" && ans[i]=='0'){
                continue;
            }
            ans_z += ans[i];
        }
        return ans_z=="" ? "0" : ans_z;
    }
};