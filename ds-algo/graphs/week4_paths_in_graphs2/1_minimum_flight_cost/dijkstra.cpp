#include <bits/stdc++.h>

using std::vector;
using std::unordered_map;
using std::pair;
using std::priority_queue;
using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::swap;
using std::make_pair;
using std::cerr;
int n,m;

using std::hash;
using std::pair;
using std::make_pair;
struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};
//currently mapped s: pair<any dt,any dt>->bool with custom hash function as hash_pair
//change data types of pair and mapped value accordingly
unordered_map<pair<int,int>,long long,hash_pair> mp;

struct CustomHeap
{
    struct Data
    {
        long long distvalue;//  no over-write in case of repeating key
        int nextnode;
    };
    vector<Data> a;
    //bool type;
    unordered_map<int,int> node_to_index;
    /*CustomHeap(bool tp)
    {
        type = tp;
        //true == min heap
        //false == max heap
    }*/
    bool first_is_more(Data p,Data q)
    {
        if(p.distvalue > q.distvalue)
            return true;
        return false;

    }
    int parent(int i)
    {
        return floor((i-1)/2);
    }
    int left(int i)
    {
        return 2*i + 1;
    }
    int right(int i)
    {
        return 2*i+2;
    }
    void siftup(int i)
    {
        while(i > 0 && first_is_more(a[parent(i)],a[i]))
        {
            //cerr << "sifting up:- i = " << i << endl;
            node_to_index[a[i].nextnode] = parent(i);
            swap(a[parent(i)],a[i]);
            i = parent(i);
        }
    }
    void siftDown(int i)
    {
        //cerr << "executing siftDown operation = " << i << endl;
        int nxt = i;
        int l = left(i),r = right(i);
        if(l < (int)a.size() && first_is_more(a[nxt],a[l]))
            nxt = l;
        if(r < (int)a.size() && first_is_more(a[nxt],a[r]))
            nxt = r;
        if(nxt != i)
        {
            //cerr << "swapping " << i << " with " << nxt << endl;
            node_to_index[a[i].nextnode] = nxt;
            swap(a[i],a[nxt]);
            siftDown(nxt);
        }
    }
    Data initialiseNode(long long distValue, int node)
    {
        Data ob;
        ob.distvalue = distValue;
        ob.nextnode = node;
        node_to_index[node] = 0;
        //cerr << "initialising dist = " << distValue << " node = " << node << endl;
        return ob;
    }
    void updatePosition(int v,long long distV)
    {
        int y = node_to_index[v];
        Data gh = a[y];
        a[y].nextnode = v;
        a[y].distvalue = distV;
        if(first_is_more(gh,a[y]))
            siftup(y);
        else
            siftDown(y);
    }
    void editValue(int i,Data dt)
    {
        Data e = a[i];
        a[i] = dt;
        if(first_is_more(e,dt))
            siftup(i);
        else
            siftDown(i);
    }
    void push_to_heap(Data d)
    {
        a.push_back(d);
        node_to_index[d.nextnode] = a.size()-1;
        siftup(a.size()-1);
    }
    Data extract_root()
    {
        Data ob;
        if(a.empty())
            cerr << "Heap is empty" << endl;
        else
        {
            ob = a[0];
            a[0] = a[a.size()-1];
            a.pop_back();
            siftDown(0);
        }
        return ob;
    }
    void buildHeap()
    {
        for(int i=a.size()/2-1;i>=0;i--)
            siftDown(i);
//        cerr << "built heap" << endl;
    }
    void simplePush(Data ob)
    {
        node_to_index[ob.nextnode] = a.size();
        a.push_back(ob);
    }
    bool empty()
    {
        return a.size() == 0;
    }
};
unordered_map<int,vector<int>> adj;
unordered_map<int,vector<long long>> cost;

long long distance(int s, int t)
{
    //write your code her
    long long dist[n];
    //long long prev[n];
    priority_queue<pair<long long,int>> pmp;
    CustomHeap heap;
    for(int i=0;i<n;i++)
    {
        dist[i] = INT_MAX;
        //prev[i] = 0;
    }
    
    dist[s] = 0;
    //for(int i=0;i<(int)adj[s].size(); i++)
    //    dist[adj[s][i]] = cost[s][i];
    /*
    for(int i = 0;i < (int)adj.size();i++)
    {
        for(int j = 0;j < (int)adj[i].size();j++)
        {
            pmp.push(make_pair(cost[i][j],adj[i][j]));
        }
    }
    */
    for(int i=0;i<n;i++)
    {
        CustomHeap::Data newnode = heap.initialiseNode(dist[i],i);
        heap.simplePush(newnode);
    }
//    cerr << "building the heap" << endl;
    heap.buildHeap();
    while(!heap.empty())
    {
        CustomHeap::Data q = heap.extract_root();
//        cerr << "extracted minimum: distance = " << q.distvalue << " node = " << q.nextnode << endl;
        int u = q.nextnode;
        for(int i = 0;i < (int)adj[u].size();i++)
        {
            int v = adj[u][i];
//            cerr << "checking node: " << v << endl;
            if(dist[v] > dist[u] + cost[u][i])
            {
                dist[v] = dist[u] + cost[u][i];
                //prev[adj[u.second][i]] = u.second;
                //pair<long long,int> k = make_pair(dist[v],v);
                //CustomHeap::Data tmp = heap.initialiseNode(dist[v],v);
                //heap.push_to_heap(tmp);
                heap.updatePosition(v,dist[v]);
            }
        }
    }
    if(dist[t] != INT_MAX)
        return dist[t];
    return -1;
}

int main()
{
    std::cin >> n >> m;
    //vector<vector<int> > adj(n, vector<int>());
    //vector<vector<int> > cost(n, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int x, y;
        long long w;
        std::cin >> x >> y >> w;
        adj[x - 1].push_back(y - 1);
        cost[x - 1].push_back(w);
        mp[make_pair(x,y)] = w;
    }
    int s, t;
    std::cin >> s >> t;
    s--;
    t--;
    if(m > 0)
        std::cout << distance(s, t) << endl;
    else
        std::cout << -1 << endl;
    return 0;
}
