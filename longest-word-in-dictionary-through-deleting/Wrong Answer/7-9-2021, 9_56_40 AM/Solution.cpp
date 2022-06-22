// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting

class Solution {
public:
    vector<int> dit;
    bool check(string& s){
        auto tmp=dit;
        for(int i=0;i<s.size();i++){
            if(tmp[s[i]]>0){
                tmp[s[i]]--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    string findLongestWord(string s, vector<string>& dict) {
        string ans="";
        dit.assign(128,0);
        for(int i=0;i<s.size();i++){
            dit[s[i]]++;
        }
        for(int i=0;i<dict.size();i++){
            if(dict[i].size()>ans.size()){
                if(check(dict[i])){
                    ans=dict[i];
                }
            }
        }
        return ans;
    }
};