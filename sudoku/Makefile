main: main.o SuDoku.o
	g++ -o main main.o SuDoku.o

main.o: main.cpp SuDoku.h
	g++ -c main.cpp

SuDoku.o: SuDoku.cpp SuDoku.h
	g++ -c SuDoku.cpp

clean:
	rm main *.o
