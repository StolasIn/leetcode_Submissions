// https://leetcode.com/problems/encode-and-decode-tinyurl

class Solution {
public:

    // Encodes a URL to a shortened URL.
    unordered_map<string,string> m1;
    unordered_map<string,string> m2;
    int cnt=0;
    string encode(string longUrl) {
        cnt++;
        m1[longUrl]=to_string(cnt);
        m2[to_string(cnt)]=longUrl;
        return to_string(cnt);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m2[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));