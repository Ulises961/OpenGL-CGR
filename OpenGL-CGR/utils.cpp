#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>


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

void useRed()
{
    glColor3f(255, 0, 0);
}

void useYellow()
{
    glColor3f(255, 255, 0);
}

void useWhite()
{
    glColor3f(255, 255, 255);
}

void useBlack()
{
    glColor3f(0, 0, 0);
}

void useGray(){
    glColor3f(0.5, 0.5, 0.5);
}