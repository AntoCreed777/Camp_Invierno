#include <bits/stdc++.h>
#include <ios>

using namespace std;
typedef long long ll;

vector<ll> a;
vector<ll> st;

// Funcion para construir el nodo i que va desde el rango l (left) hasta r (right)
void build(ll i, ll l, ll r){
    if(l == r){         // Si se cumple esto es porque es un hoja
        st[i] = a[l];
        return;
    }

    build(2*i, l, (l+r)/2);         //Construye el lado izquierdo
    build(2*i +1, (l+r)/2 +1, r);   //Construye el lado derecho

    st[i] = min(st[2*i], st[2*i +1]);        //El valor de nodo es el minimo de sus hijos
}

// i (nodo actual), l (limite izquierdo), r (limite derecho), p (valor que quiero acualizar), x (valor que quiero colocar)
void update(ll i,ll l,ll r,ll p,ll x){
    if(l == r){
        st[i] = x;
        return;
    }

    ll medio = (l+r) / 2;

    // Si esta en la parte izquierda
    if(p <= medio){
        update(i*2,l,medio,p,x);
    }
    else{   //Sino esta en la parte derecha
        update(i*2 +1,medio+1,r,p,x);
    }

    st[i] = min(st[i*2],st[2*i +1]);   //Actualizo el valor del nodo actual
    //cerr << "test " << l << ' ' << r << ' ' << st[i] << endl;
}

// i (nodo actual),l(limite izqierdo),r (limite derecho), A && B (rango de la pregunta)
ll query(ll i,ll l,ll r,ll A,ll B){
    //Si el nodo contiene a todo el rango que se pregunta
    if(l >= A && r <= B){return st[i];}

    ll medio = (l + r) / 2;

    //Si la mitad es menor al limite izquierdo 
    if(medio < A){
        return query(2*i +1,medio + 1,r,A,B);
    }
    else if (medio >= B) {  //Si la mitad es mayor o igual al limite dercho
        return query(2*i,l,medio,A,B);
    }
    else{   //Si contengo parte de lo que se pide pero no todo
        return min(query(2*i,l,medio,A,B), query(2*i +1,medio +1,r,A,B));
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n,q, opcion, l,r;
    cin >> n >> q;

    a.resize(n);
    st.resize(4*n+5);

    for(ll i=0;i<n;i++)cin >> a[i];

    build(1,0,n);

    for(ll i=0;i<q;i++){
        cin >> opcion >> l >> r;

        if(opcion == 1){    // Remplazar poscion l a r
            update(1,0,n,--l,r);
        }
        else{   //Minimo entre [l,r]
            cout << query(1,0,n,--l,--r) << "\n";
        }

    }

    return 0;
}

// abcdabc abcdabc