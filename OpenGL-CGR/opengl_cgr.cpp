#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#include "smokeCloud.cpp"

int smoke = 0;

void drawPressureValve()
{
	useYellow();
	drawCircle(0, 0, 0.2);
	useBlack();
	drawCircle(0, 0, 0.05);
}

void drawStove()
{
	glPushMatrix();

	glColor3f(0.2, 0.3, 0.4);
	glRotatef(10, 0, 1, 0);
	drawRectangle(-8, -8, 16, 16);
	glPopMatrix();

	glPopMatrix();
	for(int i = 1; i <= 4;i++){
		int row = pow(-1,i);
			for(int j = 1; j <= 4;j++){
		int column = pow(-1,j);
		glPushMatrix();
			glTranslatef(row * 3.5, column * 4+2,0);
			// Heatting pad
			glRotatef(45, 1, 0, 0);
			drawHeatingPad(smoke);
		glPopMatrix();}
		}


}

void drawHandle()
{
	useBlack();
	glPushMatrix();
	drawRectangle(1.9, 2.7, 1.4, 0.8);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.55, 2.5, 0);
	glRotatef(-60.0, 0.0, 0.0, 1.0);
	glTranslatef(-1, -0.3, 0);
	drawRectangle(0, 0, 2.0, 0.6);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.9, 1.35, 0);
	glRotatef(75.0, 0.0, 0.0, 1.0);
	glTranslatef(-0.5, -0.3, 0);
	drawRectangle(0.0, 0.0, 1.0, 0.6);
	glPopMatrix();

	glLoadIdentity();
}

void drawLid()
{

	GLfloat x = 0;
	GLfloat y = 3.5;
	drawHalfCircle(x, y);
}

void animationFrameTimer(int value)
{
	glutTimerFunc(350, animationFrameTimer, 0);

	if (smoke < 13)
		smoke++;
	else
		smoke = 0;

	glutPostRedisplay();
}

void drawFan()
{

	GLfloat triangleVertices[] = {
		0, 0, 0,	  // Center
		1.5, 0.2, 0,  // upperRight
		2, -2.5, 0,	  // bottomRight
		1, -3, 0,	  // bottomCenterRight
		-1, -3, 0,	  // bottomCenterLeft
		-2, -2.5, 0,  // bottomLeft
		-1.5, 0.2, 0, // upperLeft
		-0.5, 0.5, 0, // upperCenterLeft
		0.5, 0.5, 0,  // upperCenterRight
		1.5, 0.2, 0,  // closingCircle

	};

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, triangleVertices);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 10);
	drawLine(-0.5, 0.3, -1, -3);
	drawLine(0.5, 0.3, 1, -3);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void assembleMocca(){
	// Lower Half
	glPushMatrix();
	drawFan();
	glPopMatrix();

	// Pouring slit
	glPushMatrix();
	drawTriangle();
	glPopMatrix();

	// Upper Half
	glPushMatrix();
	glTranslatef(0, 1, 0);
	glRotatef(180, 0, 0, 1);
	drawFan();
	glPopMatrix();

	// Lid
	glPushMatrix();
	drawLid();
	useBlack();
	drawLine(-2, 3.5, 2, 3.5);
	glPopMatrix();

	// Handle
	glPushMatrix();
	drawHandle();
	glPopMatrix();

	// Lid Knob
	glPushMatrix();
	useBlack();
	glTranslatef(0, 4.2, 0);
	glScalef(0.2, 0.2, 0.2);
	glRotatef(180, 0, 0, 1);
	drawFan();
	glPopMatrix();

	glPushMatrix();
	useGray();
	drawRectangle(-1.2, 0, 2.4, 1);
	glPopMatrix();

	// Borders

	glPushMatrix();
	useBlack();

	// Lower half trapecies arists
	drawLine(-0.5, 0.3, -1, -3);
	drawLine(0.5, 0.3, 1, -3);
	// Upper half trapecies arists
	drawLine(-0.5, 0.7, -1, 3.5);
	drawLine(0.5, 0.7, 1, 3.5);

	//Rim lines
	drawLine(-1.2, 0.7, 1.2, 0.7);
	drawLine(-1.2, 0.3, 1.2, 0.3);
	glPopMatrix();

	// Pressure valve
	glPushMatrix();
	glTranslatef(-1.2, -0.3, 0);
	glRotatef(60, 0, 1, 0);
	drawPressureValve();
	glPopMatrix();

	// Smoke Cloud
	smokeCloudSwitch(smoke);
}
//render method (callback-function)
void display()
{
	//clear all pixels
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	// Cooking Stove
	glPushMatrix();
		drawStove();
	glPopMatrix();

	// // Heatting pad
	// glRotatef(45, 1, 0, 0);
	// drawHeatingPad(smoke);
	// useGray();
		// Draw Mocca
	glPushMatrix();
		assembleMocca();
	glPopMatrix();
	glLoadIdentity();


	//don't wait! process buffered OpenGL routines
	glFlush();
}

//initialization of the application. only started once.
void init()
{
	//select clearing color (color that is used as 'background')
	glClearColor(.3, 0, 0, 0.2);

	//initialize view
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);

	//set matrix-mode back to model-view for rendering
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	//initialize display mode (single buffer and RGBA)
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	//initialize window size and position. open window
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("OpenGL - CGR");

	//call initialization routine
	init();

	//register callback function to display graphics
	glutDisplayFunc(display);
	glutTimerFunc(1000, animationFrameTimer, 0);
	//enter main loop and process events
	glutMainLoop();

	return 0;
}