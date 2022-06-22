// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:
    vector<string> str= {"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> st;
    void re(string s,vector<int> &num,int x){
        if(s.size()==num.size()){
            st.push_back(s);
            return;
        }
        for(int j=0;j<str[num[x]].size();j++){
            s+=str[num[x]][j];
            re(s,num,x+1);
            s=s.substr(0,s.size()-1);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="") return nullptr;
        vector<int> num;
        string s;
        for(int i=0;i<digits.size();i++){
            num.push_back(digits[i]-'0');
        }
        re(s,num,0);
        return st;
    }
};