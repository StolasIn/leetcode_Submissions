// https://leetcode.com/problems/minimum-number-of-operations-to-convert-time

class Solution {
public:
    int convertTime(string current, string correct) {
        int c1 = atoi(current.substr(0,2).c_str());
        int c2 = atoi(current.substr(3,5).c_str());
        int c3 = atoi(correct.substr(0,2).c_str());
        int c4 = atoi(correct.substr(3,5).c_str());
        //printf("%d %d %d %d\n",c1,c2,c3,c4);
        int diff = abs(c1-c3)*60;
        diff += abs(c2-c4);
        cout<<diff<<endl;
        vector<int> v = {60,15,5,1};
        int ans = 0;
        for(int val : v){
            ans+=diff/val;
            diff%=val;
        }
        return ans;
    }
};