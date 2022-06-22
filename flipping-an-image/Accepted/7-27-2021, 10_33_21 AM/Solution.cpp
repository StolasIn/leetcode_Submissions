// https://leetcode.com/problems/flipping-an-image

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int i=0;
        for(;i<image.size();i++){
            reverse(image[i].begin(),image[i].end());
        }
        for(i=0;i<image.size();i++){
            for(int j=0;j<image[i].size();j++){
                image[i][j]=!image[i][j];
            }
        }
        return image;
    }
};