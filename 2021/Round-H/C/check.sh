for ((i=43;;i++)) do
	echo $i
	./gen $i > in
	diff -w <(./C < in) <(./brute < in) || break
done
