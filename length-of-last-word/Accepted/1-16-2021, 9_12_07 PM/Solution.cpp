// https://leetcode.com/problems/length-of-last-word

class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt=0;
        bool flag=1;
        for(int i=s.size()-1;i>=0;i--){
            if(isalpha(s[i])){
                cnt++;
                flag=0;
            }
            if(flag==0 && !isalpha(s[i])){
                break;
            }
        }
        return cnt;
    }
};