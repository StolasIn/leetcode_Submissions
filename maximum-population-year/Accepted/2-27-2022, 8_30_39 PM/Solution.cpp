// https://leetcode.com/problems/maximum-population-year

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int arr[2051] = {0};
        int ma = 0;
        int y;
        for(int i=0;i<logs.size();i++){
            arr[logs[i][0]]++;
            arr[logs[i][1]]--;
        }
        for(int i=1950;i<2051;i++){
            arr[i] += arr[i-1];
            if(ma<arr[i]){
                ma = arr[i];
                y = i;
            }
        }
        return y;
    }
};