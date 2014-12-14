; ModuleID = './test.cpp'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.10.0"

@arr = global [1000 x i32] zeroinitializer, align 16
@.str = private unnamed_addr constant [29 x i8] c"print the size of the array\0A\00", align 1
@.str1 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str2 = private unnamed_addr constant [4 x i8] c"%d \00", align 1

; Function Attrs: nounwind ssp uwtable
define void @_Z4swapPiii(i32* %a, i32 %x, i32 %y) #0 {
  %1 = alloca i32*, align 8
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  %tmp = alloca i32, align 4
  store i32* %a, i32** %1, align 8
  store i32 %x, i32* %2, align 4
  store i32 %y, i32* %3, align 4
  %4 = load i32* %2, align 4
  %5 = sext i32 %4 to i64
  %6 = load i32** %1, align 8
  %7 = getelementptr inbounds i32* %6, i64 %5
  %8 = load i32* %7, align 4
  store i32 %8, i32* %tmp, align 4
  %9 = load i32* %3, align 4
  %10 = sext i32 %9 to i64
  %11 = load i32** %1, align 8
  %12 = getelementptr inbounds i32* %11, i64 %10
  %13 = load i32* %12, align 4
  %14 = load i32* %2, align 4
  %15 = sext i32 %14 to i64
  %16 = load i32** %1, align 8
  %17 = getelementptr inbounds i32* %16, i64 %15
  store i32 %13, i32* %17, align 4
  %18 = load i32* %tmp, align 4
  %19 = load i32* %3, align 4
  %20 = sext i32 %19 to i64
  %yyy = load i32** %1, align 8
  %xxx = getelementptr inbounds i32* %yyy, i64 %20
  store i32 %18, i32* %xxx, align 4
  ret void
}

; Function Attrs: ssp uwtable
define void @_Z9quicksortPiii(i32* %array, i32 %left, i32 %right) #1 {
  %1 = alloca i32*, align 8
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  %pivot = alloca i32, align 4
  %j = alloca i32, align 4
  store i32* %array, i32** %1, align 8
  store i32 %left, i32* %2, align 4
  store i32 %right, i32* %3, align 4
  %4 = load i32* %2, align 4
  %5 = load i32* %3, align 4
  %6 = icmp slt i32 %4, %5
  br i1 %6, label %7, label %48

; <label>:7                                       ; preds = %0
  %8 = load i32* %2, align 4
  store i32 %8, i32* %pivot, align 4
  %9 = load i32* %2, align 4
  %10 = add nsw i32 %9, 1
  store i32 %10, i32* %j, align 4
  br label %11

; <label>:11                                      ; preds = %33, %7
  %12 = load i32* %j, align 4
  %13 = load i32* %3, align 4
  %14 = icmp sle i32 %12, %13
  br i1 %14, label %15, label %36

; <label>:15                                      ; preds = %11
  %16 = load i32* %j, align 4
  %17 = sext i32 %16 to i64
  %18 = load i32** %1, align 8
  %19 = getelementptr inbounds i32* %18, i64 %17
  %20 = load i32* %19, align 4
  %21 = load i32* %2, align 4
  %22 = sext i32 %21 to i64
  %23 = load i32** %1, align 8
  %24 = getelementptr inbounds i32* %23, i64 %22
  %25 = load i32* %24, align 4
  %26 = icmp slt i32 %20, %25
  br i1 %26, label %27, label %32

; <label>:27                                      ; preds = %15
  %28 = load i32** %1, align 8
  %29 = load i32* %pivot, align 4
  %30 = add nsw i32 %29, 1
  store i32 %30, i32* %pivot, align 4
  %31 = load i32* %j, align 4
  call void @_Z4swapPiii(i32* %28, i32 %30, i32 %31)
  br label %32

; <label>:32                                      ; preds = %27, %15
  br label %33

