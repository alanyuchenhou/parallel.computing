reset
dataFile="result.tsv"

set output "result.png"
set title "communication time between two processes"
set xlabel "message size (B)"
set ylabel "communication time (us)"
set term png size 1024,1024
set logscale x 2
set logscale y 2
set grid
set key reverse Left
plot dataFile using ($1):($2) notitle with linespoints, '' using ($1):(($2)*.9):($2) with labels notitle
