#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <Math.h>

void drawSmokeCloud(GLfloat start_x, GLfloat start_y, GLfloat width, GLfloat height){
    int end_x = start_x + width;
    int end_y = start_y + height;

    glPushMatrix();
    glBegin(GL_POLYGON);
    glVertex3f(start_x, start_y, 0.0); // bottom left
    glVertex3f(end_x, start_y, 0.0); // bottom right
    glVertex3f(start_x, end_y, 0.0); // top left
    glVertex3f(end_x, end_y, 0.0); // top right
    glEnd();
    glPopMatrix();
}

void smokeCloudSwitch(int cloud_nr){
    GLfloat width = 0.5;
    GLfloat height = 0.5;

    switch (cloud_nr){
        case 0:
            glColor3f(250, 1.0, 1.0);
            drawSmokeCloud(0, 0, width, height);
            break;

        case 1:
            glColor3f(250, 1.0, 1.0);
            drawSmokeCloud(0, 0, width, height);
            break;

        case 2:
            glColor3f(250, 1.0, 1.0);
            drawSmokeCloud(0, 0, width, height);
            break;

        case 3:
            glColor3f(250, 1, 1.0);
            drawSmokeCloud(0, 0, width, height);
            break;
        
        default:
            break;
    }
}