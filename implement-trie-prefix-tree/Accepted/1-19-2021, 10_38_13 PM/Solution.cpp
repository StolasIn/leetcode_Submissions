// https://leetcode.com/problems/implement-trie-prefix-tree

class Trie {
public:
    /** Initialize your data structure here. */
    unordered_map<string,vector<string>> map;
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        string str="";
        for(int i=0;i<word.size();i++){
            str+=word[i];
            map[str].push_back(word);
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto iter = map.find(word);
        if(iter!=map.end()){
            for(int i=0;i<iter->second.size();i++){
                if(iter->second[i]==word) return true;
            }
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if(map.find(prefix)!=map.end()) return true;
            return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */