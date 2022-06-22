// https://leetcode.com/problems/distribute-candies

class Solution {
public:
    int distributeCandies(vector<int>& c) {
        int arr[200001]={0};
        int m=c.size();
        unsigned long int cnt=0;
        for(int i=0;i<m;i++){
            if(arr[100000+c[i]]==0){
                arr[100000+c[i]]++;
                cnt++;
            }
            if(c.size()/2<cnt){
                return c.size()/2;
            }
        }
        return min(c.size()/2,cnt);
    }
};