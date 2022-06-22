// https://leetcode.com/problems/container-with-most-water

#define max(a,b) (a>b ? a : b)
#define min(a,b) (a<b ? a : b)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max1=-1;
        int l=0;
        int r=height.size()-1;
        while(l<r){
            max1=max(max1,(r-l)*min(height[r],height[l]));
            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return max1;
    }
};