

void drawStove(GLfloat x, GLfloat y)
{
    GLfloat radius = 2.5;

    glPushMatrix();
	useBlack();
	drawCircle(x, y, radius + 0.2);
	useWhite();
    drawCircle(x, y, radius);
    glPopMatrix();
}

void drawColdStoves(){
	glPushMatrix();
	drawStove(-4.7, 0);
	drawStove(-1.5, 10);
	drawStove(6.5, 9);
	glPopMatrix();
}

void drawHeatingStove(GLfloat x, GLfloat y, int frame)
{
    GLfloat radius = 3;

    glPushMatrix();
		useBlack();
		drawCircle(x, y, radius + 0.2);

		if (frame > 5 && frame < 10)
			useRed();
		else if (frame > 2 && frame < 6)
			useYellow();
		else
			useWhite();

        drawCircle(x, y, radius);
    glPopMatrix();
}

void drawKitchenStoveTop(int frame)
{
	glPushMatrix();
	glColor3f(0.2, 0.3, 0.4);
	glRotatef(80, 1, 0, 0);
	glRotatef(-20, 0, 0, 1);
	drawRectangle(-8, -8, 16, 25);
	glPopMatrix();

	glPushMatrix();
	glRotatef(80, 1, 0, 0);
	drawColdStoves();
	glPopMatrix();

	glPushMatrix();
	glRotatef(80, 1, 0, 0);
	drawHeatingStove(2.7, -3.1, frame);
	glPopMatrix();
}

void drawKitchenStove(int frame){
	drawKitchenStoveTop(frame);
}