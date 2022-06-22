// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:
    vector<string> str= {"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> st;
    void re(string &s,vector<int> &num,int x,int y){
        if(y==num.size()) return;
        for(int i=0;i<str[num[x]].size();i++){
            s+=str[num[x]][i];
            re(s,num,x+1,y+1);
        }
        st.push_back(s);
        s="";
    }
    vector<string> letterCombinations(string digits) {
        vector<int> num;
        string s;
        for(int i=0;i<digits.size();i++){
            num.push_back(digits[i]-'0');
        }
        re(s,num,0,0);
        return st;
    }
};