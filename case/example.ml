program example()
  // 一个判断 n 是否为奇数的函数
  function isodd(n)
    // 定义函数的参数
    var n is integer;
    // 定义函数的返回值
    return boolean;
  // 声明部分
  is
  // 实现部分
  begin
    if n % 2 == 0 then
      // yes 表示布尔真值
      return yes;
    end if
    // no 表示布尔假
    return no;
  // 函数结束
  end function isodd;

  // ackerman 函数
  function ackerman(m, n)
    var m is integer;
    var n is integer;
    return integer;
  is
  begin
    if m == 0 then
      return n + 1;
    elif m > 0 and n == 0 then
      return ackerman(m - 1, 1);
    else
      return ackerman(m - 1, ackerman(m, n - 1));
    end if
  end function ackerman;

  // 使用数组
  type line is array of 10 integer;
  // 使用二维数组
  type grid is array of 10 line;

  // 打印一个乘法表
  function multy(n)
    var n is integer;
    // 没有返回值
  is
    // 声明部分可以声明函数中用到的局部变量
    var i is integer;
    var j is integer;
    var g is grid;
    var l is line;
  begin
    i := 0;
    // 如果 i < 10 成立则进入循环体
    while i < 10 do
      j := 0;
      // 无论何种条件，进入循环体
      repeat
        g[i][j] := i * j;
      // 如果 j >= 10 成立则退出循环，否则回到循环开始
      until j >= 10;
      i := i + 1;
    // 此时回到循环的条件判断处
    end while
    // 遍历 g 中的每个元素
    foreach l in g do
      foreach i in l do
        print i;
      end foreach
    end foreach
  end function multy;

  // 可以定义一个类
  type a is class
    // 类中的所有内容都是可以公开访问的
    // 类的成员变量
    var v is integer;
    // 类的函数
    function f(x)
      var x is integer;
      return integer;
    is
      var t is integer;
    begin
      t := x + v;
      v := x;
      return t;
    end function f;
  end class;

  // 类可以被继承
  type b is class extends c
    // 函数可以被覆盖
    function f(x)
      var x is integer;
      return integer;
    is
    begin
      v := v + x;
      return v;
    end function f;
  end class;
// 主程序的声明
is
  var p is a;
  var q is b;
// 主程序
begin
  print p.f(5);
  print q.f(4);
  p.v := 3;
  print p.f(3);
  multy();
  print ackerman(3, 4);
  if isodd(3) then
    print 3;
  end if
end
