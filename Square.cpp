#include "Square.h"


namespace chess {


    bool Square::isOnBoard()
    {
        return (_rank <= 8 && _rank >= 1 && _file <= 8 && _file >= 1);
    }


    Square operator+(Square sq1, Square sq2)
    {
        return Square(sq1._file + sq2._file, sq1._rank + sq2._rank);
    }


    Square operator+(Square sq, int dir)
    {    
        switch (dir) {
        case UP : return Square(sq._file, sq._rank + 1);
        case DOWN : return Square(sq._file, sq._rank - 1);
        case LEFT : return Square(sq._file - 1, sq._rank);
        case RIGHT : return Square(sq._file + 1, sq._rank);
        case UP_L : return Square(sq._file - 1, sq._rank + 1);
        case UP_R : return Square(sq._file + 1, sq._rank + 1);
        case DOWN_L : return Square(sq._file - 1, sq._rank - 1);
        case DOWN_R : return Square(sq._file + 1, sq._rank - 1);
        default : return sq;
        }
    }


    Square& operator+=(Square& sq, int dir)
    {
        sq = sq + dir;
        return sq;
    }


    bool operator==(Square sq1, Square sq2)
    {
        return (sq1._file == sq2._file && sq1._rank == sq2._rank);
    }


    bool operator!=(Square sq1, Square sq2)
    {
        return (sq1._file != sq2._file || sq1._rank != sq2._rank);
    }


    bool operator<(Square sq1, Square sq2)
    {
        if (sq1._rank == sq2._rank)
            return (sq1._file < sq2._file);
        return (sq1._rank < sq2._rank);
    }


    int getDirection(Square pos, Square new_pos)
    {
        if (pos == new_pos) return 0;

        int file_shift = new_pos._file - pos._file;
        int rank_shift = new_pos._rank - pos._rank;

        if (file_shift == 0)
            return (rank_shift > 0) ? UP : DOWN;
        if (rank_shift == 0)
            return (file_shift > 0) ? RIGHT : LEFT;     
        if (file_shift == rank_shift)
            return (file_shift > 0) ? UP_R : DOWN_L;
        if (file_shift == -rank_shift)
            return (file_shift > 0) ? DOWN_R : UP_L;
        
        return 0;
    }


}
