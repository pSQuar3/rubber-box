#include <bits/stdc++.h>
#include <ctime>
#define lli long long int
#define ull unsigned long long
#define MX 100000
using std::cin;
using std::cout;
using std::cerr;
using std::ios_base;
using std::unordered_map;
using std::endl;
using std::string;
int n;
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
Node makeTrie()
{
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
    return trie;
}
int ctr=0;
void graphdfs(Node node,int current)
{
    if(node.this_char != '$')
    {
        for(auto i = node.nextNodes.begin();i != node.nextNodes.end();i++)
        {
            if(i->first != '$')
            {
                ++ctr;
                cout << current << "->" << ctr << ":" << i->first << endl;
                graphdfs(*i->second,ctr);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> p[i];
        p[i].push_back('$');
    }
    Node trie = makeTrie();
    graphdfs(trie,0);
    return 0;
}
