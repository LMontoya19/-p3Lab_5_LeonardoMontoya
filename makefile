main:	main.o cliente.o ingrediente.o plato.o
	g++ main.o cliente.o ingrediente.o plato.o -o main
	rm *.o
main.o:	main.cpp cliente.h cliente.cpp ingrediente.h ingrediente.cpp plato.h plato.cpp
	g++ -c main.cpp
cliente.o:	cliente.h cliente.cpp plato.h plato.cpp
	g++ -c cliente.cpp
ingrediente.o:	ingrediente.h ingrediente.cpp
	g++ -c ingrediente.cpp
plato.o:	plato.h plato.cpp ingrediente.h ingrediente.cpp
	g++ -c plato.cpp