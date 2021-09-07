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

TEST_CASE( "Test getH ruim", "[getH]" ) {
    
    std::vector<int> board = {1,2,3,4,0,5,6,7,8};
    std::vector<int> goal = {1,2,3,4,0,5,6,7,8};

    State state(board, goal, 0);
    REQUIRE( state.getH() == 0);

    
    std::vector<int> board2 = {1,2,3,4,5,0,6,7,8};
    std::vector<int> goal2 =   {1,2,3,4,0,5,6,7,8};
    State state2(board2, goal2, 0);

    REQUIRE( state2.getH() == 2);

    std::vector<int> board3 = {7,2,4,5,0,6,8,3,1};
    std::vector<int> goal3 =   {0,1,2,3,4,5,6,7,8};
    State state3(board3, goal3, 0);

    REQUIRE( state3.getH() == 9);

    std::vector<int> board4 =  {7,2,4,5,0,6,8,3,1};
    std::vector<int> goal4 =   {7,0,2,5,4,8,6,3,1};
    State state4(board4, goal4, 0);

    REQUIRE( state4.getH() == 5);

}

TEST_CASE( "Test getH manhattan", "[getH_Manhattan]" ) {
    
    std::vector<int> board = {1,2,3,4,0,5,6,7,8};
    std::vector<int> goal = {1,2,3,4,0,5,6,7,8};

    State state(board, goal, 0);
    REQUIRE( state.getH_Manhattan() == 0);

    
    std::vector<int> board2 = {1,2,3,4,5,0,6,7,8};
    std::vector<int> goal2 =   {1,2,3,4,0,5,6,7,8};
    State state2(board2, goal2, 0);

    REQUIRE( state2.getH_Manhattan() == 2);

    std::vector<int> board3 = {7,2,4,5,0,6,8,3,1};
    std::vector<int> goal3 =   {0,1,2,3,4,5,6,7,8};
    State state3(board3, goal3, 0);

    REQUIRE( state3.getH_Manhattan() == 20);
}

TEST_CASE( "Test getPossiblePositions", "[getPossiblePositions]" ) {
    
    std::vector<int> board = {1,2,3,4,0,5,6,7,8};
    std::vector<int> goal = {1,2,3,4,0,5,6,7,8};

    State state(board, goal, 0);
    auto possibleMoves = state.getPossibleMoves();
    REQUIRE( possibleMoves.size() == 4);
    REQUIRE(std::find(possibleMoves.begin(), possibleMoves.end(),State::Board{1,0,3,4,2,5,6,7,8}) != possibleMoves.end());
    REQUIRE(std::find(possibleMoves.begin(), possibleMoves.end(),State::Board{1,2,3,0,4,5,6,7,8}) != possibleMoves.end());
    REQUIRE(std::find(possibleMoves.begin(), possibleMoves.end(),State::Board{1,2,3,4,5,0,6,7,8}) != possibleMoves.end());
    REQUIRE(std::find(possibleMoves.begin(), possibleMoves.end(),State::Board{1,2,3,4,7,5,6,0,8}) != possibleMoves.end());

    std::vector<int> board2 = {1,2,3,4,5,7,6,0,8};
    std::vector<int> goal2 =   {1,2,3,4,0,5,6,7,8};
    State state2(board2, goal2, 0);
    auto possibleMoves2 = state2.getPossibleMoves();
    REQUIRE( possibleMoves2.size() == 3);
    REQUIRE(std::find(possibleMoves2.begin(), possibleMoves2.end(),State::Board{1,2,3,4,5,7,6,8,0}) != possibleMoves2.end());
    REQUIRE(std::find(possibleMoves2.begin(), possibleMoves2.end(),State::Board{1,2,3,4,5,7,0,6,8}) != possibleMoves2.end());
    REQUIRE(std::find(possibleMoves2.begin(), possibleMoves2.end(),State::Board{1,2,3,4,0,7,6,5,8}) != possibleMoves2.end());

}

TEST_CASE( "Test getSucessors", "[getSucessors]" ) {

    // std::vector<int> board = {1,2,3,4,5,7,6,0,8};
    // std::vector<int> goal =   {1,2,3,4,0,5,6,7,8};
    // State state(board, goal, 0);
    // auto sucessors = state.getPossibleMoves();
    // auto sucessor1 = State(State::Board{1,2,3,4,5,7,6,8,0},state.goal_, state.getG()+1);
    // auto sucessor2 = State(State::Board{1,2,3,4,5,7,0,6,8},state.goal_, state.getG()+1);
    // auto sucessor3 = State(State::Board{1,2,3,4,0,7,6,5,8},state.goal_, state.getG()+1);

    // REQUIRE(std::find(sucessors.begin(), sucessors.end(),sucessor1) != sucessors.end());
    // REQUIRE(std::find(sucessors.begin(), sucessors.end(),sucessor2) != sucessors.end());
    // REQUIRE(std::find(sucessors.begin(), sucessors.end(),sucessor3) != sucessors.end());

}

TEST_CASE( "Test isGoal", "[isGoal]" ) {
    
    std::vector<int> board = {1,2,3,4,0,5,6,7,8};
    std::vector<int> goal = {1,2,3,4,0,5,6,7,8};

    State state(board, goal, 0);
    REQUIRE( state.isGoal() == true);

    std::vector<int> board2 = {1,2,3,4,5,0,6,7,8};
    std::vector<int> goal2 = {1,2,3,4,0,5,6,7,8};
    State state2(board2, goal2, 0);
    REQUIRE( state2.isGoal() == false);

}