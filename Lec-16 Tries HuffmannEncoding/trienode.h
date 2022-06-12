class TrieNode{
    public:
    char data;
    TrieNode** children;
    bool isTerminal;
    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode[26];
        //Initialise the children with NULL
        for(int i=0;i<26;i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
    
};