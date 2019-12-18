SRC_FILES := $(wildcard ./lib/*.hpp)
TEST_FILES := $(wildcard ./tests/test_*.cpp)
TEST_FILES := $(filter-out ./tests/test_main.cpp, $(TEST_FILES))

program: $(SRC_FILES) $(TEST_FILES)
	g++ -c ./tests/test_main.cpp
	g++ $(SRC_FILES) $(TEST_FILES) ./test_main.o -o run_tests
	./run_tests

clean:
	-rm -f run_tests test_main.o