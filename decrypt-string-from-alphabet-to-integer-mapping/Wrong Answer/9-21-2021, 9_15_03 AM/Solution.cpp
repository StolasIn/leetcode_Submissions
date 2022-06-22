// https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping

class Solution {
public:
    string freqAlphabets(string s) {
        vector<char> st;
        string str="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='#'){
                int b=st.back();
                st.pop_back();
                int a=st.back();
                st.pop_back();
                for(int i=0;i<st.size();i++){
                    str+=(char)((st[i]-'0')+'a');
                }
                st.clear();
                str+=(char)((a-'0')*10+(b-'0')+'a'-1);
            }
            else{
                st.emplace_back(s[i]);
            }
        }
        for(int i=0;i<st.size();i++){
            str+=(char)((st[i]-'0')+'a');
        }
        return str;
    }
};