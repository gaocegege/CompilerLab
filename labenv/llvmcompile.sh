#!/bin/sh
clang++ -g llvmhelloworld.cpp -lncurses `llvm-config --cxxflags --ldflags --libs` -o HelloWorldDump.out
echo "Compile Complete"
./HelloWorldDump.out 2>HelloWorldDump.ll
echo "Dump Complete"
echo "LL Output: "
lli HelloWorldDump.ll