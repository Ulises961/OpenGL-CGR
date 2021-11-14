#include "colors.cpp"
#include "shapes.cpp"
#include "mocca.cpp"
#include "stove.cpp"
#include "smokeCloud.cpp"

int frame = 0;

void animationFrameTimer(int value)
{
	glutTimerFunc(300, animationFrameTimer, 0);

	if (frame < 13)
		frame++;
	else
		frame = 0;

	glutPostRedisplay();
}

//render method (callback-function)
void display()
{
	//clear all pixels
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	// Cooking Stove
	glPushMatrix();
		drawKitchenStove(frame);
	glPopMatrix();

	// Draw Mocca
	glPushMatrix();
		glTranslatef(2.7, 1.4, 0);
		glScalef(0.8, 0.8, 0.8);
		drawMocca();
	glPopMatrix();

	glLoadIdentity();

	// Smoke Cloud
	glPushMatrix();
		glTranslatef(2.7, 1.4, 0);
		smokeCloudSwitch(frame);
	glPopMatrix();

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
	glOrtho(-15.0, 15.0, -15.0, 15.0, -15.0, 15.0);

	//set matrix-mode back to model-view for rendering
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	//initialize display mode (single buffer and RGBA)
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	//initialize window size and position. open window
	glutInitWindowSize(500, 500);
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