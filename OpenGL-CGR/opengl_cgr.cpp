#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#include "smokeCloud.cpp"

int smoke = 0;

void drawLine(GLfloat start_x, GLfloat start_y, GLfloat end_x, GLfloat end_y)
{
	glBegin(GL_LINES);
	glVertex2f(start_x, start_y);
	glVertex2f(end_x, end_y);
	glEnd();
}

void drawHandle()
{
	useBlack();
	glPushMatrix();
	drawRectangle(1.8, 2.5, 1.4, 0.6);
	glPopMatrix();
	glPushMatrix();

	glTranslatef(3.4, 2.65, 0);
	glRotatef(-60.0, 0.0, 0.0, 1.0);
	glTranslatef(-0.5, -0.5, 0);
	drawRectangle(0, 0, 2.0, 0.6);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(3.6, 1.12, 0);
	glRotatef(80.0, 0.0, 0.0, 1.0);
	glTranslatef(-0.5, -0.5, 0);
	drawRectangle(0.0, 0.0, 1.0, 0.6);
	glPopMatrix();
	glLoadIdentity();
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
		0,0,0, // Center
		1.5,0.2,0, // upperRight
		2,-2.5,0, // bottomRight
		1,-3,0, // bottomCenterRight
		-1,-3,0, // bottomCenterLeft
		-2,-2.5,0, // bottomLeft
		-1.5,0.2,0, // upperLeft
		-0.5,0.5,0, // upperCenterLeft
		0.5,0.5,0, // upperCenterRight
		 1.5,0.2,0, // closingCircle

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

	//	drawSq();

	glColor3f(250, 1.0, 1.0);
	glRotatef(45, 45, 0, 0);
	drawHeatingPad(smoke);
	useGray();

	glLoadIdentity();
	glPushMatrix();
	drawFan();
	glPopMatrix();

	glPushMatrix();
	drawTriangle();
	glPopMatrix();

	glPushMatrix();

	glTranslatef(0, 1, 0);
	glRotatef(180, 0, 0, 1);
	drawFan();
	glPopMatrix();
	glPushMatrix();

	drawLid();

	useBlack();
	drawLine(-2, 3.5, 2, 3.5);
	glPopMatrix();

	drawHandle();
	glPushMatrix();
	useBlack();
	glTranslatef(0, 4.2, 0);
	glScalef(0.2, 0.2, 0.2);
	glRotatef(180, 0, 0, 1);
	drawFan();
	glPopMatrix();
	
	useGray();

	drawRectangle(-1.2, 0, 2.4, 1);
	glPushMatrix();
	useBlack();
	drawLine(-0.5, 0.3, -1, -3);
	drawLine(0.5, 0.3, 1, -3);
	
	// drawLine(1.5, 0.2, , );
	// drawLine(, , , );

	drawLine(-1.2, 0.7, 1.2, 0.7);
	drawLine(-1.2, 0.3, 1.2, 0.3);
	glPopMatrix();
	
	smokeCloudSwitch(smoke);
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