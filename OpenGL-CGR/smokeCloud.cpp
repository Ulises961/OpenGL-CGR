#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

// void drawSmokeCloud(GLfloat start_x, GLfloat start_y, GLfloat width, GLfloat height){
//     int end_x = start_x + width;
//     int end_y = start_y + height;

//     glPushMatrix();
//     glBegin(GL_POLYGON);
//     glVertex3f(start_x, start_y, 0.0); // bottom left
//     glVertex3f(start_x, end_y, 0.0); // top left
//     glVertex3f(end_x, start_y, 0.0); // bottom right
//     glVertex3f(end_x, end_y, 0.0); // top right
//     glEnd();
//     glPopMatrix();
// }

void drawCircle(GLfloat x, GLfloat y)
{
    //static float angle;

    int i;
    double radius = 0.30;

    glColor3f(1, 1, 1);
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
void drawSmokeCloud(GLfloat x, GLfloat y)
{
    for (int i =0; i < 5; i++)
    {
        x -= 0.1;
        y += 0.05;
        drawCircle(x, y);
        x -= i/4;
        y += i/2;
        drawCircle(x, y);
    }
}

void smokeCloudSwitch(int cloud_nr)
{
    GLfloat width = 1;
    GLfloat height = 1;

    switch (cloud_nr)
    {
    case 0:
        glColor3f(250, 1.0, 1.0);
        drawSmokeCloud(-2.5, 3.7);
        break;

    case 1:
        glColor3f(250, 1.0, 1.0);
         drawSmokeCloud(-2.6, 3.7);
      
        break;

    case 2:
        glColor3f(250, 1.0, 1.0);
         drawSmokeCloud(-2.6, 3.7);
        drawSmokeCloud(-2.7, 3.9);
        break;

    case 3:
        glColor3f(250, 1, 1.0);
      
        drawSmokeCloud(-2.8, 4);
        break;

    default:
        break;
    }
}
