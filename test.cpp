#include "ChessBoard.hpp"
#include <iostream>


using namespace square;
using namespace std;


int main()
{
    ChessBoard cb;
    
    for (int rank = 8; rank >= 1; rank--) {
	for (int file = 1; file <= 8; file++) {
	    if (cb.pieceAt(file, rank))
		cout << cb.pieceAt(file, rank)->type() << " " << flush;
	    else cout << "  ";
	}
	cout << endl;
    }


    cb.submitMove("B2", "B4");
    cb.submitMove("C1", "A3");
    cb.submitMove("G1", "F3");

    
    for (int rank = 8; rank >= 1; rank--) {
	for (int file = 1; file <= 8; file++) {
	    if (cb.pieceAt(file, rank))
		cout << cb.pieceAt(file, rank)->type() << " " << flush;
	    else cout << "  ";
	}
	cout << endl;
    }
    

    return 0;
}
