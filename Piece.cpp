#include "Piece.h"


using namespace chess;
using namespace std;


void Piece::moveTo(Square position)
{
    _position = position;
}


bool Pawn::canAccess(Square new_position)
{    
    int dir = (_colour == WHITE) ? UP : DOWN;
    
    if (_cb->isEmpty(new_position)) {
        if (new_position == _position + dir) return true;
        if (!_has_moved &&
            new_position == _position + dir + dir &&
            _cb->isEmpty(_position + dir))
            return true;
    }
    else {
        if (new_position == _position + dir + LEFT ||
            new_position == _position + dir + RIGHT)
            return true;
    }

    return false;
}


bool Piece::isLegal(Square new_position) const
{
    return (_cb->isLegal(_position, new_position));
}


string Pawn::type() const
{
    return "Pawn";
}


bool Pawn::hasNoMoves() const
{
    int dir = (_colour == WHITE) ? 1 : -1;
    
    if (isLegal(_position + dir)         ||
        isLegal(_position + dir + dir)   ||
        isLegal(_position + dir + LEFT)  ||
        isLegal(_position + dir + RIGHT))       
        return false;

    return true;
}


bool Rook::canAccess(Square new_position)
{    
    int dir = getDirection(_position, new_position);
    if (dir != UP &&
        dir != DOWN &&
        dir != LEFT &&
        dir != RIGHT)
        return false;
    
    for (Square i = _position + dir; i != new_position; i += dir) {
        if (!_cb->isEmpty(i))
            return false;
    }
    
    return true;
}


bool Rook::hasNoMoves() const
{
    for (int i = -7; i <= 7; i++) {
        if (isLegal(_position + Square(i, 0)) ||
            isLegal(_position + Square(0, i)))
            return false;
    }

    return true;
}


string Rook::type() const
{
    return "Rook";
}


bool Bishop::canAccess(Square new_position)
{    
    int dir = getDirection(_position, new_position);
    if (dir != UP_L &&
        dir != UP_R &&
        dir != DOWN_L &&
        dir != DOWN_R)
        return false;
    
    for (Square i = _position + dir; i != new_position; i += dir) {
        if (!_cb->isEmpty(i))
            return false;
    }
    
    return true;
}


bool Bishop::hasNoMoves() const
{
    for (int i = -7; i <= 7; i++) {
        if (isLegal(_position + Square(i, i)) ||
            isLegal(_position + Square(i, -i)))
            return false;
    }

    return true;
}


string Bishop::type() const
{
    return "Bishop";
}


bool Knight::canAccess(Square new_position)
{
    if (new_position == _position + Square(2, 1)    ||
        new_position == _position + Square(1, 2)    ||
        new_position == _position + Square(2, -1)   ||
        new_position == _position + Square(-1, 2)   ||
        new_position == _position + Square(-2, 1)   ||
        new_position == _position + Square(1, -2)   ||
        new_position == _position + Square(-2, -1)  ||
        new_position == _position + Square(-1, -2))
        return true;

    return false;
}


bool Knight::hasNoMoves() const
{    
    if (isLegal(_position + Square(2, 1))    ||
        isLegal(_position + Square(1, 2))    ||
        isLegal(_position + Square(2, -1))   ||
        isLegal(_position + Square(-1, 2))   ||
        isLegal(_position + Square(-2, 1))   ||
        isLegal(_position + Square(1, -2))   ||
        isLegal(_position + Square(-2, -1))  ||
        isLegal(_position + Square(-1, -2)))
        return false;

    return true;
}


string Knight::type() const
{
    return "Knight";
}


bool Queen::canAccess(Square new_position)
{
    int dir = getDirection(_position, new_position);
    if (dir == 0) return false;

    for (Square i = _position + dir; i != new_position; i += dir) {
        if (!_cb->isEmpty(i))
            return false;
    }
    
    return true;
}


bool Queen::hasNoMoves() const
{
    for (int i = -7; i <= 7; i++) {
        if (isLegal(_position + Square(0, i))  ||
            isLegal(_position + Square(i, 0))  ||
            isLegal(_position + Square(i, i))  ||
            isLegal(_position + Square(i, -i)))
            return false;
    }

    return true;
}


string Queen::type() const
{
    return "Queen";
}


bool King::canAccess(Square new_position)
{
    for (int dir = 1; dir <= 8; dir++) {
        if (new_position == _position + dir)
            return true;
    }

    if (!_has_moved) {
        if (new_position == _position + LEFT + LEFT) {
            _castling = LEFT;
            return true;
        }
        if (new_position == _position + RIGHT + RIGHT) {
            _castling = RIGHT;
            return true;
        }
    }
    
    return false;
}


bool King::hasNoMoves() const
{
    for (int dir = 1; dir <= 8; dir++) {
        if (isLegal(_position + dir))
            return false;
    }

    return true;
}


string King::type() const
{
    return "King";
}
