
GLfloat rotation = 0;

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

void drawStoveKnob(GLfloat x, GLfloat y ){
	GLfloat radius = 1;

	glPushMatrix();
	useBlack();
	drawCircle(x + 0.05, y, radius + 0.2);
	useWhite();
	drawCircle(x, y, radius);
	useGray();
	drawRectangle(x - 0.1, y - 1, 0.3, 2);
	useBlack();
	drawRectangle(x - 0.1, y - 1, 0.2, 2);
	glPopMatrix();
}

void drawAnimatedStoveKnob(GLfloat x, GLfloat y, float frame){
	GLfloat radius = 1;

	glPushMatrix();
	useBlack();
	drawCircle(x + 0.05, y, radius + 0.2);
	useWhite();
	drawCircle(x, y, radius);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(x - 0.1, y, 0);
		if (frame >= 9 &&  frame < 11){
			rotation -= 13.6;
			glRotatef(rotation, 0, 0, 1);
		}else if (frame <= 2){
			rotation += 13.6;
			glRotatef(rotation, 0, 0, 1);
		}

		useGray();
		drawRectangle(-0.1, -1, 0.4, 2);
		useBlack();
		drawRectangle(-0.1, -1, 0.2, 2);
	glPopMatrix();
}

void drawColdStoves(){
	glPushMatrix();
	drawStove(-4.7, 0);
	drawStove(-1.5, 10);
	drawStove(6.5, 9);
	glPopMatrix();
}

void drawHeatingStove(GLfloat x, GLfloat y, float frame)
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

void drawKitchenStoveTop(float frame)
{
	glPushMatrix();
	useDarkGray();
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

void drawKitchenStoveBottom(){
	glPushMatrix();
	useDarkGray();
	glTranslatef(-0.1, -2, 0);
	glRotatef(80, 1, 0, 0);
	glRotatef(-20, 0, 0, 1);
	drawRectangle(-8, -8, 16, 25);
	glPopMatrix();
}

void drawKitchenStoveBorders(){
	glPushMatrix();
	useBlack();
	drawLine(-10.12, -0.8, 4.6, -1.8);
	drawLine(4.6, -1.8, 13.3, 2.3);
	drawLine(4.6, -1.8, 4.4, -4);
	drawLine(13.3, 2.3, 13.2, 0.3);
	glPopMatrix();
}

void drawKitchenStoveSide(){
	glPushMatrix();
	useDarkGray();
	glBegin(GL_POLYGON);

    glVertex3f(4.4, -4, 0.0); // bottom left
    glVertex3f(13.2, 0.3, 0.0); // bottom right
    glVertex3f(13.3, 2.3, 0.0); // top right
    glVertex3f(4.6, -1.8, 0.0); // top left

    glEnd();
	glPopMatrix();
}

void drawKitchenStoveInterface(float frame){
	glPushMatrix();
	useDarkGray();
	drawRectangle(-8.3, -8, 14.9, 2.5);
	glPopMatrix();

	glPushMatrix();
	drawStoveKnob(-6.7, -6.7);
	drawStoveKnob(-2.7, -6.7);
	drawStoveKnob(1.3, -6.7);
	drawAnimatedStoveKnob(5.3, -6.7, frame);
	glPopMatrix();
}

void drawKitchenStove(float frame){
	drawKitchenStoveTop(frame);
	drawKitchenStoveSide();

	glPushMatrix();
	glTranslatef(-1.6, 3.4, 0);
	glRotatef(30, 1, 0, 0);
	glRotatef(-4, 0, 0, 1);
	drawKitchenStoveInterface(frame);
	glPopMatrix();

	drawKitchenStoveBorders();
	
}