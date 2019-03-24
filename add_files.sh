#!/bin/bash

echo "TEMPLATE = app"
echo "CONFIG += console"
echo "CONFIG += object_parallel_to_source"

echo "win32 {"
echo "CONFIG += c++14"
echo "}"
echo "CONFIG -= app_bundle"
echo "CONFIG -= qt"
echo

echo "!win32 {"
echo "QMAKE_CXXFLAGS = -std=c++14 -pedantic -fno-rtti -fno-exceptions"
echo "QMAKE_CXXFLAGS_DEBUG += -gdwarf-3"
echo "QMAKE_CXXFLAGS_RELEASE = -O3 -Wall -W"
echo "}"
echo "INCLUDEPATH += include/"
echo "INCLUDEPATH += ."
echo

STRINGS=0
COUNT_FILES=0

# headers ---------------

echo "#" headers

echo "##" common headers
echo -n "HEADERS +="
HEADERS=`find . -type f -name '*.hpp' | grep -v Posix | grep -v Windows | sort`
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

echo "##" Windows headers
echo "win32 {"
echo -n "HEADERS +="
HEADERS=`find . -type f -name '*.hpp' | grep Windows | sort`
for header in $HEADERS
do
  echo " \\"
  echo -n "	$header"
  count_strings=$(cat $header | wc -l)
  STRINGS=$(( STRINGS+count_strings ))
  COUNT_FILES=$(( COUNT_FILES+1 ))
done
echo
echo "}"
echo

echo "##" Posix headers
echo "!win32 {"
echo -n "HEADERS +="
HEADERS=`find . -type f -name '*.hpp' | grep Posix | sort`
for header in $HEADERS
do
  echo " \\"
  echo -n "	$header"
  count_strings=$(cat $header | wc -l)
  STRINGS=$(( STRINGS+count_strings ))
  COUNT_FILES=$(( COUNT_FILES+1 ))
done
echo
echo "}"
echo


# sources ---------------

echo "#" sources

echo -n "SOURCES +="
SOURCES=`find . -type f -name '*.cpp' | grep -v Posix | grep -v Windows | sort`
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

echo "##" Windows sources
echo "win32 {"
echo -n "SOURCES +="
SOURCES=`find . -type f -name '*.cpp' | grep Windows | sort`
for source in $SOURCES
do
  echo " \\"
  echo -n "	$source"
  count_strings=$(cat $source | wc -l)
  STRINGS=$(( STRINGS+count_strings ))
  COUNT_FILES=$(( COUNT_FILES+1 ))
done
echo
echo "}"
echo


echo "##" Posix sources
echo "!win32 {"
echo -n "SOURCES +="
SOURCES=`find . -type f -name '*.cpp' | grep Posix | sort`
for source in $SOURCES
do
  echo " \\"
  echo -n "	$source"
  count_strings=$(cat $source | wc -l)
  STRINGS=$(( STRINGS+count_strings ))
  COUNT_FILES=$(( COUNT_FILES+1 ))
done
echo
echo "}"
echo


>&2 echo count files is $COUNT_FILES
>&2 echo count strings is $STRINGS

