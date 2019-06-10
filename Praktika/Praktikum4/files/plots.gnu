reset
set terminal canvas
set autoscale x
set autoscale y
set xlabel "n[-]"
set ylabel "t[ms]"
set key top left
set key font ",12"
set xtics font ",10"

set output 'algorithms.html'

plot \
"quicksort.txt" with linespoints title 'Quicksort',\
"mergesort.txt" with linespoints title 'Mergesort',\
"heapsort.txt" with linespoints title 'Heapsort',\
"shellsort.txt" with linespoints title 'Shellsort',\
