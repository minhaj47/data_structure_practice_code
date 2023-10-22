#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;

int parent[N];
int Size[N];

void make(int v){
    parent[v]= v;
    Size[v]= 1;

}
int find(int v){
    if(parent[v]==v)
        return v;
    return parent[v] = find(parent[v]);
}
void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(Size[a] < Size[b]){
        swap(a, b);
    }
    if(a==b)return;
    parent[b] = a;
    Size[a]+=Size[b];
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        make(i);
    }
    while(q--){
        int a,b;
        cin >> a >> b;
        Union(a,b);
    }
    int cc = 0;

    for(int i= 1; i<=n; i++){
        if(find(i)==i)cc++;
    }
    cout << cc << endl;
    
    return 0;
}