#include <iostream>

using namespace std;

int main() {
    int N, D, L, R, C;
    cin >> N;
    bool board[ 11 ][ 11 ];
    for ( int i = 0; i < 11; i++ ) {
        for ( int j = 0; j < 11; j++ ) {
            board[ i ][ j ] = false;
        }
    }
    bool crash = false;
    for ( int k = 0; k < N; k++ ) {
        cin >> D >> L >> R >> C;
        if ( D == 0 ) { // horizontal
            for ( int column = C; column < C + L; column++ ) {
                if ( column > 10 || board[ R ][ column ] ) {
                    crash = true;
                }
                else {
                    board[ R ][ column ] = true;
                }
            }
        }
        else { // vertical
            for ( int row = R; row < R + L; row++ ) {
                if ( row > 10 || board[ row ][ C ] ) {
                    crash = true;
                }
                else {
                    board[ row ][ C ] = true;
                }
            }
        }
    }
    if ( crash ) {
        cout << "N" << endl;
    }
    else {
        cout << "Y" << endl;
    }
    return 0;
}

