// https://leetcode.com/problems/maximum-compatibility-score-sum

struct node{
    int val;
    int f1,f2;
    bool operator<(const node& a) const {
        return a.val>val;
    }
};
class Solution {
public:
    int cnt(vector<int>& a,vector<int>& b){
        int ans=0;
        for(int i=0;i<a.size();i++){
            if(a[i]==b[i]){
                ans++;
            }
        }
        return ans;
    }
    int maxCompatibilitySum(vector<vector<int>>& s, vector<vector<int>>& m) {
        int n = m.size();
        int ans=0;
        unordered_set<int> s1;
        unordered_set<int> s2;
        priority_queue<node> pq;
        for(int i=0;i<s.size();i++){
            for(int j=0;j<m.size();j++){
                pq.push(node{cnt(s[i],m[j]),i,j});
            }
        }
        /*while(!pq.empty()){
            cout<<pq.top().val<<endl;
            pq.pop();
        }*/
        while(n--){
            while(1 && !pq.empty()){
                auto tmp = pq.top();
                pq.pop();
                if(s1.find(tmp.f1)==s1.end() && s2.find(tmp.f2)==s2.end()){
                    s1.insert(tmp.f1);
                    s2.insert(tmp.f2);
                    ans+=tmp.val;
                    break;
                }
            }
        }
        return ans;
    }
};