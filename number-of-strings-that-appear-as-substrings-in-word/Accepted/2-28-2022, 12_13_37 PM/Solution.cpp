// https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word

class Solution {
public:
    int numOfStrings(vector<string>& p, string w) {
        int ans = 0;
        for(int i=0;i<p.size();i++){
            if(w.find(p[i])!=string::npos){
                ans++;
            }
        }
        return ans;
    }
};