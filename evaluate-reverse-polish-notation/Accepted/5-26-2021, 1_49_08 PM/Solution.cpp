// https://leetcode.com/problems/evaluate-reverse-polish-notation

class Solution {
public:
    int evalRPN(vector<string>& t) {
        if(t.size()==0) return 0;
        stack<int> s;
        int m=t.size();
        string str;
        for(int i=0;i<m;i++){
            str = t[i];
            if(str=="+"){
                auto a=s.top();
                s.pop();
                auto b=s.top();
                s.pop();
                s.push(b+a);
            }
            else if(str=="-"){
                auto a=s.top();
                s.pop();
                auto b=s.top();
                s.pop();
                s.push(b-a);
            }
            else if(str=="*"){
                auto a=s.top();
                s.pop();
                auto b=s.top();
                s.pop();
                s.push(b*a);
            }
            else if(str=="/"){
                auto a=s.top();
                s.pop();
                auto b=s.top();
                s.pop();
                s.push(b/a);
            }
            else{
                s.push(atoi(str.c_str()));
            }
        }
        return s.top();
    }
};