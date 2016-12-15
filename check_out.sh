for i in */; do
        if [ -d "${i}in" ]; then
                for j in $i*.cpp; do
                        g++ $j;
                        for k in ${i}in/*.txt; do
				echo $k;
				tmp=$(echo $k | sed 's,/in/,/out/,g');
                                ./a.out < $k > out;
				diff out $tmp;
                        done;
                done;
        fi;
done;
