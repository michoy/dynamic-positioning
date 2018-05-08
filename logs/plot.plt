# change the default colors
set colorsequence podo

# make border grey
set style line 11 lc rgb '#808080' lt 1
set border 3 back ls 11
set tics nomirror

# create a grid
set style line 12 lc rgb '#808080' lt 0 lw 1
set grid back ls 12

set autoscale

# function for displaying title with k values
pidTitle(p, i, d) = sprintf("Kp=%.4f--Ki=%.4f--Kd=%.4f.png", p, i, d)

# Sets output to file
#set output pidTitle(Kp, Ki, Kd)

# title and label
set title pidTitle(Kp, Ki, Kd) font ",14"
set xlabel "Time"


# plot
plot tp title 'Target position' lw 3,\
"log.dat" using 1:2 with lines title 'Current position' lw 3,\
""        using 1:3 with lines title 'Thrust' lw 3

# save to png
set term png
set output pidTitle(Kp, Ki, Kd)
replot
set term x11

