// https://leetcode.com/problems/ransom-note

class Solution {
public:
    bool canConstruct(string s1, string s2) {
        vector<int> v(128,0);
        int cnt = 0;
        for(int i=0;i<s1.size();i++){
            v[s1[i]]++;
            if(v[s1[i]]==1) cnt++;
        }
        for(int i=0;i<s2.size();i++){
            v[s2[i]]--;
            if(v[s2[i]]==0) cnt--;
        }
        return cnt==0;
    }
};