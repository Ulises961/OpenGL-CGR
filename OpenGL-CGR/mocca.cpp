
void drawFan()
{

	GLfloat triangleVertices[] = {
		0, 0, 0,	  // Center
		1.5, 0.2, 0,  // upperRight
		2, -2.5, 0,	  // bottomRight
		1, -3, 0,	  // bottomCenterRight
		-1, -3, 0,	  // bottomCenterLeft
		-2, -2.5, 0,  // bottomLeft
		-1.5, 0.2, 0, // upperLeft
		-0.5, 0.5, 0, // upperCenterLeft
		0.5, 0.5, 0,  // upperCenterRight
		1.5, 0.2, 0,  // closingCircle

	};

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, triangleVertices);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 10);
	drawLine(-0.5, 0.3, -1, -3);
	drawLine(0.5, 0.3, 1, -3);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void drawPressureValve()
{
	useYellow();
	drawCircle(0, 0, 0.2);
	useBlack();
	drawCircle(0, 0, 0.05);
}

void drawHandle()
{
	useBlack();
	glPushMatrix();
	drawRectangle(1.9, 2.7, 1.4, 0.8);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.55, 2.5, 0);
	glRotatef(-60.0, 0.0, 0.0, 1.0);
	glTranslatef(-1, -0.3, 0);
	drawRectangle(0, 0, 2.0, 0.6);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.9, 1.35, 0);
	glRotatef(75.0, 0.0, 0.0, 1.0);
	glTranslatef(-0.5, -0.3, 0);
	drawRectangle(0.0, 0.0, 1.0, 0.6);
	glPopMatrix();

	glLoadIdentity();
}

void drawLid()
{

	GLfloat x = 0;
	GLfloat y = 3.5;
	drawHalfCircle(x, y);
}

void drawBorders(){
    glPushMatrix();
	useBlack();

	// Lower half trapecies arists
	drawLine(-0.5, 0.3, -1, -3);
	drawLine(0.5, 0.3, 1, -3);
	// Upper half trapecies arists
	drawLine(-0.5, 0.7, -1, 3.5);
	drawLine(0.5, 0.7, 1, 3.5);

	//Rim lines
	drawLine(-1.2, 0.7, 1.2, 0.7);
	drawLine(-1.2, 0.3, 1.2, 0.3);
	glPopMatrix();
}

void drawMocca(){
	// Lower Half
	glPushMatrix();
	drawFan();
	glPopMatrix();

	// Pouring slit
	glPushMatrix();
	drawTriangle();
	glPopMatrix();

	// Upper Half
	glPushMatrix();
	glTranslatef(0, 1, 0);
	glRotatef(180, 0, 0, 1);
	drawFan();
	glPopMatrix();

	// Lid
	glPushMatrix();
	drawLid();
	useBlack();
	drawLine(-2, 3.5, 2, 3.5);
	glPopMatrix();

	// Handle
	glPushMatrix();
	drawHandle();
	glPopMatrix();

	// Lid Knob
	glPushMatrix();
	useBlack();
	glTranslatef(0, 4.2, 0);
	glScalef(0.2, 0.2, 0.2);
	glRotatef(180, 0, 0, 1);
	drawFan();
	glPopMatrix();

	glPushMatrix();
	useGray();
	drawRectangle(-1.2, 0, 2.4, 1);
	glPopMatrix();

	// Borders
    drawBorders();

	// Pressure valve
	glPushMatrix();
	glTranslatef(-1.2, -0.3, 0);
	glRotatef(60, 0, 1, 0);
	drawPressureValve();
	glPopMatrix();
}
