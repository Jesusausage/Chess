#include "ChessBoard.h"


using namespace chess;
using namespace std;


ChessBoard::ChessBoard()
{
    setBoard();
    cout << "1    2    3    4    5    6    7    8    9    10    11    12    13    14    15    16    17    18    19    20    21";
}


ChessBoard::~ChessBoard()
{
    map<Square, Piece*>::iterator iter;
    for (iter = _piece_at.begin(); iter != _piece_at.end(); iter++)
        delete iter->second;
    
    set<Piece*>::iterator it;
    for (it = _grave.begin(); it != _grave.end(); it++)
	delete *it;
}


void ChessBoard::setBoard()
{
    _current_player = WHITE;
    _game_over = false;
        
    cout << "A new chess game is started!\n";
    
    for (int i = 1; i <= 8; i++) {
        _piece_at[Square(i, 2)] = new Pawn(this, WHITE, Square(i, 2));        
        _piece_at[Square(i, 7)] = new Pawn(this, BLACK, Square(i, 7));
    }

    _piece_at[Square(1, 1)] = new Rook(this, WHITE, Square(1, 1));
    _piece_at[Square(8, 1)] = new Rook(this, WHITE, Square(8, 1));
    _piece_at[Square(1, 8)] = new Rook(this, BLACK, Square(1, 8));
    _piece_at[Square(8, 8)] = new Rook(this, BLACK, Square(8, 8));

    _piece_at[Square(3, 1)] = new Bishop(this, WHITE, Square(3, 1));
    _piece_at[Square(6, 1)] = new Bishop(this, WHITE, Square(6, 1));
    _piece_at[Square(3, 8)] = new Bishop(this, BLACK, Square(3, 8));
    _piece_at[Square(6, 8)] = new Bishop(this, BLACK, Square(6, 8));
 
    _piece_at[Square(2, 1)] = new Knight(this, WHITE, Square(2, 1));
    _piece_at[Square(7, 1)] = new Knight(this, WHITE, Square(7, 1));
    _piece_at[Square(2, 8)] = new Knight(this, BLACK, Square(2, 8));
    _piece_at[Square(7, 8)] = new Knight(this, BLACK, Square(7, 8));

    _piece_at[Square(4, 1)] = new Queen(this, WHITE, Square(4, 1));
    _piece_at[Square(4, 8)] = new Queen(this, BLACK, Square(4, 8));

    _piece_at[Square(5, 1)] = new King(this, WHITE, Square(5, 1));
    _piece_at[Square(5, 8)] = new King(this, BLACK, Square(5, 8));
}


void ChessBoard::submitMove(string const src_str, string const dest_str)
{
    if (_game_over) {
        cout << "Game is already over\n";
        return;
    }
    
    Square source = getSquare(src_str);
    Square destination = getSquare(dest_str);
    
    if (!isLegalMove(source, destination, src_str, dest_str)) return;

    _piece_at[source]->hasNowMoved(); // sets moved flag
    printMove(source, destination, src_str, dest_str);
    movePiece(source, destination);
    _current_player = (!_current_player); // swap player

    if (isInCheck(_current_player)) {
        cout << (_current_player ? "White" : "Black") << " is in check";
        cout << (isGameOver() ? "mate\n" : "\n");
    } else
        cout << (isGameOver() ? "Stalemate\n" : "");
}


bool ChessBoard::isAccessibleMove(Square source, Square destination,
                                  string const src_str, string const dest_str)
{
    if (_piece_at[source] == nullptr) {
        cout << "There is no piece at position " << src_str << "!\n";
        return false;
    }

    if (_piece_at[source]->colour() != _current_player) {
        cout << "It is not "
             << (_piece_at[source]->colour() ? "White" : "Black")
             << "'s turn to move!\n";
        return false;
    }

    if (_piece_at[destination] &&
        _piece_at[destination]->colour() == _current_player) {
        cout << (_piece_at[source]->colour() ? "White" : "Black") << "'s "
             << _piece_at[source]->type()
             << " cannot attack a friendly piece!\n";
        return false;
    }
    
    if (!_piece_at[source]->canAccess(destination)) {
        cout << (_piece_at[source]->colour() ? "White" : "Black") << "'s "
             << _piece_at[source]->type() << " cannot move to "
             << dest_str << "!\n";
        return false;
    }

    return true;
}


bool ChessBoard::isLegalMove(Square source, Square destination,
                             string const src_str, string const dest_str)
{
    if (!source.isOnBoard()) {
        cout << "'" << src_str << "' is not a valid source square.\n";
        return false;
    }
    if (!destination.isOnBoard()) {
        cout << "'" << dest_str << "' is not a valid destination square.\n";
        return false;
    }

    if (!isAccessibleMove(source, destination, src_str, dest_str))
        return false;

    if (_piece_at[source]->type() == "King" &&
        ((King*)_piece_at[source])->isCastling()) { // checks castle flag
        if (canCastle(source))
            return true;
        else
            return false;
    }

    Piece* old_piece = _piece_at[destination]; // Save state of board
    movePiece(source, destination);
    
    if (isInCheck(_current_player)) {
        undoMove(source, destination, old_piece); // Restore old piece
        cout << (_piece_at[source]->colour() ? "White" : "Black")
             << " cannot make a move that leaves them in check!\n";
        return false;
    }    
    undoMove(source, destination, old_piece); // Restore old piece
    return true;
}


