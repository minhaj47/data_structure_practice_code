#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int>s;
    
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }

    queue<string>q;
    q.push("abc");
    q.push("def");
    q.push("ghi");
    q.push("jkl");
    q.push("mno");

    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
}