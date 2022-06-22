// https://leetcode.com/problems/zigzag-conversion

class Solution {
public:
    string convert(string s, int numRows) {
        string str1;
        char str[numRows][1000];
        for(int i=0;i<numRows;i++){
            for(int j=0;j<1000;j++){
                str[i][j]='0';
            }
        }
        int x=0,y=0;
        int ind=0;
        for(;ind<s.size();){
        for(;x<numRows && ind<s.size();){
            str[x][y]=s[ind++];
            x++;
        }
            x--;
        for(;x>=1 && ind<s.size();){
            x--;
            y++;
            str[x][y]=s[ind++];
        }
            x++;
        }
        for(int i=0;i<numRows;i++){
            for(int j=0;j<(int)(2000/numRows)+1 && j<1000;j++){
                if(str[i][j]!='0'){
                    str1+=str[i][j];
                }
            }
        }
        
        return str1;
    }
};