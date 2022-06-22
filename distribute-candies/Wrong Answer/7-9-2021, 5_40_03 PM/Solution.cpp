// https://leetcode.com/problems/distribute-candies

class Solution {
public:
    int distributeCandies(vector<int>& c) {
        int arr[200001];
        int m=c.size();
        unsigned long int cnt=0;
        for(int i=0;i<m;i++){
            arr[100000+c[i]]++;
            if(arr[100000+c[i]]==1) cnt++;
        }
        return min(c.size()/2,cnt);
    }
};