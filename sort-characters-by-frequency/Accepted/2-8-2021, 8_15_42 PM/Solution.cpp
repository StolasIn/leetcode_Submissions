// https://leetcode.com/problems/sort-characters-by-frequency

class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>> pq;
        string s1="";
        vector<int> ch(128,0);
        int m=s.size();
        for(int i=0;i<m;i++){
            ch[s[i]]++;
        }
        for(int i=0;i<m;i++){
            pq.push(pair<int,char>(ch[s[i]],s[i]));
        }
        for(int i=0;i<m;i++){
            s1+=pq.top().second;
            pq.pop();
        }
        return s1;
    }
};