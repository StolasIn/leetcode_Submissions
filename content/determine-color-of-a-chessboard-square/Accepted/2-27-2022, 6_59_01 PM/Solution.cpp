// https://leetcode.com/problems/determine-color-of-a-chessboard-square

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int x=(int)(coordinates[0]-'a');
        int y=(int)(coordinates[1]-'0');
        if((x%2==0&&y%2==0)||(x%2!=0&&y%2!=0))
            return true;
        else
            return false;
    }
};