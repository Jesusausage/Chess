#ifndef SQUARE_H
#define SQUARE_H


namespace chess {

    
    enum { UP = 1, DOWN, LEFT, RIGHT, UP_L, UP_R, DOWN_L, DOWN_R };
    
    
    class Square {
    public:
        Square(int file, int rank) : _file(file), _rank(rank) {}

        // Checks if square is on a chessboard
        bool isOnBoard();
        
        // Adds the coordinates
        friend Square operator+(Square sq1, Square sq2);
        
        // Increments coordinates in direction of travel
        friend Square operator+(Square sq, int dir);
        friend Square& operator+=(Square& sq, int dir);
        
        friend bool operator==(Square sq1, Square sq2);
        friend bool operator!=(Square sq1, Square sq2);
        friend bool operator<(Square sq1, Square sq2);

        // Returns the direction of new_pos in relation to pos
        // Returns 0 if not in straight line or diagonal
        friend int getDirection(Square pos, Square new_pos);
    
    private:
        int _file;
        int _rank;
    };


}


#endif
