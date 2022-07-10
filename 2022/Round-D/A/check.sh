for ((i=1;;i++)) do
	echo $i
	./gen $i > in
	diff -w <(./A < in) <(./A1 < in) || break
done
