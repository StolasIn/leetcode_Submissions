// https://leetcode.com/problems/goal-parser-interpretation

class Solution {
public:
    string interpret(string c) {
        string ans = "";
        c+=' ';
        for(int i=0;i<c.size()-1;i++){
            if(c[i]=='G'){
                ans+='G';
            }
            else if(c[i]=='(' && c[i+1]==')'){
                ans+='o';
            }
            else if(c[i]=='(' && c[i+1]=='a'){
                ans+="al";
            }
        }
        return ans;
    }
};