; <label>:33                                      ; preds = %32
  %34 = load i32* %j, align 4
  %35 = add nsw i32 %34, 1
  store i32 %35, i32* %j, align 4
  br label %11

; <label>:36                                      ; preds = %11
  %37 = load i32** %1, align 8
  %38 = load i32* %pivot, align 4
  %39 = load i32* %2, align 4
  call void @_Z4swapPiii(i32* %37, i32 %38, i32 %39)
  %40 = load i32** %1, align 8
  %41 = load i32* %2, align 4
  %42 = load i32* %pivot, align 4
  %43 = sub nsw i32 %42, 1
  call void @_Z9quicksortPiii(i32* %40, i32 %41, i32 %43)
  %44 = load i32** %1, align 8
  %45 = load i32* %pivot, align 4
  %46 = add nsw i32 %45, 1
  %47 = load i32* %3, align 4
  call void @_Z9quicksortPiii(i32* %44, i32 %46, i32 %47)
  br label %48

; <label>:48                                      ; preds = %36, %0
  ret void
}

; Function Attrs: ssp uwtable
define i32 @main() #1 {
  %1 = alloca i32, align 4
  %n = alloca i32, align 4
  %t = alloca i32, align 4
  %i = alloca i32, align 4
  %i1 = alloca i32, align 4
  store i32 0, i32* %1
  %2 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([29 x i8]* @.str, i32 0, i32 0))
  %3 = call i32 (i8*, ...)* @scanf(i8* getelementptr inbounds ([3 x i8]* @.str1, i32 0, i32 0), i32* %n)
  store i32 0, i32* %i, align 4
  br label %4

; <label>:4                                       ; preds = %14, %0
  %5 = load i32* %i, align 4
  %6 = load i32* %n, align 4
  %7 = icmp slt i32 %5, %6
  br i1 %7, label %8, label %17

; <label>:8                                       ; preds = %4
  %9 = call i32 (i8*, ...)* @scanf(i8* getelementptr inbounds ([3 x i8]* @.str1, i32 0, i32 0), i32* %t)
  %10 = load i32* %t, align 4
  %11 = load i32* %i, align 4
  %12 = sext i32 %11 to i64
  %13 = getelementptr inbounds [1000 x i32]* @arr, i32 0, i64 %12
  store i32 %10, i32* %13, align 4
  br label %14

; <label>:14                                      ; preds = %8
  %15 = load i32* %i, align 4
  %16 = add nsw i32 %15, 1
  store i32 %16, i32* %i, align 4
  br label %4

; <label>:17                                      ; preds = %4
  %18 = load i32* %n, align 4
  %19 = sub nsw i32 %18, 1
  call void @_Z9quicksortPiii(i32* getelementptr inbounds ([1000 x i32]* @arr, i32 0, i32 0), i32 0, i32 %19)
  store i32 0, i32* %i1, align 4
  br label %20

; <label>:20                                      ; preds = %30, %17
  %21 = load i32* %i1, align 4
  %22 = load i32* %n, align 4
  %23 = icmp slt i32 %21, %22
  br i1 %23, label %24, label %33

; <label>:24                                      ; preds = %20
  %25 = load i32* %i1, align 4
  %26 = sext i32 %25 to i64
  %27 = getelementptr inbounds [1000 x i32]* @arr, i32 0, i64 %26
  %28 = load i32* %27, align 4
  %29 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i32 0, i32 0), i32 %28)
  br label %30

; <label>:30                                      ; preds = %24
  %31 = load i32* %i1, align 4
  %32 = add nsw i32 %31, 1
  store i32 %32, i32* %i1, align 4
  br label %20

; <label>:33                                      ; preds = %20
  ret i32 0
}

declare i32 @printf(i8*, ...) #2

declare i32 @scanf(i8*, ...) #2

attributes #0 = { nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = metadata !{metadata !"Apple LLVM version 6.0 (clang-600.0.54) (based on LLVM 3.5svn)"}
