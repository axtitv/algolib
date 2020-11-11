#include <iostream>
#include <vector>

#define pb push_back

using namespace std;

vector<bool> visited;
vector<vector<int> > adj;

void dfs(int v){
    visited[v] = true;
    cout << v << ") -> (";
    for(auto a : adj[v]){
        if(visited[a]!=true){
            dfs(a);
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;

    visited = vector<bool>(n);
    adj = vector<vector<int> >(n);

    for(int i = 0;i < m;i++){
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(0);
    cout << "End" << endl;

    return 0;
}
