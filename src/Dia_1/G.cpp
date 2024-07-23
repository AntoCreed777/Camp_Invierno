#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, aux;
    cin >> n;

    long long r=0, l=0;

    for(int i=0;i<n;i++){
        cin >> aux;

        if(r + aux < 0){
            l+= - r - aux;
            r = 0;
        }
        else{r+=aux;}
    }

    cout << l << endl;


    return 0;
}