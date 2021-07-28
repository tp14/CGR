#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>


// anglex of rotation for the camera direction
float anglex = 0.0f;
float angley = 0.0f;
// actual vector representing the camera's direction
//when no key is being presses
float deltaAnglex = 0.0f;
float deltaAngley = 0.0f;

void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
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

void drawRobo() {
	GLUquadricObj *pObj;

    pObj = gluNewQuadric();
	gluQuadricDrawStyle(pObj, GLU_FILL);
	gluQuadricNormals(pObj, GLU_SMOOTH);

    //corpo
    glPushMatrix();
    glColor3f(35/255.0f, 142/255.0f, 104/255.0f);
    glTranslatef(0.0f, 13.f, 0.f);
    glScalef(5.0f, 8.f, 3.0f);
    glutSolidCube(1.0f);
    glPopMatrix();
    	
    //bola pescoço
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(0.0f, 17.25f, 0.f);
    gluSphere(pObj, .3f, 40, 30);
    glPopMatrix();

    //primeira bola braço direito
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(1.70f, 16.5f, 2.f);
    gluSphere(pObj, .5f, 40, 30);
    glPopMatrix();

    //primeira bola braço esquerdo
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(-1.70f, 16.5f, 2.f);
    gluSphere(pObj, .5f, 40, 30);
    glPopMatrix();

    //primeira bola perna direita
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(1.8f, 8.7f, 0.f);
    gluSphere(pObj, .35f, 40, 30);
    glPopMatrix();

    //primeira bola perna esquerda
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(-1.8f, 8.7f, 0.f);
    gluSphere(pObj, .35f, 40, 30);
    glPopMatrix();

    //cabeça
    glPushMatrix();
    glColor3f(35/255.0f, 142/255.0f, 104/255.0f);
    glTranslatef(0.0f, 19.f, 0.f);
    glScalef(3.0f, 3.f, 2.0f);
    glutSolidCube(1.0f);
    glPopMatrix();
    //olho direito
    glPushMatrix();
    glColor3f(180/255.0f, 1.f, .0f);
    glTranslatef(0.7f, 19.5f, 1.1f);
    glScalef(.75f, .5f, .0f);
    glutSolidCube(1.0f);
    glPopMatrix();
    //olho esquerdo
    glPushMatrix();
    glColor3f(180/255.0f, 1.f, .0f);
    glTranslatef(-0.7f, 19.5f, 1.1f);
    glScalef(.75f, .5f, .0f);
    glutSolidCube(1.0f);
    glPopMatrix();
    //boca
    glPushMatrix();
    glColor3f(180/255.0f, 1.f, .0f);
    glTranslatef(0.f, 18.5f, 1.1f);
    glScalef(1.5f, .3f, .0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    //antebraço direito
    glPushMatrix();
    glColor3f(35/255.0f, 142/255.0f, 104/255.0f);
    glTranslatef(1.7f, 16.5f, 4.f);
    glScalef(1.0f, 1.f, 3.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    //segunda bola braço direito
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(1.7f, 16.5f, 5.8f);
    gluSphere(pObj, .35f, 40, 30);
    glPopMatrix();

    //braço direito
    glPushMatrix();
    glColor3f(35/255.0f, 142/255.0f, 104/255.0f);
    glTranslatef(1.7f, 16.5f, 7.5f);
    glScalef(.75f, 0.75f, 3.f);
    glutSolidCube(1.0f);
    glPopMatrix();

    //mão direita
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(1.7f, 16.5f, 9.1f);
    glScalef(.5f, 0.5f, 0.25f);
    glutSolidCube(1.0f);
    glPopMatrix();
    //laser1 mao direita
    glPushMatrix();
    glColor3f(1.0f, .0f, .0f);
    glTranslatef(1.7f, 16.5f, 9.8f);
    glScalef(.05f, 0.05f, 1.3f);
    glutSolidCube(3.5f);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1.0f, .0f, .0f);
    glTranslatef(1.7f, 16.5f, 9.2f);
    glScalef(.7f, 0.05f, .3f);
    glutSolidCube(1.0f);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1.0f, .0f, .0f);
    glTranslatef(1.7f, 16.5f, 9.2f);
    glScalef(.05f, 0.7f, .3f);
    glutSolidCube(1.0f);
    glPopMatrix();
    //laser2 mao direita
    glPushMatrix();
    glColor3f(1.0f, .0f, .0f);
    glTranslatef(1.7f, 16.5f, 23.8f);
    glScalef(.05f, 0.05f, 1.3f);
    glutSolidCube(3.5f);
    glPopMatrix();



    //antebraço esquerdo
    glPushMatrix();
    glColor3f(35/255.0f, 142/255.0f, 104/255.0f);
    glTranslatef(-1.7f, 16.5f, 4.f);
    glScalef(1.0f, 1.f, 3.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    //segunda bola braço esquerdo
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(-1.7f, 16.5f, 5.8f);
    gluSphere(pObj, .35f, 40, 30);
    glPopMatrix();

    //braço esquerdo
    glPushMatrix();
    glColor3f(35/255.0f, 142/255.0f, 104/255.0f);
    glTranslatef(-1.7f, 16.5f, 7.5f);
    glScalef(.75f, 0.75f, 3.f);
    glutSolidCube(1.0f);
    glPopMatrix();

    //mão esquerda
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(-1.7f, 16.5f, 9.1f);
    glScalef(.5f, 0.5f, 0.25f);
    glutSolidCube(1.0f);
    glPopMatrix();
    //laser1 mao esquerda
    glPushMatrix();
    glColor3f(1.0f, .0f, .0f);
    glTranslatef(-1.7f, 16.5f, 9.2f);
    glScalef(.7f, 0.15f, .3f);
    glutSolidCube(1.0f);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1.0f, .0f, .0f);
    glTranslatef(-1.7f, 16.5f, 9.2f);
    glScalef(.15f, 0.7f, .3f);
    glutSolidCube(1.0f);
    glPopMatrix();
    //laser2 mao esquerda
    glPushMatrix();
    glColor3f(1.0f, .0f, .0f);
    glTranslatef(-1.7f, 16.5f, 16.8f);
    glScalef(.05f, 0.05f, 1.3f);
    glutSolidCube(3.5f);
    glPopMatrix();
    //laser3 mao esquerda
    glPushMatrix();
    glColor3f(1.0f, .0f, .0f);
    glTranslatef(-1.7f, 16.5f, 30.8f);
    glScalef(.05f, 0.05f, 1.3f);
    glutSolidCube(3.5f);
    glPopMatrix();

    //coxa direita
    glPushMatrix();
    glColor3f(35/255.0f, 142/255.0f, 104/255.0f);
    glTranslatef(1.8f, 6.6f, 0.f);
    glScalef(1.5f, 3.5f, 2.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    //joelho direito
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(1.8f, 4.6f, 0.f);
    gluSphere(pObj, .35f, 40, 30);
    glPopMatrix();

    //perna direita
    glPushMatrix();
    glColor3f(35/255.0f, 142/255.0f, 104/255.0f);
    glTranslatef(1.8f, 2.5f, 0.f);
    glScalef(1.35f, 3.5f, 1.35f);
    glutSolidCube(1.0f);
    glPopMatrix();

    //pé direito
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(1.8f, 0.f, .5f);
    glScalef(1.5f, 1.5f, 3.f);
    glutSolidCube(1.0f);
    glPopMatrix();

    //coxa esquerda
    glPushMatrix();
    glColor3f(35/255.0f, 142/255.0f, 104/255.0f);
    glTranslatef(-1.8f, 6.6f, 0.f);
    glScalef(1.5f, 3.5f, 2.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    //joelho esquerdo
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(-1.8f, 4.6f, 0.f);
    gluSphere(pObj, .35f, 40, 30);
    glPopMatrix();

    //perna esquerda
    glPushMatrix();
    glColor3f(35/255.0f, 142/255.0f, 104/255.0f);
    glTranslatef(-1.8f, 2.5f, 0.f);
    glScalef(1.35f, 3.5f, 1.35f);
    glutSolidCube(1.0f);
    glPopMatrix();

    //pé esquerdo
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(-1.8f, 0.f, .5f);
    glScalef(1.5f, 1.5f, 3.f);
    glutSolidCube(1.0f);
    glPopMatrix();

}


void renderScene(void) {

	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(.0, .0, .0, 1.0);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(	0.0f, 25.f,  45.0f,
				0.0f, 10.0f,  4.0f,
				0.0f, 1.0f,  0.0f);

    glRotatef(anglex, 0.0f, 1.0f, 0.0f);
    glRotatef(angley, 1.0f, 0.0f, 0.0f);

    // Draw ground

	glColor3f(79/255.0f, 47/255.0f, 79/255.0f);
	glBegin(GL_QUADS);
		glVertex3f(-25.0f, 0.0f, -25.0f);
		glVertex3f(-25.0f, 0.0f,  25.0f);
		glVertex3f( 25.0f, 0.0f,  25.0f);
		glVertex3f( 25.0f, 0.0f, -25.0f);
	glEnd();

    glPushMatrix();
    glTranslatef(0,0,0);
    drawRobo();
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