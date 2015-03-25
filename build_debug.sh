#!/bin/bash

case "$1" in
"")
    make -j4 -f Makefile BUILD="Debug"
    ;;

"clean")
    make -j4 -f Makefile BUILD="Debug" clean
    ;;
esac
exit

