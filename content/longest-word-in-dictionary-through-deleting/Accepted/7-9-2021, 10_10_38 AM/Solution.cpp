// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting

/**
My Solution 3

Create a jump table to make subsequence check through s faster.
*/
class Solution {
public:
    std::string findLongestWord(std::string s, std::vector<std::string>& dictionary) {
        const auto slen = s.length();

        /** Build a 2D array of m[slen][26] where
            m[i][c] means the next location of character c
            from index i in s.
        */

        std::vector<std::vector<int>> m(slen, std::vector<int>(26, slen));

        for ( int i = s.size()-1; i >= 0; --i ) {
            m[i][s[i]-'a'] = i;
            if ( i > 0 ) {
                for ( int c = 0; c < 26; ++ c )
                    m[i-1][c] = m[i][c];
            }
        }

        std::string res;

        for ( const auto& w : dictionary ) {
            const auto wlen = w.length();

            int idx = 0;
            int i = 0;

            while ( i < wlen ) {
                if ( idx == slen or m[idx][w[i]-'a'] == slen )
                    break;

                idx = ( m[idx][w[i]-'a'] + 1 );
                ++i;
            }

            if ( i == wlen ) {
                if ( wlen > res.length() or ( wlen == res.length() and w < res ) )
                    res = w;
            }
        }

        return res;
    }
};

// fast IO
static char __ = []() -> char {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return '\0';
}();