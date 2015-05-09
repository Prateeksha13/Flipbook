LIBS    = -lGL -lGLU -lglut -lSOIL
FLAGS = -Wall -std=c++11

all : build/flipbook

clean :
	rm -r build

run : build/flipbook
	cd build && ./flipbook

build :
	mkdir build 

build/main.o : main.cpp
	$(CXX) -c main.cpp -o build/main.o

build/Drawings.o : components/Drawings.cpp
	$(CXX) -c components/Drawings.cpp -o build/Drawings.o

build/Room.o : components/Room.cpp
	$(CXX) -c components/Room.cpp -o build/Room.o

build/Textures.o : components/Textures.cpp
	$(CXX) -c components/Textures.cpp -o build/Textures.o

build/Welcome.o : components/Welcome.cpp
	$(CXX) -c components/Welcome.cpp -o build/Welcome.o

build/Book.o : lib/Book.cpp
	$(CXX) -c lib/Book.cpp -o build/Book.o

build/Page.o : lib/Page.cpp
	$(CXX) -c lib/Page.cpp -o build/Page.o

build/flipbook : build build/main.o build/Room.o build/Textures.o build/Welcome.o build/Drawings.o build/Book.o build/Page.o
	cd build &&	$(CXX) main.o Room.o Textures.o Welcome.o Drawings.o Book.o Page.o $(LIBS) -o flipbook
