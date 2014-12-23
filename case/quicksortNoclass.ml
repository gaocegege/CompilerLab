program quick()
	// global variable
	type arr is array of 100 int;

	// quicksort
	function quicksort(a,left,right)
		var a is array of int;
		var left is int;
		var right is int;
		return void;
	is
		var pivot is int;
		var j is int;
		var k is int;
		var temp is int;
	begin
		if left<right then
			pivot := left;
			j := left + 1;
			k := right + 1;

			while j < k do
				if a[j] < a[left] then
					pivot := pivot + 1;
					temp := a[pivot];
					a[pivot] := a[j];
					a[j] := temp;
				end if

				j := j + 1;
			end while 

			temp := a[pivot];
			a[pivot] := a[left];
			a[left] := temp;

			quicksort(a, left, pivot - 1);
        	quicksort(a, pivot + 1 , right);

		end if
		return void;
	end

is
	var i 	is int;
	var num is int;
	var tmp is int;

begin
	// limit numbers;
	num := 5 ;

	// input numbers
	i := 0;
	while i < num do
		i := i + 1;
		scanf("%d",&tmp);
		arr[i] := tmp;
	end while

	quicksort(arr, 0, num - 1);

	// print
	while i < num do
		i := i + 1;
		print arr[i];
	end while

end

