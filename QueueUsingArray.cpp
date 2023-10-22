#include <bits/stdc++.h>
using namespace std;

class Queue{
private:
    int front;
    int rear;
    int size;
    int *Q;
public:
    Queue(){
        front = rear = -1;
        cout << "Enter Size\n";
        cin >> size;
        Q = new int[size];
    }
    void enque(int x);
    int dequeue();
    void display();
};


void Queue::enque(int x){
    if((rear+1)%size == front)cout << "Overflow\n";
    else{
        rear=(rear+1)%size;
        Q[rear]=x;
    }
}

int Queue :: dequeue(){
    if(front== rear){
        cout << "Underflow\n";
        return -1;
    }
    front= (front+1)%size;
    return Q[front];
}
void Queue :: display()
{
    for(int i=front+1; i<=rear; i++)cout << Q[i] << " ";
    cout << endl;
}

int main()
{
    struct Queue q;

    q.dequeue();
    q.enque(5);
    q.enque (6);
    q.enque(7);
    q.enque(8);
    q.enque(8);
    q.display();
    q.enque(8);
    q.enque(9);
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.enque(4);
    q.display();

}