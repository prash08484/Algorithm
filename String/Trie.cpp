
class Trie{

    struct Node{
        Node* next[26];
        bool flag;
        Node(){
            flag=0;
            for(int i=0; i<26; i++)
                next[i]=nullptr;
        }
    }; 

    public:
    
    Node* root; 

    Trie(){
        root=new Node();
    }

    // insert a new word
    void insertWord(string &word){
        Node* tRoot=root; 
        for(char c: word){
            if(tRoot->next[c-'a']==nullptr){
                tRoot->next[c-'a']=new Node();
            }
            tRoot=tRoot->next[c-'a'];
        }
        tRoot->flag=1;
    }

    // serach a word
    bool searchWord(string &word){
        Node* tRoot=root; 
        for(char c: word){
            if(tRoot->next[c-'a']==nullptr) return 0;
            tRoot=tRoot->next[c-'a'];
        }
        return tRoot->flag; 
    }
    
    // prefix search
    bool prefixSearch(string &word){
        Node* tRoot=root;
        for(char c: word){
            if(tRoot->next[c-'a']==nullptr) return 0;
            tRoot=tRoot->next[c-'a'];
        }
        return 1; 
    }

}; 
 
