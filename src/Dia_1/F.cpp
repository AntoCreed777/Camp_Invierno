#include <bits/stdc++.h>

using namespace std;

int main(){
    unsigned int cigarros, k;
    cin >> cigarros >> k;

    unsigned int colillas = 0, n=0;

    do{
        colillas += cigarros;
        n+=cigarros;
        cigarros=0;
        cigarros=colillas/k;
        colillas = colillas%k;
    }
    while(cigarros != 0);

    cout << n << endl;

    return 0;
}