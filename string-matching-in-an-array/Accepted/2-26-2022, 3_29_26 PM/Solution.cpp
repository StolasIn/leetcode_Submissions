// https://leetcode.com/problems/string-matching-in-an-array

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string>out;
        for(auto i:words)//traverse for the substring to be searcher
        {
            for(auto j:words)//traverse for the substring to search
            {
                if(i==j)//if the word are same skip it
                    continue;
					//incase of -1 we can also use string::npos
                if(j.find(i)!=-1) //if found it will return thr pos i.e not equal to -1
                {
                    out.push_back(i);// put it in out vector
                    break;
                }
            }
        }
        return out;
    }
};