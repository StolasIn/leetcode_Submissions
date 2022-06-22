// https://leetcode.com/problems/remove-duplicate-letters

class Solution {
public:
    string removeDuplicateLetters(string s) {
        bool arr[129]={false};
        int m=s.size();
        for(int i=0;i<m;i++){
            arr[s[i]]=true;
        }
        string ans;
        for(int i=0;i<129;i++){
            if(arr[i]) ans+=(char)i;
        }
        return ans;
    }
};