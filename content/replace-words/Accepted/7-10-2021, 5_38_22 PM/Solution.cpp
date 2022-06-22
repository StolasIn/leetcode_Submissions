// https://leetcode.com/problems/replace-words

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
    void insert(string& word) {
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
    string search(string& word) {
        trie_pointer=root;
        counter=0;
        string str;
        while(trie_pointer!=nullptr && counter<word.size()){
            if(trie_pointer->isend==true){
                return str;
            }
            str+=word[counter];
            trie_pointer=trie_pointer->link[word[counter++]-'a'];
        }
        /*if(trie_pointer==nullptr) return false;
        if(trie_pointer->isend==false) return false;
        return true;*/
        return word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string& prefix) {
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
class Solution {
public:
    vector<string> split(const string& str, const string& delim) {
        vector<string> res;
        if("" == str) return res;
        char * strs = new char[str.length() + 1] ;
        strcpy(strs, str.c_str()); 
        char * d = new char[delim.length() + 1];
        strcpy(d, delim.c_str());
        char *p = strtok(strs, d);
        while(p) {
            string s = p;
            res.push_back(s);
            p = strtok(NULL, d);
        }
        return res;
    }
    string replaceWords(vector<string>& d, string& s) {
        Trie t;
        for(int i=0;i<d.size();i++){
            t.insert(d[i]);
        }
        string ans="";
        vector<string> tok;
        string dim=" ";
        tok=split(s,dim);
        for(int i=0;i<tok.size();i++){
            ans+=t.search(tok[i]);
            if(i!=tok.size()-1) ans+=" ";
        }
        return ans;
    }
};