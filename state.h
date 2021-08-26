#pragma once
#include <vector>
class State {
    public:
        
        using Board = std::vector<int>;
        State(Board board, Board goal, int parentG );

        int getEmptySpaceIndex();
        std::vector<State> getSucessors();
        //bool operator==(State & other);
        int getF();
        int getG();

        
        // this is the h, in this case the euristic
        int distanceFromGoal(Board goal);
        std::vector<Board> getPossibleMoves();
        
        Board board_, goal_;
        int h_, parentG_;
};