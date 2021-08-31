# all:
# 	echo "not implemented"
test: state.cpp tests/test.cpp
     g++ -std=c++17 state.cpp tests/test.cpp -o test.o
# clean:
# 	echo "not implemented"