// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool let[300];
        int max=0;
        int cnt;
        for(int i=0;i<s.size();i++){
            cnt=0;
            memset(let,false,sizeof(let));
            for(int j=i;j<s.size();j++){
                if(let[s[j]]){
                    break;
                }
                cnt++;
                if(cnt>max) max=cnt;
                let[s[j]]=true;
            }
        }
        return max;
    }
};