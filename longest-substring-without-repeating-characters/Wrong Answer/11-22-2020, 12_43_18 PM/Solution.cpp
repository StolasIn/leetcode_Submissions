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
            
            for(int j=i;j<str.size()-1;j++){
                cnt++;
                let[str[j]]=true;
                if(let[str[j+1]]){
                    if(cnt>max) max=cnt;
                    break;
                }
                
            }
        }
        return max;
    }
};