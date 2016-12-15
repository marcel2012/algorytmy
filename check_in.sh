g++ tools/punkty_wspolliniowe.cpp;
for i in "sortowanie-biegunowe/" "wypukla-otoczka-graham/" "wypukla-otoczka-jarvis/"; do
	for k in ${i}in/*.txt; do
		echo $k;
		./a.out < $k;
       	done;
done;
