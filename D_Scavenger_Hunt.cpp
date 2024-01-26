#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;

int cnt;

void solve()
{
    int n;
    cin  >> n;

    map<string, string> route;
    map<string, int> isFirst;

    for(int i=0; i<n-1; i++){
        string a, b;
        cin >> a >> b;
        route[a] = b;
        isFirst[a]++;
        isFirst[b]++;
        if(isFirst[b] == 1){
            route[b] = "null#";
        }
    }

    cout << "Scenario #" << cnt << ":" << endl;
    string cur;

    for(auto it: isFirst){
        if(it.second == 1 and route[it.first] != "null#"){
            cur = it.first;
            break;
        }
    }

    while(cur != "null#"){
        cout << cur << endl;
        cur = route[cur];
    }
    cout << endl;
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