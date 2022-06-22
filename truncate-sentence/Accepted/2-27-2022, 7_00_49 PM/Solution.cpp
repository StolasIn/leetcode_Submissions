// https://leetcode.com/problems/truncate-sentence

class Solution {
public:
    string truncateSentence(string s, int k) {
        stringstream ss(s);
        string ans = "";
        string tmp;
        while(k>0){
            ss>>tmp;
            ans+=tmp;
            if(k>1){
                ans+=' ';
            }
            k--;
        }
        return ans;
    }
};