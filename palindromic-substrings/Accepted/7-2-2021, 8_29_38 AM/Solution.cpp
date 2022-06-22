// https://leetcode.com/problems/palindromic-substrings

class Solution {
public:
    bool isp(string& s) {
        int m=s.size();
        for(int i=0;i<(m+1)/2;i++){
            if(s[i]!=s[m-i-1]){
                return false;
            }
        }
        return true;
    }
    string substr(const char s[],int l,int r){
        string str(s+l,s+r);
        return str;
    }
    int countSubstrings(string& s) {
        int m=s.size();
        string str;
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=i+1;j<=m;j++){
                str=substr(s.c_str(),i,j);
                if(isp(str)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};