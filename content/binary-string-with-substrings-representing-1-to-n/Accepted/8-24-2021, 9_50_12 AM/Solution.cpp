// https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n

class Solution {
public:
    string get(int n){
        string str="";
        while(n!=0){
            str+=to_string(n%2);
            n/=2;
        }
        reverse(str.begin(),str.end());
        return str;
    }
    bool queryString(string s, int n) {
        for(int i=n;i>=1;i--){
            if(s.find(get(i))==string::npos){
                return false;
            }
        }
        return true;
    }
};