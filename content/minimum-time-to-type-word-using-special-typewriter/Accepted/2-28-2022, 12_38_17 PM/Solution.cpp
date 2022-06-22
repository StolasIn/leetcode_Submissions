// https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter

class Solution {
public:
    int minTimeToType(string word) {
        int m = word.size();
        int ans = 0;
        ans+= m;
        ans+=abs(word[0]-'a')>13 ? 26 - abs(word[0]-'a') : abs(word[0]-'a');
        for(int i=1;i<m;i++){
            ans+=abs(word[i]-word[i-1])>13 ? 26 - abs(word[i]-word[i-1]): abs(word[i]-word[i-1]);
        }
        return ans;
    }
};