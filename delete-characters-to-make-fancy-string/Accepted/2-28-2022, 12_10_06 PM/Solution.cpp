// https://leetcode.com/problems/delete-characters-to-make-fancy-string

class Solution {
public:
    string makeFancyString(string s) {
        if(s.size()<=2){
            return s;
        }
        vector<char> v;
        for(int i=0;i<2;i++){
            v.emplace_back(s[i]);
        }
        for(int i=2;i<s.size();i++){
            int m = v.size();
            if(v[m-2]==v[m-1] && v[m-1]==s[i]){
                continue;
            }
            v.emplace_back(s[i]);
        }
        string ans(v.begin(),v.end());
        return ans;
    }
};