// https://leetcode.com/problems/lemonade-change

class Solution {
public:
    bool lemonadeChange(vector<int>& b) {
        if(b[0]!=5) return false;
        int five=0,ten=0;
        for(int i=0;i<b.size();i++){
            if(b[i]==5){
                five++;
            }
            else if(b[i]==10){
                if(five<1) return false;
                five--;
                ten++;
            }
            else{
                if(ten>=1 && five>=1){
                    ten--;
                    five--;
                }
                else if(five>=3){
                    five-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};