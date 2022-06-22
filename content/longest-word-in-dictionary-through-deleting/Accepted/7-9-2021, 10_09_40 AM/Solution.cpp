// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting

class Solution {
public:
    string findLongestWord(string s, vector<string>& dict) {
        int c1,c2;
        string ans;
        for(int i=0;i<dict.size();i++){
            c1=c2=0;
            while(c1<s.size() && c2<dict[i].size()){
                if(s[c1]==dict[i][c2]){
                    c1++;
                    c2++;
                }
                else{
                    c1++;
                }
            }
            if(c2==dict[i].size()){
                if(dict[i].size()>ans.size()){
                    ans=dict[i];
                }
                else if(dict[i].size()==ans.size() && dict[i]<ans){
                    ans=dict[i];          
                }
            }
        }
        return ans;
    }
};