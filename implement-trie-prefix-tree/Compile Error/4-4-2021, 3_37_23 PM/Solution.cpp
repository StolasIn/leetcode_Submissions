// https://leetcode.com/problems/implement-trie-prefix-tree

class tn{
public:
    vector<tn*> link;
    tn(){
        link.assign(27,nullptr);
    }
};
class Trie {
public:
    /** Initialize your data structure here. */
    tn* root;
    Trie() {
        root=new tn(' ');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        insert_u(word,0,root);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return search_u(word,0,root);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return start_with_u(prefix,0,root);
    }
private:
    void insert_u(string word,int idx,tn* r){
        if(idx>=word.size()){
            r->link[26] = new tn('\0');
            return;
        }
        if(r->link[word[idx]-'a']==nullptr){
            r->link[word[idx]-'a'] = new tn(word[idx]);
            insert_u(word,idx+1,r->link[word[idx]-'a']);
        }
        else{
            insert_u(word,idx+1,r->link[word[idx]-'a']);
        }
    }
    bool search_u(string word,int idx,tn* r){
        if(r==nullptr) return false;
        if(idx>=word.size()) return false;
        if(idx==(word.size()-1) && r->link[word[idx]-'a']!=nullptr){
            if(r->link[word[idx]-'a']->link[26]!=nullptr){
                return true;
            }
            else{
                return false;
            }
        }
        return search_u(word,idx+1,r->link[word[idx]-'a']);
    }
    bool start_with_u(string word,int idx,tn* r){
        if(r==nullptr) return false;
        if(idx>=word.size()) return false;
        if(idx==(word.size()-1) && r->link[word[idx]-'a']!=nullptr){
            for(auto i : r->link[word[idx]-'a']->link){
                if(i!=nullptr){
                    return true;
                }
            }
            return false;
        }
        return start_with_u(word,idx+1,r->link[word[idx]-'a']);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */