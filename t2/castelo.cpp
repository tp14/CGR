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

void tower(GLUquadricObj *quad, GLfloat x, GLfloat y, GLfloat z){
	glTranslatef(x, y, z);
    glColor3f(217/255.0, 179/255.0, 148/255.0);
	gluCylinder(quad, 1.3f, 1.3f, 6.0f, 30, 15);
	glTranslatef(0.0f, 0.0f, 6.0f);
    glColor3f(182/255.0, 110/255.0, 110/255.0);
	gluCylinder(quad, 1.5f, 0.0f, 1.5f, 30, 15);
}

void drawCastle() {
	GLUquadricObj *pObj;


    pObj = gluNewQuadric();
	gluQuadricDrawStyle(pObj, GLU_FILL);
	gluQuadricNormals(pObj, GLU_SMOOTH);

    glPushMatrix();
	tower(pObj, -10.0f, 10.0f, 0.0f);
    glPopMatrix();

    glPushMatrix();
	tower(pObj, 10.0f, 10.0f, 0.0f);
    glPopMatrix();

    glPushMatrix();
	tower(pObj, -10.0f, -10.0f, 0.0f);
    glPopMatrix();

    glPushMatrix();
	tower(pObj, 10.0f, -10.0f, 0.0f);
    glPopMatrix();


    //parede frontal direita
    glPushMatrix();
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glColor3f(217/255.0, 179/255.0, 148/255.0);
    glTranslatef(6.0, 1.5, 10.0f);
    glScalef(8.0f, 3.0f, 1.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    //teto parede frontal direita
    glPushMatrix();
    glTranslatef(6, -10, 3);
    glRotated(90, 1, 0, 0);
    glScaled(8.0,0.7,1.3);
    glColor3f(182/255.0, 110/255.0, 110/255.0);
    glBegin(GL_QUADS);
        glVertex3f(0.5, 0, 0.5);
        glVertex3f(0.5, 0, -0.5);
        glVertex3f(-0.5, 0, -0.5);
        glVertex3f(-0.5, 0, 0.5);

        glVertex3f(0.5,0,-0.5);
        glVertex3f(0.5,1,0);
        glVertex3f(-0.5,1,0);
        glVertex3f(-0.5,0,-0.5);

        glVertex3f(0.5,1,0);
        glVertex3f(-0.5,1,0);
        glVertex3f(-0.5,0,0.5);
        glVertex3f(0.5,0,0.5);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex3f(0.5,0,0.5);
        glVertex3f(0.5,1,0);
        glVertex3f(0.5,0,-0.5);

        glVertex3f(-0.5,0,0.5);
        glVertex3f(-0.5,1,0);
        glVertex3f(-0.5,0,-0.5);
    glEnd();
    glPopMatrix();

    //parede frontal esquerda
    glPushMatrix();
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glColor3f(217/255.0, 179/255.0, 148/255.0);
    glTranslatef(-6.0, 1.5, 10.0f);
    glScalef(8.0f, 3.0f, 1.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    //teto parede frontal esquerda
    glPushMatrix();
    glTranslatef(-6, -10, 3);
    glRotated(90, 1, 0, 0);
    glScaled(8.0,0.7,1.3);
    glColor3f(182/255.0, 110/255.0, 110/255.0);
    glBegin(GL_QUADS);
        glVertex3f(0.5, 0, 0.5);
        glVertex3f(0.5, 0, -0.5);
        glVertex3f(-0.5, 0, -0.5);
        glVertex3f(-0.5, 0, 0.5);

        glVertex3f(0.5,0,-0.5);
        glVertex3f(0.5,1,0);
        glVertex3f(-0.5,1,0);
        glVertex3f(-0.5,0,-0.5);

        glVertex3f(0.5,1,0);
        glVertex3f(-0.5,1,0);
        glVertex3f(-0.5,0,0.5);
        glVertex3f(0.5,0,0.5);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex3f(0.5,0,0.5);
        glVertex3f(0.5,1,0);
        glVertex3f(0.5,0,-0.5);

        glVertex3f(-0.5,0,0.5);
        glVertex3f(-0.5,1,0);
        glVertex3f(-0.5,0,-0.5);
    glEnd();
    glPopMatrix();

    //parete traseira
    glPushMatrix();
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glColor3f(217/255.0, 179/255.0, 148/255.0);
    glTranslatef(0.0, 1.5, -10.0f);
    glScalef(20.0f, 3.0f, 1.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    //teto parede traseira
    glPushMatrix();
    glTranslatef(0.0, 10, 3);
    glRotated(90, 1, 0, 0);
    glScaled(20.0,0.7,1.3);
    glColor3f(182/255.0, 110/255.0, 110/255.0);
    glBegin(GL_QUADS);
        glVertex3f(0.5, 0, 0.5);
        glVertex3f(0.5, 0, -0.5);
        glVertex3f(-0.5, 0, -0.5);
        glVertex3f(-0.5, 0, 0.5);

        glVertex3f(0.5,0,-0.5);
        glVertex3f(0.5,1,0);
        glVertex3f(-0.5,1,0);
        glVertex3f(-0.5,0,-0.5);

        glVertex3f(0.5,1,0);
        glVertex3f(-0.5,1,0);
        glVertex3f(-0.5,0,0.5);
        glVertex3f(0.5,0,0.5);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex3f(0.5,0,0.5);
        glVertex3f(0.5,1,0);
        glVertex3f(0.5,0,-0.5);

        glVertex3f(-0.5,0,0.5);
        glVertex3f(-0.5,1,0);
        glVertex3f(-0.5,0,-0.5);
    glEnd();
    glPopMatrix();

    //parede esquerda
    glPushMatrix();
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glColor3f(217/255.0, 179/255.0, 148/255.0);
    glTranslatef(10.0, 1.5, 0.0f);
    glScalef(1.0f, 3.0f, 20.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    //teto parede esquerda
    glPushMatrix();
    glTranslatef(10.0, 0, 3);
    glRotated(90, 1, 0, 0);
    glRotated(90, 0, 1, 0);
    glScaled(20.0,0.7,1.3);
    glColor3f(182/255.0, 110/255.0, 110/255.0);
    glBegin(GL_QUADS);
        glVertex3f(0.5, 0, 0.5);
        glVertex3f(0.5, 0, -0.5);
        glVertex3f(-0.5, 0, -0.5);
        glVertex3f(-0.5, 0, 0.5);

        glVertex3f(0.5,0,-0.5);
        glVertex3f(0.5,1,0);
        glVertex3f(-0.5,1,0);
        glVertex3f(-0.5,0,-0.5);

        glVertex3f(0.5,1,0);
        glVertex3f(-0.5,1,0);
        glVertex3f(-0.5,0,0.5);
        glVertex3f(0.5,0,0.5);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex3f(0.5,0,0.5);
        glVertex3f(0.5,1,0);
        glVertex3f(0.5,0,-0.5);

        glVertex3f(-0.5,0,0.5);
        glVertex3f(-0.5,1,0);
        glVertex3f(-0.5,0,-0.5);
    glEnd();
    glPopMatrix();

    //parede direita
    glPushMatrix();
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glColor3f(217/255.0, 179/255.0, 148/255.0);
    glTranslatef(-10.0, 1.5, 0.0f);
    glScalef(1.0f, 3.0f, 20.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    //teto parede direita
    glPushMatrix();
    glTranslatef(-10.0, 0, 3);
    glRotated(90, 1, 0, 0);
    glRotated(90, 0, 1, 0);
    glScaled(20.0,0.7,1.3);
    glColor3f(182/255.0, 110/255.0, 110/255.0);
    glBegin(GL_QUADS);
        glVertex3f(0.5, 0, 0.5);
        glVertex3f(0.5, 0, -0.5);
        glVertex3f(-0.5, 0, -0.5);
        glVertex3f(-0.5, 0, 0.5);

        glVertex3f(0.5,0,-0.5);
        glVertex3f(0.5,1,0);
        glVertex3f(-0.5,1,0);
        glVertex3f(-0.5,0,-0.5);

        glVertex3f(0.5,1,0);
        glVertex3f(-0.5,1,0);
        glVertex3f(-0.5,0,0.5);
        glVertex3f(0.5,0,0.5);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex3f(0.5,0,0.5);
        glVertex3f(0.5,1,0);
        glVertex3f(0.5,0,-0.5);

        glVertex3f(-0.5,0,0.5);
        glVertex3f(-0.5,1,0);
        glVertex3f(-0.5,0,-0.5);
    glEnd();
    glPopMatrix();

    //portão superior
    glPushMatrix();
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glColor3f(217/255.0, 179/255.0, 148/255.0);
    glTranslatef(0.0, 3.0, 10.0f);
    glScalef(4.0f, 2.5f, 2.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    //teto portão
    glPushMatrix();
    glTranslatef(0.0, -10, 4.25);
    glRotated(90, 1, 0, 0);
    glRotated(90, 0, 1, 0);
    glScaled(2.2,1.5,4.5);
    glColor3f(182/255.0, 110/255.0, 110/255.0);
    glBegin(GL_QUADS);
        glVertex3f(0.5, 0, 0.5);
        glVertex3f(0.5, 0, -0.5);
        glVertex3f(-0.5, 0, -0.5);
        glVertex3f(-0.5, 0, 0.5);

        glVertex3f(0.5,0,-0.5);
        glVertex3f(0.5,1,0);
        glVertex3f(-0.5,1,0);
        glVertex3f(-0.5,0,-0.5);

        glVertex3f(0.5,1,0);
        glVertex3f(-0.5,1,0);
        glVertex3f(-0.5,0,0.5);
        glVertex3f(0.5,0,0.5);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex3f(0.5,0,0.5);
        glVertex3f(0.5,1,0);
        glVertex3f(0.5,0,-0.5);

        glVertex3f(-0.5,0,0.5);
        glVertex3f(-0.5,1,0);
        glVertex3f(-0.5,0,-0.5);
    glEnd();
    glPopMatrix();

    //torre central
    glPushMatrix();
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glColor3f(217/255.0, 179/255.0, 148/255.0);
    glTranslatef(0.0, 2.0, 0.0);
    glScalef(10.0f, 4.0f, 10.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    //teto torre central
    glPushMatrix();
    glTranslatef(0.0, 0.0, 4.0);
    glRotated(90, 1, 0, 0);
    glRotated(90, 0, 1, 0);
    glScaled(10.5,2.2,10.5);
    glColor3f(182/255.0, 110/255.0, 110/255.0);
    glBegin(GL_QUADS);
        glVertex3f(0.5, 0, 0.5);
        glVertex3f(0.5, 0, -0.5);
        glVertex3f(-0.5, 0, -0.5);
        glVertex3f(-0.5, 0, 0.5);

        glVertex3f(0.5,0,-0.5);
        glVertex3f(0.5,1,0);
        glVertex3f(-0.5,1,0);
        glVertex3f(-0.5,0,-0.5);

        glVertex3f(0.5,1,0);
        glVertex3f(-0.5,1,0);
        glVertex3f(-0.5,0,0.5);
        glVertex3f(0.5,0,0.5);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex3f(0.5,0,0.5);
        glVertex3f(0.5,1,0);
        glVertex3f(0.5,0,-0.5);

        glVertex3f(-0.5,0,0.5);
        glVertex3f(-0.5,1,0);
        glVertex3f(-0.5,0,-0.5);
    glEnd();
    glPopMatrix();

    //mini torre central
    glPushMatrix();
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glColor3f(217/255.0, 179/255.0, 148/255.0);
    glTranslatef(0.0, 5.0, 0.0);
    glScalef(3.0f, 10.0f, 3.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    //teto mini torre central
    glPushMatrix();
    glTranslatef(0.0, 0.0, 10.0);
    glRotated(90, 1, 0, 0);
    glRotated(90, 0, 1, 0);
    glScaled(3.5,2.2,3.5);
    glColor3f(182/255.0, 110/255.0, 110/255.0);
    glBegin(GL_QUADS);
        glVertex3f(0.5, 0, 0.5);
        glVertex3f(0.5, 0, -0.5);
        glVertex3f(-0.5, 0, -0.5);
        glVertex3f(-0.5, 0, 0.5);

        glVertex3f(0.5,0,-0.5);
        glVertex3f(0.5,1,0);
        glVertex3f(-0.5,1,0);
        glVertex3f(-0.5,0,-0.5);

        glVertex3f(0.5,1,0);
        glVertex3f(-0.5,1,0);
        glVertex3f(-0.5,0,0.5);
        glVertex3f(0.5,0,0.5);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex3f(0.5,0,0.5);
        glVertex3f(0.5,1,0);
        glVertex3f(0.5,0,-0.5);

        glVertex3f(-0.5,0,0.5);
        glVertex3f(-0.5,1,0);
        glVertex3f(-0.5,0,-0.5);
    glEnd();
    glPopMatrix();

    //portão inferior esquerdo
    glPushMatrix();
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glColor3f(217/255.0, 179/255.0, 148/255.0);
    glTranslatef(-1.25, 1.75/2.0, 10.0f);
    glScalef(1.5f, 1.75f, 2.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    //portão inferior direito
    glPushMatrix();
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glColor3f(217/255.0, 179/255.0, 148/255.0);
    glTranslatef(+1.25, 1.75/2.0, 10.0f);
    glScalef(1.5f, 1.75f, 2.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

}


void renderScene(void) {

	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glClearColor(1.0, 1.0, 1.0, 1.0);
	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(	0.0f, 10.0f,  30.0f,
				0.0f, 1.0f,  4.0f,
				0.0f, 1.0f,  0.0f);

    glRotatef(anglex, 0.0f, 1.0f, 0.0f);
    glRotatef(angley, 1.0f, 0.0f, 0.0f);

    glPushMatrix();
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);


// Draw ground
    glPushMatrix();
    glColor4f(0.9f, 0.9f, 0.9f, 0.0f);
    glTranslatef(0.0f, 0.0f, 0.0f);
    glScalef(25.0f, 25.0f, 0.3f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    drawCastle();
    glPopMatrix();
    glPopMatrix();
    anglex+=deltaAnglex;
    angley+=deltaAngley;

	glutSwapBuffers();
}

void SetupRC(){

    // Light values and coordinates
    GLfloat  whiteLight[] = { 0.05f, 0.05f, 0.05f, 1.0f };
    GLfloat  sourceLight[] = { 0.25f, 0.25f, 0.25f, 1.0f };
    GLfloat  lightPos[] = { -10.f, 5.0f, 5.0f, 1.0f };

    glEnable(GL_DEPTH_TEST);    // Hidden surface removal
    glFrontFace(GL_CCW);        // Counter clock-wise polygons face out

    // Enable lighting
    glEnable(GL_LIGHTING);

    // Setup and enable light 0
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,whiteLight);
    glLightfv(GL_LIGHT0,GL_AMBIENT,sourceLight);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,sourceLight);
    glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
    glEnable(GL_LIGHT0);

    // Enable color tracking
    glEnable(GL_COLOR_MATERIAL);

    // Set Material properties to follow glColor values
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
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

void processNormalKeys(unsigned char key, int x, int y) {

	if (key == 27)
		exit(0);
}


int main(int argc, char **argv) {

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(0,0);
	glutInitWindowSize(1200,768);
	glutCreateWindow("Endrew e Thiago Pimenta - Castelo");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
    glutSpecialFunc(pressKey);
    glutIgnoreKeyRepeat(1);
	glutSpecialUpFunc(releaseKey);
    glutKeyboardFunc(processNormalKeys);

	// OpenGL init
	SetupRC();

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}