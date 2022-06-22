// https://leetcode.com/problems/flatten-nested-list-iterator

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    deque<int> ans;
    NestedIterator(vector<NestedInteger> &n) {
        for(auto i:n){
            if(i.isInteger()){
                ans.emplace_back(i.getInteger());
            }
            else{
                NestedIterator it=NestedIterator(i.getList());
                while(it.hasNext()) ans.emplace_back(it.next());
            }
        }
    }
    
    int next() {
        auto i=ans.front();
        ans.pop_front();
        return i;
    }
    
    bool hasNext() {
        return !ans.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */