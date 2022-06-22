// https://leetcode.com/problems/alphabet-board-path

struct node{
    int r,c;
};
class Solution {
public:
    string alphabetBoardPath(string tar) {
        char now = 'a';
        unordered_map<char,node> map;
        int cnt=0;
        int x=0,y=0;
        int nx,ny;
        string str="";
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                map[now++]=node{i,j};
            }
        }
        map[now]=node{5,0};
        for(auto& t : tar){
            nx = map[t].r-x;
            ny = map[t].c-y;
            if(nx>0){
                for(int i=0;i<nx;i++){
                    str+='D';
                }
            }
            else if(nx<0){
                nx=-nx;
                for(int i=0;i<nx;i++){
                    str+='U';
                }
            }
            if(ny>0){
                for(int i=0;i<ny;i++){
                    str+='R';
                }
            }
            else if(ny<0){
                ny=-ny;
                for(int i=0;i<ny;i++){
                    str+='L';
                }
            }
            str+='!';
            x=map[t].r;
            y=map[t].c;
        }
        return str;
    }
};