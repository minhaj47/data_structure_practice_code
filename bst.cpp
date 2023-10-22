#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node *lchild;
    int data;
    Node *rchild;
}*root=NULL;

void insert(int key){
    Node *t = root;
    Node *r, *p;
    if(root==NULL){
        p = new Node;
        p->data = key;
        p->rchild= p->lchild =NULL;
        root = p;
        return;
    } 
    while(t!=NULL){
        r = t;
        if(key>t->data)
            t=t->rchild;
        else if(key<t->data)
            t= t->lchild;
        else 
            return;  
    }
    p = new Node;
    p->data = key;
    p->rchild= p->lchild =NULL;
    if(key<r->data)
        r->lchild = p;
    else 
        r->rchild = p;
}

Node * rInsert(Node *p, int key){
    if(key < p->data)
        p->lchild = rInsert(p->lchild, key);
    else 
        p->rchild = rInsert(p->rchild, key);
    return p;
}

void inorder(Node *p)
{
    if(p){
        inorder(p->lchild);
        cout << p->data << " ";
        inorder(p->rchild);
    }
}

Node * search(int key){
    Node *t = root;

    while(t!= NULL){
        if(key==t->data)
            return t;
        else if (key< t->data)
            t=t->lchild;
        else 
            t= t->rchild;
    }
    return NULL;
}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int i, j;
    Node *temp = NULL;

    
    insert(10);
    insert(40);
    insert(5);
    insert(30);
    insert(60);
    insert(20);

    inorder(root);

    temp = search(30);
    cout << endl <<  temp->data << endl;
    

    return 0;
}