# A Toy Compiler

[![Join the chat at https://gitter.im/gaocegege/CompilerLab](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/gaocegege/CompilerLab?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

## 项目地址

本项目所有内容在Github上可获得，地址为[https://github.com/gaocegege/CompilerLab](https://github.com/gaocegege/CompilerLab)

## 代码说明文档

[http://gaocegege.com/CompilerLab/](http://gaocegege.com/CompilerLab/)

## 文件结构

	source/								源代码文件夹
		LLVM-Simple-Wrapper/			LLVM封装代码
		UI/								图形化界面
		parser/							前端
		semantic/						语义分析
		ml.cpp							编译文件
		ml_clang						二进制文件
		...
	bnf/
		syntax.md						bnf文件
	case/								各种用例，有正确的有错误的用例
	Final/
		...								放置各种答辩需要的材料
	labenv/								无意义
	asm/								无意义
		
## 编译命令

	./ml.cpp
	./ml_clang <filename>

