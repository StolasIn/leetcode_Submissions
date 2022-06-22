// https://leetcode.com/problems/super-pow

class Solution {
public:
    int one;
    int mul(int a,int b){
        return ((a%1337)*(b%1337))%1337;
    }
    int qmul(int n){
        if(n==1){
            return one;
        }
        int tmp=qmul(n/2);
        tmp=mul(tmp,tmp);
        if(n%2==1){
            tmp=mul(one,tmp);
        }
        return tmp;
    }
    int superPow(int a, vector<int>& b) {
        int c=0;
        int pro=1;
        for(int i=b.size()-1;i>=0;i--){
            c+=b[i]*pro;
            pro*=10;
        }
        one=a;
        return qmul(c);
    }
};