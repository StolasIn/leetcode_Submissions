// https://leetcode.com/problems/first-unique-character-in-a-string

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> map(128);
        int m=s.size();
        for(int i=0;i<m;i++){
            map[s[i]]++;
        }
        for(int i=0;i<m;i++){
            if(map[s[i]]<=1){
                return i;
            }
        }
        return -1;
    }
};