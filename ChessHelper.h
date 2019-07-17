#ifndef CHESSHELPER_H
#define CHESSHELPER_H


#include "Square.h"
#include <string>


namespace chess {


    bool const WHITE = true;
    bool const BLACK = false;

    // Generates a square based on string coordinates
    chess::Square getSquare(std::string const coordinates);


}


#endif
