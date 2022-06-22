// https://leetcode.com/problems/hand-of-straights

bool cmp(pair<int,int> a,pair<int,int> b){
    return a.first<b.first;
}
class Solution {
public:
    bool isNStraightHand(vector<int>& h, int k) {
        map<int,int> m;
        int t;
        if(h.size()%k!=0) return false;
        for(int i=0;i<h.size();i++){
            if(m.find(h[i])==m.end()){
                m[h[i]]=1;
            }
            else{
                m[h[i]]++;
            }
        }
        int n=h.size()/k;
        for(int j=0;j<n;j++){
            t=min_element(m.begin(),m.end(),cmp)->first;
            m[t]--;
            if(m[t]==0) m.erase(t);
            for(int i=1;i<k;i++){
                if(m.find(t+i)==m.end()){
                    return false;
                }
                else{
                    m[t+i]--;
                    if(m[t+i]<=0) m.erase(t+i);
                }
            }
        }
        return true;
    }
};