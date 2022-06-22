// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        long int max=-1;
        long int cnt;
        for(int i=0;i<height.size();i++){
            for(int j=i+1;j<height.size();j++){
                cnt=(j-i)*min(height[i],height[j]);
                if(cnt>max) max=cnt;
            }
        }
        return max;
    }
};