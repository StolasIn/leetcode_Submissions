// https://leetcode.com/problems/shortest-distance-to-a-character

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int m = s.size();
        vector<int> v(m);
        int now = -1;
        for(int i=0;i<m;i++){
            if(s[i]==c){
                v[i] = 0;
                now = i;
            }
            else{
                if(now==-1){
                    v[i] = 1e9;
                }
                else{
                    v[i] = i-now;
                }
            }
        }
        now = -1;
        for(int i=m-1;i>=0;i--){
            if(s[i]==c){
                v[i] = 0;
                now = i;
            }
            else{
                if(now!=-1){
                    v[i] = min(v[i],now-i);
                }
            }
        }
        return v;
    }
};