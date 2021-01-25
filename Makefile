# Compiler and its flags
CC=gcc
CFLAGS = -std=c99 -pedantic -W -Wall

# Project name
PROJECT_NAME="Puissance 4"

# All directories
BIN_DIR=bin
TESTS_DATA_DIR=tests_data
TESTS_LOG_DIR=tests_log
DOC_DIR=doc
SRC_DIR=src

# Executable file
EXEC=connect4

# Tests script file
TESTS=tests.sh

# All log files
DOXYGEN_LOG=doxygen.log
VALGRIND_LOG=valgrind.log

# Documentation index
DOC_INDEX=index.html

.PHONY: default memcheck test clean
.SILENT: $(DOC_DIR) memcheck

# Compile the executable.
default:
	mkdir -p $(BIN_DIR)
	$(CC) $(SRC_DIR)/$(EXEC).c -g $(CFLAGS) -o $(BIN_DIR)/$(EXEC)

# Generate the documentation.
$(DOC_DIR):
	mkdir -p $@
	(cat Doxyfile 2> $(DOXYGEN_LOG);\
	echo 'GENERATE_LATEX=NO';\
	echo 'HAVE_DOT=NO';\
	echo 'OPTIMIZE_OUTPUT_FOR_C=YES';\
	echo 'OUTPUT_DIRECTORY=$@';\
	echo 'PROJECT_NAME=$(PROJECT_NAME)';\
	echo 'RECURSIVE=YES') | doxygen - >> $(DOXYGEN_LOG)
	ln -rsf $@/html/$(DOC_INDEX) $@/$(DOC_INDEX)

# Check for memory leaks.
memcheck: default
	valgrind --leak-check=full \
	--show-leak-kinds=all \
	--track-origins=yes \
	--verbose \
	--log-file=$(VALGRIND_LOG) \
	$(BIN_DIR)/$(EXEC) < $(TESTS_DATA_DIR)/test_06.in > /dev/null

# Run a series of tests.
test:
	rm -rf $(TESTS_LOG_DIR)
	mkdir $(TESTS_LOG_DIR)
	./$(TESTS)

# Clean the working directory.
clean:
	rm -rf $(BIN_DIR) $(DOC_DIR) *log
