#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;

int cnt;


void solve(int n)
{
    int m;
    vector<int> adj[n+1];
    cin >> m;

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    vector<int> color(n+1, -1);
    bool isBipartite = true;

    q.push(0);

    while(!q.empty()){
        int cur_node = q.front();
        q.pop();

        for(auto it: adj[cur_node]){
            if(color[it] == -1){
                color[it] = 1 - color[cur_node];
                q.push(it);
            }
            else if(color[it] == color[cur_node]){
                isBipartite = false;
                break;
            }
        }
    }
    if(isBipartite) cout << "BICOLORABLE." << endl;
    else cout << "NOT BICOLORABLE." << endl;
    
}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int t;
    cin >> t;

    while (t)
    {

    solve(t);

    cin >> t;

    }
    return 0;
}