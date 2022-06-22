// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int diff = 0;
        map<char,int> m;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                diff++;
            }
            m[s1[i]]++;
            m[s2[i]]--;
        }
        if(!(diff==0 || diff==2)){
            return false;
        }
        for(auto i : m){
            if(i.second!=0){
                return false;
            }
        }
        return true;
    }
};