#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

vector<int> g[N];
bool vist[N];
int level[N];


void bfs(int vertex){
    queue<int>q;
    q.push(vertex);
    vist[vertex]= true;
    //cout << vertex << endl;

    while(!q.empty()){
        int cur_v= q.front();
        q.pop();
        cout << cur_v << endl;
        for(int child: g[cur_v]){
            if(!vist[child]){
                q.push(child);
                vist[child]=true;
                level[child]= level[cur_v]+ 1;
                cout << "lev: " << level[child] << " " << "par:" << cur_v << " child:" << child << endl;
            }
            
        }
    
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
    bfs(1);

    return 0;
}