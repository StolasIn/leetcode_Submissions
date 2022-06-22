// https://leetcode.com/problems/basic-calculator-ii

class Solution {
public:
    struct data{
        int d;
        bool f;
    };
    int calculate(string s) {
        stack<char> st;
        vector<data> exp;
        stack<int> ans;
        string str;
        string dig="";
        int m=s.size();
        vector<int> pri(128);
        pri['+']=pri['-']=1;
        pri['*']=pri['/']=2;
        for(int i=0;i<m;i++){
            if(s[i]!=' '){
                str+=s[i];
            }
        }
        m=str.size();
        for(int i=0;i<m;i++){
            if(isdigit(str[i])){
                dig+=str[i];
            }
            else{
                exp.emplace_back(data{atoi(dig.c_str()),1});
                if(st.empty() || pri[str[i]]>pri[st.top()]){
                    st.push(str[i]);
                }
                else{
                    while(!st.empty() && pri[str[i]]<=pri[st.top()]){
                        exp.emplace_back(data{(int)st.top(),0});
                        st.pop();
                    }
                    st.push(str[i]);
                }
                dig="";
            }
        }
        if(dig!=""){
            exp.emplace_back(data{atoi(dig.c_str()),1});
        }
        while(!st.empty()){
            exp.emplace_back(data{(int)st.top(),0});
            st.pop();
        }
        /*for(auto i : exp){
            cout<<i.d<<endl;
        }*/
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