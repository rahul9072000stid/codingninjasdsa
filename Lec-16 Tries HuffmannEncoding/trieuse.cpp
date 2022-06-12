// { Driver Code Starts
// Initial function template for C++

#include <iostream>
#include<string>
#include<algorithm>

using namespace std;

// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

// trie node
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void) {
    struct TrieNode *pNode = NULL;

    pNode = (struct TrieNode *) malloc(sizeof(struct TrieNode));

    if (pNode) {
        int i;

        pNode->isLeaf = false;

        for (i = 0; i < ALPHABET_SIZE; i++) pNode->children[i] = NULL;
    }

    return pNode;
}

void insert(struct TrieNode *, string);

bool search(struct TrieNode *, string);

// Driver
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        // Input keys (use only 'a' through 'z' and lower case)
        int n;
        cin >> n;
        string keys[n];

        for (int i = 0; i < n; i++) {
            cin >> keys[i];
        }

        struct TrieNode *root = getNode();
        // Construct trie
        for (int i = 0; i < n; i++) insert(root, keys[i]);

        string abc;

        cin >> abc;
        // Search for different keys

        if (search(root, abc))
            cout << "1\n";
        else
            cout << "0\n";
        // char ex;
        // cin >> ex;
        // cout << ex << "\n";
    }
    return 0;
}// } Driver Code Ends


// User function template for C++



//Function to insert string into TRIE.
void insert(struct TrieNode *root, string key)
{
    //base case
    if(key.size()==1)
    {
        //add the terminal to true
    }
    //i jus have to insert the current character and call the rest on the recursion
    int idx = key[0]-'a';
    //just check the root has the child of the key[0] or not
    TrieNode* child;
    if(root->children[idx]!=NULL)
    {
        //dont need to make the new 
        child = root->children[idx];
    }
    else
    {
        //How to create new trienode 
        child = new TrieNode(idx);
    }
    //insert recursively the new characters
    insert(child,key.substr(1));
}

//Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string key) 
{
    //search on the trie
    //base case
    if(key.size()==0)
    {
        return true;
    }
    //Now Check the current character
    //compare with the index 
    int idx = key[0]-'a';
    TrieNode* child ;
    if(root->children[idx]!=NULL)
    {
        child = root->children[idx];
    }
    else
    {
        //Current character does not exisr
        return false;
    }
    //Now call the recursion for further checks
    return search(child,key.substr(1));
}