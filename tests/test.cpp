#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"
#include "../state.h"


TEST_CASE( "Test getEmptySpaceIndex", "[getEmptySpaceIndex]" ) {
    
    std::vector<int> board = {1,2,3,4,0,5,6,7,8};
    std::vector<int> board2 = {1,2,3,4,8,5,6,7,0};
    std::vector<int> goal = {1,2,3,4,5,0,6,7,8};

    State state(board, goal, 0);
    REQUIRE( state.getEmptySpaceIndex() == 4);

    State stat2(board2, goal, 0);
    REQUIRE( stat2.getEmptySpaceIndex() == 8);
}