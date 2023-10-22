#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int a[N]={0, 1, 4, 2, 6, 9, 5, 3, 7, 19, 11};
int bit[N];
int n = 10;

void update(int i, int x)
{
    for(i; i<=n; i+=(i&-i)){
        bit[i]+=x;
    }
}

int sum(int i){
    int ans = 0;
    for(i; i>0; i-=(i&-i)){
        ans+=bit[i];
    }
    return ans;
}

int query(int l, int r)
{
    return sum(r)-sum(l-1);
}

int main()
{
    
    for(int i=1;i<=n; i++){
        update(i, a[i]);
    }

    cout << query(3, 5) << endl;
}