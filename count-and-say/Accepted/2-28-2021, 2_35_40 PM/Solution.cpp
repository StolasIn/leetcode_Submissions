// https://leetcode.com/problems/count-and-say

class Solution {
public:
    string gen(string str){
        string str1;
        int m=str.size();
        char c=str[0];
        int cnt=1;
        for(int i=1;i<m;i++){
            if(c!=str[i]){
                str1+=to_string(cnt);
                str1+=c;
                c=str[i];
                cnt=1;
            }
            else{
                cnt++;
            }
        }
        str1+=to_string(cnt);
        str1+=c;
        return str1;
    }
    string countAndSay(int n) {
        string str="1";
        for(int i=2;i<=n;i++){
            str=gen(str);
        }
        return str;
    }
};