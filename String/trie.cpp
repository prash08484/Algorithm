 
 struct Node {  // Node structure for Trie
    Node* links[26]; 
    bool flag = false; 
    bool has(char ch) { return links[ch - 'a']!=nullptr; }
    void put(char ch,Node* node){ links[ch - 'a'] = node; } 
    Node* get(char ch) { return links[ch - 'a']; } 
    void setEnd() { flag = true; } 
    bool isEnd() { return flag; }
};

// Trie class
class Trie {
 public:

    Node* root;
    Trie() { root = new Node(); }   

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i<word.size(); i++) {
            if (!node->has(word[i])) 
                node->put(word[i], new Node());  
            node = node->get(word[i]);
        } 
        node->setEnd();
    }

    bool search(string word) {
        Node* node = root;
        for (int i = 0; i<word.size(); i++) {
            if (!node->has(word[i])) 
                return false; 
            node = node->get(word[i]);
        } 
        return node->isEnd();
    }
 
    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i<prefix.size(); i++) {
            if (!node->has(prefix[i])) 
                return false; 
            node = node->get(prefix[i]);
        } 
        return true; 
    }

};
