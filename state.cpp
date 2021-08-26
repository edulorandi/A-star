#include <array>
#include "state.h"

State::State(Board board, Board goal, int g ) : board_(board), goal_(goal), g_(g){
}

 int State::getEmptySpaceIndex() {
     for(int i = 0; i<board_.size(); ++i) {
         if( board_.at(i) == 0 ) {
             return i;
         }
     }
     return board_.size();
 }

 std::vector<State> getSucessors() {
     // for each positibility:
    // list.add(posibility)
     return{};
 }

std::vector<State::Board> getPossibleMoves();


 int State::getF() {
     return getG()+getH();
 }

int State::getG() {
    return g_;
}

bool State::isGoal() {
    return goal_ == board_;
}

// aqui a gente faz a euristica -> manhattan ou ruim
int State::getH() {
    
}