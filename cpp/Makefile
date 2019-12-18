SRC_FILES := $(wildcard ./lib/*.hpp)
TEST_FILES := $(wildcard ./tests/test_*.cpp)
TEST_FILES := $(filter-out ./tests/test_main.cpp, $(TEST_FILES))

g++ ./tests/test_main.cpp -c
g++ $(SRC_FILES) $(SRC_FILES) ./test_main.o -o tests
./tests