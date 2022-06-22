// https://leetcode.com/problems/check-if-string-is-a-prefix-of-array

class Solution {
public:
    bool isPrefixString(string s, vector<string>& w) {
        string str = "";
        for(int i=0;i<w.size();i++){
            if(str.size()<s.size()){
                str+=w[i];
            }
            else{
                break;
            }
        }
        return str==s;
    }
};