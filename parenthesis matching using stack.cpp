#include <iostream>
#include <bits/stdc++.h>
#include <stack>
#include <cstring>
#include <vector>
using namespace std;

struct Node{
    char data;
    Node *next;
}*top = NULL;

vector<int>v;

void push(char x)
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

char pop()
{
    if(!top){
        cout << "The stack is empty\n";
        return -1;
    }
    Node *q;
    q=top;
    top=top->next;
    char x= q->data;
    delete q;
    return x;
}
char peek(char pos)
{
    Node *p = top;
    for(int i=1; p && i<pos; i++){
        p=p->next;
    }
    if(p) return p->data;
    return -1;
}
char stackTop()
{
    if(top)return top->data;
    return -1;
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

int isBalanced(char *exp)
{
    for(int i= 0; exp[i]; i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            push(exp[i]);
        else if(exp[i]== ')'|| exp[i]=='}' || exp[i]==']'){
            if(!top)return 0;
            int x = pop();
            if(abs(x-exp[i])>3)return 0;
        }
    }
    if(top)return 0;
    return 1;
}

int main()
{
    char exp[] = "([(a+[b])(*{c-d})])";
    cout << isBalanced(exp)<< endl;
    return 0;
}