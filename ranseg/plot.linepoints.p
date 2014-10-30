reset
dataFile="data.speedup.csv"
set output "speedup.png"
set xlabel "process_count"
set ylabel "speedup"
set term png size 1024,1024
set logscale x 2
set logscale y 2
set grid
set key reverse Left bottom
plot dataFile using ($1):($2) notitle with linespoints
