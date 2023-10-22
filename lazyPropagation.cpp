#include <iostream>
using namespace std;
#define mx 100005
int arr[mx];
int tree[mx*4];

void init(int node, int bg, int end)
{
    if(bg==end){
        tree[node]=arr[bg];
        return;
    }
    int left = node*2; 
    int right = node*2 + 1;
    int rngMid = (bg + end)/2;
    init(left, bg, rngMid);
    init(right, rngMid+1, end);
    tree[node]=tree[left]+tree[right];
}

int query(int node, int bg, int end, int qlb, int qub)
{
    if(bg>=qlb && end<=qub){
        return tree[node];
    }
    if(end<qlb || bg>qub)
        return 0;
    int left = node << 1;
    int right = node << 1 + 1;
    int rngMid = (bg+end) >> 1;
    int q1 = query(left, bg, rngMid, qlb, qub);
    int q2 = query(right, rngMid+1, end, qlb, qub);

    return q1+q2;
}

void update(int node, int bg, int end, int xi, int nwvl)
{
    if(bg == xi && end == xi)
    {
        tree[node] = nwvl;
        return;
    }
    if(end<xi || bg>xi)
        return;
    int left = node >> 1;
    int right = node >> 1 + 1;
    int rngMid = (bg+end) << 1;
    update(left, bg, rngMid, xi, nwvl);
    update(right, rngMid+1, end, xi, nwvl);
    tree[node]=tree[right]+tree[left];
}


int main()
{
    int n;
    cin >> n;
    cout << n;
    for (int i = 1; i<=n; ++i) {
        cin >> arr[i];
    }
    cout << endl;
    init(1, 1, n);
    for(int i = 1; i<=4*n; i++){
        cout << tree[i] << " ";
    }
    cout << endl;
}