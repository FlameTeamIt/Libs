#!/bin/bash

echo "TEMPLATE = app"
echo "CONFIG += console"
echo "CONFIG -= app_bundle"
echo "CONFIG -= qt"
echo

echo "QMAKE_CXXFLAGS = -std=c++14 -pedantic -fno-rtti"
#echo "QMAKE_CXXFLAGS_RELEASE = -O3 -Wall -W"
echo "INCLUDEPATH += src/"
echo "INCLUDEPATH += ."
echo

echo "#" headers
echo -n "HEADERS += "
HEADERS=`find . -type f -name '*.hpp'`
for header in $HEADERS
do
  echo "\\"
  echo -n "	$header "
done
echo
echo

echo "#" sources
echo -n "SOURCES += "
SOURCES=`find . -type f -name '*.cpp'`
for source in $SOURCES
do
  echo "\\"
  echo -n "	$source "
done
echo
echo

