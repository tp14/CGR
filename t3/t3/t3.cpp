#include <windows.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <GL/glut.h>
#include <GL/gl.h>
#include <ctime>

#include "firework.hpp"

float anglex = 0.0f;
float angley = 0.0f;
float anglez = 0.0f;

float deltaAnglex = 0.0f;
float deltaAngley = 0.0f;
float deltaAnglez = 0.0f;

vector<Firework> fireworks;

void drawFireworks(){
	if (randomFloat(0, 1) < 0.2)
	{
		fireworks.push_back(Firework());
	}

	for (int i = fireworks.size()-1; i >= 0; i--) {
		Firework f = fireworks[i];
        
		f.run();
        // if (i == 0)
        // {
        //     cout << i << ": x=" << f.firework.location[0] << ", y="<<f.firework.location[1]<<", z="<<f.firework.location[2]<<endl;
        // }
        
		if (f.done()) {
            fireworks.erase(fireworks.begin() + i);
        } else{
            fireworks.erase(fireworks.begin() + i);
            fireworks.push_back(f);
        }
  }
	
	
}


void drawScene(){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(.0f, 0.0f, 0.00f, 0.0f);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

	gluLookAt(	0.0f, -100.0f + anglez,  50.0f + angley,
				0.0f, 1.0f,  4.0f,
				0.0f, 1.0f,  0.0f);

	glRotatef(anglex+90, 0.0f, 0.0f, 1.0f);
    // glRotatef(angley, 0.0f, 1.0f, 0.0f);

	glPushMatrix();
    glRotatef(0.0f, 1.0f, 0.0f, 0.0f);
    glColor3f(0.05f, 0.05, 0.05);
    glTranslatef(0.0f, 0.0f, 0.0f);
    glScalef(50.0f, 50.0f, 0.3f);
    glutSolidCube(1.0f);
    glPopMatrix();

    drawFireworks();

	anglex+=deltaAnglex;
	angley+=deltaAngley;
	anglez+=deltaAnglez;

	if (angley <= -20)
	{
		angley = -20;
	}
	
    glEnd();
	
    glutSwapBuffers(); 
}



void ChangeSize(int w, int h){
    GLfloat fAspect;
    // Prevent a divide by zero
    if(h == 0)
        h = 1;
    // Set Viewport to window dimensions
    glViewport(0, 0, w, h);
    fAspect = (GLfloat)w/(GLfloat)h;
    // Reset coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Produce the perspective projection
    gluPerspective(35.0f, fAspect, 1.0, 400.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void pressKey(int key, int xx, int yy) {

	switch (key) {
		case GLUT_KEY_LEFT : deltaAnglex = -0.5f; break;
		case GLUT_KEY_RIGHT : deltaAnglex = 0.5f; break;
        case GLUT_KEY_UP : deltaAngley = 0.5f; break;
		case GLUT_KEY_DOWN : deltaAngley = -0.5f; break;
        case GLUT_KEY_PAGE_UP : deltaAnglez = 0.5f; break;
		case GLUT_KEY_PAGE_DOWN : deltaAnglez = -0.5f; break;
	}
}

void releaseKey(int key, int x, int y) {

	switch (key) {
		case GLUT_KEY_LEFT :
		case GLUT_KEY_RIGHT : deltaAnglex = 0.0f;break;
        case GLUT_KEY_UP :
		case GLUT_KEY_DOWN : deltaAngley = 0.0f;break;
        case GLUT_KEY_PAGE_UP :
		case GLUT_KEY_PAGE_DOWN : deltaAnglez = 0.0f;break;
	}
}

void processNormalKeys(unsigned char key, int x, int y) {

	if (key == 27)
		exit(0);
}

void idle ( ) {
  glutPostRedisplay();
}

// Programa Principal 
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    srand(time(NULL));

    glutInitDisplayMode(GLUT_DEPTH | GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Fogo de artificio - Thiago e Endrew");

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );
    
    glutDisplayFunc(drawScene); 
    glutReshapeFunc(ChangeSize);
    glutIdleFunc(idle);
	glutSpecialFunc(pressKey);
    glutIgnoreKeyRepeat(1);
	glutSpecialUpFunc(releaseKey);
    glutKeyboardFunc(processNormalKeys);
    glutMainLoop();
}