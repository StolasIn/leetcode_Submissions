// https://leetcode.com/problems/add-strings

class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int m=min(num1.size(),num2.size());
        int t,carry=0;
        string str;
        for(int i=0;i<m;i++){
            t=(num1[i]+num2[i])-96+carry;
            if(t>=10){
                t-=10;
                carry=1;
            }
            else{
                carry=0;
            }
            str+=to_string(t);
        }
        if(num1.size()>num2.size()){
            for(int i=num2.size();i<num1.size();i++){
                t=(num1[i])-48+carry;
                if(t>=10){
                    t-=10;
                    carry=1;
                }
                else{
                    carry=0;                    
                }
                str+=to_string(t);
            }
        }
        else if(num1.size()<num2.size()){
            for(int i=num1.size();i<num2.size();i++){
                t=(num2[i])-48+carry;
                if(t>=10){
                    t-=10;
                    carry=1;
                }
                else{
                    carry=0;                    
                }
                str+=to_string(t);
            }
        }
        if(carry==1){
            str+='1';
        }
        reverse(str.begin(),str.end());
        return str;
    }
};