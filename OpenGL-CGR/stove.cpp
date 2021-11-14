
void drawHeatingPad(int frame)
{
    int x = 0;
    int y = -3;

    int i;
    GLfloat radius = 2.5;

    glPushMatrix();
    if (frame > 5 && frame < 10)
        useRed();
    else if (frame > 2 && frame < 6)
        useYellow();
    else
        useWhite();

        drawCircle(x, y, radius);

    glPopMatrix();
}

void drawStove(int frame)
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
			drawHeatingPad(frame);
		glPopMatrix();}
		}

}