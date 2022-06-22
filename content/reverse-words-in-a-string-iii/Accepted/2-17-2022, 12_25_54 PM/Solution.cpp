// https://leetcode.com/problems/reverse-words-in-a-string-iii

class Solution {
public:
    vector<string> split(string& s,char dim){
        string str;
        vector<string> ans;
        for(int i=0;i<s.size();i++){
            if(s[i]==dim){
                if(str!=""){
                    ans.emplace_back(str);
                    str="";
                }
            }
            else{
                str+=s[i];
            }
        }
        if(str!=""){
            ans.emplace_back(str);
            str="";
        }
        return ans;
    }
    
    string reverseWords(string s) {
        vector<string> strs = split(s,' ');
        string ans;
        int m = strs.size();
        int n = m>>1;
        for(int i=0;i<m;i++){
            reverse(strs[i].begin(),strs[i].end());
            ans+=strs[i];
            if(i!=m-1) ans+=' ';
        }
        return ans;
    }
};