// https://leetcode.com/problems/count-and-say

class Solution {
public:
    string count(string &s){
        string str;
        int n=s.size();
        char key=s[0];
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]==key){
                cnt++;
            }
            else{
                key=s[i];
                str+=cnt;
                str+=s[i-1];
                cnt=0;
            }
        }
        if(cnt!=0){
            str+=cnt;
            str+=s[n-1];
        }
        return str;
    }
    string countAndSay(int n) {
        vector<string> str(n+1);
        str[1]="1";
        str[2]="11";
        if(n==1) return str[1];
        for(int i=3;i<=n;i++){
            str[i]=count(str[i-1]);
        }
        return str[n];
    }
};