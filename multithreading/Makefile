.PHONY: all

all: async1 async2 async3 future1 thread1 promise1

LDFLAG = -lpthread

async1: async1.cpp
	g++ -o$@ $< -std=c++17 $(LDFLAG)

async2: async2.cpp
	g++ -o$@ $< -std=c++17 $(LDFLAG)

async3: async3.cpp
	g++ -o$@ $< -std=c++17 $(LDFLAG)

future1: future1.cpp
	g++ -o$@ $< -std=c++17 $(LDFLAG)

thread1: thread1.cpp
	g++ -o$@ $< -std=c++17 $(LDFLAG)

promise1: promise1.cpp
	g++ -o$@ $< -std=c++17 $(LDFLAG)

clean:
	rm -rf async1 async2 async3 future1 thread1 promise1
