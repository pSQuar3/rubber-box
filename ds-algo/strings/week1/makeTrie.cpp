#include <bits/stdc++.h>
#define lli long long int
#define ull unsigned long long
#define MX 100000
using std::cin;
using std::cout;
using std::cerr;
using std::floor;
using std::ceil;
using std::vector;
using std::ios_base;
using std::unordered_map;
using std::map;
using std::endl;
using std::stack;
using std::queue;
using std::max;
using std::min;
using std::deque;
using std::bitset;
using std::set;
using std::sort;
using std::hash;
using std::pair;
using std::make_pair;
using std::string;
using std::swap;
using std::hash;
int n;
string p[100];
struct Node
{
    char this_char;
    unordered_map<char,Node*> nextNodes;
    Node(char c)
    {
        this_char = c;
        cerr << "storing character ->" << c << "<- character" << endl;
    }
    bool find(char c)
    {
        return nextNodes.find(c) != nextNodes.end();
    }
};
Node makeTrie()
{
    
    //white in dark : oceanic_material
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
                cerr << "value = " << p[i][j] << " ";
                Node newNode(p[i][j]);
                q->nextNodes[p[i][j]] = &newNode;
                q = &newNode;
                cerr << "current entry = " << q->this_char << endl;
            }
        }
        cerr << endl;
    }
    cerr << "check " << trie.nextNodes['G']->this_char << endl;
    return trie;
}
void findInTrie(Node trie)
{
//    string s;
//    cin >> s;
    cerr << "entering the printing function" << endl;
    for(auto i = trie.nextNodes.begin();i != trie.nextNodes.end();i++)
    {
        //if()
        cerr << "in for  loop" << endl;
        cout << i->first << " ";
        findInTrie(*i->second);
    }
}
int ctr=0;
void graphdfs(Node node,int current)
{
    cerr << "node ->" << node.this_char <<  "<-\n";
    cerr << "current = " << current << endl;
    if(node.this_char != '$')
    {
        cerr << "entered if block" << endl;
        for(auto i = node.nextNodes.begin();i != node.nextNodes.end();i++)
        {
            ++ctr;
            cerr << "in for loop" << endl;
            cout << current << "->" << ctr << ":" << i->first << endl;
            graphdfs(*i->second,ctr);
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
    findInTrie(trie);
    graphdfs(trie,0);
    return 0;
}
