// https://leetcode.com/problems/base-7

class Solution {
public:
    string convertToBase7(int num) {
        string str;
        bool flag=false;
        if(num==0) return "0";
        if(num<0){
            flag=true;
            num=-num;
        }
        while(num!=0){
            str=to_string(num%7)+str;
            num/=7;
        }
        if(flag==true) return "-"+str;
        return str;
    }
};