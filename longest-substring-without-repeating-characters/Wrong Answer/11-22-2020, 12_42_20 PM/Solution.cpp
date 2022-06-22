// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool let[300]={false};
        string str;
        int max=0;
        int cnt;
        for(int i=0;i<s.size();i++){
            if(isalpha(s[i])) str+=s[i];
        }

        for(int i=0;i<str.size();i++){
            cnt=0;
            memset(let,false,sizeof(let));
            
            for(int j=i;j<str.size();j++){
                cnt++;
                
                if(let[str[j]]){
                    if(cnt>max) max=cnt;
                    break;
                }
                let[str[j]]=true;
            }
        }
        return max-1;
    }
};