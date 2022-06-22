// https://leetcode.com/problems/zigzag-conversion

class Solution {
public:
    string convert(string s, int numRows) {
        string str1;
        char str[numRows][s.size()];
        for(int i=0;i<numRows;i++){
            for(int j=0;j<s.size();j++){
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
            for(int j=0;j<(int)(2*s.size()/numRows)+1 && j<s.size();j++){
                if(str[i][j]!='0'){
                    str1+=str[i][j];
                }
            }
        }
        
        return str1;
    }
};