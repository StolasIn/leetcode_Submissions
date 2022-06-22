// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    bool cmp(vector<int> a,vector<int> b){
        return a[0]>b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),
             [](vector<int> a,vector<int> b) { 
                 return a[0]<=b[0];});
        deque<vector<int> > de(intervals.begin(),intervals.end());
        for(int i=0;i<de.size()-1;i++){
            if(de[i][1]>de[i+1][0]){
                de[i+1][0]=de[i][0];
                de.pop_front();
            }
        }
        return vector<vector<int>> (de.begin(),de.end());
    }
};