// https://leetcode.com/problems/reordered-power-of-2

class Solution {
public:
    int arr[10];
    bool check(int num){
        int p[10];
        memset(p,0,sizeof(p));
        while(num!=0){
            p[num%10]++;
            num/=10;
        }
        for(int i=0;i<10;i++){
            if(p[i]!=arr[i]){
                return false;
            }
        }
        return true;
    }
    bool reorderedPowerOf2(int n) {
        int pro=1;
        memset(arr,0,sizeof(arr));
        while(n!=0){
            arr[n%10]++;
            n/=10;
        }
        while(pro<=1000000000){
            if(check(pro)) return true;
            pro*=2;
        }
        return false;
    }
};