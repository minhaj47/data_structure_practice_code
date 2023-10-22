#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5+5;
vector<ll>g[N];
int par[N];
bool vis[N];
bool loopExists;
bool flag;
vector<vector<int>>cc;
vector<int>current_cc;

void dfs(int vertex, int par)
{
    vis[vertex]= true;
    current_cc.push_back(vertex);

    for(auto child : g[vertex])
    {
        if(vis[child] and child == par)continue;
        if(vis[child]){
            loopExists = true;
            continue;
        }
        dfs(child, vertex);
    }
}

int main()
{
    ll n , m, cnt=0; // cnt = number of connected component
    cin >> n >> m;
    for (int i = 0; i<m; ++i) {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i<=n; ++i) {
        if(vis[i])continue;
        cnt++;
        current_cc.clear();
        dfs(i, 0);
        cc.push_back(current_cc);
    }
    cout << cnt << endl; // number of connected component

    for (auto c_cc: cc) {
        for(int x: c_cc){
            cout << x << " ";
        }
        cout << endl;
    }
    if(loopExists)cout << "YEs\n";
    else cout << "NO\n"; 
        
}

