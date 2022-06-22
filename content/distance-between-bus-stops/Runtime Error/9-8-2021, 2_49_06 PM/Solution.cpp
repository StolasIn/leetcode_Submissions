// https://leetcode.com/problems/distance-between-bus-stops

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& dis, int s, int d) {
        if(s>d){
            swap(s,d);
        }
        int l=0,r=0,m=dis.size();
        for(int i=s;i<d;i++){
            l+=dis[i];
        }
        for(int i=d;i!=s;i++){
            r+=dis[i];
            i%=m;
        }
        return min(l,r);
    }
};