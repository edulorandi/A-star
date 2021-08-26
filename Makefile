# all:
# 	echo "not implemented"
test: board.cpp tests/test.cpp
     g++ -std=c++17 board.cpp tests/test.cpp -o test.o
# clean:
# 	echo "not implemented"