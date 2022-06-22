// https://leetcode.com/problems/bulls-and-cows

class Solution {
public:
    string getHint(string secret, string guess) {
        
        int n = secret.length();
        int b=0,c=0;
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
      
        for(int i=0;i<n;i++)
        {
            if(secret[i] == guess[i])
                b++;
            else{
            mp1[secret[i]]++;
            mp2[guess[i]]++;
            }
        }
        for(auto &i : mp1)
        {
            c += min(i.second , mp2[i.first]);
        }
        string ans = "";
        ans += to_string(b);
        ans += "A";
        ans += to_string(c);
        ans += "B";
        return ans;
    }
};