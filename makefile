myAppStore: main.o bst.o
	g++ main.o bst.o -std=c++11 -o myAppStore

main.o: main.cpp defn.h
	g++ main.cpp -c

bst.o: bst.cc defn.h
	g++ bst.cc defn.h -c

clean:
	rm main.o bst.o