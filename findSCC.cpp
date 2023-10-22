#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 1e5+10;
vector<int>g[N];
vector<int>r[N];
bool vis[N];
stack<int>st;

void dfs1(int vertex){
    vis[vertex]= true;
    for(auto child: g[vertex]){
        if(vis[child])continue;
        dfs1(child);
    }
    //cout << vertex << " ";
    st.push(vertex);
}
void dfs2(int vertex){
    cout << vertex << " ";
    vis[vertex]= true;
    for(auto child: r[vertex]){
        if(vis[child])continue;
        dfs2(child);
    }
    
    //st.push(vertex);
}

int findSCC(int n)
{
    int cnt=0;
    for (int i = 1; i<=n; ++i) {
        if(vis[i])continue;
        dfs1(i);
    }
    
    memset(vis, false, sizeof(vis));

    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!vis[node]){
            cnt++;
            dfs2(node);
        }
        cout << "\n";
    }
    
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i<m; ++i) {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        r[b].push_back(a);
    }
    cout << findSCC(n) << endl;

    return 0;
}