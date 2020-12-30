CC=g++

main: main.o Hand.o Card.o
	$(CC) -o main main.o Hand.o Card.o

main.o: main.cpp Hand.h
	$(CC) -c main.cpp

Hand.o: Hand.cpp Hand.h
	$(CC) -c Hand.cpp

Card.o: Card.cpp Card.h
	$(CC) -c Card.cpp

clean:
	rm main *.o
