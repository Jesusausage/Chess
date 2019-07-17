EXE = chess
SRC = ChessMain.cpp Piece.cpp Square.cpp ChessBoard.cpp ChessHelper.cpp
OBJ = $(SRC:%.cpp=%.o)
DEP = $(OBJ:%.o=%.d)
FLAGS = -Wall -g -MMD -c

$(EXE): $(OBJ)
	g++ $^ -o $@

%.o: %.cpp
	g++ $(FLAGS) $<

-include $(DEP)

clean:
	rm -f $(OBJ) $(DEP) $(EXE)

.PHONY: clean
