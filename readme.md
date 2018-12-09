# Dynamic positioning project

Please read section 3.1 in the report for explanation and overview of the code. 

## Hvor var du

Printproblem:
    fprintf kjører som den skal og kaster ingen error.
    [] test log funksjonen
    [] Sjekk om fclose kjører som den skal.
    [x] Kan prøve å åpne en annen fil.
    Hvis det ikke hjelper -> noe for å fortelle fprint at stringen er ferdig.
    

------------------------

## todo

### MVP todos

[x] Fix plotting
[x] Juster K'er -> les om pid

### other todos

[] muligvis unødvendig serial og channel styr, se onAttachHandler

### Må testes

------------------------

## Compilering

mingw32-make <- for vs code versjonen

## Lenker

[Phidgets API](https://www.phidgets.com/?view=api)  
[Servo motor API](https://www.phidgets.com/?tier=3&prodid=0)  
[Servo motor manual](https://www.phidgets.com/productfiles/1000/1000_0/Documentation/1000_0_Product_Manual.pdf)  
[An openGL graph component](https://www.codeproject.com/Articles/16830/A-Lightweight-Real-time-OpenGL-Graph-Component)   
[D3 for data vis.](https://d3js.org/)  
[Vega for data vis.](https://vega.github.io/vega/examples/line-chart/)   
[Ziegler-Nichols for PID tuning](https://en.wikipedia.org/wiki/Ziegler%E2%80%93Nichols_method)  

## Annet å huske på 

Gnuplot _piping_ i c

```
FILE *gnuplot = popen("gnuplot", "w");
fprintf(gnuplot, "plot '-'\n");
for (i = 0; i < count; i++)
    fprintf(gnuplot, "%g %g\n", x[i], y[i]);
fprintf(gnuplot, "e\n");
fflush(gnuplot);
```

------------------------

## Notes

a)  
Bruker windows libs

b)  
Bruker Sleep funksjonen til windows, som kan være upresis. Dette er en feilkilde for PID algoritmen. 
Anbefalt at iteration_time er over 200 ms for bedre nøyaktighet. 
^ref <https://www.codeproject.com/articles/3831/quantifying-the-accuracy-of-sleep>

c)  
PID implementasjon basert på <http://robotsforroboticists.com/pid-control/> og mekatronikk pdf

d)  
Bruk av flere phidgets samtidig <https://www.phidgets.com/docs/Using_Multiple_Phidgets>

e)  
Sampling rate interface kit ok

f)  
volten ved enden av basenget har endret seg, vurder funksjon for å finne intervallet.

g)
Bruker anbefalte nanosleep for unix <http://man7.org/linux/man-pages/man2/nanosleep.2.html>

nicols)  
ultimate gain = 3.5
oscilation period = 3 sek
BUGS  
No thrust bug
    -> ingen thrust når Kp på 3
