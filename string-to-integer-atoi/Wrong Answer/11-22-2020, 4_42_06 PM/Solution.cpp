// https://leetcode.com/problems/string-to-integer-atoi

class Solution {
public:
    int myAtoi(string s) {
        int start;
        string str;
        bool sign;
        long long pro=1;
        long long sum=0;
        for(start=0;start<s.size();){
            if(s[start]!=' ') break;
            start++;
        }
        if(isdigit(s[start])){
            for(int i=start;i<s.size();i++){
                if(!isdigit(s[i])) break;
                str+=s[i];
            }
            sign=0;
        }
        else if(s[start]=='-'){
            for(int i=start+1;i<s.size();i++){
                if(!isdigit(s[i])) break;
                str+=s[i];
            }
            sign=1;
        }
        else if(s[start]=='+'){
            for(int i=start+1;i<s.size();i++){
                if(!isdigit(s[i])) break;
                str+=s[i];
            }
            sign=0;
        }
        else{
            return 0;
        }
        if(str.size()>11){
            if(sign){
                return -2147483648;
            }
            else{
                return 2147483647;
            }
        }
        for(int i=str.size()-1;i>=0;i--){
            sum+=pro*(str[i]-'0');
            pro*=10;
        }
        if(sum>2147483647 || -sum<-2147483648){
            if(sign) return -2147483648;
            else return 2147483647;
        }
        else{
            if(sign) return -sum;
            else return sum;
        }
    }
};