(trocar os parâmetros do Glut caso não esteja utilizando freeglut)

O projeto possui um Makefile, então se tiver make instalado
basta executar make para compilar e ./t3 para executar.

Se não tiver make instalado é necessário compilar os 4 arquivos
e depois executar o t3;

para compilar:

g++ -c functions.cpp -lopengl32 -lglew32 -lfreeglut -lglu32 -o functions.o
g++ -c particle.cpp -lopengl32 -lglew32 -lfreeglut -lglu32 -o particle.o
g++ -c firework.cpp -lopengl32 -lglew32 -lfreeglut -lglu32 -o firework.o
g++ -c t3.cpp -lopengl32 -lglew32 -lfreeglut -lglu32 -o t3.o
g++ functions.o particle.o firework.o t3.o -lopengl32 -lglew32 -lfreeglut -lglu32 -o t3
