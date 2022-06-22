// https://leetcode.com/problems/flood-fill

struct point{
    int x;
    int y;
};
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if(volor == newColor){
            return image;
        }
        int m = image.size(),n = image[0].size();
        vector<vector<int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};
        queue<point> q;
        q.push(point{sr,sc});
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            if(t.x<0 || t.y<0 || t.x>=m || t.y>=n){
                continue;
            }
            if(image[t.x][t.y] == color){
                image[t.x][t.y] = newColor;
                for(int i=0;i<dir.size();i++){
                    q.push(point{t.x + dir[i][0] , t.y + dir[i][1]});
                }
            }
        }
        return image;
    }
};