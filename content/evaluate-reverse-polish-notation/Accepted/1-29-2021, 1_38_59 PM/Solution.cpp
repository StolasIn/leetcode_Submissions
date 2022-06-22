// https://leetcode.com/problems/evaluate-reverse-polish-notation

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st1;
        int n=tokens.size();
        int tmp1,tmp2;
        for(int i=0;i<n;i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                tmp1=st1.top();
                st1.pop();
                tmp2=st1.top();
                st1.pop();
                if(tokens[i]=="+"){
                    st1.push(tmp1+tmp2);
                }
                else if(tokens[i]=="-"){
                    st1.push(tmp2-tmp1);
                }
                else if(tokens[i]=="*"){
                    st1.push(tmp1*tmp2);
                }
                else if(tokens[i]=="/"){
                    st1.push(tmp2/tmp1);
                }
            }
            else{
                st1.push(stoi(tokens[i]));
            }
        }
        return st1.top();
    }
};