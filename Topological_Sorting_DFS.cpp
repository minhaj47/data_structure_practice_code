#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;

int cnt;
int vis[N];
vector<int> adj[N];
vector<int> topo;
stack<int>st;

int isCycle = false;

void dfs(int vertex)
{
    vis[vertex] = 1;

    for(auto it: adj[vertex]){
        if(vis[it] == 0){
            dfs(it);
        }
        else if(vis[it] == 1){
            isCycle = true;
            break;
        }
    }

    vis[vertex] = 2;
    st.push(vertex);
    
}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for(int i=n; i; i--){
        if(!vis[i]){
            dfs(i);
        }
    }

    while(!st.empty()){
        topo.push_back(st.top());
        st.pop();
    }

    

    if(isCycle){
        cout << "Sandro fails." << endl;
    }
    else{
        for(auto it: topo){
            cout << it << " ";
        }
    }

    return 0;
} 