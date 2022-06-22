// https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters

class Solution {
public:
    int countGoodSubstrings(string s) {
        int v[128] = {0};
        int cnt = 0;
        int ans = 0;
        for(int i=0;i<3;i++){
            v[s[i]]++;
            if(v[s[i]]==1){
                cnt++;
            }
        }
        if(cnt==3){
            ans++;
        }
        for(int i=3;i<s.size();i++){
            v[s[i-3]]--;
            if(v[s[i-3]]==0){
                cnt--;
            }
            v[s[i]]++;
            if(v[s[i]]==1){
                cnt++;
            }
            if(cnt==3){
                ans++;
            }
        }
        return ans;
    }
};