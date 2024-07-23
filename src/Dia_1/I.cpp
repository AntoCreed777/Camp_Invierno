#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n, oro=0,costo_reparacion=1;
    cin >> n;

    vector <long long> oroC(n);

    for(int i=0;i<n;i++){
        cin >> oroC[i];
    }

    sort(oroC.rbegin(),oroC.rend());

    for(int i=0;i<n;i++){
        if(oroC[i] - costo_reparacion > 0){
            oro+= oroC[i] - costo_reparacion;
            costo_reparacion++;
        }
        else{break;}
    }

    cout << oro << endl;

    return 0;
}

// 2 3 4 5 10