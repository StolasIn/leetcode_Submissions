// https://leetcode.com/problems/basic-calculator-ii

class Solution {
public:
    struct data{
        int d;
        bool f;
    };
    int calculate(string str) {
        vector<char> st;
        vector<data> exp;
        stack<int> ans;
        string dig="";
        int m=str.size();
        vector<int> pri(6);
        pri['+'-42]=pri['-'-42]=1;
        pri['*'-42]=pri['/'-42]=2;
        for(int i=0;i<m;i++){
            if(str[i]==' ') continue;
            if(isdigit(str[i])){
                dig+=str[i];
            }
            else{
                exp.emplace_back(data{atoi(dig.c_str()),1});
                if(st.empty() || pri[str[i]-42]>pri[st.back()-42]){
                    st.emplace_back(str[i]);
                }
                else{
                    while(!st.empty() && pri[str[i]-42]<=pri[st.back()-42]){
                        exp.emplace_back(data{(int)st.back(),0});
                        st.pop_back();
                    }
                    st.emplace_back(str[i]);
                }
                dig="";
            }
        }
        if(dig!=""){
            exp.emplace_back(data{atoi(dig.c_str()),1});
        }
        while(!st.empty()){
            exp.emplace_back(data{(int)st.back(),0});
            st.pop_back();
        }
        for(auto i : exp){
            if(i.f==true){
                ans.push(i.d);
            }
            else{
                auto t1=ans.top();
                ans.pop();
                auto t2=ans.top();
                ans.pop();
                if(i.d==42){
                    ans.push(t1*t2);
                }
                else if(i.d==43){
                    ans.push(t1+t2);
                }
                else if(i.d==45){
                    ans.push(t2-t1);
                }
                else if(i.d==47){
                    ans.push(t2/t1);
                }
            }
        }
        return ans.top();
    }
};