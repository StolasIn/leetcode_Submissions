// https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int n = rectangles.size() , c = 1 , ans = 0 , mx = INT_MIN;
        for(int i = 0 ; i < n ; i++)
        {
            ans = min(rectangles[i][0],rectangles[i][1]);
            if(ans > mx)
            {
                mx = ans;
                c = 1;
            }
            else if(ans == mx)
            {
                c++;
            }
        }
        return c;
    }
};