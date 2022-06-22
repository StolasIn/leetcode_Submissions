// https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers

class Solution {
public:
     bool checkValid(vector<vector<int>>& matrix) {
        int n=matrix.size();
       
        for(int i=0;i<matrix.size();i++)
        {    set<int>s1;
            set<int>s2;
            for(int j=0;j<matrix[i].size();j++)
            {
                s1.insert(matrix[i][j]);
                s2.insert(matrix[j][i]);
            }
            if(s1.size()!=matrix[i].size()) return false;
            if(s2.size()!=matrix[i].size()) return false;
        }
        return true;
    }
};