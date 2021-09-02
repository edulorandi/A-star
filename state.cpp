#include <array>
#include "state.h"

State::State(Board board, Board goal, int g ) : board_(board), goal_(goal), g_(g){
}

std::vector<State> State::getSucessors() const {
    auto possibleMoves = getPossibleMoves();
    std::vector<State> sucessors;
    std::transform(possibleMoves.begin(), possibleMoves.end(), std::back_inserter(sucessors),[this](auto const & sucessorBoard){
        return State(sucessorBoard, goal_, getG()+1);
    } );
    return sucessors;
}

bool State::operator==(State const & other) const{
    return goal_ == other.goal_ &&
           board_ == other.board_ &&
           getG() == other.getG();
}

bool State::operator!=(State const & other) const{
    return !((*this)==other);
}

int State::getEmptySpaceIndex() const{
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

State::Board State::swapElements(int i1, int i2) const{
    Board result = board_;
    result[i2] = board_[i1];
    result[i1] = board_[i2];
    return result;
}

std::vector<State::Board> State::getPossibleMoves() const{
    std::vector<State::Board> moves;
    switch (getEmptySpaceIndex())
    {
    case 0:
        moves.push_back(swapElements(0,1));
        moves.push_back(swapElements(0,3));
        break;
    case 1:
        moves.push_back(swapElements(1,0));
        moves.push_back(swapElements(1,2));
        moves.push_back(swapElements(1,4));
        break;
    case 2:
        moves.push_back(swapElements(2,1));
        moves.push_back(swapElements(2,5));
        break;
    
    case 3:
        moves.push_back(swapElements(3,0));
        moves.push_back(swapElements(3,4));
        moves.push_back(swapElements(3,6));
        break;
    case 4:
        moves.push_back(swapElements(4,1));
        moves.push_back(swapElements(4,3));
        moves.push_back(swapElements(4,5));
        moves.push_back(swapElements(4,7));
        break;
    case 5:
        moves.push_back(swapElements(5,4));
        moves.push_back(swapElements(5,2));
        moves.push_back(swapElements(5,8));
        break;
    case 6:
        moves.push_back(swapElements(6,3));
        moves.push_back(swapElements(6,7));
        break;
    case 7:
        moves.push_back(swapElements(7,6));
        moves.push_back(swapElements(7,8));
        moves.push_back(swapElements(7,4));
        break;
     case 8:
        moves.push_back(swapElements(8,7));
        moves.push_back(swapElements(8,5));
        break;
    default:
        assert(false);
        break;
    }

    return moves;
}


 int State::getF() const{
     return getG()+getH();
 }

int State::getG() const {
    return g_;
}

bool State::isGoal() const{
    return goal_ == board_;
}

// aqui a gente faz a euristica -> manhattan ou ruim
int State::getH() const {
    auto misplacedCells  = 0;
    for(auto i = 0; i<board_.size(); ++i) {
        if( goal_[i] != board_[i]) {
            misplacedCells++;
        }
    }
    return misplacedCells;
}