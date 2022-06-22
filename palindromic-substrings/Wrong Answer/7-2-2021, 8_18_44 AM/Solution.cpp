// https://leetcode.com/problems/palindromic-substrings

class Solution {
public:
    bool isp(string& s) {
        string str="";
        int m=s.size();
        for(int i=0;i<m;i++){
            if(isalpha(s[i])){
                str+=tolower(s[i]);
            }
            else if(isdigit(s[i])){
                str+=s[i];
            }
        }
        m=str.size();
        for(int i=0;i<(m+1)/2;i++){
            if(str[i]!=str[m-i-1]){
                return false;
            }
        }
        return true;
    }
    string substr(string& s,int l,int r){
        string str="";
        for(int i=l;i<=r;i++){
            str+=s[i];
        }
        return str;
    }
    int countSubstrings(string s) {
        int m=s.size();
        unordered_map<string,bool> map;
        string str;
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=i;j<m;j++){
                str=substr(s,i,j);
                if(map.find(str)!=map.end()){
                    if(map[str]==true) cnt++;
                }
                if(isp(str)){
                    map[str]=true;
                    cnt++;
                }
                else{
                    map[str]=false;
                }
            }
        }
        return cnt;
    }
};