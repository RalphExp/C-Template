.PHONY: all

all: weakptr1 weakptr2 esft1 esft2

weakptr1: weakptr1.cpp
	g++ -o$@ $< -std=c++17 $(LDFLAG)

weakptr2: weakptr2.cpp
	g++ -o$@ $< -std=c++17 $(LDFLAG)

esft1: esft1.cpp
	g++ -o$@ $< -std=c++17 $(LDFLAG)

esft2: esft2.cpp
	g++ -o$@ $< -std=c++17 $(LDFLAG)

clean:
	rm -rf weakptr1 weakptr2 esft1 esft2
