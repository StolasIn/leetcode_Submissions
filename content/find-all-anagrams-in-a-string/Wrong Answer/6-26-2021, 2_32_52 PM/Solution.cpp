// https://leetcode.com/problems/find-all-anagrams-in-a-string

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int l=0,r=0;
        int cnt=0;
        int check[128];
        int in[128];
        vector<int> ans;
        memset(in,0,sizeof(in));
        memset(check,0,sizeof(check));
        for(int i=0;i<p.size();i++){
            in[p[i]]++;
        }
        while(r<=s.size()){
            if(cnt<p.size()){
                if(in[s[r]]!=0 && check[s[r]]==in[s[r]]-1){
                    cnt++;
                }
                check[s[r]]++;
                r++;
            }
            else{
                if((r-l)==(p.size())) ans.emplace_back(l);
                if(in[s[l]]!=0 && check[s[l]]==in[s[l]]){
                    cnt--;
                }
                check[s[l]]--;
                l++;
            }
        }
        return ans;
    }
};