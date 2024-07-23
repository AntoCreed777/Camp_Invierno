#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;

    for(unsigned int i=0;i<s.size();i++){
        if(s[i] == 'M'){
            for(unsigned int j=i;j<s.size();j++){
                if(s[j] == 'R'){
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "Yes" <<endl;
    return 0;
}