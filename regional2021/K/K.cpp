#include <iostream>

using namespace std;

int main() {
    int T, D, M;
    cin >> T >> D >> M;
    int meal[ M + 1 ];
    meal[0] = 0;
    for ( int i = 1; i <= M; i++ ) {
        cin >> meal[i];
    }
    // basta voce dormir uma unica vez para ficar descansado
    // logo, se entre duas refeicoes, isso ocorrer pelo menos
    // uma vez, entao problema resolvido!
    for ( int i = 1; i <= M; i++ ) {
        if ( meal[ i ] - meal[ i - 1 ] >= T ) {
            cout << "Y" << endl; // aconteceu uma vez = fim!
            return 0;
        }
    }
    if ( D - meal[ M ] >= T ) {
        cout << "Y" << endl;  // entre a ultima refeicao e o final do voo
        return 0;
    }
    cout << "N" << endl;
    return 0;
}

