#include "state.h"
#include <iostream>

int solve(State::Board initialBoard, State::Board goalBoard) {
    std::vector<State> openList;
    std::vector<State> closedList;
    int numberOfMoves = 0;

    auto initialState = State(initialBoard,goalBoard,0);

    openList.push_back(initialState);
    while(!openList.empty()) {
        auto smallestNode = std::min_element(openList.begin(), openList.end(), [](State first, State second){
        return first.getF() < second.getF();
        });
        auto currentNode = *smallestNode;
        openList.erase(smallestNode);

        if(currentNode.board_ == goalBoard) {
            return numberOfMoves;
        }

        for( auto const sucessor : currentNode.getSucessors()) {
            auto equalNodeOnOpen = std::find_if(openList.begin(), openList.end(), [&sucessor](State existingNode){
                return existingNode.board_ == sucessor.board_;
                 });
            auto equalNodeOnClosed = std::find_if(closedList.begin(), closedList.end(), [&sucessor](State existingNode){
                return existingNode.board_ == sucessor.board_;
                });

            if( equalNodeOnOpen != openList.end() ) {
                // equalNodeOnOpen exists
                if( equalNodeOnOpen->getF() < sucessor.getF() ) {
                    continue;
                } 
            }

            if( equalNodeOnClosed != closedList.end() ) {
                // equalNodeOnClosed exists
                if( equalNodeOnClosed->getF() < sucessor.getF() ) {
                    continue;
                } 
            } 
            else {
                openList.push_back(sucessor);
            }
        }
        closedList.push_back(currentNode);
        numberOfMoves++;
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

    std::cout << solve(worstBoard, goal) << std::endl;

    return 0;
}