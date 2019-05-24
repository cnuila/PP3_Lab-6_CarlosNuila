main.out: main.o Carro.o Motor.o Chasis.o Pintura.o
	g++ main.o Carro.o Motor.o Chasis.o Pintura.o -o main.out

main.o: main.cpp Carro.h Motor.h Chasis.h Pintura.h
	g++ -c main.cpp

Carro.o: Carro.cpp Carro.h Motor.h Chasis.h Pintura.h
	g++ -c Carro.cpp

Motor.o: Motor.cpp Motor.h
	g++ -c Motor.cpp

Chasis.o: Chasis.cpp Chasis.h
	g++ -c Chasis.cpp

Pintura.o: Pintura.cpp Pintura.h
	g++ -c Pintura.cpp