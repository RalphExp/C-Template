.PHONY: all

all: weakptr1 weakptr2

weakptr1: weakptr1.cpp
	g++ -o$@ $< -std=c++17 $(LDFLAG)

weakptr2: weakptr2.cpp
	g++ -o$@ $< -std=c++17 $(LDFLAG)

clean:
	rm -rf weakptr1 weakptr2
