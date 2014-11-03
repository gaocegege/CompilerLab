  1 program example()
  2   // 一个判断 n 是否为奇数的函数
  3   function isodd(n)
  4     // 定义函数的参数
  5     var n is integer;
  6     // 定义函数的返回值
  7     return boolean;
  8   // 声明部分
  9   is
 10   // 实现部分
 11   begin
 12     if n % 2 == 0 then
 13       // yes 表示布尔真值
 14       return yes;
 15     end if
 16     // no 表示布尔假
 17     return no;
 18   // 函数结束
 19   end function isodd;
 20 
 21   // ackerman 函数
 22   function ackerman(m, n)
 23     var m is integer;
 24     var n is integer;
 25     return integer;
 26   is
 27   begin
 28     if m == 0 then
 29       return n + 1;
 30     elif m > 0 and n == 0 then
 31       return ackerman(m - 1, 1);
 32     else
 33       return ackerman(m - 1, ackerman(m, n - 1));
 34     end if
 35   end function ackerman;
 36 
 37   // 使用数组
 38   type line is array of 10 integer;
 39   // 使用二维数组
 40   type grid is array of 10 line;
 41 
 42   // 打印一个乘法表
 43   function multy(n)
 44     var n is integer;
 45     // 没有返回值
 46   is
 47     // 声明部分可以声明函数中用到的局部变量
 48     var i is integer;
 49     var j is integer;
 50     var g is grid;
 51     var l is line;
 52   begin
 53     i := 0;
 54     // 如果 i < 10 成立则进入循环体
 55     while i < 10 do
 56       j := 0;
 57       // 无论何种条件，进入循环体
 58       repeat
 59         g[i][j] := i * j;
 60       // 如果 j >= 10 成立则退出循环，否则回到循环开始
 61       until j >= 10;
 62       i := i + 1;
 63     // 此时回到循环的条件判断处
 64     end while
 65     // 遍历 g 中的每个元素
 66     foreach l in g do
 67       foreach i in l do
 68         print i;
 69       end foreach
 70     end foreach
 71   end function multy;
 72 
 73   // 可以定义一个类
 74   type a is class
 75     // 类中的所有内容都是可以公开访问的
 76     // 类的成员变量
 77     var v is integer;
 78     // 类的函数
 79     function f(x)
 80       var x is integer;
 81       return integer;
 82     is
 83       var t is integer;
 84     begin
 85       t := x + v;
 86       v := x;
 87       return t;
 88     end function f;
 89   end class;
 90 
 91   // 类可以被继承
 92   type b is class extends c
 93     // 函数可以被覆盖
 94     function f(x)
 95       var x is integer;
 96       return integer;
 97     is
 98     begin
 99       v := v + x;
100       return v;
101     end function f;
102   end class;
103 // 主程序的声明
104 is
105   var p is a;
106   var q is b;
107 // 主程序
108 begin
109   print p.f(5);
110   print q.f(4);
111   p.v := 3;
112   print p.f(3);
113   multy();
114   print ackerman(3, 4);
115   if isodd(3) then
116     print 3;
117   end if
118 end