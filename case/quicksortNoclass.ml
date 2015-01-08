program quick()
	// global fastiable
	static arr is array of 100 int;

	// quicksort
	function quicksort(left,right)
		fast left is int;
		fast right is int;
	is
		fast pivot is int;
		fast j is int;
		fast k is int;
		fast temp is int;
	begin
		if left<right then
			pivot := left;
			j := left + 1;
			k := right + 1;

			while j < k do
				if arr[j] < arr[left] then
					pivot := pivot + 1;
					temp := arr[pivot];
					arr[pivot] := arr[j];
					arr[j] := temp;
				end if

				j := j + 1;
			end while 

			temp := arr[pivot];
			arr[pivot] := arr[left];
			arr[left] := temp;

			quicksort(left, pivot - 1);
        	quicksort(pivot + 1 , right);

		end if
	end;

is
	fast i 	is int;
	fast num is int;
	fast tmp is int;

begin
	// limit numbers;
	num := 5 ;

	// input numbers
	i := 0;
	while i < num do
		i := i + 1;
		arr[i] := num - i;
	end while

	quicksort(arr, 0, num - 1);

	// print
	while i < num do
		i := i + 1;
		print arr[i];
	end while

end