#!/bin/bash
# Directories
DATA_DIR=tests_data
LOG_DIR=tests_log

# Executable
EXEC=bin/connect4

# test_00: Compile using makefile.
make > $LOG_DIR/test_00.err
if [ $? -gt 0 ]; then
	echo -e "[\033[31mERR\033[0m] \033[1mtest_00: makefile has errors\e[0m"
	echo -e "$(cat $LOG_DIR/test_00.err)"
	exit 1
elif [ ! -f $EXEC ]; then
	echo -e "[\033[31mERR\033[0m] \033[1mtest_00: executable not found\e[0m"
	echo -e "$(cat $LOG_DIR/test_00.err)"
	exit 1
else
	echo -e "[\033[32mOK\e[0m] \033[1mtest_00: make succesfully completed\e[0m"
fi

# test_**: Run all unit tests.
for data in $(ls $DATA_DIR/*.in); do
	test_basename=$(basename "$data")
	test_name="${test_basename%.*}"
	test_in="$DATA_DIR/$test_name.in"
	test_res="$DATA_DIR/$test_name.res"
	test_out="$LOG_DIR/$test_name.out"
	test_diff="$LOG_DIR/$test_name.diff"

	# Make sure the expected result file exists in the working directory.
	if [ ! -f $test_res ]; then
		echo -e "[\033[31mERR\033[0m] \033[1m$test_name: expected result not found\e[0m"
		continue
	fi

	# Run the test.
	timeout 2 $EXEC < $test_in > $test_out 2>&1
	if [ $? -gt 0 ]; then
		echo -e "[\033[31mERR\033[0m] \033[1m$test_name: timeout\e[0m"
		continue
	fi

	# Remove trailing whitespace from the output.
	sed -i 's/\s*$//' $test_out

	# Make sure the output is not empty.
	if [ ! -f $tests_out ]; then
		echo -e "[\033[31mERR\033[0m] \033[1m$test_name: no output\e[0m"
		continue
	fi

	# Make sure the output is not different from the expected result.
	diff $test_res $test_out > $test_diff
	if [ -s $test_diff ]; then
		echo -ne "[\033[33mDIFF\033[0m] \033[1m$test_name: $(basename "$test_out") "
		echo -e "is different from $(basename "$test_res")\e[0m"
	else
		echo -e "[\033[32mOK\e[0m] \033[1m$test_name\e[0m"
	fi
done
