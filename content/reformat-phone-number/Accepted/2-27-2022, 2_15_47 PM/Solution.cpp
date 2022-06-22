// https://leetcode.com/problems/reformat-phone-number

class Solution {
public:
    string re(string& s){
        if(s.size()>4){
            string tmp = s.substr(3,s.size()-1);
            return s.substr(0,3) + '-' + re(tmp);
        }
        else if(s.size()<=3){
            return s;
        }
        else{
            return s.substr(0,2) + '-' + s.substr(2,3);
        }
    }
    string reformatNumber(string num) {
        string s = "";
        for(int i=0;i<num.size();i++){
            if(isdigit(num[i])){
                s+=num[i];
            }
        }
        return re(s);
    }
};