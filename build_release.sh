#!/bin/bash

build_type=Release

case "$1" in
"")
    make -j4 -f Makefile BUILD="$build_type"
    ;;

"clean")
    make -j4 -f Makefile BUILD="$build_type" clean
    ;;
esac
exit

