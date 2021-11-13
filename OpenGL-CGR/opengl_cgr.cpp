#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#include "smokeCloud.cpp"

int smoke = 0;

void drawSq()
{
	glBegin(GL_POLYGON);
	glVertex3f(-1.2, 0, 0.0);
	glVertex3f(-1.2, 1, 0.0);
	glVertex3f(1.2, 1, 0.0);
	glVertex3f(1.2, 0, 0.0);
	glEnd();
}
void drawHandle(){
	glBegin(GL_POLYGON);
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glEnd();

}

void drawTriangle()
{
	glBegin(GL_TRIANGLES);
	glVertex3f(-2, 3.5, 0);
	glVertex3f(-2.8, 3.5, 0);
	glVertex3f(-1.5, 2.2, 0);
	glEnd();
}

void drawLid()
{
	int i;

	GLfloat twicePi = 2.0 * 3.142;
	GLfloat radius = 2;
	GLfloat x = 0;
	GLfloat y = 3.5;
	glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE

	glVertex2f(x, y); // center of circle
	for (i = 0; i <= 10; i++)
	{
		glVertex2f(
			(x + (radius * cos(i * twicePi / 20))), (y + (radius * (sin(i * twicePi / 20) * .4))));
	}
	glEnd(); //END
}

void smokeTimer(int value)
{
	glutTimerFunc(1000, smokeTimer, 0);

	printf("I am about to make a smoke cloud.\n");
	printf("This is the cloud nr %d.\n", smoke);

	if (smoke < 13)
		smoke++;
	else
		smoke = 0;

	glutPostRedisplay();
}

void drawFan()
{

	GLfloat triangleVertices[] = {
		0,
		0,
		0,
		1.5,
		0.2,
		0,
		2,
		-2.5,
		0,
		1,
		-3,
		0,
		-1,
		-3,
		0,
		-2,
		-2.5,
		0,
		-1.5,
		0.2,
		0,
		-0.5,
		0.5,
		0,
		0.5,
		0.5,
		0,
		1.5,
		0.2,
		0,

	};

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, triangleVertices);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 10);
	glDisableClientState(GL_VERTEX_ARRAY);
}
//render method (callback-function)
void display()
{
	//clear all pixels
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	//draw white polygon with corners
	glColor3f(1.0, 1.0, 1.0);
	//	drawSq();

	glColor3f(250, 1.0, 1.0);
	glRotatef(45, 45, 0, 0);
	drawHeatingPad(smoke);
	glColor3f(.5, .5, 0.5);

	glLoadIdentity();
	glPushMatrix();

	drawFan();
	glPopMatrix();

	glPushMatrix();
	drawTriangle();
	glPopMatrix();

	glPushMatrix();
	glColor3f(.5, .5, 0.5);
	glTranslatef(0, 1, 0);
	glRotatef(180, 0, 0, 0);
	drawFan();
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	drawLid();
	glPopMatrix();
	drawSq();
	smokeCloudSwitch(smoke);
	//don't wait! process buffered OpenGL routines
	glFlush();
}

//initialization of the application. only started once.
void init()
{
	//select clearing color (color that is used as 'background')
	glClearColor(0, 0, 0, 0.0);

	//initialize view
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.0, 10.0, -10.0, 10.0, -5.0, 5.0);

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
	glutTimerFunc(1000, smokeTimer, 0);
	//enter main loop and process events
	glutMainLoop();

	return 0;
}