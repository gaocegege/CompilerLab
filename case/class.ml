program test()
	type MyClass is class
		var x is integer;
		var y is integer;
		function returnX()
			return integer;
		is
		begin
			return x;
		end
	end class;
is
	var buf is integer;
	var classBuf is MyClass;
begin
	classBuf.x := 1;
	buf := classBuf.returnX();
end
