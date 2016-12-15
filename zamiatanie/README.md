# miotla
Określa czy istnieją odcinki, które się przecijaną

Zał.
<ul>
<li>nie istnieją odcinki pionowe</li>
<li>3 odcinki nie przecinają się w 1 punkcie</li>
<li>przecinanie oznacza, że odcinki się stykają, ale koniec żadnego nie nazleży do drugiego<br>
sgn(deg(a,b,c))*sgn(deg(a,b,d))==-1 && sgn(deg(c,d,a))*sgn(deg(c,d,b))==-1</li>
</ul>

Dane<br>
<br>
test 1<br>
<br>
6<br>
4 1 5 9<br>
3 4 0 0<br>
6 0 5 6<br>
7 2 3 0<br>
6 2 3 1<br>
5 5 8 7<br>
<br>
<img width="500" src="img/1.png"/><br>
<br>
TRUE<br>
<br>
test 2<br>
<br>
3<br>
2 9 3 2<br>
6 4 9 5<br>
4 6 6 1<br>
<br>
<img width="500" src="img/2.png"/><br>
<br>
FALSE<br>
<br>
test 3<br>
<br>
7<br>
5 5 1 4<br>
7 1 1 7<br>
9 3 0 8<br>
1 1 9 9<br>
0 5 3 0<br>
1 2 0 9<br>
0 6 4 1<br>
<br>
<img width="500" src="img/3.png"/><br>
<br>
TRUE<br>
<br>
test 4<br>
<br>
6<br>
0 0 7 3<br>
2 1 0 2<br>
2 0 3 9<br>
7 4 8 8<br>
8 4 4 2<br>
3 3 0 3<br>
<br>
<img width="500" src="img/4.png"/><br>
<br>
TRUE<br>
<br>
test 5<br>
<br>
3<br>
1 8 7 1<br>
4 0 6 8<br>
6 0 2 4<br>
<br>
<img width="500" src="img/5.png"/><br>
<br>
TRUE<br>
<br>
test 6<br>
<br>
7<br>
9 2 0 9<br>
5 3 3 3<br>
0 3 4 2<br>
6 1 4 5<br>
2 8 7 9<br>
1 9 8 3<br>
6 0 7 6<br>
<br>
<img width="500" src="img/6.png"/><br>
<br>
TRUE<br>
<br>
test 7<br>
<br>
3<br>
4 9 5 4<br>
4 3 0 7<br>
0 0 4 8<br>
<br>
<img width="500" src="img/7.png"/><br>
<br>
TRUE<br>
<br>
test 8<br>
<br>
5<br>
0 1 6 3<br>
6 0 4 0<br>
9 8 2 9<br>
8 5 4 4<br>
4 9 5 9<br>
<br>
<img width="500" src="img/8.png"/><br>
<br>
FALSE<br>
<br>
test 9<br>
<br>
3<br>
3 9 7 7<br>
7 1 0 5<br>
1 4 0 1<br>
<br>
<img width="500" src="img/9.png"/><br>
<br>
FALSE