bool ChessBoard::isLegal(Square source, Square destination)
{
    if (!source.isOnBoard() || !destination.isOnBoard())
        return false;
    
    if (_piece_at[source] == nullptr)
        return false;

    if (_piece_at[source]->colour() != _current_player)
        return false;

    if (_piece_at[destination] &&
        _piece_at[destination]->colour() == _current_player)
        return false;
    
    if (!_piece_at[source]->canAccess(destination))
        return false;
    
    Piece* old_piece = _piece_at[destination];
    movePiece(source, destination);
    
    if (isInCheck(_current_player)) {
        undoMove(source, destination, old_piece);
        return false;
    }    
    undoMove(source, destination, old_piece);
    return true;
}


void ChessBoard::printMove(Square source, Square destination,
                           string const src_str, string const dest_str)
{    
    Piece* piece = _piece_at[source];
    cout << (piece->colour() ? "White" : "Black") << "'s "
         << piece->type() << " moves from " << src_str
         << " to " << dest_str;    
    if (_piece_at[destination] != nullptr) {
        Piece* enemy = _piece_at[destination];
        cout << " taking " << (enemy->colour() ? "White" : "Black")
             << "'s " << enemy->type() << endl;
    } else
        cout << endl;
}


void ChessBoard::movePiece(Square source, Square destination)
{
    if (_piece_at[destination])
        _piece_at[destination]->moveTo(Square(-1, -1));
    _piece_at[source]->moveTo(destination);

    if (_piece_at[destination])
        _grave.insert(_piece_at[destination]);
    _piece_at[destination] = _piece_at[source];
    _piece_at[source] = nullptr;
}


void ChessBoard::undoMove(Square source, Square destination,
                          Piece* old_piece)
{
    _piece_at[destination]->moveTo(source);
    if (old_piece)
        old_piece->moveTo(destination);
    
    _piece_at[source] = _piece_at[destination];
    _piece_at[destination] = old_piece;
    if (old_piece)
	_grave.erase(old_piece);
    
}


bool ChessBoard::isEmpty(Square position)
{
    return (_piece_at[position] == nullptr);
}


bool ChessBoard::isInCheck(bool current_player)
{
    Square king_position(-1, -1);
    for (auto mapping : _piece_at) {
        Piece* piece = mapping.second;
        
        if (piece != nullptr &&
            piece->colour() == current_player &&
            piece->type() == "King") {      
            king_position = mapping.first; // Get king position
            break;
        }
    }
    
    for (auto mapping : _piece_at) {
        Piece* piece = mapping.second;
        
        if (piece != nullptr &&
            piece->colour() != current_player &&
            piece->canAccess(king_position))        
            return true;
    }

    return false;
}


bool ChessBoard::isGameOver()
{
    map<Square, Piece*>::iterator iter;
    for (iter = _piece_at.begin(); iter != _piece_at.end(); iter++) {
        Piece* piece = iter->second;

        if (piece != nullptr &&
            piece->colour() == _current_player &&
            !piece->hasNoMoves()) // Checks if any piece has moves
            return false;
    }

    _game_over = true;
    return true;
}


void ChessBoard::resetBoard()
{
    for (auto mapping : _piece_at) {
        delete mapping.second;
    }    

    _piece_at.clear();

    setBoard();
}


bool ChessBoard::canCastle(Square king_position)
{
    int dir = ((King*)_piece_at[king_position])->isCastling();    
    int file = (dir == LEFT) ? 1 : 8;
    int rank = (_current_player) ? 1 : 8;
    Square rook_position(file, rank);

    // Checks if rook satisfies conditions
    if (!_piece_at[rook_position]                  ||
        _piece_at[rook_position]->type() != "Rook" ||
        _piece_at[rook_position]->hasMoved()) {
        cout << (_current_player ? "White" : "Black")
             << " cannot castle after rook has moved\n";
        return false;
    }

    // Checks if path is free
    for (Square i = king_position + dir; i != rook_position; i += dir)
        if (!isEmpty(i)) {
            cout << (_current_player ? "White" : "Black")
                 << " cannot castle through blocked path\n";
            return false;
        }

    // Checks if castling through check
    if (!legalCastle(king_position, rook_position, dir)) {
        cout << (_current_player ? "White" : "Black")
             << " cannot castle through check\n";
        return false;
    }
    
    cout << (_current_player ? "White" : "Black") << " is castling:\n";
    ((King*)_piece_at[king_position])->hasCastled();
    return true;
}


bool ChessBoard::legalCastle(Square king_position,
                             Square rook_position, int dir)
{
    // Ensure first king position is not in check
    movePiece(king_position, king_position + dir);    
    if (isInCheck(_current_player)) {
        undoMove(king_position, king_position + dir, nullptr);
        return false;
    }
    undoMove(king_position, king_position + dir, nullptr);

    // Ensure second king position is not in check
    movePiece(king_position, king_position + dir + dir);
    movePiece(rook_position, king_position + dir);
    if (isInCheck(_current_player)) {
        undoMove(king_position, king_position + dir + dir, nullptr);
        undoMove(rook_position, king_position + dir, nullptr);
        return false;
    }    
    undoMove(king_position, king_position + dir + dir, nullptr);
    // If castling is legal, the rook is not moved back
    return true;
}
