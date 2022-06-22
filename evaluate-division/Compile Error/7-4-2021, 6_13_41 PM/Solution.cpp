// https://leetcode.com/problems/evaluate-division

struct edge{
    string to
    int val;  
};
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& v, vector<vector<string>>& q) {
        vector<double> ans;
        unordered_set<string> st;
        unordered_map<string,vector<edge>> map;
        unordered_set<string> ch;
        queue<edge> qu;
        string s1,s2;
        for(int i=0;i<eq.size();i++){
            if(st.find(eq[i][0])==st.end()){
                st.insert(eq[i][0]);
            }
            if(st.find(eq[i][1])==st.end()){
                st.insert(eq[i][1]);
            }
            map[eq[i][0]].emplace_back(edge{eq[i][1],v[i]});
            map[eq[i][1]].emplace_back(edge{eq[i][0],1/v[i]});
        }
        for(int i=0;i<q.size();i++){
            s1=q[i][0];
            s2=q[i][1];
            qu.push();
            while(!qu.empty()){
                auto t = qu.front();
                qu.pop();
                
            }
        }
    }
};