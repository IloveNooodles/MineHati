TC_FOLDER = tests
COVERAGE_DIR = coverage
EXT_IN = in
EXT_OUT = out
EXT_ANS = ans
EXECUTABLE_FILENAME = main
ALL_SRCS := $(wildcard lib/*/*.cpp)
SRCS     := $(filter-out check.cpp, $(ALL_SRCS))
ALL_INPUT := $(wildcard $(TC_FOLDER)/*.in)


all: compile test check

coverage_all: coverage_test coverage_run coverage_show

# Get coverage for all tests
coverage_test: 
	rm -rf $(COVERAGE_DIR)
	mkdir $(COVERAGE_DIR)
	cd ${COVERAGE_DIR} && g++ -std=c++17 -o main ../main_coverage.cpp --coverage ${addprefix "../", $(SRCS)}
	cd ${COVERAGE_DIR} && gcov ../main_coverage.cpp

coverage_show:
	cd ${COVERAGE_DIR} && lcov --directory . --capture --output-file coverage.info
	cd ${COVERAGE_DIR} && genhtml coverage.info --output-directory html

coverage_run:
	cd ${COVERAGE_DIR} && \
	for inputfile in $(addprefix "../",${ALL_INPUT}); do \
		 ./$(EXECUTABLE_FILENAME) < $$inputfile; \
	done;

# Compile all cpp files except check.cpp
compile:
	g++ -std=c++17 -o main main.cpp ${ALL_SRCS}

# run the program
run:
	./$(EXECUTABLE_FILENAME)

# Test
test: $(TC_FOLDER)/*.$(EXT_IN) $(EXECUTABLE_FILENAME)
	for inputfile in $(TC_FOLDER)/*.$(EXT_IN); do \
		./$(EXECUTABLE_FILENAME) < $$inputfile; \
	done;

# Check
check: FORCE check.cpp
	g++ -std=c++17 -o check check.cpp
	./check

FORCE: ;