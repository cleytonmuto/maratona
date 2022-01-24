#include <iostream>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int array[N + 1], cor[N + 1];
    for ( int i = 1; i <= N; i++ ) {
        cin >> array[ i ] >> cor[ i ];
    }
    for ( int i = 1; i <= N; i++ ) {
        if ( cor[ array[ i ] ] != cor[ i ] ) {
            cout << "N" << endl;
            return 0;
        }
    }
    cout << "Y" << endl;
    return 0;
}
