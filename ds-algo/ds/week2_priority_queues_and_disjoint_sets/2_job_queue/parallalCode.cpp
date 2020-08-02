#include <iostream>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::ios_base;
using std::pair;
using std::priority_queue;
using std::queue;
using std::vector;

#define For(i,a,n) for (int i = a; i < n; i++)
typedef pair<int,int> PII;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n,m,t,val;
    PII p;
    priority_queue<PII> pq;
    queue<int> q;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >> t;
        q.push(t);
    }
    for(int i=0;i<n;i++)
        pq.push({0, -i});
    while(!q.empty())
    {
        p = pq.top();
        pq.pop();
        cout << -p.second << " " << -p.first << endl;
        val = q.front();
        q.pop();
        pq.push({ -val + p.first, p.second });
    }

    return 0;
}
