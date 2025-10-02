class TrieNode
{
public:
    char data;
    unordered_map<char, TrieNode *> children;
    bool isterminal;

    TrieNode(char data)
    {
        this->data = data;
        isterminal = false;
    }
};
void insertIntoTrie(TrieNode *root, string word)
{
    if (word.length() == 0)
    {
        root->isterminal = true;
        return;
    }

    char ch = word[0];
    TrieNode *child;

    if (root->children.count(ch) == 1)
    {
        child = root->children[ch];
    }
    else
    {
        child = new TrieNode(ch);
        root->children[ch] = child;
    }
    insertIntoTrie(child, word.substr(1));
}
void findlcp(TrieNode*root,string&ans){
    if(root->isterminal){
        return;
    }
    TrieNode*child;
    if(root->children.size()==1){
        for(auto i:root->children){
            ans.push_back(i.first);
            child=i.second;
        }
    }
    else    return;

    findlcp(child,ans);
}
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        TrieNode*root=new TrieNode('-');
        for(auto word:strs){
            insertIntoTrie(root,word);
        }

        string ans="";
        findlcp(root,ans);
        return ans;
    }
};