#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector <int> st;    //Arbol que representa la suma de sus hijos
vector <int> a;     //Valores originales

// Funcion para construir el nodo i que va desde el rango l (left) hasta r (right)
void build(int i, int l, int r){
    if(l == r){         // Si se cumple esto es porque es un hoja
        st[i] = a[l];
        return;
    }

    build(2*i, l, (l+r)/2);         //Construye el lado izquierdo
    build(2*i +1, (l+r)/2 +1, r);   //Construye el lado derecho

    st[i] = st[2*i] + st[2*i +1];        //El valor de nodo es la suma de sus hijos
}

// i (nodo actual), l (limite izquierdo), r (limite derecho), p (valor que quiero acualizar), x (valor que quiero colocar)
void update(int i,int l,int r,int p,int x){
    if(l == r){
        st[i] = x;
        return;
    }

    int medio = (l+r) / 2;

    // Si esta en la parte izquierda
    if(p >= medio){
        update(i*2,l,medio,p,x);
    }
    else{   //Sino esta en la parte derecha
        update(i*2 +1,medio+1,r,p,x);
    }

    st[i] = st[i*2] + st[2*i +1];   //Actualizo el valor del nodo actual
}

// i (nodo actual),l(limite izqierdo),r (limite derecho), A && B (rango de la pregunta)
int query(int i,int l,int r,int A,int B){
    //Si el nodo contiene a todo el rango que se pregunta
    if(l >= A && r <= B){return st[i];}

    int medio = (l + r) / 2;

    //Si la mitad es menor al limite izquierdo 
    if(medio < A){
        return query(i*2 +1,medio + 1,r,A,B);
    }
    else if (medio >= B) {  //Si la mitad es mayor o igual al limite dercho
        return query(i,l,medio,A,B);
    }
    else{   //Si contengo parte de lo que se pide pero no todo
        return query(2*i,l,medio,A,B) + query(2*i +1,medio +1,r,A,B);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);



    return 0;
}