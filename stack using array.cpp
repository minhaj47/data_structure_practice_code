#include <iostream>
using namespace std;

struct Stack
{
    int top;
    int size;
    int *p;
};

void create(struct Stack *st)
{
    cin >> st->size;
    st->top = -1;
    st->p = new int [st -> size];
}
void display(struct Stack st)
{
    int i;
    for(int i=st.top; i>=0; i--){
        cout << st.p[i] << " ";
    }
    cout << endl;
}
void push(struct Stack *st, int x)
{
    if(st->top==st->size-1)
        cout << "Overflow\n";
    else{
        st->top++;
        st->p[st->top] = x;
    }
    
}
int pop(struct Stack *st)
{
    int x;
    if(st->top==-1){
        cout << "Underflow\n";
        return -1;
    }    
    x = st->p[st->top--];
    return x; 
}
int peek(struct Stack st, int pos)
{
    int b = st.top-pos+1;
    if(b<0 || b>st.top){
        cout << "invalid index\n";
        return -1;
    }
    return st.p[b];
}
int isEmpty(struct Stack st)
{
    return (st.top == -1);
}
int isFull(struct Stack st)
{
   return (st.top == st.size-1);
}

int stackTop(struct Stack st)
{
    if(!isEmpty(st)){
        return st.p[st.top];
    }
    return -1; 
}

int main()
{
    struct Stack st;
    create(&st);
    push(&st, 3);
    push(&st, 5);
    push(&st, 8);
    push(&st, 17);
    push(&st, 5);
    if(isFull(st)==1)cout << "Full\n";
    else cout << "not Full\n";
    push(&st, 22);
    push(&st, 68);
    cout << endl << "popped:"<< pop(&st) << endl;
    push(&st, 33);
    cout << "top value:"<< stackTop(st) << endl;
    push(&st, 3);
    push(&st, 5);
    push(&st, 8);
    push(&st, 3);
    cout << "top value:"<< stackTop(st) << endl;
    push(&st, 27);
    push(&st, 5);
    if(isFull(st)==1)cout << "Full\n";
    else cout << "not Full\n";
    push(&st, 17);
    push(&st, 5);
    cout << "popped:"<< pop(&st) << endl;
    cout << "popped:"<< pop(&st) << endl;
    cout << "popped:"<< pop(&st) << endl;
    cout << "top value:"<< stackTop(st) << endl;
    cout << "popped:"<< pop(&st) << endl;
    cout << "popped:"<< pop(&st) << endl;
    if(isEmpty(st)==1)cout << "Empty\n";
    else cout << "not Empty\n";
    cout << "popped:"<< pop(&st) << endl;
    cout << "popped:"<< pop(&st) << endl;
    cout << "popped:"<< pop(&st) << endl;
    display(st);
    cout << "popped:"<< pop(&st) << endl;
    cout << "popped:"<< pop(&st) << endl;
    cout << "popped:"<< pop(&st) << endl;
    if(isEmpty(st)==1)cout << "Empty\n";
    else cout << "not Empty\n";
    push(&st, 22);
    push(&st, 5);
    push(&st, 17);
    push(&st, 5);
    cout << "top value:"<< stackTop(st) << endl;
    push(&st, 8);
    push(&st, 3);
    display(st);
    cout << "top value:"<< stackTop(st) << endl;
    cout << "peeked:"<< peek(st, 1) << endl;
    cout << "peeked:"<< peek(st, 10) << endl;
    cout << "peeked:"<< peek(st, 3)<< endl;
    cout << "peeked:"<< peek(st, 4) << endl;

 
    cout << st.top << endl;

    return 0;
}