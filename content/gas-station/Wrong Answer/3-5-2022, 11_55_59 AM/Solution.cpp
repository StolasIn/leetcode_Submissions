// https://leetcode.com/problems/gas-station

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int mi = 1e9;
        int now = 0;
        int pos = 0;
        int tol = 0;
        for(int i=0;i<gas.size();i++){
            now += gas[i] - cost[i];
            tol += gas[i] - cost[i];
            if(mi>now){
                mi = now;
                pos = i;
            }
            if(now>0){
                now = 0;
            }
        }
        return tol>=0? (pos+1)%gas.size() : -1;
    }
};