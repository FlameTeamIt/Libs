#!/bin/bash

echo "TEMPLATE = app"
echo "CONFIG += console"
echo "CONFIG += object_parallel_to_source"
echo "CONFIG -= app_bundle"
echo "CONFIG -= qt"
echo

echo "QMAKE_CXXFLAGS = -std=c++14 -pedantic -fno-rtti -fno-exceptions"
#echo "QMAKE_CXXFLAGS_RELEASE = -O3 -Wall -W"
echo "INCLUDEPATH += src/"
echo "INCLUDEPATH += ."
echo

echo "#" headers
echo -n "HEADERS +="
HEADERS=`find . -type f -name '*.hpp'`
STRINGS=0
for header in $HEADERS
do
  echo " \\"
  echo -n "	$header"
  count_strings=$(cat $header | wc -l)
  STRINGS=$(( STRINGS+count_strings ))
done
echo
echo

echo "#" sources
echo -n "SOURCES +="
SOURCES=`find . -type f -name '*.cpp'`
for source in $SOURCES
do
  echo " \\"
  echo -n "	$source"
  count_strings=$(cat $source | wc -l)
  STRINGS=$(( STRINGS+count_strings ))
done
echo
echo

>&2 echo $STRINGS

