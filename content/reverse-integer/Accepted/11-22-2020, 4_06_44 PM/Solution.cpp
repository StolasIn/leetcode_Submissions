// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        bool sign;
        long lon= x;
        long int pro=1;
        long int l=0;
        vector<int> num;
        if(lon>0) {
            sign=0;
        }
        else {
            sign=1;
            lon*=-1;
        }
        
        for(int i=0;lon!=0;i++){
            num.push_back(lon%10);
            lon/=10;
        }
        for(int i=num.size()-1;i>=0;i--){
            l+=pro*num[i];
            pro*=10;
        }
        if(l>2147483647) return 0;
        else if(l<-2147483647) return 0;
        if(!sign) return l;
        else return -l;
    }
};