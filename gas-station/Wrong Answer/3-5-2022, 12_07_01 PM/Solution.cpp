// https://leetcode.com/problems/gas-station

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int mi = 1e9,ma = -1e9;
        int inow = 0,mnow = 0;
        int ipos = 0,mpos = 0,tol = 0;
        for(int i=0;i<gas.size();i++){
            inow += gas[i] - cost[i];
            mnow += gas[i] - cost[i];
            tol += gas[i] - cost[i];
            if(mi>inow){
                mi = inow;
                ipos = i;
            }
            if(inow>0){
                inow = 0;
            }
            if(ma<mnow){
                ma = mnow;
            }
            if(mnow<0){
                mpos = i;
                mnow = 0;
            }
        }
        if(tol-mi>ma){
            return tol>=0? (ipos+1)%gas.size() : -1;
        }
        else{
            return tol>=0? (mpos+1)%gas.size() : -1;
        }
    }
};