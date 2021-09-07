#include "state.h"
#include <iostream>

static constexpr int MAX_MOVES = 1000;

struct SolveReturn {
    State* finalState_;
    int numOfMoves_;
};

SolveReturn solve(State::Board initialBoard, State::Board goalBoard) {
    std::vector<State*> openList;
    std::vector<State*> closedList;

    auto initialState = new State(initialBoard,goalBoard,0);

    openList.push_back(initialState);
    while(!openList.empty()) {
        
        //this is when we give up
        if(closedList.size()>MAX_MOVES) {
            return {nullptr,0};
        }
       
        auto smallestNode = std::min_element(openList.begin(), openList.end(), [](State* first, State* second){
        return first->getF() < second->getF();
        });
        auto currentNode = *smallestNode;
        openList.erase(smallestNode);

        if(currentNode->board_ == goalBoard) {
            return {currentNode, (int)closedList.size()};
        }

        for( auto sucessor : currentNode->getSucessors()) {
            auto equalNodeOnOpen = std::find_if(openList.begin(), openList.end(), [&sucessor](State *existingNode){
                return existingNode->board_ == sucessor->board_;
                 });
            auto equalNodeOnClosed = std::find_if(closedList.begin(), closedList.end(), [&sucessor](State *existingNode){
                return existingNode->board_ == sucessor->board_;
                });

            if( equalNodeOnOpen != openList.end() ) {
                // equalNodeOnOpen exists
                if( (*equalNodeOnOpen)->getF() < sucessor->getF() ) {
                    continue;
                } 
            }

            if( equalNodeOnClosed != closedList.end() ) {
                // equalNodeOnClosed exists
                if( (*equalNodeOnClosed)->getF() < sucessor->getF() ) {
                    continue;
                } 
            } 
            else {
                openList.push_back(sucessor);
            }
        }
        closedList.push_back(currentNode);
    }
    return {nullptr,0};
}

void printPath(State*current) {
    if(current!=nullptr) {
        printPath(current->getParent());
        std::cout << *current << std::endl;
    }
}

int getNumOfMoves(State*current) {
    auto moves=1;
    if(current!=nullptr) {
        return getNumOfMoves(current->parent_)+1;
    }
    return -1;
}

int main () {

    State::Board goal = {1,2,3,8,0,4,7,6,5};
    
    //easy
    State::Board easyBoard = {1,3,4,8,6,2,0,7,5};
    //medium
    State::Board mediumBoard = {2,8,1,0,4,3,7,6,5};
    //hard
    State::Board hardBoard = {2,8,1,4,6,3,0,7,5};
    //worst
    State::Board worstBoard = {5,6,7,4,0,8,3,2,1};

    auto result = solve(worstBoard, goal);
    if( result.finalState_ == nullptr ) {
        std::cout << "More than " << MAX_MOVES << " moves analysed and no solution, aborting" << std::endl;
        return 0;
    }
    printPath(result.finalState_);
    std::cout << "Puzzle solved in " << getNumOfMoves(result.finalState_) << " moves" << std::endl;
    std::cout << "A total of " << result.numOfMoves_ << " moves were analysed" << std::endl;

    return 0;
}