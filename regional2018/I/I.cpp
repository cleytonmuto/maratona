#include <iostream>
#include <cmath>

using namespace std;

bool allZeroes( int array[], int size ) {
    bool result = true;
    for ( int k = 0; k < size; k++ ) {
        if ( array[ k ] != 0 ) {
            result = false;
        }
    }
    return result;
}

bool compareArrays( int array1[], int array2[], int size ) {
    bool result = true;
    for ( int k = 0; k < size; k++ ) {
        if ( array1[ k ] != array2[ k ] ) {
            return false;
        }
    }
    return true;
}

int main() {
    int N, M;  // N = interruptores ; M = lampadas
    cin >> N >> M;
    int MAX = max(N,M) * max(N,M);
    int L; // quantidade de lampadas acesas
    cin >> L;
    int lampada[ M + 1 ], inicial[ M + 1];
    for ( int i = 0; i < M + 1; i++ ) {
        lampada[ i ] = 0;
        inicial[ i ] = 0;
    }
    for ( int i = 0; i < L; i++ ) {
        int index;
        cin >> index;
        lampada[ index ] = 1;
        inicial[ index ] = 1;
    }
    int interruptor[ N + 1 ][ M + 1 ];
    for ( int i = 0; i < N + 1; i++ ) {
        for ( int j = 0; j < M + 1; j++ ) {
            interruptor[ i ][ j ] = 0;
        }
    }
    for ( int i = 1; i < N + 1; i++ ) {
        int associacoes;
        cin >> associacoes;
        for ( int j = 0; j < associacoes; j++ ) {
            int index;
            cin >> index;
            interruptor[ i ][ index ] = 1;
        }
    }
    int count = 1, index = 1;
    bool worked = false;
    while ( count < MAX ) {
        for ( int j = 1; j < M + 1; j++ ) {
            if ( interruptor[ index ][ j ] == 1 ) {
                lampada[ j ] = ( lampada[ j ] + 1 ) % 2;
            }
        }
        if ( allZeroes(lampada, M + 1) ) {
            worked = true;
            break;
        }
        index++;
        if ( index == N + 1 ) {
            index = 1;
            if ( compareArrays( lampada, inicial, M + 1 ) ) {
                worked = false;  // apos uma sequencia completa,
                break;           // as lampadas retornaram ao inicio
            }
        }
        count++;
    }
    if ( worked ) {
        cout << count << endl;
    }
    else {
        cout << "-1" << endl;
    }
    return 0;
}
