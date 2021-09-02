#pragma once
#include <vector>
class State {
    public:
        
        using Board = std::vector<int>; // 2, 5, 7,  --> 
                                        // 0, 1, 3, 
                                        // 6, 8, 4
        
        State(Board board, Board goal, int g );

        std::vector<State> getSucessors() const;
        int getF() const;
        bool isGoal() const;

        bool operator==(State const & other) const;
        bool operator!=(State const & other) const;
        //bool operator>(State const & other);

        // ** private methods ** //
        int getEmptySpaceIndex() const;
        std::vector<Board> getPossibleMoves() const;
        Board swapElements(int i1, int i2) const;
        // Distance from goal
        int getH() const;
        int getG() const;
        
        Board board_, goal_;
        int g_;
};