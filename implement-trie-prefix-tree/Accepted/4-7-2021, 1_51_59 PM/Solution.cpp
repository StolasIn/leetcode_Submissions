// https://leetcode.com/problems/implement-trie-prefix-tree

class tn{
public:
    bool isend;
    vector<tn*> link;
    tn(){
        isend=false;
        link.assign(26,nullptr);
    }
};
class Trie {
public:
    /** Initialize your data structure here. */
    tn* root;
    Trie() {
        root=new tn();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int m=word.size();
        auto tmp=root;
        for(int i=0;i<m;i++){
            if(tmp->link[word[i]-'a']==nullptr){
                tmp->link[word[i]-'a']=new tn();
            }
            tmp=tmp->link[word[i]-'a'];
        }
        tmp->isend=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto tmp=root;
        int c=0;
        while(tmp!=nullptr && c<word.size()){
            tmp=tmp->link[word[c++]-'a'];
        }
        if(tmp==nullptr) return false;
        if(tmp->isend==false) return false;
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto tmp=root;
        int c=0;
        while(tmp!=nullptr && c<prefix.size()){
            tmp=tmp->link[prefix[c++]-'a'];
        }
        if(tmp==nullptr) return false;
        else{
            for(int i=0;i<26;i++){
                if(tmp->link[i]!=nullptr){
                    return true;
                }
            }
        if(tmp==nullptr) return false;
        if(tmp->isend==false) return false;
        return true;
        }
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */