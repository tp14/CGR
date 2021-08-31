buildFolder=build/

all: compile

compile: functions.o particle.o firework.o t3.o 
	g++ -O0 -g $(buildFolder)functions.o $(buildFolder)particle.o $(buildFolder)firework.o $(buildFolder)t3.o -lopengl32 -lglew32 -lfreeglut -lglu32 -o t3

functions.o: functions.cpp functions.hpp
	g++ -O0 -c -g functions.cpp -lopengl32 -lglew32 -lfreeglut -lglu32 -o $(buildFolder)functions.o

particle.o: particle.cpp particle.hpp
	g++ -O0 -c -g particle.cpp -lopengl32 -lglew32 -lfreeglut -lglu32 -o $(buildFolder)particle.o

firework.o: firework.cpp firework.hpp
	g++ -O0 -c -g firework.cpp -lopengl32 -lglew32 -lfreeglut -lglu32 -o $(buildFolder)firework.o

t3.o: t3.cpp 
	g++ -O0 -c -g t3.cpp -lopengl32 -lglew32 -lfreeglut -lglu32 -o $(buildFolder)t3.o
