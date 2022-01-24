#include <iostream>

using namespace std;

int main( ) {
    int N, first, candidate;
    bool someone = false;
    cin >> N;
    cin >> first;
    for ( int i = 1; i < N; i++ ) {
        cin >> candidate;
        if ( candidate > first ) {
            someone = true;
        }
    }
    if ( someone ) {
        cout << "N" << endl;
    }
    else {
        cout << "S" << endl;
    }
    return 0;
}
