#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5+5;
vector<int>g[N];
int vis[N], c;
bool isCycle;

void dfs(int vertex)
{
    vis[vertex]= 1;
    
    for(auto child : g[vertex])
    {
        if(vis[child]==0) dfs(child);
        if(vis[child]==1){
            isCycle = true;
            break;
        }
       
    }
    vis[vertex]=2;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    ll n , m, cnt=0;
    cin >> m;
    for (int i = 0; i<m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    
    for (int i = 1; i<=cnt; ++i) {
        if(!vis[i]){
            dfs(i);
        }
    }
    
    if(isCycle)
        cout << "Yes\n";
    else 
        cout << "No\n";

    return 0;
}