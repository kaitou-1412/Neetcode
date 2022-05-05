class TrieNode {
public:
    TrieNode* links[26];
    bool isEnd;
    
    TrieNode() {
        this->isEnd = false;
        for(int i=0; i<26; i++) {
            links[i] = NULL;
        }
    }
};

class Trie {
public:
    
    TrieNode* root;
    
    Trie() {
        this->root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(char c: word) {
            if(node->links[c-'a'] == NULL) {
                node->links[c-'a'] = new TrieNode();
            }
            node = node->links[c-'a'];               
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(char c: word) {
            if(node->links[c-'a']) {
                node = node->links[c-'a'];
            }
            else {
                return false;         
            }
        }
        return node->isEnd;        
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char c: prefix) {
            if(node->links[c-'a']) {
                node = node->links[c-'a'];
            }
            else {
                return false;               
            }
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