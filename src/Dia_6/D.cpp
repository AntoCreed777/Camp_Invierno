#include <bits/stdc++.h>
#include <tuple>

using namespace std;
typedef long long ll;

vector <ll> arbol;
vector <ll> libros;

void build(int i, int l, int r){
    if(l == r){         // Si se cumple esto es porque es un hoja
        arbol[i] = libros[l];
        return;
    }

    build(2*i, l, (l+r)/2);         //Construye el lado izquierdo
    build(2*i +1, (l+r)/2 +1, r);   //Construye el lado derecho

    arbol[i] = arbol[2*i] + arbol[2*i +1];        //El valor de nodo es la suma de sus hijos
}
/*
tuple<ll,ll,ll> query(int i,int l,int r,int x){
    if(arbol[i] <= x)return {arbol[i],l,r};
    if(l == r)return {0,0,0};

    int medio = (l + r) / 2;

    return max(query(2*i,l,medio,x), query(2*i +1,medio +1,r,x));
}
*/

// i (nodo actual),l(limite izqierdo),r (limite derecho), A && B (rango de la pregunta)
int query(int i,int l,int r,int A,int B){
    //Si el nodo contiene a todo el rango que se pregunta
    if(l >= A && r <= B){return arbol[i];}

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t,n;

    cin >> n >> t;  //Libros >> Tiempo

    libros.resize(n);
    arbol.resize(4*n);

    for(int i=0;i<n;i++)cin >> libros[i];

    build(1,0,n);

    ll x,l,r;

    tie(x,l,r) = query(1, 0, n, t);

    cout << x << " " << l << " " << r << "\n";

    cout << r-l+1 << "\n";

    return 0;
}