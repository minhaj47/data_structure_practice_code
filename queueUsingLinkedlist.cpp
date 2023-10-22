#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
}*front =NULL, *rear= NULL;

void enqueue(int x){
    Node *t;
    t= new Node;
    if(t==NULL){
        cout << "Overflow\n";
        return;
    }
    t->data = x;
    t->next = NULL;
    if(front == NULL)front=rear=t;
    else{
        rear->next= t;
        rear= t;
    }
}
int dequeue(){

    int x;
    if(front == NULL){
        cout << "Queue is Empty\n";
        return -1;
    }
    x= front->data;
    Node *t = front;
    front = front->next;
    delete t;
    return x;
}
void display()
{
    for(Node *i=front; i; i=i->next)cout << i->data << " ";
    cout << endl;
}

int main()
{
    dequeue();
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(8);
    display();
    enqueue(8);
    enqueue(9);
    display();
    dequeue();
    display();
    dequeue();
    enqueue(4);
    display();
    
    return 0;
}