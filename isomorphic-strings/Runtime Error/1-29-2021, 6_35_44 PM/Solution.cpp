// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char> sv(123,'\0');
        vector<char> tv(123,'\0');
        int m=s.size();
        for(int i=0;i<m;i++){
            if(sv[s[i]]=='\0'){
                sv[s[i]]=t[i];
                if(tv[t[i]]=='\0'){
                    tv[t[i]]=s[i];
                }
                else{
                    return false;
                }
            }
            else{
                if(sv[s[i]]!=t[i]){
                    return false;
                }
            }
        }
        return true;
    }
};