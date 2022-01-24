#include <iostream>
#include <string>

using namespace std;

class Player {
    public:
    int points;
    int games;
};

int main() {
    Player p1, p2;
    string sequence;
    cin >> sequence;
    int sacador = 1;
    p1.points = 0; p2.points = 0; p1.games = 0; p2.games = 0;
    bool gameOver = false;
    int winner = 0;
    for ( int i = 0; i < sequence.length(); i++ ) {
        switch ( sequence[ i ] ) {
            case 'S': if (!gameOver) {
                if ( sacador == 1 ) {
                    p1.points++;
                    if ( p1.points >= 5 && p1.points - p2.points >= 2 || p1.points == 10 ) { // end game
                        p1.games++;
                        p1.points = 0;
                        p2.points = 0;
                        if ( p1.games == 2 ) {
                            gameOver= true;
                            winner = 1;
                        }
                    }
                }
                else { // sacador == 2
                    p2.points++;
                    if ( p2.points >= 5 && p2.points - p1.points >= 2 || p2.points == 10 ) { // end game
                        p2.games++;
                        p1.points = 0;
                        p2.points = 0;
                        if ( p2.games == 2 ) {
                            gameOver= true;
                            winner = 2;
                        }
                    }
                }
                
            }; break;
            case 'R': if (!gameOver) {
                if ( sacador == 1 ) {
                    p2.points++;
                    sacador = 2;
                    if ( p2.points >= 5 && p2.points - p1.points >= 2 || p2.points == 10 ) { // end game
                        p2.games++;
                        p1.points = 0;
                        p2.points = 0;
                        if ( p2.games == 2 ) {
                            gameOver= true;
                            winner = 2;
                        }
                    }
                }
                else { // sacador == 2
                    p1.points++;
                    sacador = 1;
                    if ( p1.points >= 5 && p1.points - p2.points >= 2 || p1.points == 10 ) { // end game
                        p1.games++;
                        p1.points = 0;
                        p2.points = 0;
                        if ( p1.games == 2 ) {
                            gameOver= true;
                            winner = 1;
                        }
                    }
                    
                }
            }; break;
            case 'Q': {
                if (gameOver) {
                    if ( winner == 1 ) {
                        cout << p1.games << " (winner) - " << p2.games << endl;
                    }
                    else {
                        cout << p1.games << " - " << p2.games << " (winner)" << endl;
                    }
                }
                else { // not game over yet
                    if ( sacador == 1 ) {
                        cout << p1.games << " (" << p1.points << "*) - " << p2.games << " (" << p2.points << ")" << endl;
                    }
                    else {
                        cout << p1.games << " (" << p1.points << ") - " << p2.games << " (" << p2.points << "*)" << endl;
                    }
                }
            }; break;
        }
    }
    return 0;
}
