#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

void drawRectangle(GLfloat start_x, GLfloat start_y, GLfloat width, GLfloat height){
    GLfloat end_x = start_x + width;
    GLfloat end_y = start_y + height;

    glBegin(GL_POLYGON);
        
    glVertex3f(start_x, start_y, 0.0); // bottom left
    glVertex3f(end_x, start_y, 0.0); // bottom right
    glVertex3f(end_x, end_y, 0.0); // top right
    glVertex3f(start_x, end_y, 0.0); // top left

    glEnd();
}

void drawHalfCircle(GLfloat x,GLfloat y )
{
	int i;

	GLfloat twicePi = 2.0 * 3.142;
	GLfloat radius = 2;
	
	glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE

	glVertex2f(x, y); // center of circle
	for (i = 0; i <= 10; i++)
	{
		glVertex2f(
			(x + (radius * cos(i * twicePi / 20))), (y + (radius * (sin(i * twicePi / 20) * 0.4))));
	}
	glEnd(); //END
}

void drawLine(GLfloat start_x, GLfloat start_y, GLfloat end_x, GLfloat end_y)
{
	glBegin(GL_LINES);
	glVertex2f(start_x, start_y);
	glVertex2f(end_x, end_y);
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


void drawCircle(GLfloat x, GLfloat y, GLfloat radius)
{
    int i;

    double twicePi = 2.0 * 3.142;

    glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
    glVertex2f(x, y);         // center of circle
    for (i = 0; i <= 20; i++)
    {
        glVertex2f(
            (x + (radius * cos(i * twicePi / 20))), (y + (radius * sin(i * twicePi / 20))));
    }
    glEnd(); //END
}