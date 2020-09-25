#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::ios_base;
using std::unordered_map;
using std::endl;
using std::string;
int n;
string text;
string p[100];
struct Node
{
    char this_char;
    unordered_map<char,Node*> nextNodes;
    Node(char c)
    {
        this_char = c;
    }
    bool find(char c)
    {
        return nextNodes.find(c) != nextNodes.end();
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> text;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> p[i];
        p[i].push_back('$');
    }
    Node trie(' ');
    for(int i=0;i<n;i++)
    {
        Node *q = &trie;
        for(int j=0;j<(int)p[i].size();j++)
        {
            if(q->find(p[i][j]))
                q = q->nextNodes[p[i][j]];
            else
            {
                Node *newNode = new Node(p[i][j]);
                q->nextNodes.insert({p[i][j], newNode});
                q = q->nextNodes[p[i][j]];
            }
        }
    }
    for(int i=0;i<(int)text.size();i++)
    {
        
        if(trie.find(text[i]))
        {
            Node *q = trie.nextNodes[text[i]];
            int j = i+1;
            while(j < (int)text.size() && q->find(text[j]))
            {
                q = q->nextNodes[text[j]];
                j++;
            }
            if(q->find('$'))
                cout << i << " ";
        }
    }
    return 0;
}
