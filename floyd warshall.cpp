#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 510;
const ll inf = 1e9+10;

ll dist[N][N];
int level[N];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=n; ++j) {
            if(i==j)dist[i][j]=0;
            else dist[i][j]= inf;
        }
    }
    for(int i=0; i<m; i++){
        ll v1, v2, w;
        cin >> v1 >> v2 >> w;
        dist[v1][v2] = w;
    }
    for (int k=1; k<=n; ++k)
        for (int i = 1; i<=n; ++i)
            for(int j = 1; j<=n; ++j)
                if(dist[i][k]!=inf and dist[k][j]!=inf)
                    dist[i][j]= min(dist[i][j], dist[i][k]+dist[k][j]);

    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=n; ++j) {
            if(dist[i][j]==inf)cout << "I "; 
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}