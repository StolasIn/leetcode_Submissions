// https://leetcode.com/problems/sum-of-digits-of-string-after-convert

class Solution {
public:
    int re(string& s,int k){
        int cnt = 0;
        while(k--){
            cnt = 0;
            for(int i=0;i<s.size();i++){
                cnt+=s[i]-'0';
            }
            s = to_string(cnt);
        }
        return cnt;
    }
    int getLucky(string s, int k) {
        string tran[26];
        string str = "";
        for(int i=0;i<26;i++){
            tran[i] = to_string(i+1);
        }
        for(int i=0;i<s.size();i++){
            str+=tran[s[i]-'a'];
        }
        return re(str,k);
    }
};