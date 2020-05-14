class Trie {
public:
    /** Initialize your data structure here. */
    Trie* cnt[26];
    bool ends;
    Trie() {
        for(int i = 0 ; i < 26 ; i++) cnt[i]=NULL;
        ends = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        //map < char , Trie * > ok=this->sd;
        Trie * tmp = this;
        //Trie * last;
        for(auto i : word){
            //Trie* tmp;
            //cout << i << "\n";
            if(tmp->cnt[i-'a'] == NULL) tmp->cnt[i-'a'] = new Trie(); 
            tmp = tmp->cnt[i-'a'];
           // cout << tmp->ends << "\n";
        }
        tmp->ends = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* tmp = this;
       // cout << "\n";
        for(auto i : word) {
          //  cout << i << "++\n";
            if(tmp->cnt[i-'a'] == NULL) return false;
            tmp = tmp->cnt[i-'a'];
        }
        
        if(tmp->ends) return true;
        else return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* tmp = this;
        for(auto i : prefix) {
            //cout << i << "\n";
            if(tmp->cnt[i-'a'] == NULL) return false;
            tmp = tmp->cnt[i-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
