// https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() < 1) return "";
        string str=strs[0];
        for(int i=0;i<strs[0].size();i++) str.push_back(strs[0][i]);
        for(int i=1;i<strs.size();i++){
            for(int j=0;j<str.size();j++){
                if(str[j]!=strs[i][j]){
                    str=str.substr(0,j);
                    break;
                }
            }
        }
        return str;
    }
};