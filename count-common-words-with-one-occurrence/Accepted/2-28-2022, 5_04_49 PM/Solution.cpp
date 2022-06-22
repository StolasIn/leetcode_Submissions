// https://leetcode.com/problems/count-common-words-with-one-occurrence

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> m;
        int ans = 0;
        for (auto &w : words1){
            m[w]++;
        }
        for (auto &w : words2){
            if (m[w] < 2){
                m[w]--;
            }
        }
        for(auto i : m){
            if(i.second==0){
                ans++;
            }
        }
        return ans;

    }
};