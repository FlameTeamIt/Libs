#!/bin/bash

readonly SOURCE_FILENAME=Sources.cmake
readonly HEADER_FILENAME=Headers.cmake
readonly SOURCE_MODULES_FILENAME=cmake/SourceModules.cmake
readonly HEADER_MODULES_FILENAME=cmake/HeaderModules.cmake
readonly TEST_MODULES_FILENAME=cmake/TestModules.cmake

add_sources()
{
	local SRC_DIR=$1
	local ADD_TO_MODULE_LIST=$2

	local CMAKE_VARNAME="SOURCE_LIST"
	local MODULE_LIST_FILE=$SOURCE_MODULES_FILENAME

	if [[ "$ADD_TO_MODULE_LIST" == "true" ]]
	then
		echo -en "set(SOURCE_MODULES\n" > $MODULE_LIST_FILE
	fi

	echo "Source dir is '$SRC_DIR'"
	local directories=($(find $SRC_DIR -type d | grep -v "Tests"))
	echo "Directory list is ${directories[*]}"
	for dir in ${directories[*]}; do

		cd $dir &>/dev/null
		local src_files=($(find -maxdepth 1 -type f -name "*.cpp" | sort))
		cd - &>/dev/null

		if (( ${#src_files[*]} != 0 ))
		then
			if [[ "$ADD_TO_MODULE_LIST" == "true" ]]
			then
				echo -en "\t""\${CMAKE_CURRENT_SOURCE_DIR}/$dir""\n" >> $MODULE_LIST_FILE
			fi

			local FILE=$dir/$SOURCE_FILENAME

			echo "Add to $FILE:"
			echo -en "set ($CMAKE_VARNAME\n"
			echo -en "set ($CMAKE_VARNAME\n" > $FILE
			for src_file in ${src_files[*]}; do
				echo -en "\t\${CMAKE_CURRENT_SOURCE_DIR}/${src_file:2}\n"
				echo -en "\t\${CMAKE_CURRENT_SOURCE_DIR}/${src_file:2}\n" >> $FILE;
			done
			echo -en ")\n"
			echo -en ")\n" >> $FILE;
			echo
		else
			if [[ -e "$dir/$SOURCE_FILENAME" ]]
			then
				echo Remove $dir/$SOURCE_FILENAME
				rm -rf $dir/$SOURCE_FILENAME
				echo
			fi
		fi

	done

	if [[ "$ADD_TO_MODULE_LIST" == "true" ]]
	then
		echo -en ")\n" >> $MODULE_LIST_FILE
	fi
}

add_headers()
{
	local INC_DIR=$1
	local ADD_TO_MODULE_LIST=$2

	local CMAKE_VARNAME="HEADER_LIST"
	local MODULE_LIST_FILE=$HEADER_MODULES_FILENAME

	if [[ "$ADD_TO_MODULE_LIST" == "true" ]]
	then
		echo -en "set(HEADER_MODULES\n" > $MODULE_LIST_FILE
	fi

	echo "Header dir is '$INC_DIR'"
	local directories=($(find $INC_DIR -type d | grep -v "Tests"))
	echo "Directory list is ${directories[*]}"

	for dir in ${directories[*]}; do

		cd $dir &>/dev/null
		local inc_files=($(find -maxdepth 1 -type f -name "*.hpp" | sort))
		cd - &>/dev/null

		if (( ${#inc_files[*]} != 0 ))
		then
			if [[ "$ADD_TO_MODULE_LIST" == "true" ]]
			then
				if echo $dir | grep -v "Test"
				then
					echo -en "\t""\${CMAKE_CURRENT_SOURCE_DIR}/$dir""\n" >> $MODULE_LIST_FILE
				fi
			fi

			local FILE=$dir/$HEADER_FILENAME

			echo "Add to $dir/$FILE:"
			echo -en "set ($CMAKE_VARNAME\n"
			echo -en "set ($CMAKE_VARNAME\n" > $FILE
			for inc_file in ${inc_files[*]}; do
				echo -en "\t\${CMAKE_CURRENT_SOURCE_DIR}/${inc_file:2}\n"
				echo -en "\t\${CMAKE_CURRENT_SOURCE_DIR}/${inc_file:2}\n" >> $FILE;
			done
			echo -en ")\n"
			echo -en ")\n" >> $FILE;
		else
			echo Remove $dir/$HEADER_FILENAME
			rm -rf $dir/$HEADER_FILENAME
		fi
		echo
	done

	if [[ "$ADD_TO_MODULE_LIST" == "true" ]]
	then
		echo -en ")\n" >> $MODULE_LIST_FILE
	fi
}

add_tests()
{
	local SRC_DIR=$1
	local ADD_TO_MODULE_LIST=$2

	local CMAKE_VARNAME="SOURCE_LIST"
	local MODULE_LIST_FILE=$TEST_MODULES_FILENAME

	if [[ "$ADD_TO_MODULE_LIST" == "true" ]]
	then
		echo -en "set(TEST_MODULES\n" > $MODULE_LIST_FILE
	fi

	echo "Source dir is '$SRC_DIR'"
	local directories=($(find $SRC_DIR -type d | grep "Tests"))
	echo "Directory list is ${directories[*]}"
	for dir in ${directories[*]}; do

		cd $dir &>/dev/null
		local src_files=($(find -maxdepth 1 -type f -name "*.?pp" | sort))
		cd - &>/dev/null

		if (( ${#src_files[*]} != 0 ))
		then
			if [[ "$ADD_TO_MODULE_LIST" == "true" ]]
			then
				echo -en "\t""\${CMAKE_CURRENT_SOURCE_DIR}/$dir""\n" >> $MODULE_LIST_FILE
			fi

			local FILE=$dir/$SOURCE_FILENAME

			echo "Add to $FILE:"
			echo -en "set ($CMAKE_VARNAME\n"
			echo -en "set ($CMAKE_VARNAME\n" > $FILE
			for src_file in ${src_files[*]}; do
				echo -en "\t\${CMAKE_CURRENT_SOURCE_DIR}/${src_file:2}\n"
				echo -en "\t\${CMAKE_CURRENT_SOURCE_DIR}/${src_file:2}\n" >> $FILE;
			done
			echo -en ")\n"
			echo -en ")\n" >> $FILE;
			echo
		else
			if [[ -e "$dir/$SOURCE_FILENAME" ]]
			then
				echo Remove $dir/$SOURCE_FILENAME
				rm -rf $dir/$SOURCE_FILENAME
				echo
			fi
		fi

	done

	if [[ "$ADD_TO_MODULE_LIST" == "true" ]]
	then
		echo -en ")\n" >> $MODULE_LIST_FILE
	fi
}


add_sources src true
add_headers src false
add_headers include/FlameIDE true

add_sources tests true
add_headers tests true
add_tests src false
