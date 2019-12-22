SRC_FILES := $(wildcard ./src/*.hpp)
TEST_FILES := $(wildcard ./tests/test_*.cpp)
TEST_FILES := $(filter-out ./tests/test_main.cpp, $(TEST_FILES))

program: $(SRC_FILES) $(TEST_FILES)
ifeq ($(wildcard test_main.o),)
	g++ -c ./tests/test_main.cpp -std=c++11
endif
	g++ $(SRC_FILES) $(TEST_FILES) ./test_main.o -o run_tests -std=c++11
	./run_tests

clean:
	-rm -f run_tests test_main.o