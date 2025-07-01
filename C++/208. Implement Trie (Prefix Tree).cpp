class Trie {

    private:
        Trie* children[26];
        bool isEndOfWord;
    public:
        Trie() {
            isEndOfWord=false;
            for (int i=0;i<26;i++)
            {
                children[i]=nullptr;
            }
        }
        
        void insert(string word) {
            Trie* node=this;
            for (char c: word)
            {
                int index=c-'a';
                if(!node->children[index])
                    node->children[index]=new Trie();
                node=node->children[index];
            }
            node->isEndOfWord=true;
        }
        
        bool search(string word) {
            Trie* node=this;
            for (char c:word)
            {
                int index=c-'a';
                if(!node->children[index])
                   return false;
                node=node->children[index];
            }
    
            return node->isEndOfWord; // true
            
        }
        
        bool startsWith(string prefix) {
             Trie* node=this;
            for (char c:prefix)
            {
                int index=c-'a';
                if(!node->children[index])
                   return false;
                node=node->children[index];
            }
    
            return true; // true
        }
    };
    
    /**
     * Your Trie object will be instantiated and called as such:
     * Trie* obj = new Trie();
     * obj->insert(word);
     * bool param_2 = obj->search(word);
     * bool param_3 = obj->startsWith(prefix);
     */