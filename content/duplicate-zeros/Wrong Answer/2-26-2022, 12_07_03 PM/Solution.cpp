// https://leetcode.com/problems/duplicate-zeros

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int m = arr.size();
        int z = 0;
        int j = m-1;
        for(int i=0;i<m;i++){
            if(arr[i]==0){
                z++;
            }
        }
        for(int i=m-1;i>=0;i--){
            if(z>0){
                z -= arr[i]==0 ? 2 : 1;
            }
            else{
                if(arr[i]==0){
                    arr[j] = 0;
                    j--;
                    arr[j] = 0;
                    j--;
                }
                else{
                    arr[j] = arr[i];
                    j--;
                }
            }
        }
    }
};