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
    tn* tmp;
    int c;
    Trie() {
        root=new tn();
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        c=0;
        int m=word.size();
        tmp=root;
        while(c<word.size()){
            if(tmp->link[word[c]-'a']==nullptr){
                tmp->link[word[c]-'a']=new tn();
            }
            tmp=tmp->link[word[c]-'a'];
            c++;
        }
        tmp->isend=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        tmp=root;
        c=0;
        while(tmp!=nullptr && c<word.size()){
            tmp=tmp->link[word[c++]-'a'];
        }
        if(tmp==nullptr) return false;
        if(tmp->isend==false) return false;
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        tmp=root;
        c=0;
        while(tmp!=nullptr && c<prefix.size()){
            tmp=tmp->link[prefix[c++]-'a'];
        }
        if(tmp==nullptr) return false;
        else{
            if(tmp->isend==true) return true;
            for(int i=0;i<26;i++){
                if(tmp->link[i]!=nullptr){
                    return true;
                }
            }
            return false;
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