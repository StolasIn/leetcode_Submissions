// https://leetcode.com/problems/ransom-note

class Solution {
public:
    bool canConstruct(string r1, string r2) {
        int c2[26];
        for(int i=0;i<26;i++){
            c2[i]=0;
        }
        int m=r1.size();
        int n=r2.size();
        for(int i=0;i<r2.size();i++){
            c2[r2[i]-'a']++;
        }
        for(int i=0;i<r1.size();i++){
            if(c2[r1[i]-'a']>0){
                c2[r1[i]-'a']--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};