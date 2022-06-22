// https://leetcode.com/problems/1-bit-and-2-bit-characters

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int m=bits.size();
        if(bits[m-1]!=0) return false;
        for(int i=0;i<m;i++){
            if(i==0) return true;
            if(bits[i]==1){
                i++;
            }
        }
        return false;
    }
};