// https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters

class Solution {
public:
    string modifyString(string s) {
        s = 'x' + s + 'x';
        char v[128] = {0};
        for(int i=1;i<s.size()-1;i++){
            if(s[i]=='?'){
                v[s[i-1]]++;
                v[s[i+1]]++;
                for(int j=0;j<3;j++){
                    if(v[j+'a']==0){
                        s[i] = (char)(j+'a');
                        break;
                    }
                }
            }
        }
        return s.substr(1,s.size()-2);
    }
};