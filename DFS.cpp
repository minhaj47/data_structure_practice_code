#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

vector<int> g[N];
bool vist[N];

void dfs(int vertex){
    vist[vertex]= true;
    cout << vertex << endl;

    for(int child: g[vertex]){
        cout << "par:" << vertex << " child:" << child << endl;
        if(vist[child])continue;
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
    dfs(3);

    return 0;
}