// https://leetcode.com/problems/remove-k-digits

class Solution {
public:
    string mi;
    string removeKdigits(string num, int k) {
        if(num.size()<=k){
            return "0";
        }
        string ans = "";
        string ans_z = "";
        for(int i=0;i<num.size();i++){
            if(ans!="" && k>0){
                if(ans.back()>num[i]){
                    ans.pop_back();
                    ans+=num[i];
                    k--;
                }
                else{
                    ans+=num[i]; 
                }
            }
            else{
                ans+=num[i];   
            }
        }
        for(int i=0;i<k;i++){
            ans.pop_back();
        }
        for(int i=0;i<ans.size();i++){
            if(ans_z=="" && ans[i]=='0'){
                continue;
            }
            ans_z+=ans[i];
        }
        return ans_z=="" ? "0" : ans_z;
    }
};