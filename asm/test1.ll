; ModuleID = './test.cpp'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.10.0"

@arr = global [1000 x i32] zeroinitializer, align 16
@.str1 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str2 = private unnamed_addr constant [4 x i8] c"%d \00", align 1
@str = private unnamed_addr constant [28 x i8] c"print the size of the array\00"

; Function Attrs: nounwind ssp uwtable
define void @_Z4swapPiii(i32* nocapture %a, i32 %x, i32 %y) #0 {
  %1 = sext i32 %x to i64
  %2 = getelementptr inbounds i32* %a, i64 %1
  %3 = load i32* %2, align 4, !tbaa !1
  %4 = sext i32 %y to i64
  %5 = getelementptr inbounds i32* %a, i64 %4
  %6 = load i32* %5, align 4, !tbaa !1
  store i32 %6, i32* %2, align 4, !tbaa !1
  store i32 %3, i32* %5, align 4, !tbaa !1
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @_Z9quicksortPiii(i32* %array, i32 %left, i32 %right) #0 {
  %1 = icmp slt i32 %left, %right
  br i1 %1, label %.preheader, label %tailrecurse._crit_edge

.preheader:                                       ; preds = %0, %tailrecurse
  %left.tr3 = phi i32 [ %23, %tailrecurse ], [ %left, %0 ]
  %2 = sext i32 %left.tr3 to i64
  %3 = getelementptr inbounds i32* %array, i64 %2
  br label %.outer

.outer:                                           ; preds = %.preheader, %13
  %indvars.iv6 = phi i64 [ %2, %.preheader ], [ %indvars.iv.next7, %13 ]
  %j.0.in.ph = phi i32 [ %left.tr3, %.preheader ], [ %14, %13 ]
  %4 = sext i32 %j.0.in.ph to i64
  br label %5

; <label>:5                                       ; preds = %.outer, %8
  %indvars.iv = phi i64 [ %4, %.outer ], [ %indvars.iv.next, %8 ]
  %indvars.iv.next = add nsw i64 %indvars.iv, 1
  %6 = trunc i64 %indvars.iv to i32
  %7 = icmp slt i32 %6, %right
  br i1 %7, label %8, label %tailrecurse

; <label>:8                                       ; preds = %5
  %9 = getelementptr inbounds i32* %array, i64 %indvars.iv.next
  %10 = load i32* %9, align 4, !tbaa !1
  %11 = load i32* %3, align 4, !tbaa !1
  %12 = icmp slt i32 %10, %11
  br i1 %12, label %13, label %5

; <label>:13                                      ; preds = %8
  %14 = trunc i64 %indvars.iv.next to i32
  %indvars.iv.next7 = add nsw i64 %indvars.iv6, 1
  %15 = getelementptr inbounds i32* %array, i64 %indvars.iv.next7
  %16 = load i32* %15, align 4, !tbaa !1
  store i32 %10, i32* %15, align 4, !tbaa !1
  store i32 %16, i32* %9, align 4, !tbaa !1
  br label %.outer

tailrecurse:                                      ; preds = %5
  %17 = trunc i64 %indvars.iv6 to i32
  %sext = shl i64 %indvars.iv6, 32
  %18 = ashr exact i64 %sext, 32
  %19 = getelementptr inbounds i32* %array, i64 %18
  %20 = load i32* %19, align 4, !tbaa !1
  %21 = load i32* %3, align 4, !tbaa !1
  store i32 %21, i32* %19, align 4, !tbaa !1
  store i32 %20, i32* %3, align 4, !tbaa !1
  %22 = add nsw i32 %17, -1
  tail call void @_Z9quicksortPiii(i32* %array, i32 %left.tr3, i32 %22)
  %23 = add nsw i32 %17, 1
  %24 = icmp slt i32 %23, %right
  br i1 %24, label %.preheader, label %tailrecurse._crit_edge

tailrecurse._crit_edge:                           ; preds = %tailrecurse, %0
  ret void
}

; Function Attrs: nounwind ssp uwtable
define i32 @main() #0 {
  %n = alloca i32, align 4
  %t = alloca i32, align 4
  %puts = call i32 @puts(i8* getelementptr inbounds ([28 x i8]* @str, i64 0, i64 0))
  %1 = call i32 (i8*, ...)* @scanf(i8* getelementptr inbounds ([3 x i8]* @.str1, i64 0, i64 0), i32* %n)
  %2 = load i32* %n, align 4, !tbaa !1
  %3 = icmp sgt i32 %2, 0
  br i1 %3, label %.lr.ph5, label %._crit_edge6

.lr.ph5:                                          ; preds = %0, %.lr.ph5
  %indvars.iv8 = phi i64 [ %indvars.iv.next9, %.lr.ph5 ], [ 0, %0 ]
  %4 = call i32 (i8*, ...)* @scanf(i8* getelementptr inbounds ([3 x i8]* @.str1, i64 0, i64 0), i32* %t)
  %5 = load i32* %t, align 4, !tbaa !1
  %6 = getelementptr inbounds [1000 x i32]* @arr, i64 0, i64 %indvars.iv8
  store i32 %5, i32* %6, align 4, !tbaa !1
  %indvars.iv.next9 = add nuw nsw i64 %indvars.iv8, 1
  %7 = load i32* %n, align 4, !tbaa !1
  %8 = trunc i64 %indvars.iv.next9 to i32
  %9 = icmp slt i32 %8, %7
  br i1 %9, label %.lr.ph5, label %._crit_edge6

._crit_edge6:                                     ; preds = %.lr.ph5, %0
  %.lcssa = phi i32 [ %2, %0 ], [ %7, %.lr.ph5 ]
  %10 = add nsw i32 %.lcssa, -1
  call void @_Z9quicksortPiii(i32* getelementptr inbounds ([1000 x i32]* @arr, i64 0, i64 0), i32 0, i32 %10)
  %11 = load i32* %n, align 4, !tbaa !1
  %12 = icmp sgt i32 %11, 0
  br i1 %12, label %.lr.ph, label %._crit_edge

.lr.ph:                                           ; preds = %._crit_edge6, %.lr.ph
  %indvars.iv = phi i64 [ %indvars.iv.next, %.lr.ph ], [ 0, %._crit_edge6 ]
  %13 = getelementptr inbounds [1000 x i32]* @arr, i64 0, i64 %indvars.iv
  %14 = load i32* %13, align 4, !tbaa !1
  %15 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i64 0, i64 0), i32 %14)
  %indvars.iv.next = add nuw nsw i64 %indvars.iv, 1
  %16 = load i32* %n, align 4, !tbaa !1
  %17 = trunc i64 %indvars.iv.next to i32
  %18 = icmp slt i32 %17, %16
  br i1 %18, label %.lr.ph, label %._crit_edge

._crit_edge:                                      ; preds = %.lr.ph, %._crit_edge6
  ret i32 0
}

; Function Attrs: nounwind
declare i32 @printf(i8* nocapture readonly, ...) #1

; Function Attrs: nounwind
declare i32 @scanf(i8* nocapture readonly, ...) #1

; Function Attrs: nounwind
declare i32 @puts(i8* nocapture readonly) #2

attributes #0 = { nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { nounwind }

!llvm.ident = !{!0}

!0 = metadata !{metadata !"Apple LLVM version 6.0 (clang-600.0.54) (based on LLVM 3.5svn)"}
!1 = metadata !{metadata !2, metadata !2, i64 0}
!2 = metadata !{metadata !"int", metadata !3, i64 0}
!3 = metadata !{metadata !"omnipotent char", metadata !4, i64 0}
!4 = metadata !{metadata !"Simple C/C++ TBAA"}
