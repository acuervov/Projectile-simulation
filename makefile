all:Grafica.pdf

main.x: main.cpp
	g++-10  main.cpp -o main.x


Grafica.pdf: Grafica.gp "10 grafica.txt"
	cd resultados
	gnuplot Grafica.gp
	open Grafica.pdf
