// https://leetcode.com/problems/design-add-and-search-words-data-structure

class trie_node{
public:
    bool isend;
    vector<trie_node*> link;
    trie_node(){
        isend=false;
        link.assign(26,nullptr);
    }
};
class Trie {
public:
    /** Initialize your data structure here. */
    trie_node* root;
    trie_node* trie_pointer;
    int counter;
    Trie() {
        root=new trie_node();
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        counter=0;
        int m=word.size();
        trie_pointer=root;
        while(counter<word.size()){
            if(trie_pointer->link[word[counter]-'a']==nullptr){
                trie_pointer->link[word[counter]-'a']=new trie_node();
            }
            trie_pointer=trie_pointer->link[word[counter]-'a'];
            counter++;
        }
        trie_pointer->isend=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(trie_node* tr,string& word,int idx) {
        if(tr==nullptr) return false;
        if(idx==word.size()-1){
            if(tr->isend==true) return true;
            for(int i=0;i<tr->link.size();i++){
                if(tr->link[i]!=nullptr) return true;
            }
            return false;
        }
        else{
            if(word[idx]!='.'){
                return search(tr->link[word[idx]-'a'],word,idx+1);
            }
            else{
                bool flag=false;
                for(int i=0;i<tr->link.size();i++){
                    flag |= search(tr->link[i],word,idx+1);
                }
                return flag;
            }
        }
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        trie_pointer=root;
        counter=0;
        while(trie_pointer!=nullptr && counter<prefix.size()){
            trie_pointer=trie_pointer->link[prefix[counter++]-'a'];
        }
        if(trie_pointer==nullptr) return false;
        else{
            if(trie_pointer->isend==true) return true;
            for(int i=0;i<26;i++){
                if(trie_pointer->link[i]!=nullptr){
                    return true;
                }
            }
            return false;
        }
    }
};
class WordDictionary {
public:
    /** Initialize your data structure here. */
    Trie t;
    WordDictionary() {
        t=Trie();
    }
    
    void addWord(string word) {
        t.insert(word);
    }
    
    bool search(string word) {
        return t.search(t.root,word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */