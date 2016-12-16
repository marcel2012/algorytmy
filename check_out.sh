for i in */; do
        if [ -d "${i}in" ]; then
                for j in $i*.cpp; do
                        g++ -fprofile-arcs -ftest-coverage $j;
                        for k in ${i}in/*.txt; do
				echo $k;
				tmp=$(echo $k | sed 's,/in/,/out/,g');
                                ./a.out < $k > out;
				tmp=$(diff out $tmp);
				if [ "$tmp" != "" ]; then
					exit -1;
				fi;
                        done;
                done;
        fi;
done;
