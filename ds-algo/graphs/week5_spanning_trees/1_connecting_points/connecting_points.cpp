#include <bits/stdc++.h>
using namespace std;
/*struct Story
{
    int ind;
    int x,y;
};*/
using std::map;
/*
struct MinHeap
{
    struct Cont
    {
        double dist;
        int indx;
    };
    vector<Cont> a;
    map<MinHeap::Cont,int> ni;
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
    bool comp_with_second(Cont x1,Cont x2)
    {
        if(x1.dist > x2.dist)
            return true;
        return false;
    }
    bool comp_with_second(int x1,int x2)
    {
        if(a[x1].dist > a[x2].dist)
            return true;
        return false;
    }
    void siftUp(int i)
    {
        while(i > 0 && comp_with_second(a[parent(i)],a[i]))
        {
            ni[a[i]] = parent(i);
            swap(a[parent(i)],a[i]);
            i = parent(i);
        }
    }
    void siftDown(int i)
    {
        int nextIndx = i;
        int l = left(i);
        int r = right(i);
        if(l < a.size() && comp_with_second(a[nextIndx],a[l]))
            nextIndx = l;
        if(r < a.size() && comp_with_second(a[nextIndx],a[r]))
            nextIndx = r;
        if(nextIndx != i)
        {
            ni[a[i]] = nextIndx;
            swap(a[nextIndx],a[i]);
            siftDown(nextIndx);
        }
    }
    MinHeap::Cont getRoot()
    {
        Cont ob = a[0];
        a[0] = a[a.size()-1];
        a.pop_back();
        siftDown(0);
        return ob;
    }
    void simpleAdd(double d,int i)
    {
        Cont ob;
        ob.dist = d;
        ob.indx = i;
        ni[ob] = a.size();
        a.push_back(ob);
    }
    void build()
    {
        for(int i=a.size()/2-1;i>=0;i--)
            siftDown(i);
    }
    void insert(Cont ob)
    {
        a.push_back(ob);
        siftUp(a.size()-1);
    }
    void insert(double d,int g)
    {
        Cont e;
        e.dist = d;
        e.indx = g;
        insert(e);
    }
    void editValue(Cont x, double d, int ind)
    {
        int i = ni[x];
        Cont g = a[i];
        a[i].dist = d;
        a[i].indx = ind;
        if(comp_with_second(g,a[i]))
            siftUp(i);
        else
            siftDown(i);
    }
};
*/


double distance(int x1,int x2,int y1,int y2)
{
    return sqrt(pow(x2-x1,2) + pow(y2-y1,2));
}
double minimum_distance(vector<int> x, vector<int> y)
{
    auto cmp = [](pair<double, int> left, pair<double, int> right)
    {
        //comparison function
        return (((left.first) > (right.first)) || (((left.first) == (right.first)) && ((left.second) > (right.second))));
    };
	std::priority_queue<pair<double, int>, std::vector<pair<double, int>>, decltype(cmp)> priq(cmp);


    int n = x.size();
    double cost[n];
    double result = 0.000000;
    for(int i=0;i<n;i++)
        cost[i] = INT_MAX;
    cost[0] = 0;
    pair<double,int> g = make_pair(0.0,0);
    priq.push(g);
    vector<bool> vist(n,false);
    while(!priq.empty())
    {
        g = priq.top();
        priq.pop();
        if(vist[g.second] == false)
        {
            for(int i = 0;i<n;i++)
            {
                if(i != g.second && vist[i] == false)
                {
                    double dst = distance(x[i],x[g.second],y[i],y[g.second]);
                    if(cost[i] > dst)
                    {
                        cost[i] = dst;
                        priq.push(make_pair(cost[i],i));
                    }
                }
            }
            vist[g.second] = true;
        }
    }
    for(int i=0;i<n;i++)
        result += cost[i];
    return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
