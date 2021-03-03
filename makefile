myAppStore: main.o
	g++ main.o -std=c++11 -o myAppStore

main.o: main.cpp
	g++ main.cpp -c

clean:
	rm main.o