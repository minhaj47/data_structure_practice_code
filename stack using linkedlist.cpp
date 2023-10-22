#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node{

    int data;
    Node *next;
}*top = NULL;

void push(int x)
{
    Node *t = new Node;
    if(!t){
        cout << "Overflow\n";
        return;
    }
    t->data = x;
    t->next = top;
    top = t; 
}

int pop()
{
    if(!top){
        cout << "The stack is empty\n";
        return -1;
    }
    Node *q;
    q=top;
    top=top->next;
    int x= q->data;
    delete q;
    return x;
}
int peek(int pos)
{
    Node *p = top;
    for(int i=1; p && i<pos; i++){
        p=p->next;
    }
    if(p) return p->data;
    return -1;
}
int stackTop()
{
    if(top)return top->data;
    return -1;
}
int isEmpty()
{
    return top?0:1;
}
int isFull()
{
    Node *t;
    t = new Node;
    
    int r= t?0:1;
    delete t;
    return r;
}
void display(){
    for(Node *i= top; i; i=i->next){
        cout << i->data<< " ";
    } 
    cout << endl;
}

int main()
{

    cout << pop()<< endl;
    display();
    isEmpty()?cout << "Empty" << endl:cout << "not empty\n";
    push(3);
    push(2);
    isEmpty()?cout << "Empty" << endl:cout << "not empty\n";
    push(7);
    push(19);
    cout << "index 2 :" << peek(2) << endl;
    cout << "index 4 :" << peek(190) << endl;
    push(33);
    isFull()?cout << "Full\n":cout << "not Full\n";
    display();
    cout << stackTop()<< endl;
    cout << pop()<< endl;
    display();
}