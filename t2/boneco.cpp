#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>


// anglex of rotation for the camera direction
float anglex = 0.0f;
float angley = 0.0f;
// actual vector representing the camera's direction
float deltaAnglex = 0.0f;
float deltaAngley = 0.0f;

void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	if (h == 0)
		h = 1;
	float ratio =  w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void drawSnowman() {
	GLUquadricObj *pObj;

    pObj = gluNewQuadric();
	gluQuadricDrawStyle(pObj, GLU_FILL);
	gluQuadricNormals(pObj, GLU_SMOOTH);
    
    //corpo base
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(0.f, 3.f, 0.0f);
	gluSphere(pObj, 4.0f, 40, 30);
    //corpo tronco
    glTranslatef(0.f, 4.5f, 0.0f); 
	gluSphere(pObj, 3.0f, 40, 30);

    //cabeça
    glTranslatef(0.f, 3.7f, 0.0f);
	gluSphere(pObj, 2.f, 40, 30);
    
    //chapeu
    glPushMatrix();
    glColor3f(.0f, .0f, .0f);
    glRotated(90,1,0,0);
    glTranslatef(0.f, 0.f, -2.25f);
    gluCylinder(pObj, 0.f, 3.f, 1.0f, 30, 15);
    glPopMatrix();

    //olho esquerdo
    glColor3f(.0f, .0f, .0f);
	glTranslatef(-.7f, .6f, 1.7f);
	gluSphere(pObj, 0.3, 40, 30);

    //olho direito
    glColor3f(.0f, .0f, .0f);
    glTranslatef(1.5f, .05f, -.05f);
	gluSphere(pObj, 0.3, 40, 30);

    //nariz
    glColor3f(1.0f, 165/255.f, 0.0f);
	glTranslatef(-.7f, -.7f, -.6f);
	gluCylinder(pObj, 0.6f, 0.0f, 2.4f, 26, 20);
	
    //botoes primeira esfera
    glColor3f(92/255.0, 64/255.0, 51/255.0);
    glTranslatef(0.f, -9.2f, 2.8f);
	gluSphere(pObj, .4f, 40, 30);

    glTranslatef(0.f, 2.9f, -0.3f);
	gluSphere(pObj, .4f, 40, 30);

    //botao segunda esfera
    glTranslatef(0.f, 3.f, -.5f);
	gluSphere(pObj, .4f, 40, 30);


	
}


void renderScene(void) {

	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(94/255.0, 159/255.0, 159/255.0, 1.0);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(	0.0f, 1.0f,  45.0f,
				0.0f, 1.0f,  4.0f,
				0.0f, 1.0f,  0.0f);

    glRotatef(anglex, 0.0f, 1.0f, 0.0f);
    glRotatef(angley, 1.0f, 0.0f, 0.0f);

    // Draw ground

	glColor3f(0.f, 0.f, 0.f);
	glBegin(GL_QUADS);
		glVertex3f(-25.0f, 0.0f, -25.0f);
		glVertex3f(-25.0f, 0.0f,  25.0f);
		glVertex3f( 25.0f, 0.0f,  25.0f);
		glVertex3f( 25.0f, 0.0f, -25.0f);
	glEnd();

    glPushMatrix();
    glTranslatef(0,0,0);
    drawSnowman();
    glPopMatrix();
    anglex+=deltaAnglex;
    angley+=deltaAngley;

	glutSwapBuffers();
}

void pressKey(int key, int xx, int yy) {

	switch (key) {
		case GLUT_KEY_LEFT : deltaAnglex = -0.5f; break;
		case GLUT_KEY_RIGHT : deltaAnglex = 0.5f; break;
        case GLUT_KEY_UP : deltaAngley = 0.5f; break;
		case GLUT_KEY_DOWN : deltaAngley = -0.5f; break;
	}
}

void releaseKey(int key, int x, int y) {

	switch (key) {
		case GLUT_KEY_LEFT :
		case GLUT_KEY_RIGHT : deltaAnglex = 0.0f;break;
        case GLUT_KEY_UP :
		case GLUT_KEY_DOWN : deltaAngley = 0.0f;break;
	}
}


int main(int argc, char **argv) {

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(0,0);
	glutInitWindowSize(1200,768);
	glutCreateWindow("Endrew e Thiago Pimenta - Boneco");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
    glutSpecialFunc(pressKey);
    glutIgnoreKeyRepeat(1);
	glutSpecialUpFunc(releaseKey);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}