MyLang Compiler
===

This is a toy compiler of a programming language called MyLang.

The project is set up for SJTU SE302: Compilers Principles and Techniques.

Project requirements:

* Qt5
* boost
* c++11 new features

***Notice***

If you want to run the UI in your PC, you need to change the `INCLUDEPATH` in `/UI/UI.pro` to your boost path.

[Doc is here](https://gaocegege.github.io/CompilerLab)

# Reference

* [Mapping-High-Level-Constructs-to-LLVM-IR](http://llvm.lyngvig.org/Articles/Mapping-High-Level-Constructs-to-LLVM-IR) 
* [llvm-how-to-access-to-struct-fields-based-on-their-names](http://stackoverflow.com/questions/17409216/llvm-how-to-access-to-struct-fields-based-on-their-names)
* [do-i-need-to-calculate-padding-by-myself-to-construct-a-structtype](http://stackoverflow.com/questions/13300717/do-i-need-to-calculate-padding-by-myself-to-construct-a-structtype)
* [create-struct-and-union-type-in-llvmir-using-c-api](http://stackoverflow.com/questions/16767544/create-struct-and-union-type-in-llvmir-using-c-api)
* [llvm-linking-problem](http://stackoverflow.com/questions/1419139/llvm-linking-problem)