#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5+5;
vector<ll>g[N];
map<ll, ll>mp;
vector<ll>ans;

void toposort(int n){
    queue<int>q;                   // use priority queue to make it sorted in ascending order
    for (int i = 1; i<=n; ++i) {
        if(mp[i]==0)    
            q.push(i);
        }
    while(!q.empty()){
        ll node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto child: g[node]){
            mp[child]--;
            if(!mp[child])
                q.push(child);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    ll n, m;
    
    while (1)
    {
    cin >> n >> m;
    if(!n and !m)return 0;
    for (int i = 0; i<m; ++i) {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        mp[b]++;
    }
    toposort(n);
    for(auto x: ans){
        cout << x << " ";
    }
    cout << endl;
    mp.clear();
    ans.clear();
    for (int i = 0; i<N; ++i) {
    g[i].clear();
    }
    }
    return 0;
}
