#include <iostream>
#include <cmath>

using namespace std;

int main( ) {
    int voltas, placas;
    cin >> voltas >> placas;
    double decimo = ( double ) ( voltas * placas ) / 10.0;
    for ( int i = 1; i < 10; i++ ) {
        if ( i > 1 ) {
            cout << " ";
        }
        cout << ( int ) ceil( ( double ) i * decimo );
    }
    cout << endl;
    return 0;
}
