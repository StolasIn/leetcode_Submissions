// https://leetcode.com/problems/course-schedule-iii

bool cmp(vector<int>& a,vector<int>& b){
    return a[1]<b[1];
}
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& cour) {
        int m=cour.size();
        sort(cour.begin(),cour.end(),cmp);
        int cnt=1;
        int en=cour[0][1];
        for(int i=1;i<m;i++){
            if(cour[i][0]>cour[i][1]) continue;
            if(cour[i][0]>en){
                en=cour[i][1];
                cnt++;
            }
        }
        return cnt;
    }
};