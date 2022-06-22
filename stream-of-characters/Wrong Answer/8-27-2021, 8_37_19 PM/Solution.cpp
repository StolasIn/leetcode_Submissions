// https://leetcode.com/problems/stream-of-characters

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
    bool search(string word) {
        trie_pointer=root;
        counter=0;
        while(trie_pointer!=nullptr && counter<word.size()){
            trie_pointer=trie_pointer->link[word[counter++]-'a'];
        }
        if(trie_pointer==nullptr) return false;
        if(trie_pointer->isend==false) return false;
        return true;
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
class StreamChecker {
public:
    Trie t;
    StreamChecker(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            reverse(words[i].begin(),words[i].end());
            t.insert(words[i]);
        }
    }
    
    bool query(char letter) {
        string str="";
        str+=letter;
        if(t.startsWith(str)){
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */