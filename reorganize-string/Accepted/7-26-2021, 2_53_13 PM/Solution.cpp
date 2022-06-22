// https://leetcode.com/problems/reorganize-string

struct node{
    char c;
    int f;
};
bool operator<(node a,node b){
    return a.f<b.f;
}
class Solution {
public:
    string reorganizeString(string s) {
        vector<int> ch(128,0);
        string str="";
        priority_queue<node> pq;
        for(int i=0;i<s.size();i++){
            ch[s[i]]++;
        }
        for(int i='a';i<='z';i++){
            pq.push(node{(char)i,ch[i]});
        }
        node tmp=pq.top();
        pq.pop();
        str+=tmp.c;
        tmp.f--;
        pq.push(tmp);
        while(1){
            node tmp=pq.top();
            pq.pop();
            if(tmp.f<=0) break;
            if(tmp.c==str.back()){
                if(pq.empty()) return "";
                node tmp2=pq.top();
                pq.pop();
                if(tmp2.f<=0) return "";
                str+=tmp2.c;
                tmp2.f--;
                pq.push(tmp2);
                pq.push(tmp);
            }
            else{
                str+=tmp.c;
                tmp.f--;
                pq.push(tmp);
            }
        }
        return str;
    }
};