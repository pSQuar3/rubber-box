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
//        cerr << "storing character ->" << c << "<- character" << endl;
    }
    void insertChars(char ch)
    {

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
//        cerr << "Node= " << (long long)q << endl;
        for(int j=0;j<(int)p[i].size();j++)
        {
            if(q->find(p[i][j]))
                q = q->nextNodes[p[i][j]];
            else
            {
//                cerr << "character value = " << p[i][j] << " ";
                Node *newNode = new Node(p[i][j]);
//                q->nextNodes[p[i][j]] = &newNode;
//                q = q->nextNodes[p[i][j]];
                q->nextNodes.insert({p[i][j], newNode});
                q = q->nextNodes[p[i][j]];
//                cerr << "check top = " << trie.nextNodes['A']->this_char << endl;
//                cerr << "current entry = " << q->this_char << endl;
            }
//            cerr << "Node = " << (long long)q << endl;
        }
//        cerr << endl;
    }
//    cerr << "end check " << trie.nextNodes['A']->this_char << endl;
    return trie;
}
int ctr=0;
void graphdfs(Node node,int current)
{
//    cerr << "node ->" << node.this_char <<  "<-\n";
//    cerr << "current = " << current << endl;
    //TODO: Change this procedure and modify dfs
    if(node.this_char != '$')
    {
//        cerr << "entered if block" << endl;
        for(auto i = node.nextNodes.begin();i != node.nextNodes.end();i++)
        {
            ++ctr;
//            cerr << "in for loop" << endl;
            if(i->first != '$')
            {
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
//    findInTrie(trie);
    graphdfs(trie,0);
    return 0;
}
