#include <iostream>
#include <queue>

using namespace std;

#define pb push_back

//stuff used for bfs;
queue<int> q;
vector<bool> visited;
vector<int> dist;
vector<vector<int> > adj;

//Works, I think!
void bfs(){
    //root of bfs is node 0;
    visited[0] = true;
    dist[0] = 0;
    q.push(0);
    
    cout << 0 << "->";

    //do the shit;
    while(!q.empty()){
        int s = q.front();
        q.pop();

        for(auto a : adj[s]){
            if(visited[a]) continue;
            visited[a] = true;
            cout << a << "->";

            dist[a] = dist[s]+1;
            q.push(a);
        }
    }
    cout << "End" << endl;
}

int main(){
    //inp the number of nodes & edges;
    int n, m;
    cin >> n >> m;

    visited = vector<bool>(n);
    dist = vector<int>(n);
    adj = vector<vector<int> >(n);

    //input the node values for each edge;
    for(int i = 0;i < m;i++){
        int x, y;
        cin >> x >> y;

        adj[x].pb(y);
        adj[y].pb(x);
    }

    bfs();
    for(int i = 0; i < n;i++){
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}
