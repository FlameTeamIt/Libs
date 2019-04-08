#!/bin/bash

SRC_DIR=$1

add_files()
{
	local SRC_DIR=$1
	echo "Surce dir is '$SRC_DIR'"
	echo "Directory list is" `find $SRC_DIR -type d`
	for dir in `find $SRC_DIR -type d`; do
		local FILE=./Files.cmake
		echo "Add to $dir/$FILE:"
		echo -en "set (FILE_LIST\n"

		cd $dir

		echo -en "set (FILE_LIST\n" > $FILE

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

add_files $1

