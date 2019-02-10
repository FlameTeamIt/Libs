#!/bin/bash

echo "TEMPLATE = app"
echo "CONFIG += console"
echo "CONFIG += object_parallel_to_source"
echo "CONFIG -= app_bundle"
echo "CONFIG -= qt"
echo

echo "QMAKE_CXXFLAGS = -std=c++14 -Wpedantic -Wextra -fno-rtti -fno-exceptions"
echo "QMAKE_CXXFLAGS_DEBUG += -gdwarf-3"
echo "INCLUDEPATH += include/"
echo "INCLUDEPATH += ."
echo

STRINGS=0
COUNT_FILES=0

echo "#" headers
echo -n "HEADERS +="
HEADERS=`find . -type f -name '*.hpp' | sort`
for header in $HEADERS
do
  echo " \\"
  echo -n "	$header"
  count_strings=$(cat $header | wc -l)
  STRINGS=$(( STRINGS+count_strings ))
  COUNT_FILES=$(( COUNT_FILES+1 ))
done
echo
echo

echo "#" sources
echo -n "SOURCES +="
SOURCES=`find . -type f -name '*.cpp' | sort`
for source in $SOURCES
do
  echo " \\"
  echo -n "	$source"
  count_strings=$(cat $source | wc -l)
  STRINGS=$(( STRINGS+count_strings ))
  COUNT_FILES=$(( COUNT_FILES+1 ))
done
echo
echo

>&2 echo count files is $COUNT_FILES
>&2 echo count strings is $STRINGS

