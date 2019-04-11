#!/bin/bash

add_sources()
{
	local SRC_DIR=$1
	local CMAKE_VARNAME="SOURCE_LIST"

	echo "Surce dir is '$SRC_DIR'"
	echo "Directory list is" `find $SRC_DIR -type d`
	for dir in `find $SRC_DIR -type d`; do
		local FILE=./Sources.cmake
		echo "Add to $dir/$FILE:"
		echo -en "set ($CMAKE_VARNAME\n"

		cd $dir

		echo -en "set ($CMAKE_VARNAME\n" > $FILE
		for src_file in `find . -maxdepth 1 -type f -name "*.cpp" | sort`; do
			echo -en "\t$src_file\n"
			echo -en "\t$src_file\n" >> $FILE;
		done
		echo -en ")\n"
		echo -en ")\n" >> $FILE;

		cd -

		echo
	done

}

add_headers()
{
	local FILE=cmake/Headers.cmake

	echo -ne "set(HEADER_LIST\n" > $FILE
	for header in `find $1 -type f -name "*.hpp" | sort`; do
		echo -ne "\t$header\n" >> $FILE
	done
	echo ")" >> $FILE
}

add_sources src
add_sources tests
add_headers include

