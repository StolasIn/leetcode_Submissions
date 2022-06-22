// https://leetcode.com/problems/convert-a-number-to-hexadecimal

class Solution {
public:
    string toHex(int n) {
        if(n==0) return "0";
        long long num=n;
        if(num<0){
            num+=INT_MAX;
            num+=INT_MAX;
            num+=2;
            //num-=(n);
        }
        string str;
        while(num!=0){
            int t=num%16;
            if(t<=9) str+=to_string(t);
            else str+=(char)(t+87);
            num/=16;
        }
        reverse(str.begin(),str.end());
        return str;
    }
};