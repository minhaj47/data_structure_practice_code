#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;

int cnt;

void solve()
{
    int n;
    cin >> n;
    int mat[n+1][n+1];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int x;
            cin >> x;
            mat[i][j] = x;
        }
    }

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                mat[i][j] = min(mat[i][k] + mat[k][j], mat[i][j]);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }    
    
}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int t;
    cin >> t ;

    while (t--)
    {
    cnt++;
    solve();
    }
    return 0;
}