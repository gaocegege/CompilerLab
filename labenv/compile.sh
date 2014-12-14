#!/bin/sh
llvm-gcc helloworld.cpp -S -emit-llvm
echo "Compile complete. The program's output:"
lli helloworld.ll
