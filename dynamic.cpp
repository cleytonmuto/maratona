#include <iostream>

using namespace std;

int main() {
    int L, C;
    cin >> L >> C;
    int estacao[ L ][ C ], soma[ L ][ C ], escolha[ L ][ C ];
    for ( int i = 0; i < L; i++ ) {
        for ( int j = 0; j < C; j++ ) {
            cin >> estacao[ i ][ j ];
            soma[ i ][ j ] = 0;
            escolha[ i ][ j ] = -1;
        }
    }
    int peso[ L ][ C + 1 ];
    for ( int i = 0; i < L; i++ ) {
        for ( int j = 0; j < C + 1; j++ ) {
            cin >> peso[ i ][ j ];
        }
    }
    soma[ 0 ][ 0 ] = peso[ 0 ][ 0 ] + estacao[ 0 ][ 0 ];
    soma[ 1 ][ 0 ] = peso[ 1 ][ 0 ] + estacao[ 1 ][ 0 ];
    int porCima = 0, porBaixo = 0;
    for ( int j = 1; j < C; j++ ) {
        for ( int i = 0; i < L; i++ ) {
            if ( i == 0 ) {
                porCima  = soma[ 0 ][ j - 1 ] + estacao[ 0 ][ j ];
                porBaixo = soma[ 1 ][ j - 1 ] + peso[ 1 ][ j ] + estacao[ 0 ][ j ];
            }
            else {
                porCima  = soma[ 0 ][ j - 1 ] + peso[ 0 ][ j ] + estacao[ 1 ][ j ];
                porBaixo = soma[ 1 ][ j - 1 ] + estacao[ 1 ][ j ];
            }
            if ( porCima < porBaixo ) {
                soma[ i ][ j ] = porCima;
                escolha[ i ][ j ] = 0;
            }
            else {
                soma[ i ][ j ] = porBaixo;
                escolha[ i ][ j ] = 1;
            }
        }
    }
    porCima = soma[ 0 ][ C - 1 ] + peso[ 0 ][ C ];
    porBaixo = soma[ 1 ][ C - 1 ] + peso[ 1 ][ C ];
    for ( int i = 0; i < L; i++ ) {
        for ( int j = 0; j < C; j++ ) {
            if ( j > 0 ) {
                cout << " ";
            }
            cout << soma[ i ][ j ];
        }
        cout << endl;
    }
    for ( int i = 0; i < L; i++ ) {
        for ( int j = 1; j < C; j++ ) {
            if ( j > 1 ) {
                cout << " ";
            }
            cout << escolha[ i ][ j ] + 1;
        }
        cout << endl;
    }
    cout << min( porCima, porBaixo ) << endl;
    return 0;
}

