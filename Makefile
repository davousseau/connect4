CFLAGS = -std=c99 -pedantic -W -Wall

.PHONY: default memcheck test clean
.SILENT: doc memcheck

default:
	mkdir -p bin
	gcc src/connect4.c -g $(CFLAGS) -o bin/connect4

doc:
	mkdir -p $@
	(cat Doxyfile 2> doxygen.log;\
	echo 'GENERATE_LATEX=NO';\
	echo 'HAVE_DOT=NO';\
	echo 'OPTIMIZE_OUTPUT_FOR_C=YES';\
	echo 'OUTPUT_DIRECTORY=$@';\
	echo 'PROJECT_NAME="Puissance 4"';\
	echo 'RECURSIVE=YES') | doxygen - >> doxygen.log
	ln -rsf $@/html/index.html $@/index.html

memcheck: default
	valgrind --leak-check=full \
	--show-leak-kinds=all \
	--track-origins=yes \
	--verbose \
	--log-file=valgrind.log \
	bin/connect4 < tests-data/td06.in > /dev/null

test: default
	./tests.sh

clean:
	rm -rf bin doc *log
