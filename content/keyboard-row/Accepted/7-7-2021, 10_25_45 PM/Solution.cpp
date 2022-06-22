// https://leetcode.com/problems/keyboard-row

class Solution {
public:
    bool s[3][128];
    bool check(string& str,int ind){
        for(int i=0;i<str.size();i++){
            if(s[ind][str[i]]==false){
                return false;
            }
        }
        return true;
    }
    vector<string> findWords(vector<string>& w) {
        vector<string> ans;
        memset(s,false,sizeof(s));
        vector<string> strs={"QWERTYUIOPqwertyuiop","ASDFGHJKLasdfghjkl","ZXCVBNMzxcvbnm"};
        for(int i=0;i<3;i++){
            for(int j=0;j<strs[i].size();j++){
                s[i][strs[i][j]]=true;
            }
        }
        int m=w.size();
        for(int i=0;i<m;i++){
            for(int j=0;j<3;j++){
                if(check(w[i],j)){
                    ans.emplace_back(w[i]);
                    break;
                }
            }
        }
        return ans;
    }
};