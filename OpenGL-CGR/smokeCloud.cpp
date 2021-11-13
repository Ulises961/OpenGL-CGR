#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

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
void drawCircle(GLfloat x, GLfloat y, GLfloat radius)
{
    //static float angle;

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
void drawHeatingPad(int counter)
{
    int x = 0;
    int y = -3;

    int i;
    GLfloat radius = 2.5;

    glPushMatrix();
    if (counter > 5 && counter < 10)
        useRed();
    else if (counter > 2 && counter < 6)
        useYellow();
    else
        useWhite();

        drawCircle(x, y, radius);

    glPopMatrix();
}

void drawSmokeCloud(GLfloat x, GLfloat y)
{
    glColor3f(250, 1.0, 1.0);

    for (int i = 0; i < 5; i++)
    {
        x -= 0.1;
        y += 0.05;
  
    drawCircle(x, y, 0.5);
  
        x -= i / 4;
        y += i / 2;
       
    drawCircle(x, y, 0.7);
    
    }
}

void smokeCloudSwitch(int cloud_nr)
{
    GLfloat width = 1;
    GLfloat height = 1;

    switch (cloud_nr)
    {
    case 5:
        glColor3f(250, 1.0, 1.0);
        drawSmokeCloud(-2.5, 3.6);
        break;

    case 6:
        glColor3f(250, 1.0, 1.0);

        drawSmokeCloud(-2.6, 3.75);
        drawSmokeCloud(-2.6, 3.85);

        break;

    case 7:
        glColor3f(250, 1.0, 1.0);

        drawSmokeCloud(-2.8, 4);
        drawSmokeCloud(-3, 4.5);
        drawSmokeCloud(-3.5, 5);
        break;

    case 8:
        glColor3f(250, 1, 1.0);

        drawSmokeCloud(-2.9, 5);
        drawSmokeCloud(-3, 4.5);
        drawSmokeCloud(-3.5, 5);
        break;

    default:
        break;
    }
}
