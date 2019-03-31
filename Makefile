OBJECTS := bird.o pipe.o scene.o game.o main.o
LIBS    := -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
INCLUDE := -I.
CXXFLAGS:= -std=c++11

all: main


main: $(OBJECTS) 
	g++ -o $@ $^ $(LIBS) 

%.o: %.cpp
	g++ -c $^ $(CXXFLAGS) $(INCLUDE)

clean:
	rm *.o main