// https://leetcode.com/problems/path-crossing

class Solution {
public:
    bool isPathCrossing(string path) {
        int x=0, y=0;
        set<pair<int, int>>s;
        s.insert(make_pair(0,0));
        
        for(int i=0; i<path.length(); i++){
            if(path[i]=='N') y++;
            else if(path[i]=='W') x--;
            else if(path[i]=='E') x++;
            else y--;
            
            if(s.find({x,y}) != s.end()) return true;
            else s.insert(make_pair(x,y));
        }
        
        return false;
    }
};