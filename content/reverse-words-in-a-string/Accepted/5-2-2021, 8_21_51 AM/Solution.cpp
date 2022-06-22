// https://leetcode.com/problems/reverse-words-in-a-string

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss;
        ss<<s;
        string str;
        vector<string> v;
        while(ss>>str){
            v.emplace_back(str);
        }
        string ans;
        for(int i=v.size()-1;i>=0;i--){
            ans+=v[i];
            if(i!=0)ans+=' ';
        }
        return ans;
    }
};