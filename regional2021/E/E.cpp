#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int start[ N ], end[ N ], direction[ N ];
    int LENGTH = 100000;
    int stairStatus[ LENGTH ];
    for ( int k = 0; k < LENGTH; k++ ) {
        stairStatus[ k ] = -1;
    }
    for ( int i = 0; i < N; i++ ) {
        cin >> start[ i ] >> direction[ i ];
        end[ i ] = start[ i ] + 10;
    }
    for ( int k = start[ 0 ]; k < end[ 0 ]; k++ ) {
        stairStatus[ k ] = direction[ 0 ];
    }
    for ( int i = 1; i < N; i++ ) {
        if ( stairStatus[ start[ i ] ] == -1 ) { // stopped stair
            for ( int k = start[ i ]; k < end[ i ]; k++ ) {
               stairStatus[ k ] = direction[ i ];
            }       
        }
        else {  // moving stair
            if ( stairStatus[ start[ i ] ] == direction[ i ] ) { // same direction
                // it needs to push the pendent forward, before filling the interval
                int intervalIndex = start[ i ];
                while ( stairStatus[ intervalIndex ] == direction[ i ] ) {
                    intervalIndex++;
                }
                int intervalStart = intervalIndex - 10;
                int intervalEnd = intervalIndex;
                int difference = start[ i ] - intervalStart;
                int temp[ 10 ];
                for ( int k = 0; k < 10; k++ ) { // temporarily saves the stair status
                    temp[ k ] = stairStatus[ intervalEnd + k ];
                    stairStatus[ intervalEnd + k ] = -1; // empty the saved status
                }
                for ( int k = 0; k < 10; k++ ) { // push away the saved satus
                    stairStatus[ intervalEnd + difference + k ] = temp[ k ];
                }
                for ( int k = start[ i ]; k < end[ i ]; k++ ) { // fills the interval to stretch it
                    stairStatus[ k ] = direction[ i ];
                }
            }
            else {  // opposite direction = push forward
                int intervalIndex = start[ i ];
                while ( stairStatus[ intervalIndex ] == ( direction[ i ] + 1 ) % 2 ) {
                    intervalIndex++;
                }
                int intervalStart = intervalIndex - 10;
                int intervalEnd = intervalIndex;
                start[ i ] = intervalEnd;
                end[ i ] = start[ i ] + 10;
                for ( int k = start[ i ]; k < end[ i ]; k++ ) {
                    stairStatus[ k ] = direction[ i ];
                }
            }
        }
    }
    int lastNonNullIndex = -1;
    for ( int k = 0; k < LENGTH; k++ ) {
        if ( stairStatus[ k ] != -1 ) {
            lastNonNullIndex = k;
        }
    }
    cout << lastNonNullIndex + 1 << endl;
    return 0;
}
