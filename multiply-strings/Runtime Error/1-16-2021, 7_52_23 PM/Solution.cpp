// https://leetcode.com/problems/multiply-strings

class Solution {
public:
    int myatoi(string s) {
        int start;
        string str;
        string str1;
        int q;
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
        if(str[0]=='0'){
            for(q=0;q<str.size();q++){
                if(str[q]!='0') break;
            }
            for(int i=q;i<str.size();i++){
                str1+=str[i];
            }
            str=str1;
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
    
    string multiply(string num1, string num2) {
        int a=myatoi(num1)*myatoi(num2);
        string str;
        vector<char> c;
        if(a==0) str+='0';
        for(;a>0;){
            c.push_back(a%10+48);
            a/=10;
        }
        for(int i=c.size()-1;i>=0;i--) str+=c[i];
        return str;
    }
};