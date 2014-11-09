reset
dataFile="speedup.tsv"
data1="2.thread"
data2="4 thread"
set output "data.png"
set xlabel "input_size"
set ylabel "speedup"
set term png size 1024,1024
set logscale x 2
#set logscale y 2
set grid
set key reverse Left bottom
plot \
dataFile using ($2):($4) title data1 with linespoints, \
dataFile using ($2):($5) title data2 with linespoints
