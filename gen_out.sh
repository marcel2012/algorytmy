for i in */; do
	if [ -d "${i}in" ]; then
		for j in $i*.cpp; do
			g++ $j;
			for k in ${i}in/*.txt; do
				tmp=$(echo $k | sed 's,/in/,/out/,g');
				./a.out < $k > $tmp;
			done;
		done;
	fi;
done;
