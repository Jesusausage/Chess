#include "ChessHelper.h"


namespace chess {


    Square getSquare(std::string const coordinates)
    {
        if (coordinates.length() != 2) return Square(-1, -1);
    
        int file = coordinates[0] - 'A' + 1;
        int rank = coordinates[1] - '1' + 1;
        return Square(file, rank);
    }


}
