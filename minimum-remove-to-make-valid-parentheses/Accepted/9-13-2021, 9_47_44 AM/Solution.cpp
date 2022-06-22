// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses

struct node{
    char c;
    int p;
};
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<node> st;
        unordered_set<int> map;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push_back(node{'(',i});
            }
            else if(s[i]==')'){
                if(st.empty() || st.back().c==')'){
                    st.push_back(node{')',i});
                }
                else{
                    st.pop_back();
                }
            }
        }
        for(int i=0;i<st.size();i++){
            map.insert(st[i].p);
        }
        for(int i=0;i<s.size();i++){
            if(map.find(i)==map.end()){
                ans+=s[i];
            }
        }
        return ans;
    }
};