class Trie{
    public:
        int end = 0;
        Trie* node[26] = {};
        Trie(){
            for(int i=0;i<26;i++){
                node[i] = NULL;
            }
        }
};

class WordDictionary {
public:
    Trie* root = NULL;
    Trie* temp = NULL;
    WordDictionary() {
        // this section was always ment to be left empty
    }
    
    void addWord(string word) {
        
        if(root == NULL) root = new Trie();
        temp = root;
        for(char c: word){
            if(temp->node[c-'a'] == NULL){
                temp->node[c - 'a'] = new Trie();
            }
            temp = temp->node[c-'a'];
        }
        temp->end = 1;
    }
    
    bool find(string&word, int ind, Trie* root){
        if(ind >= word.size()) return (root->end == 1);
        
        else if(word[ind] == '.'){
            bool ans = false;
            for(int i=0;i<26;i++){
                if(root->node[i] != NULL)
                ans |= find(word, ind+1, root->node[i]);
                if(ans) return ans;
            }
            return ans;
        }
        else{
            if(root->node[word[ind] - 'a'] == NULL) return false;
            else return find(word, ind+1, root->node[word[ind] - 'a']);
        }
    }
    
    bool search(string word) {
        if(root == NULL) return false;
        return find(word, 0, root);
    }
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */