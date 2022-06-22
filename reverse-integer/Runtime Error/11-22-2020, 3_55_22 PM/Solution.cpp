// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        bool sign;
        int pro=1;
        int l=0;
        vector<int> num;
        if(x>0) sign=0;
        else sign=1;
        x=abs(x);
        for(int i=0;x!=0;i++){
            num.push_back(x%10);
            x/=10;
        }
        for(int i=num.size()-1;i>=0;i--){
            l+=pro*num[i];
            pro*=10;
        }
        if(!sign) return l;
        else return -l;
    }
};