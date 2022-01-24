#include <iostream>

using namespace std;

int main( ) {
    int caixa, C, max = 100, atual = max;
    cin >> C;
    for ( int k = 0; k < C; k++ ) {
        cin >> caixa;
        atual += caixa;
        if ( atual > max ) {
            max = atual;
        }
    }
    cout << max << endl;
    return 0;
}

