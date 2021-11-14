

void drawSmokeCloud(GLfloat x, GLfloat y)
{
    useWhite();

    for (int i = 0; i < 5; i++)
    {
        x -= 0.1;
        y += 0.05;
  
    drawCircle(x, y, 0.5);
  
        x -= i / 4;
        y += i / 2;
       
    drawCircle(x, y, 0.6);
    
    }
}

void smokeCloudSwitch(int frame)
{
    GLfloat width = 1;
    GLfloat height = 1;

    switch (frame)
    {
    case 6:
        drawSmokeCloud(-2.5, 3.6);
        break;

    case 7:
        drawSmokeCloud(-2.6, 3.75);
        drawSmokeCloud(-2.6, 3.85);

        break;

    case 8:
        drawSmokeCloud(-2.8, 4);
        drawSmokeCloud(-3, 4.5);
        drawSmokeCloud(-3.5, 5);
        break;

    case 9:
        drawSmokeCloud(-2.9, 5);
        drawSmokeCloud(-3, 4.5);
        drawSmokeCloud(-3.5, 5);
        break;

    default:
        break;
    }
}
