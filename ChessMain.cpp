#include "ChessBoard.h"

#include <iostream>

using namespace std;

int main() {

    cout << "===========================" << endl;
    cout << "Testing the Chess Engine" << endl;
    cout << "===========================" << endl;
    cout << endl;
    
    ChessBoard cb;
    //cout << "ChessBoard was created" <<endl;
    cout << endl;
    
    //Not black's turn
    cb.submitMove("D7", "D6");
    cout << endl;

    //No piece at D4
    cb.submitMove("D4", "H6");
    cout << endl;

    //White Pawn moves
    cb.submitMove("D2", "D4");
    cout << endl;

    //Black Bishop cannot move
    cb.submitMove("F8", "B4");
    cout << endl;

    //Self created from here on
    //Too many characters


    cb.submitMove("F1D", "D2");
    cout << endl;

    // Not upper case
    cb.submitMove("12", "23");
    cout << endl;

    //Seond character not digit
    cb.submitMove("DD", "WD");
    cout << endl;

    // No position
    cb.submitMove("D2", "");
    cout<< endl;

    //Position is outside the file
    cb.submitMove("D2", "K2");
    cout<< endl;

    // Position is outside the rank
    cb.submitMove("D9", "D2");
    cout << endl;

    //Second position lower alphabet
    cb.submitMove("D2", "a8");
    cout << endl;

    //Black King cannot move because landing position is occupied by same team
    cb.submitMove("E8", "E7");
    cout << endl;

    //Black King cannot move because ending move is diagonal
    cb.submitMove("E8", "D7");
    cout << endl;

    //Black pawn moves two spaces ahead on first move
    cb.submitMove("A7", "A5");
    cout << endl;

    //Getting pawn in front of white king out of the way
    cb.submitMove("E2", "E4");
    cout << endl;

    //Moving black pawn in front of Queen
    cb.submitMove("D7", "D5");
    cout << endl;

    //Moving white king into unoccupied space but two spaces away
    cb.submitMove("E1", "E3");
    cout << endl;

    //Moving white king into correct space one step ahead
    cb.submitMove("E1", "E2");
    cout << endl;

    //Moving Black's Bishop to occupied position
    cb.submitMove("C8", "B7");
    cout << endl;

    //Moving Black's Queen to the same position
    cb.submitMove("D8", "D8");
    cout << endl;

    //Moving Black's Queen to position occupied by same team
    cb.submitMove("D8", "E7");
    cout << endl;

    //Black's knight cannot be moved because it is on the same square
    cb.submitMove("G8", "G8");
    cout << endl;

    //Black's Knight cannot be moved because it is an invalid shape
    cb.submitMove("G8", "G6");
    cout << endl;

    //Black's knight cannot be moved because of occupied position
    cb.submitMove("G8", "E7");
    cout << endl;

    //Black's knight move to valid position
    cb.submitMove("G8", "H6");
    cout << endl;

    //White's Rook cannot move diagonally
    cb.submitMove("H1", "F3");
    cout << endl;

    //White's Rook cannot move to occupied position
    cb.submitMove("H1", "H2");
    cout << endl;

    //White's Rook cannot move over uncleared path 
    cb.submitMove("H1", "H3");
    cout << endl;

    //Moves white pawn in front of rook away
    cb.submitMove("H2" , "H4");
    cout << endl;

    //Moves black pawn at D5 vertically one step to palce occupied by white pawn
    cb.submitMove("D5", "D4");
    cout << endl;

    //Moves black pawn diagonally to empty spot
    cb.submitMove("D5", "C4");
    cout << endl;

    //Moves black pawn for one step for the first move
    cb.submitMove("B7", "B6");
    cout << endl;

    //Moves white rook 
    cb.submitMove("H1", "H5");
    cout << endl;

    //Moves white rook 
    cb.submitMove("H1", "H3");
    cout << endl;

    //Moves black pawn for second time for two steps
    cb.submitMove("B6", "B4");
    cout << endl;

    //Moves black pawn for the second time for one step
    cb.submitMove("B6", "B5");
    cout << endl;

    //Moves white rook 
    cb.submitMove("H3", "G3");
    cout << endl;

    //Moves black pawn
    cb.submitMove("B5", "B4");
    cout << endl;

    //Moves white rook
    cb.submitMove("G3", "G6");
    cout << endl;

    //Black pawn eats rook
    cb.submitMove("H7", "G6");
    cout << endl;

    

    cout << "===========================" << endl;
    cout << "Alekhine vs. Vasic (1931)" << endl;
    cout << "===========================" << endl;
    cout << endl;

    cb.resetBoard();
    cout << endl;

    cb.submitMove("E2", "E4");
    cb.submitMove("E7", "E6");
    cout << endl;

    cb.submitMove("D2", "D4");
    cb.submitMove("D7", "D5");
    cout << endl;

    cb.submitMove("B1", "C3");
    cb.submitMove("F8", "B4");
    cout << endl;

    cb.submitMove("F1", "D3");
    cb.submitMove("B4", "C3");
    cout << endl;

    cb.submitMove("B2", "C3");
    cb.submitMove("H7", "H6");
    cout << endl;

    cb.submitMove("C1", "A3");
    cb.submitMove("B8", "D7");
    cout << endl;

    cb.submitMove("D1", "E2");
    cb.submitMove("D5", "E4");
    cout << endl;

    cb.submitMove("D3", "E4");
    cb.submitMove("G8", "F6");
    cout << endl;

    cb.submitMove("E4", "D3");
    cb.submitMove("B7", "B6");
    cout << endl;

    cb.submitMove("E2", "E6");
    cb.submitMove("F7", "E6");
    cout << endl;

    cb.submitMove("D3", "G6");
    cout << endl;

    
    cout << "===========================" << endl;
    cout << "A game that should end with white in checkmate!" << endl;
    cout << "===========================" << endl;
    cout << endl;
    
    cb.resetBoard();
    cout << endl;

    cb.submitMove("C2","C4");
    cb.submitMove("B7","B5");
    cout << endl;
    
    cb.submitMove("C4","B5");
    cb.submitMove("G7","G5");
    cout << endl;
    
    cb.submitMove("E2","E3");
    cb.submitMove("H7","H5");
    cout << endl;
    
    cb.submitMove("F1","E2");
    cb.submitMove("G8","F6");
    cout << endl;
    
    cb.submitMove("B2","B3");
    cb.submitMove("F8","G7");
    cout << endl;
    
    cb.submitMove("C1","B2");
    cb.submitMove("G5","G4");
    cout << endl;
    
    cb.submitMove("H2","H3");
    cb.submitMove("C8","B7");
    cout << endl;
    
    cb.submitMove("H1","H2");
    cb.submitMove("A7","A6");
    cout << endl;
    
    cb.submitMove("B5","A6");
    cb.submitMove("B8","A6");
    cout << endl;
    
    cb.submitMove("B1","C3");
    cb.submitMove("D8","B8");
    cout << endl;
    
    cb.submitMove("H3","G4");
    cb.submitMove("C7","C5");
    cout << endl;
    
    cb.submitMove("G2","G3");
    cb.submitMove("H5","H4");
    cout << endl;
    
    cb.submitMove("F2","F4");
    cb.submitMove("H4","G3");
    cout << endl;
    
    cb.submitMove("H2","H8");
    cb.submitMove("G7","H8");
    cout << endl;
    
    cb.submitMove("G4","G5");
    cb.submitMove("F6","E4");
    cout << endl;
    
    cb.submitMove("D1","C2");
    cb.submitMove("A6","B4");
    cout << endl;
    
    cb.submitMove("C2","B1");
    cb.submitMove("E4","F2");
    cout << endl;
    
    cb.submitMove("B1","H7");
    cb.submitMove("D7","D6");
    cout << endl;
    
    cb.submitMove("H7","H8");
    cb.submitMove("E8","D7");
    cout << endl;
    
    cb.submitMove("H8","B8");
    cb.submitMove("A8","B8");
    cout << endl;
    
    cb.submitMove("A1","B1");
    cb.submitMove("B8","H8");
    cout << endl;
    
    cb.submitMove("E2","F3");
    cb.submitMove("B4","C2");
    cout << endl;
    
    cb.submitMove("E1","E2");
    cb.submitMove("B7","A6");
    cout << endl;
    
    cb.submitMove("D2","D3");
    cb.submitMove("H8","H2");
    cout << endl;
    
    cb.submitMove("F3","G4");


    cb.submitMove("F2","G4");
    cout << endl;
    
    cb.submitMove("E2","F3");
    cb.submitMove("C2","E3");
    cout << endl;
    
    cb.submitMove("B2","C1");
    cb.submitMove("A6","B7");
    cout << endl;
    
    cb.submitMove("F3","G3");
    cb.submitMove("H2","G2");
    cout << endl;
    
    cb.submitMove("G3","H3");
    cb.submitMove("G4","F2");
    cout << endl;
    
    cb.submitMove("H3","H4");
    cb.submitMove("E3","F5");
    cout << endl;
    
    cb.submitMove("H4","H5");
    cb.submitMove("G2","H2");
    cout << endl;
 
    cb.submitMove("G1","H3");
    cb.submitMove("H2","H3");
    cout << endl;

    cout << "===========================" << endl;
    cout << "A game with castling!" << endl;
    cout << "===========================" << endl;
    cout << endl;
    
    cb.resetBoard();
    cout << endl;

    cb.submitMove("G2", "G4");
    cb.submitMove("F7", "F5");
    cout << endl;

    cb.submitMove("F2", "F3");
    cb.submitMove("F5", "G4");
    cout << endl;

    cb.submitMove("F3", "G4");
    cb.submitMove("G7", "G5");
    cout << endl;

    cb.submitMove("F1", "H3");
    cb.submitMove("F8", "H6");
    cout << endl;

    cb.submitMove("G1", "F3");
    cb.submitMove("G8", "F6");
    cout << endl;    

    cb.submitMove("F3", "G5");
    cb.submitMove("F6", "G4");
    cout << endl;

    cb.submitMove("G5", "E4");
    cb.submitMove("G4", "E5");
    cout << endl;

    cb.submitMove("B1", "C3");
    cb.submitMove("B8", "C6");
    cout << endl;

    cb.submitMove("B2", "B4");
    cb.submitMove("B7", "B5");
    cout << endl;

    cb.submitMove("E2", "E3");
    cb.submitMove("E7", "E6");
    cout << endl;

    cb.submitMove("C1", "A3");
    cb.submitMove("C8", "A6");
    cout << endl;

    cb.submitMove("D1", "F3");
    cb.submitMove("D8", "F6");
    cout << endl;

    cb.submitMove("C3", "A4");
    cb.submitMove("C6", "A5");
    cout << endl;

    cb.submitMove("A4", "B6");
    cb.submitMove("A5", "B3");
    cout << endl;

    
    
    cb.submitMove("E1", "C1");
    cb.submitMove("E8", "C8");
    
    return 0;
}

