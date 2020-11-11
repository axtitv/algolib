#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

#define pb push_back

//stuff used for bfs;
queue<pair<int,int> > q;
vector<bool> visited;
vector<int> dist;
vector<vector<pair<int, int> > > adj;

void dijkstra(int n, int m){
    //code goes here;
    for (int i = 1; i <= n; i++) dist[i] = 10000;
    dist[0] = 0;
    q.push({0,0});

    while (!q.empty()) {
        int a = q.front().second; q.pop();
        
        if (visited[a]) continue;
        visited[a] = true;

        for (auto u : adj[a]) {
            int b = u.first, w = u.second;
            if (dist[a]+w < dist[b]) {
                dist[b] = dist[a]+w;
                q.push({-dist[b],b});
            }
        }
    }
}

int main(){
    //implementation of dijkstra:
    int n, m;
    cin >> n >> m;

    visited = vector<bool>(n);
    dist = vector<int>(n);
    adj = vector<vector<pair<int,int> > >(n);

    //input the node values for each edge;
    for(int i = 0;i < m;i++){
        int x, y, w;
        cin >> x >> y >> w;

        adj[x].pb({y, w});
        adj[y].pb({x, w});
    }

    dijkstra(n, m);
    for(int i = 0; i < n;i++){
        cout << dist[i] << " ";
    }
    cout << endl;
    

    return 0;
}
