// https://leetcode.com/problems/distance-between-bus-stops

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& dis, int s, int d) {
        if(s>d){
            swap(s,d);
        }
        int l=0,r=0;
        for(int i=s;i<d;i++){
            l+=dis[i];
        }
        for(int i=d;i%dis.size()!=s;i++){
            r+=dis[i%dis.size()];
        }
        return min(l,r);
    }
};