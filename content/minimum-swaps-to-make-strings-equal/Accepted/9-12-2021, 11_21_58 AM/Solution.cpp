// https://leetcode.com/problems/minimum-swaps-to-make-strings-equal

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int x=0,y=0;
        int xn=0,yn=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                if(s1[i]=='x'){
                    x++;
                }
                else{
                    y++;
                }
            }
            if(s1[i]=='x'){
                xn++;
            }
            if(s2[i]=='x'){
                xn++;
            }
            if(s1[i]=='y'){
                yn++;
            }
            if(s2[i]=='y'){
                yn++;
            }
        }
        if(xn%2!=0 || yn%2!=0) return -1;
        if(x%2==0){
            if(y%2==0){
                return x/2+y/2;
            }
        }
        else{
            return x/2+y/2+2;
        }
        return -1;
    }
};