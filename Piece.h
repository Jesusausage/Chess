#ifndef PIECE_H
#define PIECE_H


#include "ChessHelper.h"
#include "Square.h"
#include "ChessBoard.h"
#include <map>


class ChessBoard;


class Piece {    
public:
    Piece(ChessBoard* cb, bool colour, chess::Square position)
        : _cb(cb), _colour(colour), _position(position), _has_moved(false) {}
    virtual ~Piece() {};

    // Checks if a square is within reach to move
    virtual bool canAccess(chess::Square new_position) = 0;

    // Checks if a piece has any legal moves
    virtual bool hasNoMoves() const = 0;
    
    virtual std::string type() const = 0; // Returns the type of piece
    bool colour() const { return _colour; }
    void moveTo(chess::Square position); // Update a piece's position
    bool hasMoved() { return _has_moved; }
    void hasNowMoved() { _has_moved = true; } // Set the has_moved flag
    
protected:
    ChessBoard* _cb;
    bool _colour;
    chess::Square _position;
    bool _has_moved;

    bool isLegal(chess::Square new_position) const;
};


class Pawn : public Piece {
public:
    Pawn(ChessBoard* cb, bool colour, chess::Square position)
        : Piece(cb, colour, position) {};
    ~Pawn() override {};
    
    bool canAccess(chess::Square new_position) override;
    bool hasNoMoves() const override;
    std::string type() const override;
};


class Rook : public Piece {
public:
    Rook(ChessBoard* cb, bool colour, chess::Square position)
        : Piece(cb, colour, position) {};
    ~Rook() override {};

    bool canAccess(chess::Square new_position) override;
    bool hasNoMoves() const override;
    std::string type() const override;
};


class Bishop : public Piece {
public:
    Bishop(ChessBoard* cb, bool colour, chess::Square position)
        : Piece(cb, colour, position) {};
    ~Bishop() override {};

    bool canAccess(chess::Square new_position) override;
    bool hasNoMoves() const override;
    std::string type() const override;
};


class Knight : public Piece {
public:
    Knight(ChessBoard* cb, bool colour, chess::Square position)
        : Piece(cb, colour, position) {};
    ~Knight() override {};

    bool canAccess(chess::Square new_position) override;
    bool hasNoMoves() const override;
    std::string type() const override;
};


class Queen : public Piece {
public:
    Queen(ChessBoard* cb, bool colour, chess::Square position)
        : Piece(cb, colour, position) {};
    ~Queen() override {};

    bool canAccess(chess::Square new_position) override;
    bool hasNoMoves() const override;
    std::string type() const override;
};


class King : public Piece {
public:
    King(ChessBoard* cb, bool colour, chess::Square position)
        : Piece(cb, colour, position), _castling(0) {};
    ~King() override {};

    bool canAccess(chess::Square new_position) override;
    bool hasNoMoves() const override;
    std::string type() const override;
    int isCastling() { return _castling; }
    void hasCastled() { _castling = 0; } // Reset castling flag

private:
    int _castling; // Stores direction of castle, or 0 if not castling
};


#endif
