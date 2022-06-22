// https://leetcode.com/problems/map-sum-pairs

class trie_node{
public:
    bool isend;
    vector<trie_node*> link;
    int val;
    trie_node(){
        isend=false;
        val=0;
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
    void insert(string word,int val) {
        counter=0;
        int m=word.size();
        trie_pointer=root;
        while(counter<word.size()){
            if(trie_pointer->link[word[counter]-'a']==nullptr){
                trie_pointer->link[word[counter]-'a']=new trie_node();
            }
            trie_pointer->link[word[counter]-'a']->val+=val;
            trie_pointer=trie_pointer->link[word[counter]-'a'];
            counter++;
        }
        trie_pointer->isend=true;
    }
    
    /** Returns if the word is in the trie. */
    int search(string word) {
        trie_pointer=root;
        counter=0;
        while(trie_pointer!=nullptr && counter<word.size()){
            trie_pointer=trie_pointer->link[word[counter++]-'a'];
        }
        /*if(trie_pointer==nullptr) return false;
        if(trie_pointer->isend==false) return false;*/
        if(trie_pointer==nullptr) return 0;
        return trie_pointer->val;
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
class MapSum {
public:
    /** Initialize your data structure here. */
    Trie t;
    unordered_map<string,int> map;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        if(map.find(key)!=map.end()){
            int tmp=val;
            val=val-map[key];
            map[key]=tmp;
        }
        else{
            map[key]=val;
        }
        t.insert(key,val);
    }
    
    int sum(string prefix) {
        return t.search(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */