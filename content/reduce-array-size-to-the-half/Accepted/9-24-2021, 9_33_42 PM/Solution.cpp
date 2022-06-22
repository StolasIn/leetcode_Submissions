// https://leetcode.com/problems/reduce-array-size-to-the-half

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> map;
        priority_queue<int> pq;
        int m=arr.size();
        int c=0;
        for(int i=0;i<arr.size();i++){
            map[arr[i]]++;
        }
        for(auto i : map){
            pq.push(i.second);
        }
        while(m>arr.size()/2){
            c++;
            m-=pq.top();
            pq.pop();
        }
        return c;
    }
};