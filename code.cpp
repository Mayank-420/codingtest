using namespace std;
#include<bits/stdc++.h>
void bfs(vector < vector <int> > &adj, vector <int> visited, int n, int u, vector <int> &dist)
{
    queue <int> q;
    q.push(u);
    visited[u] = 1;
    vector <int> distance;
    distance.resize(n+1);
    distance[u] = 0;
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        for(int i=0;i<adj[temp].size();i++)
        {
            if(visited[adj[temp][i]] == 0)
            {
                visited[adj[temp][i]] = 1;
                distance[adj[temp][i]] = 1 + distance[temp];
                q.push(adj[temp][i]);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        dist[i] = max(dist[i],distance[i]);
    }
}
int main()
{
    int n,h,x;
    cin>>n>>h>>x;
    vector <int> hotspots;
    for(int i=0;i<h;i++)
    {
        int p;
        cin>>p;
        hotspots.push_back(p);
    }
    vector < vector <int> > adj;
    adj.resize(n+1);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector <int> visited;
    visited.resize(n+1);
    vector <int> dist;
    dist.resize(n+1);
    dist.assign(n+1,-1);
    for(int i=0;i<h;i++)
    {
        bfs(adj, visited, n, hotspots[i],dist);
    }
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        if(dist[i] <= x)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}