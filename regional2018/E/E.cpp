#include <iostream>
#include <cstring>

using namespace std;

int main() {
    string cipher, crib;
    cin >> cipher;
    cin >> crib;
    int N = cipher.length() - crib.length() + 1;
    int valids = 0;
    for (int i = 0; i < N; i++) {
        bool coincident = false;
        for (int j = 0; j < crib.length(); j++) {
            if ( cipher[ i + j ] == crib[ j ] ) {
                coincident = true;
            }
        }
        if ( !coincident ) {
            valids++;
        }
    }
    cout << valids << endl;
    return 0;
}
