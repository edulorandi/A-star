#include <array>
#include "state.h"

State::State(Board board, Board goal, int parentG ) : board_(board), goal_(goal), parentG_(parentG){
}

 int State::getEmptySpaceIndex() {
     auto emptyIndex = std::find(board_.begin(), board_.end(), 0);
     assert(emptyIndex != board_.end());
     return *emptyIndex;
 }

 std::vector<State> getSucessors() {
     return{};
 }

std::vector<State::Board> getPossibleMoves();


 int State::getF() {
     return getG()+h_;
 }

int State::getG() {
    return parentG_+1;
}