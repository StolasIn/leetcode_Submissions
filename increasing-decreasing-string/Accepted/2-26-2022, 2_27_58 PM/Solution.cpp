// https://leetcode.com/problems/increasing-decreasing-string

class Solution {
public:
    string sortString(string s) {
        vector<int> v(26);
        int cnt = 0;
        string ans = "";
        for(int i=0;i<s.size();i++){
            v[s[i]-'a']++;
            if(v[s[i]-'a']==1){
                cnt++;
            }
        }
        while(cnt!=0){
            for(int i=0;i<26;i++){
                if(v[i]>0){
                    v[i]--;
                    if(v[i]==0){
                        cnt--;
                    }
                    ans+=(char)(i+'a');
                }
            }
            for(int i=25;i>=0;i--){
                if(v[i]>0){
                    v[i]--;
                    if(v[i]==0){
                        cnt--;
                    }
                    ans+=(char)(i+'a');
                }
            }
        }
        return ans;
    }
};