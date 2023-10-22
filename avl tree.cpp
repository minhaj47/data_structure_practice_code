#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    //int height;
    Node *lchild, *rchild;
    Node(int key)
    {
        data = key;
        //height = 1;
        lchild = rchild = NULL;
    }
}*root = NULL;


int height(Node *p){
    int x, y;
    if(p==NULL)return 0;
    x = height(p->lchild);
    y = height(p->rchild);
    return max(x+1, y+1);
}

int blFactor(Node *p)
{
    return height(p->lchild)-height(p->rchild);
}

Node *LLrotation(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;

    if(root = p)
        root = pl;
    
    return pl;
}

Node *LRrotation(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild=plr->lchild;
    p->lchild = plr->rchild;

    plr->rchild = p;
    plr->lchild = pl;

    if(root = p)
        root = plr;
    
    return root;
}

Node *RRrotation(Node *p)
{
    Node * pr = p->rchild;
    Node * prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    if(root == p)
        root = pr;

    return root;
}

Node * RInsert(Node *p, int key)
{
    if(p==NULL){
        p= new Node(key);
        return p;
    }
    if(key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else if(key > p->data)
        p->rchild = RInsert(p->rchild, key);

    //p->height = max(p->lchild->height, p->rchild->height);

    if(blFactor(p)==2 and blFactor(p->lchild)==1) // what should happen for bl factor of p->lchild = 0
        return LLrotation(p);
    if(blFactor(p)==2 and blFactor(p->lchild)==-1)
        return LRrotation(p);
    if(blFactor(p)==-2 and blFactor(p->rchild)==-1)
        return RRrotation(p);
    // if(blFactor(p)==-2 and blFactor(p->rchild)==1)
    //     return RLrotation(p);

    return p;
}

void inorder(Node *p)
{
    if(p==NULL)
        return;
    inorder(p->lchild);
    cout << p->data << " ";
    inorder(p->rchild);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    Node *temp = NULL;

    root = RInsert(root,30);
    RInsert(root,10);
    RInsert(root,20);
    //RInsert(root,1000);
    //RInsert(root,5000);
    // RInsert(root,100000);


    //Delete(root, 20);
    cout << root->data << endl;
    cout << root->rchild->data << endl;
    cout << root->lchild->data << endl;

    inorder(root);

    // temp = search(30);
    // cout << endl;

    // cout << temp->data << endl;

    return 0;
}