#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> a;
vector<ll> st, lazy;

// Función para construir el nodo i que va desde el rango l (left) hasta r (right)
void build(ll i, ll l, ll r) {
    if (l == r) { // Si se cumple esto es porque es un hoja
        st[i] = a[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(2 * i, l, mid); // Construye el lado izquierdo
    build(2 * i + 1, mid + 1, r); // Construye el lado derecho
    st[i] = min(st[2 * i], st[2 * i + 1]); // El valor del nodo es el mínimo de sus hijos
}

//Funcion que propaga los cambios del nodo a sus hijos
void propagate(ll i, ll l, ll r) {
    if (lazy[i] != 0) {
        st[i] += lazy[i];   // Aplico los cambios en el nodo
        if (l != r) {       // Si no es una hoja
            lazy[2 * i] += lazy[i];
            lazy[2 * i + 1] += lazy[i];
        }
        lazy[i] = 0;    //Reset de los cambios del nodo actual
    }
}

// i (nodo actual), l (límite izquierdo), r (límite derecho), A & B (rango que quiero actualizar), x (valor que quiero colocar)
void update(ll i, ll l, ll r, ll A, ll B, ll x) {
    if (l > B || r < A) return; // Si fuera de rango
    if (l >= A && r <= B) {     // Si contengo a todo el intervalo de Update
        lazy[i] += x;   //Solo actualizo el Update del nodo especifico
        return;
    }

    //Propago el Update a sus hijos
    propagate(i, l, r);

    ll mid = (l + r) / 2;

    //Update de los hijos
    update(2 * i, l, mid, A, B, x);
    update(2 * i + 1, mid + 1, r, A, B, x);

    //Actualizacion del nodo actual
    st[i] = min(st[2 * i], st[2 * i + 1]); // Actualizo el valor del nodo actual
}

// i (nodo actual), l (límite izquierdo), r (límite derecho), A & B (rango de la pregunta)
ll query(ll i, ll l, ll r, ll A, ll B) {
    if (l > B || r < A) return LLONG_MAX; // Si fuera de rango
    if (l >= A && r <= B) return st[i] + lazy[i]; // Si el nodo contiene todo el rango que se pregunta

    // Si contengo parcialmente el rango de Query
    propagate(i, l, r);  //Propago los Update

    ll mid = (l + r) / 2;
    return min(query(2 * i, l, mid, A, B), query(2 * i + 1, mid + 1, r, A, B));
}

//Lee una linea de input de cualquier tamaño (inputs separados por 'espacios', al apretar 'ENTER' se envia toda la linea)
vector<ll> input_raro() {
    string line;
    getline(cin, line); //Ingresa una linea
    stringstream ss(line);
    vector<ll> v;
    ll x;
    while (ss >> x) v.push_back(x); //Extraigo los inputs separados por 'espacios'
    return v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    vector<ll> aux = input_raro();
    n = aux[0];

    a = input_raro();
    st.resize(4 * n);
    lazy.resize(4 * n, 0);
    build(1, 0, n - 1);

    aux = input_raro();
    m = aux[0];

    for (ll i = 0; i < m; i++) {
        vector<ll> input = input_raro();
        if (input.size() == 2) {
            ll lf = input[0], rg = input[1];
            if (lf <= rg) {
                cout << query(1, 0, n - 1, lf, rg) << "\n";
            } else {
                ll izquierda = query(1, 0, n - 1, 0, rg);
                ll derecha = query(1, 0, n - 1, lf, n - 1);
                cout << min(izquierda, derecha) << "\n";
            }
        } else {
            ll lf = input[0], rg = input[1], v = input[2];
            if (lf <= rg) {
                update(1, 0, n - 1, lf, rg, v);
            } else {
                update(1, 0, n - 1, 0, rg, v);
                update(1, 0, n - 1, lf, n - 1, v);
            }
        }
    }

    return 0;
}