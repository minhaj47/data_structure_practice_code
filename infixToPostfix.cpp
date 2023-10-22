#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

struct Node{
    char data;
    Node *next;
}*top = NULL;

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
int opPre(char x)
{
    if(x == '+' ||x == '-')
        return 1;
    else if(x == '*' ||x== '/' )
        return 2;
    else 
        return 0;
}

string inToPostfix(string &in)
{
    int i=0;
    string post;
    int len = in.length();
    post = new char[len+2];
    while(in[i]){
        if(!opPre(in[i]))
            post+=in[i++];
        else if(opPre(in[i])>opPre(top->data))
                push(in[i++]);
        else 
            post+=in.pop();
    }
    while(top)post+=in.pop();
    post+='\0';
    return post;
}

int evaluateEq(char *eq);

int main()
{
    push('#');
    string in = "a+b*c-d/e";
    string postfix = inToPostfix(in);
    printf("%s\n", postfix);
    
    return 0;
}