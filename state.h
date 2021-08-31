#pragma once
#include <vector>
class State {
    public:
        
        using Board = std::vector<int>; // 2, 5, 7,  --> 
                                        // 0, 1, 3, 
                                        // 6, 8, 4
        State(Board board, Board goal, int g );

        int getEmptySpaceIndex();
        std::vector<State> getSucessors();
        //bool operator==(State & other);
        int getF();
        int getG();
        
        // Distance from goal
        int getH();

        bool isGoal();

        //
        std::vector<Board> getPossibleMoves();
        Board swapElements(int i1, int i2);
        
        Board board_, goal_;
        int g_;
};