#ifndef CHESSBOARD_H
#define CHESSBOARD_H


#include "ChessHelper.h"
#include "Square.h"
#include "Piece.h"
#include <map>
#include <set>
#include <iostream>


class Piece;
    

class ChessBoard {
public:
    ChessBoard();
    ~ChessBoard();

    // Deletes all pieces, sets the board to an initial state
    void resetBoard();

    // Parse a move, and make it if legal
    void submitMove(std::string const src_str, std::string const dest_str);

    // Tests whether a square contains no chess piece
    bool isEmpty(chess::Square position);

    // Tests whether a move from Square source to Square destination is legal
    // Does not print errors
    bool isLegal(chess::Square source, chess::Square destination);

private:
    /* Map gives nullptr is no piece is at specified square, and pointer to the
       piece if there is */
    std::map<chess::Square, Piece*> _piece_at;
    std::set<Piece*> _grave; // Stores dead pieces
    bool _current_player;
    bool _game_over;

    // Creates new set of pieces and puts them on the board
    void setBoard();

    // Checks if a move from source to destination is legal. The _str are square names
    bool isLegalMove(chess::Square source, chess::Square destination,
                     std::string const src_str, std::string const dest_str);

    // Checks if a move is reachable, but does not check whether leaves the player in check
    bool isAccessibleMove(chess::Square source, chess::Square destination,
                          std::string const src_str, std::string const dest_str);

    // Provides move info to standard output stream
    void printMove(chess::Square source, chess::Square destination,
                   std::string const src_str, std::string const dest_str);

    // Move a piece from source to destination and update board and piece data
    void movePiece(chess::Square source, chess::Square destination);

    // Undo the move from source to destination, and restores 'old_piece' (unless nullptr)
    void undoMove(chess::Square source, chess::Square destination,
                  Piece* old_piece);

    // Check if a given player is in check
    bool isInCheck(bool current_player);

    // Check if no more moves can be made
    bool isGameOver();

    // Check if a king can castle (castle flag in type King must be set)
    bool canCastle(chess::Square king_position);

    // Checks if a king passes through check during castling
    bool legalCastle(chess::Square king_position,
                     chess::Square rook_position, int dir);
};


#endif
