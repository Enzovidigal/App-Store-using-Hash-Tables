myAppStore: main.o bst.o heap.o hash.o prime.o
	g++ main.o bst.o heap.o hash.o prime.o -std=c++11 -o myAppStore

main.o: main.cpp defn.h
	g++ main.cpp -c

bst.o: bst.cc defn.h
	g++ bst.cc defn.h -c

heap.o: heap.cc defn.h
	g++ heap.cc defn.h -c

hash.o: hash.cc defn.h
	g++ hash.cc defn.h -c

prime.o: prime.cc defn.h
	g++ prime.cc defn.h -c

clean:
	rm main.o bst.o heap.o hash.o prime.o