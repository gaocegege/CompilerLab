program eightqueens()
	// print
	function output(a, num)
		var a is array of 8 array of 8 int;
		var num is int;
		return void;
	is
		var i 	is int;
		var j 	is int;
		var tmp is int;
	begin
		print num;
		while i < 8 do
			while j < 8 do
				print a[i][j];
				j = j + 1; 
			end while
			i = i + 1;
		end while
		return void;
	end

	// check whether the queens placed is ok 
	function check( a, row, column)
		var a is array of 8 array of 8 int;
		var row 	is int;
		var column 	is int;
		return boolean;
	is
		var i 	is int;
		var j 	is int;
		var tmp is int;
	begin
		if row == 1 then
			return true;
		end if

		i = 0;
		j = 0;
		tmp = row - 2;
		while i <= tmp	do
			if a[i][column-1] == 1 then 
				return false;
			end if
			i = i + 1;
		end while

		i = row - 2;
		j = i - (row - column);
		while i >= 0 do
			if j >= 0 then
				if a[i][j] == 1
					return false;
				end if
				i = i - 1;
				j = j - 1;
			end if
		end while

		i = row - 2;
		j = row + column - i - 2;
		while i >= 0 do
			if j <= 7 then
				if a[i][j] == 1
					return false;
				end if
				i = i - 1;
				j = j + 1;
			end if
		end while
		return true;
	end

	// solve ..
	function solve(a, row, num)
		var a is array of 8 array of 8 int;
		var row is int;
		var num is int;
		return void;
	is
		var k is int;
		var result is boolean;
	begin
		k = 0;
		while k < 8 do
			a[row - 1][k] = 1;
			result = check(a, row, k + 1);
			if result == true then
				if row == 8 then
					num = num + 1;
					output(a, num);
				else
					solve(a, row + 1);
				end if
			end if
			a[row - 1][k] = 0;
			k = k + 1;
		end while
		return void;
	end
is
	var qarray is array of 8 array of 8 int;
	var num is int ;
	var qi is int;
	var qj is int;
begin
	num = 0;
	qi = 0;
	qj = 0;
	while qi < 8 do
		while qj < 8 do
			qarray[qi][qj] = 0;
			qj = qj + 1; 
		end while
		qi = qi + 1;
	end while
	solve(qarray, 1, num);
end
