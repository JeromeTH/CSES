#include <iostream>
#include <algorithm>
using namespace std;
const int SIZE = 16;
bool a[SIZE];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < (1 << n); i++){
        for(int j = 0; j < n; j++){
            a[n - j - 1] = (i >> j) & 1;
        }
        cout << a[0];
        for(int j = 0; j < n - 1; j++){
            int t = a[j]^a[j + 1];
            cout << t;
        }
        cout << endl;
    }
    return 0;
}