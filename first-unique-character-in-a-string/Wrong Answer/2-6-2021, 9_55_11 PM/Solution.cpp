// https://leetcode.com/problems/first-unique-character-in-a-string

class Solution {
public:
    unordered_map<char,int> map;
    int firstUniqChar(string s) {
        int m=s.size();
        for(int i=0;i<m;i++){
            map[s[i]]=i;
        }
        for(int i=0;i<m;i++){
            if(map[s[i]]==i) return i;
        }
        return -1;
    }
};