// https://leetcode.com/problems/container-with-most-water

#define max(a,b) (a>b ? a : b)
#define min(a,b) (a<b ? a : b)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max1=-1;
        for(int i=0;i<height.size();i++){
            for(int j=i+1;j<height.size();j++){
                max1=max(max1,(j-i)*min(height[i],height[j]));
            }
        }
        return max1;
    }
};