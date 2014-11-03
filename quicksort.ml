program quickSort()
	type intArray is array of 100000 integer

	type quickSortClass is a class

		var size is integer;
		var data is intArray;

		// partition: dig hole from two sides

		function partition(low, high)
			var low is integer;
			var high is integer;
			return integer;
		is
			var buf is integer;
			var i is integer;
			var j is integer;
		begin
			buf := intArray[low];
			// first hole is i (low)
			i := low;
			j := high;

			while i < j do
				// get a element which is in the right side but it < buf
				while i < j && data[j] >= buf do
					j := j - 1;
				end while

				if i < j then
					data[i] := data[j];
					i := i + 1;
				end if

				while i < j && data[i] <= buf do
					i := i + 1;
				end while

				if i < j then
					data[j] := data[i];
					j := j - 1;
				end if
			end while

			data[i] := buf;
		end
		end function partition

		function quicksort(low, high)
			var low is integer;
			var high is integer;
		is
			var pos is integer;
		begin
			if high - low == 1 then
				return;
			end if
			pos := partition(low, high);
			quicksort(low, pos - 1);
			quicksort(pos + 1, high);
		end
		end function quicksort
	end class;
is
	var size is integer;
	var solver is quickSortClass;
	var i is integer;
begin
	input size;
	solver.size := size;
	foreach i in size;
		input solver.data[i];
	end foreach
	solver.quicksort(0, size - 1);
end