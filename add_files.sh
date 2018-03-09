#!/bin/bash

echo "TEMPLATE = app"
echo "CONFIG += console"
echo "CONFIG -= app_bundle"
echo "CONFIG -= qt"
echo

echo "QMAKE_CXXFLAGS += -std=c++14 -pedantic"
echo "INCLUDEPATH += src/ ."
echo

echo "#" headers
HEADERS=`find . -type f -name '*.hpp'`
for header in $HEADERS
do
  echo "HEADERS += $header"
done
echo

echo "#" sources
SOURCES=`find . -type f -name '*.cpp'`
for source in $SOURCES
do
  echo "SOURCES += $source"
done

echo

