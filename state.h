#pragma once
#include <vector>
#include <iostream>

class State {
    public:
        
        using Board = std::vector<int>; // 2, 5, 7,  --> 
                                        // 0, 1, 3, 
                                        // 6, 8, 4
        
        State(Board board, Board goal, int g, State * parent = nullptr );

        std::vector<State*> getSucessors();
        int getF() const;
        bool isGoal() const;

        bool operator==(State const & other) const;
        bool operator!=(State const & other) const;
        friend std::ostream& operator<<(std::ostream& os, State const&);
        //bool operator>(State const & other);

        // ** private methods ** //
        int getEmptySpaceIndex() const;
        std::vector<Board> getPossibleMoves() const;
        Board swapElements(int i1, int i2) const;
        // Distance from goal
        int getH() const;
        int getG() const;
        State * getParent();
        
        Board board_, goal_;
        State * parent_ = nullptr;
        int g_;
};