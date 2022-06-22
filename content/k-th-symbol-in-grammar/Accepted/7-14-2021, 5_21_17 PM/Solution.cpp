// https://leetcode.com/problems/k-th-symbol-in-grammar

class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1) return 0;
        int tmp=pow(2,n-2);
        if(k>tmp){
            if(kthGrammar(n-1,k-tmp)==1){
                return 0;
            }
            else{
                return 1;
            }
        }
        else{
            return kthGrammar(n-1,k);
        }
    }
};