// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string

class Solution {
public:
    string removeDuplicates(string s) {
        string st;
        for(int i=0;i<s.size();i++){
            if(st.size()!=0){
                if(st.back()==s[i]){
                    st.pop_back();
                    continue;
                }
            }
            st.push_back(s[i]);
        }
        return st;
    }
};