#include <bits/stdc++.h>

using namespace std;

int main(){

    set <int> s = {1,2,3};
    s.insert(1);    //No hace nada, ya hay un 1     -> O(log n)

    multiset <int> ms = {1,2,3};
    s.insert(1);    // ms = {1,1,2,3}

    map <int,int> mi_mapa;
    mi_mapa[5] = 3; // mi_mapa = {{5,3}}

    //Cola(Queue) y Pilas(Stack)     -> O(1)

    //Cola(Queue), FIFO, el priemro que entra es el primero que sale
    //q = {3,4,5,2,3,10}

    //Pila(Stack)
    //s = {3,4,7,3}

    stack <int> st;
    st.push(3);
    st.push(5);
    st.push(7);
    cout << st.top() << endl;   // 7
    st.pop();
    cout << st.top() << endl;   // 5

    queue <int> qu;
    qu.push(3);
    qu.push(5);
    qu.push(7);

    cout << qu.top() << endl;   // 3
    st.pop();
    cout << st.top() << endl;   // 5

    priority_queue <int> pq;

    pq.push(3);
    pq.push(5);
    pq.push(4);
    
    //pq.top() entregar el mayor
    cout << pq.top() << endl;   //5
    pq.pop();

    deque <int> dq;
    //  double-ended queue

    return 0;
}