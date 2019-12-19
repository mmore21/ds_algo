SRC_FILES := $(wildcard ./lib/*.hpp)
TEST_FILES := $(wildcard ./tests/test_*.cpp)
TEST_FILES := $(filter-out ./tests/test_main.cpp, $(TEST_FILES))

program: $(SRC_FILES) $(TEST_FILES)
	g++ -c ./tests/test_main.cpp -std=c++11
	g++ $(SRC_FILES) $(TEST_FILES) ./test_main.o -o run_tests -std=c++11
	./run_tests

clean:
	-rm -f run_tests test_main.o