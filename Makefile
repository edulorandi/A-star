all:
# 	echo "not implemented"
     g++ -std=c++17 state.cpp main.cpp -o main
test: state.cpp tests/test.cpp
     g++ -std=c++17 state.cpp tests/test.cpp -o test.o
# clean:
# 	echo "not implemented"