// https://leetcode.com/problems/interleaving-string

class Solution {
public:
    string c1,c2,cm;
    bool re(int x,int y,int z){
        if(z==cm.size()){
            return true;
        }
        if(x>=c1.size() && y>=c2.size()){
            return false;
        }
        if(x>=c1.size()){
            return c2[y]==cm[z]? re(x,y+1,z+1):false;
        }
        if(y>=c2.size()){
            return c1[x]==cm[z]? re(x+1,y,z+1):false;
        }
        //printf("%d %d %d %c %c %c\n",x,y,z,c1[x],c2[y],cm[z]);
        if(c1[x]!=cm[z] && c2[y]!=cm[z]){
            return false;
        }
        if(c1[x]==cm[z] && c2[y]==cm[z]){
            return re(x+1,y,z+1)|re(x,y+1,z+1);
        }
        else if(c1[x]==cm[z]){
            return re(x+1,y,z+1);
        }
        else if(c2[y]==cm[z]){
            return re(x,y+1,z+1);
        }
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        c1=s1;
        c2=s2;
        cm=s3;
        return re(0,0,0);
    }
};