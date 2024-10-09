.PHONY: all

all: async1 async2

LDFLAG = -lpthread

async1: async1.cpp
	g++ -o$@ $< -std=c++17 $(LDFLAG)

async2: async2.cpp
	g++ -o$@ $< -std=c++17 $(LDFLAG)

clean:
	rm -rf async1 async2
