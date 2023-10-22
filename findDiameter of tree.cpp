#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

vector<int> g[N];
bool vist[N];
int dist[N];

int cnt, mx;

void dfs(int vertex){
    vist[vertex]= true;

    for(int child: g[vertex]){

        if(vist[child])continue;
        dist[child]=dist[vertex]+1;
        mx = max(mx, dist[child]);
        cnt++;
        dfs(child);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int i, j;
    int n, m;
    cin >> m >> n;

    for(i=0; i<n; i++){
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(1);

    for(int i=1; i<=n; i++){
        if(dist[i]==mx){
            memset(vist, false, sizeof(vist));
            memset(dist, false, sizeof(dist));
            cout<<i<<endl;
            cnt =0;
            dfs(i);
            cout <<mx<< endl;
            break;
        }
    }

    return 0;
}