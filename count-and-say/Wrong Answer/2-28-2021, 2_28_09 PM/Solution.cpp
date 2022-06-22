// https://leetcode.com/problems/count-and-say

class Solution {
public:
    string gen(string str){
        vector<int> dig(10,0);
        string str1;
        int m=str.size();
        for(int i=0;i<m;i++){
            dig[str[i]-'0']++;
        }
        for(int i=0;i<m;i++){
            if(dig[str[i]-'0']!=0){
                str1+=to_string(dig[str[i]-'0']);
                str1+=str[i];
                dig[str[i]-'0']=0;
            }
        }
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