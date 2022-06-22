// https://leetcode.com/problems/base-7

class Solution {
public:
    string convertToBase7(int num) {
        string str;
        if(num==0) return "0";
        while(num!=0){
            str=to_string(num%7)+str;
            num/=7;
        }
        return str;
    }
};