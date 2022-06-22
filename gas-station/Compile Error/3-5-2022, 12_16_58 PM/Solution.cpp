// https://leetcode.com/problems/gas-station

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ma = -1e9;
        int now = 0;
        int pos = 0,tol = 0;
        for(int i=0;i<gas.size();i++){
            now += gas[i] - cost[i];
            tol += gas[i] - cost[i];
            if(ma<now){
                ma = now;
            }
            if(now<0){
                pos = i+1;
                now = 0;
            }
        }
        return tol>=0? mpos : -1;
    }
};