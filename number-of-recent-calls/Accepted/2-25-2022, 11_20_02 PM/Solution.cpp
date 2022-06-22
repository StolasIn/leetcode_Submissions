// https://leetcode.com/problems/number-of-recent-calls

class RecentCounter {
public:
    queue<int> calls;
    RecentCounter() {}
    
    int ping(int t) {
        calls.push(t);
        while (calls.front() < t - 3000){
            calls.pop();
        }
        return calls.size();
    }
};