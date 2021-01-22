CFLAGS = -std=c99 -pedantic -W -Wall

.PHONY: default memcheck test clean

default:
	mkdir -p bin
	gcc src/connect4.c -g $(CFLAGS) -o bin/connect4

doc:
	mkdir -p $@
	(cat Doxyfile ; echo 'GENERATE_LATEX=NO';\
	echo 'HAVE_DOT=NO';\
	echo 'OPTIMIZE_OUTPUT_FOR_C=YES';\
	echo 'OUTPUT_DIRECTORY=$@';\
	echo 'PROJECT_NAME="Puissance 4"';\
	echo 'RECURSIVE=YES') | doxygen -
	ln -rsf $@/html/index.html $@/index.html

memcheck: default
	valgrind --leak-check=full \
	--show-leak-kinds=all \
	--track-origins=yes \
	--verbose \
	--log-file=valgrind.log \
	bin/connect4 test/data/test6.in

test: default
	mkdir -p $@/log
	$@/tests.sh

clean:
	rm -rf bin doc *log
