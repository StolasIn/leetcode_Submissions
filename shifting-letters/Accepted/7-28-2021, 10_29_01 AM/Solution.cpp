// https://leetcode.com/problems/shifting-letters

class Solution {
public:
    string shiftingLetters(string& s, vector<int>& sh) {
        std::ios_base::sync_with_stdio(false);
	    std::cin.tie(0);
	    std::cout.tie(0);
        int i;
        for(i=sh.size()-1;i>0;i--){
            sh[i-1]=(sh[i]+sh[i-1])%26;
        }
        for(i=0;i<s.size();i++){
            s[i]=((s[i]-'a')+sh[i])%26+'a';
        }
        return s;
    }
};