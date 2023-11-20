#include<iostream>
#include<GL/glut.h>
#include<math.h>
using namespace std;

void Background(bool);
int globx = 600;
int globy = 700;
bool globday = true;
int theta;
int radius;

void myInit(void)
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,0.0);
	glPointSize(3.0);
	glLineWidth(3.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,1920.0,0.0,1080.0);
	Background(true);
}

void Scenery(void)
{
	int p = 0, q = 0;

	glClear(GL_COLOR_BUFFER_BIT);
	
	// Background Sky
	glBegin(GL_POLYGON);
		glColor3f(0.529,0.808,0.922);	// Sky Blue
		glVertex2i(0,700);
		glVertex2i(0,1080);
		glVertex2i(1920,1080);
		glVertex2i(1920,700);
	glEnd();

	// Grass background
	glBegin(GL_POLYGON);
		glColor3f(0.6,0.7,0.0);
		glVertex2i(0,700);
		glVertex2i(1920,700);		
		glVertex2i(1920,0);
		glVertex2i(0,0);
	glEnd();
	
	// Mountain 1
	glBegin(GL_POLYGON);
		glColor3f(0.6,0.4,0.2);
		glVertex2i(2,700);
		glVertex2i(202,980);		
		glVertex2i(402,700);
	glEnd();
	glFlush();
	
	// Mountain 2
	glBegin(GL_POLYGON);
		glColor3f(0.6,0.4,0.2);
		glVertex2i(252,700);
		glVertex2i(452,1000);		
		glVertex2i(652,700);
	glEnd();
	glFlush();
	
	// Mountain 3
	glBegin(GL_POLYGON);
		glColor3f(0.6,0.4,0.2);
		glVertex2i(510,700);
		glVertex2i(710,960);		
		glVertex2i(910,700);
	glEnd();
	glFlush();
	
	// Mountain 4
	glBegin(GL_POLYGON);
		glColor3f(0.6,0.4,0.2);
		glVertex2i(1010,700);
		glVertex2i(1210,950);		
		glVertex2i(1410,700);
	glEnd();
	glFlush();
    
    // River
	glBegin(GL_POLYGON);
		glColor3f(0.300,0.700,0.920);	// water
		glVertex2i(790,0);
		glVertex2i(900,700);		
		glVertex2i(1020,700);
		glVertex2i(1130,0);
	glEnd();
	
		// Tree 1
		p = 0, q = 0;	
		for(int i = 0; i<=5; i++)
		{
			glBegin(GL_POLYGON);
			glColor3f(0.0,0.392,0.0);		//Dark Green
			glVertex2i(400-p,500+q);
			glVertex2i(450,550+q);		
			glVertex2i(500+p,500+q);
			glEnd();
			
			p += 10;
			q += -20;
		}
		glBegin(GL_POLYGON);
			glColor3f(0.647,0.164,0.164);
			glVertex2i(440,400);
			glVertex2i(460,400);		
			glVertex2i(460,350);
			glVertex2i(440,350);			
			glEnd();
			
		p = 0, q = 0;	
		// Tree 2	
		for(int i = 0; i<=5; i++)
		{
			glBegin(GL_POLYGON);
			glColor3f(0.0,0.392,0.0);		//Dark Green
			glVertex2i(300-p,300+q);
			glVertex2i(350,350+q);		
			glVertex2i(400+p,300+q);
			glEnd();
			
			p += 10;
			q += -20;
		}
		glBegin(GL_POLYGON);
			glColor3f(0.647,0.164,0.164);
			glVertex2i(340,200);
			glVertex2i(360,200);		
			glVertex2i(360,150);
			glVertex2i(340,150);			
			glEnd();
			
		p = 0, q = 0;	
		// Tree 3
		for(int i = 0; i<=5; i++)
		{
			glBegin(GL_POLYGON);
			glColor3f(0.0,0.392,0.0);		//Dark Green
			glVertex2i(100-p,600+q);
			glVertex2i(150,650+q);		
			glVertex2i(200+p,600+q);
			glEnd();
			
			p += 10;
			q += -20;
		}
		glBegin(GL_POLYGON);
			glColor3f(0.647,0.164,0.164);
			glVertex2i(140,500);
			glVertex2i(160,500);		
			glVertex2i(160,450);
			glVertex2i(140,450);			
			glEnd();
			
		p = 0, q = 0;	
		// Tree 4
		for(int i = 0; i<=5; i++)
		{
			glBegin(GL_POLYGON);
			glColor3f(0.0,0.392,0.0);		//Dark Green
			glVertex2i(60-p,350+q);
			glVertex2i(110,400+q);		
			glVertex2i(160+p,350+q);
			glEnd();
			
			p += 10;
			q += -20;
		}
		glBegin(GL_POLYGON);
			glColor3f(0.647,0.164,0.164);
			glVertex2i(100,250);
			glVertex2i(120,250);		
			glVertex2i(120,200);
			glVertex2i(100,200);			
			glEnd();			
		
	// Boat
		glBegin(GL_POLYGON);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(910,500);
		glVertex2i(930,540);		
		glVertex2i(990,540);
		glVertex2i(1010,500);
	glEnd();
	
		glBegin(GL_LINE_LOOP);
		glColor3f(1.0,1.0,1.0);
		glVertex2i(910,500);
		glVertex2i(930,540);		
		glVertex2i(990,540);
		glVertex2i(1010,500);
	glEnd();
	
	glBegin(GL_POLYGON);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(900,500);
		glVertex2i(960,525);		
		glVertex2i(1020,500);
		glVertex2i(1000,445);
		glVertex2i(960,450);	
		glVertex2i(920,445);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
		glColor3f(1.0,1.0,1.0);
		glVertex2i(900,500);
		glVertex2i(960,525);		
		glVertex2i(1020,500);
		glVertex2i(1000,445);
		glVertex2i(960,450);	
		glVertex2i(920,445);
	glEnd();
	
		glBegin(GL_POLYGON);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(935,540);
		glVertex2i(945,575);		
		glVertex2i(975,575);
		glVertex2i(985,540);
	glEnd();
		
	// Boat window	
		glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glVertex2i(945,550);
		glVertex2i(950,565);		
		glVertex2i(955,565);
		glVertex2i(955,550);
	glEnd();
	
		glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glVertex2i(965,550);
		glVertex2i(965,565);		
		glVertex2i(970,565);
		glVertex2i(975,550);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
		glColor3f(1.0,1.0,1.0);
		glVertex2i(960,460);
		glVertex2i(960,515);	
		glEnd();
		
		glBegin(GL_POLYGON);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(955,575);
		glVertex2i(960,650);		
		glVertex2i(965,575);	
		glEnd();
		
		glBegin(GL_LINE_LOOP);
		glColor3f(1.0,1.0,1.0);
		glVertex2i(955,575);	
		glVertex2i(965,575);			
		glEnd();
		
		glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(950,610);	
		glVertex2i(970,610);			
		glEnd();
		
	// House
	
	// Front Wall
		glBegin(GL_POLYGON);
		glColor3f(1.0,0.98,0.8); // Cream
		glVertex2i(1300,300);
		glVertex2i(1300,450);		
		glVertex2i(1750,450);	
		glVertex2i(1750,300);	
		glEnd();
		
		// Front Piller Left
		glBegin(GL_POLYGON);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(1270,250);
		glVertex2i(1270,450);		
		glVertex2i(1280,450);	
		glVertex2i(1280,250);	
		glEnd();	
		
		// Front Piller Right
		glBegin(GL_POLYGON);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(1770,250);
		glVertex2i(1770,450);		
		glVertex2i(1780,450);	
		glVertex2i(1780,250);	
		glEnd();	
		
		// Lower Wall Part
		glBegin(GL_POLYGON);
		glColor3f(0.71,0.396,0.114);
		glVertex2i(1300,300);
		glVertex2i(1300,320);		
		glVertex2i(1750,320);	
		glVertex2i(1750,300);	
		glEnd();
		
	// Ceiling
		glBegin(GL_POLYGON);
		glColor3f(0.647,0.164,0.164); // brown
		glVertex2i(1220,450);
		glVertex2i(1350,580);		
		glVertex2i(1700,580);	
		glVertex2i(1830,450);	
		glEnd();
		
	// Ceiling Lines
		p = 0, q = 0;
		
		glBegin(GL_LINE_LOOP);	
			glColor3f(0.0,0.0,0.0);
			glVertex2i(1260,490);
			glVertex2i(1790,490);			
			glEnd();
		
		for(int i = 1; i <= 4; i++)
		{
			glBegin(GL_LINE_LOOP);	
			glColor3f(0.0,0.0,0.0);
			glVertex2i(1260+p,490+q);
			glVertex2i(1790-p,490+q);			
			glEnd();
			
			p += 30;
			q += 30;
		}
		
		// Floor
		glBegin(GL_POLYGON);
		glColor3f(0.647,0.164,0.164);
		glVertex2i(1300,300);
		glVertex2i(1750,300);
		glVertex2i(1790,250);		
		glVertex2i(1260,250);	
		glEnd();
		
		// Floor Front Side
		glBegin(GL_POLYGON);
		glColor3f(0.3,0.3,0.3);
		glVertex2i(1260,250);
		glVertex2i(1790,250);
		glVertex2i(1790,220);		
		glVertex2i(1260,220);	
		glEnd();
		
		// Floor Steps
		glBegin(GL_POLYGON);
		glColor3f(0.71,0.396,0.114);	// light brown
		glVertex2i(1480,240);
		glVertex2i(1400,240);		
		glVertex2i(1400,210);	
		glVertex2i(1480,210);	
		glEnd();
		
		// Floor Steps Lines
		glBegin(GL_LINE_LOOP);	
		glColor3f(0.0,0.0,0.0);	// black
		glVertex2i(1480,240);
		glVertex2i(1400,240);		
		glVertex2i(1400,225);	
		glVertex2i(1480,225);	
		glEnd();
		
		// Floor Steps Lines
		glBegin(GL_LINE_LOOP);	
		glColor3f(0.0,0.0,0.0);	// black
		glVertex2i(1400,225);	
		glVertex2i(1480,225);	
		glVertex2i(1480,210);
		glVertex2i(1400,210);
		glEnd();
		
		// Door Outline	
		glBegin(GL_LINE_LOOP);	
		glColor3f(0.647,0.164,0.164);	// brown
		glVertex2i(1400,300);	
		glVertex2i(1480,300);	
		glVertex2i(1480,430);
		glVertex2i(1400,430);
		glEnd();
		
		// Door		
		glBegin(GL_POLYGON);
		glColor3f(0.71,0.396,0.114);	// light brown
		glVertex2i(1400,300);	
		glVertex2i(1480,300);	
		glVertex2i(1480,430);
		glVertex2i(1400,430);
		glEnd();
		
		// Window 1	
		glBegin(GL_POLYGON);
		glColor3f(1.0,0.98,0.8);   // Cream
		glVertex2i(1550,350);
		glVertex2i(1600,350);		
		glVertex2i(1600,420);	
		glVertex2i(1550,420);	
		glEnd();
		
		// Window 2	
		glBegin(GL_POLYGON);
		glColor3f(1.0,0.98,0.8);   // Cream
		glVertex2i(1650,350);
		glVertex2i(1700,350);		
		glVertex2i(1700,420);	
		glVertex2i(1650,420);	
		glEnd();
		
		// Window Outline 1	
		glBegin(GL_LINE_LOOP);	
		glColor3f(0.647,0.164,0.164);	// brown
		glVertex2i(1550,350);
		glVertex2i(1600,350);		
		glVertex2i(1600,420);	
		glVertex2i(1550,420);	
		glEnd();
		
		// Window Outline 2	
		glBegin(GL_LINE_LOOP);	
		glColor3f(0.647,0.164,0.164);	// brown
		glVertex2i(1650,350);
		glVertex2i(1700,350);		
		glVertex2i(1700,420);	
		glVertex2i(1650,420);	
		glEnd();
		
		// Window lines 1
		p = 0;	
			
		for(int i = 1; i <= 4; i++)
		{
			glBegin(GL_LINE_LOOP);	
			glColor3f(0.647,0.164,0.164);	// brown
			glVertex2i(1560+p,353);
			glVertex2i(1560+p,417);			
			glEnd();
			
			p += 10;
		}

		// Window lines 2
		p = 0;	
			
		for(int i = 1; i <= 4; i++)
		{
			glBegin(GL_LINE_LOOP);	
			glColor3f(0.647,0.164,0.164);	// brown
			glVertex2i(1660+p,353);
			glVertex2i(1660+p,417);			
			glEnd();
			
			p += 10;
		}
		
		// Plant
		// 1
		glBegin(GL_POLYGON);
		glColor3f(0.71,0.396,0.114);	// light brown
		glVertex2i(1330,150);
		glVertex2i(1360,150);		
		glVertex2i(1370,200);	
		glVertex2i(1320,200);	
		glEnd();
		
		glBegin(GL_LINE_LOOP);	
		glColor3f(0.3,0.3,0.3);   // light black
		glVertex2i(1330,150);
		glVertex2i(1360,150);		
		glVertex2i(1370,200);	
		glVertex2i(1320,200);	
		glEnd();
		
		// Flower
		glBegin(GL_LINE_LOOP);	
		glColor3f(0.0,0.392,0.0);		//Dark Green
		glVertex2i(1345,200);
		glVertex2i(1345,250);			
		glEnd();
		
		// petal 1
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		theta;
		radius=13;
		for(int i = 0; i < 360; i++) {
		    theta = i * 3.142/180;
		    glVertex2f(1335 + radius*sin(theta), 260 + radius*cos(theta));
		}
		glEnd();
		
		// petal 2
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		theta;
		radius=13;
		for(int i = 0; i < 360; i++) {
		    theta = i * 3.142/180;
		    glVertex2f(1345 + radius*sin(theta), 265 + radius*cos(theta));
		}
		glEnd();
		
		// petal 3
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		theta;
		radius=13;
		for(int i = 0; i < 360; i++) {
		    theta = i * 3.142/180;
		    glVertex2f(1355 + radius*sin(theta), 260 + radius*cos(theta));
		}
		glEnd();
		
		// petal 4
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		theta;
		radius=13;
		for(int i = 0; i < 360; i++) {
		    theta = i * 3.142/180;
		    glVertex2f(1335 + radius*sin(theta), 240 + radius*cos(theta));
		}
		glEnd();
		
		// petal 5
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		theta;
		radius=13;
		for(int i = 0; i < 360; i++) {
		    theta = i * 3.142/180;
		    glVertex2f(1345 + radius*sin(theta), 235 + radius*cos(theta));
		}
		glEnd();
		
		// petal 6
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		theta;
		radius=13;
		for(int i = 0; i < 360; i++) {
		    theta = i * 3.142/180;
		    glVertex2f(1355 + radius*sin(theta), 240 + radius*cos(theta));
		}
		glEnd();
		
		glColor3f(1.0, 0.647, 0.0);
		glBegin(GL_POLYGON);
		theta;
		radius=10;
		for(int i = 0; i < 360; i++) {
		    theta = i * 3.142/180;
		    glVertex2f(1345 + radius*sin(theta), 250 + radius*cos(theta));
		}
		glEnd();
		
		glBegin(GL_POLYGON);
		glColor3f(0.71,0.396,0.114);	// light brown
		glVertex2i(1630,150);
		glVertex2i(1660,150);		
		glVertex2i(1670,200);	
		glVertex2i(1620,200);	
		glEnd();
		
		glBegin(GL_LINE_LOOP);	
		glColor3f(0.3,0.3,0.3);   // light black
		glVertex2i(1630,150);
		glVertex2i(1660,150);		
		glVertex2i(1670,200);	
		glVertex2i(1620,200);	
		glEnd();
		
		// Flower
		glBegin(GL_LINE_LOOP);	
		glColor3f(0.0,0.392,0.0);		//Dark Green
		glVertex2i(1645,200);
		glVertex2i(1645,250);			
		glEnd();
		
		// petal 1
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		theta;
		radius=13;
		for(int i = 0; i < 360; i++) {
		    theta = i * 3.142/180;
		    glVertex2f(1635 + radius*sin(theta), 240 + radius*cos(theta));
		}
		glEnd();
		
		// petal 2
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		theta;
		radius=13;
		for(int i = 0; i < 360; i++) {
		    theta = i * 3.142/180;
		    glVertex2f(1645 + radius*sin(theta), 235 + radius*cos(theta));
		}
		glEnd();
		
		// petal 3
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		theta;
		radius=13;
		for(int i = 0; i < 360; i++) {
		    theta = i * 3.142/180;
		    glVertex2f(1655 + radius*sin(theta), 240 + radius*cos(theta));
		}
		glEnd();
		
		// petal 4
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		theta;
		radius=13;
		for(int i = 0; i < 360; i++) {
		    theta = i * 3.142/180;
		    glVertex2f(1635 + radius*sin(theta), 260 + radius*cos(theta));
		}
		glEnd();
		
		// petal 5
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		theta;
		radius=13;
		for(int i = 0; i < 360; i++) {
		    theta = i * 3.142/180;
		    glVertex2f(1645 + radius*sin(theta), 265 + radius*cos(theta));
		}
		glEnd();
		
		// petal 6
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		theta;
		radius=13;
		for(int i = 0; i < 360; i++) {
		    theta = i * 3.142/180;
		    glVertex2f(1655 + radius*sin(theta), 260 + radius*cos(theta));
		}
		glEnd();
		
		glColor3f(1.0, 0.647, 0.0);
		glBegin(GL_POLYGON);
		theta;
		radius=10;
		for(int i = 0; i < 360; i++) {
		    theta = i * 3.142/180;
		    glVertex2f(1645 + radius*sin(theta), 250 + radius*cos(theta));
		}
		glEnd();
		
		glBegin(GL_POLYGON);
		glColor3f(0.71,0.396,0.114);	// light brown
		glVertex2i(1730,150);
		glVertex2i(1760,150);		
		glVertex2i(1770,200);	
		glVertex2i(1720,200);	
		glEnd();
		
		glBegin(GL_LINE_LOOP);	
		glColor3f(0.3,0.3,0.3);   // light black
		glVertex2i(1730,150);
		glVertex2i(1760,150);		
		glVertex2i(1770,200);	
		glVertex2i(1720,200);	
		glEnd();
		
		// Flower
		glBegin(GL_LINE_LOOP);	
		glColor3f(0.0,0.392,0.0);		//Dark Green
		glVertex2i(1745,200);
		glVertex2i(1745,250);			
		glEnd();
		
		// petal 1
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		theta;
		radius=13;
		for(int i = 0; i < 360; i++) {
		    theta = i * 3.142/180;
		    glVertex2f(1735 + radius*sin(theta), 240 + radius*cos(theta));
		}
		glEnd();
		
		// petal 2
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		theta;
		radius=13;
		for(int i = 0; i < 360; i++) {
		    theta = i * 3.142/180;
		    glVertex2f(1745 + radius*sin(theta), 235 + radius*cos(theta));
		}
		glEnd();
		
		// petal 3
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		theta;
		radius=13;
		for(int i = 0; i < 360; i++) {
		    theta = i * 3.142/180;
		    glVertex2f(1755 + radius*sin(theta), 240 + radius*cos(theta));
		}
		glEnd();
		
		// petal 4
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		theta;
		radius=13;
		for(int i = 0; i < 360; i++) {
		    theta = i * 3.142/180;
		    glVertex2f(1735 + radius*sin(theta), 260 + radius*cos(theta));
		}
		glEnd();
		
		// petal 5
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		theta;
		radius=13;
		for(int i = 0; i < 360; i++) {
		    theta = i * 3.142/180;
		    glVertex2f(1745 + radius*sin(theta), 265 + radius*cos(theta));
		}
		glEnd();
		
		// petal 6
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		theta;
		radius=13;
		for(int i = 0; i < 360; i++) {
		    theta = i * 3.142/180;
		    glVertex2f(1755 + radius*sin(theta), 260 + radius*cos(theta));
		}
		glEnd();
		
		glColor3f(1.0, 0.647, 0.0);
		glBegin(GL_POLYGON);
		theta;
		radius=10;
		for(int i = 0; i < 360; i++) {
		    theta = i * 3.142/180;
		    glVertex2f(1745 + radius*sin(theta), 250 + radius*cos(theta));
		}
		glEnd();
		
	// Cloud 1	
	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(300 + radius*sin(theta), 1000 + radius*cos(theta));
    }
    glEnd();
    
    // Cloud 1
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(320 + radius*sin(theta), 980 + radius*cos(theta));
    }
    glEnd();
    
    // Cloud 1
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(340 + radius*sin(theta), 1000 + radius*cos(theta));
    }
    glEnd();	
		
	glFlush();	
	
	// Cloud 1
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(360 + radius*sin(theta), 980 + radius*cos(theta));
    }
    glEnd();	
    
    // Cloud 1
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(380 + radius*sin(theta), 1000 + radius*cos(theta));
    }
    glEnd();
    
    // Cloud 2
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(60 + radius*sin(theta), 980 + radius*cos(theta));
    }
    glEnd();
    
    // Cloud 2
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(80 + radius*sin(theta), 960 + radius*cos(theta));
    }
    glEnd();	
		
	// Cloud 2
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(100 + radius*sin(theta), 980 + radius*cos(theta));
    }
    glEnd();
    
    // Cloud 2
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(120 + radius*sin(theta), 960 + radius*cos(theta));
    }
    glEnd();	
    
    // Cloud 2
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(140 + radius*sin(theta), 980 + radius*cos(theta));
    }
    glEnd();
    
    // Cloud 3
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(480 + radius*sin(theta), 920 + radius*cos(theta));
    }
    glEnd();
    
    // Cloud 3
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(500 + radius*sin(theta), 900 + radius*cos(theta));
    }
    glEnd();
    
    // Cloud 3
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(520 + radius*sin(theta), 920 + radius*cos(theta));
    }
    glEnd();
		
	// Cloud 3
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(540 + radius*sin(theta), 900 + radius*cos(theta));
    }
    glEnd();	
    
    // Cloud 3
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(560 + radius*sin(theta), 920 + radius*cos(theta));
    }
    glEnd();
    
    // Cloud 4
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(1250 + radius*sin(theta), 980 + radius*cos(theta));
    }
    glEnd();
    
    // Cloud 4
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(1270 + radius*sin(theta), 960 + radius*cos(theta));
    }
    glEnd();
    
    // Cloud 4
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(1290 + radius*sin(theta), 980 + radius*cos(theta));
    }
    glEnd();
		
	// Cloud 4
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(1310 + radius*sin(theta), 960 + radius*cos(theta));
    }
    glEnd();	
    
    // Cloud 4
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
	theta;
	radius=30;
    for(int i = 0; i < 360; i++) {
        theta = i * 3.142/180;
        glVertex2f(1330 + radius*sin(theta), 980 + radius*cos(theta));
    }
    glEnd();
    
    // Birds 
    
    // Bird-1 Wing-Left
		glBegin(GL_LINE_LOOP);
			glColor3f(0.0,0.0,0.0);
			glVertex2i(1000,1000);
			glVertex2i(1020,980);		
			glVertex2i(1020,970);			
			glEnd();  	
			
		// Bird-1 Wing-Right
			glBegin(GL_LINE_LOOP);
			glColor3f(0.0,0.0,0.0);
			glVertex2i(1020,970);
			glVertex2i(1020,980);		
			glVertex2i(1040,1000);			
			glEnd(); 	
	
	 // Bird-2 Wing-Left
		glBegin(GL_LINE_LOOP);
			glColor3f(0.0,0.0,0.0);
			glVertex2i(900,950);
			glVertex2i(920,930);		
			glVertex2i(920,920);			
			glEnd();  	
			
		// Bird-2 Wing-Right	
			glBegin(GL_LINE_LOOP);
			glColor3f(0.0,0.0,0.0);
			glVertex2i(920,920);
			glVertex2i(920,930);		
			glVertex2i(940,950);			
			glEnd(); 
			
	 // Bird-3 Wing-Left
		glBegin(GL_LINE_LOOP);
			glColor3f(0.0,0.0,0.0);
			glVertex2i(960,980);
			glVertex2i(980,960);		
			glVertex2i(980,950);			
			glEnd();  	
			
		// Bird-3 Wing-Right	
			glBegin(GL_LINE_LOOP);
			glColor3f(0.0,0.0,0.0);
			glVertex2i(980,950);
			glVertex2i(980,960);		
			glVertex2i(1000,980);			
			glEnd(); 
			
	 // Bird-4 Wing-Left
		glBegin(GL_LINE_LOOP);
			glColor3f(0.0,0.0,0.0);
			glVertex2i(1800,900);
			glVertex2i(1820,880);		
			glVertex2i(1820,870);			
			glEnd();  	
			
		// Bird-4 Wing-Right	
			glBegin(GL_LINE_LOOP);
			glColor3f(0.0,0.0,0.0);
			glVertex2i(1820,870);
			glVertex2i(1820,880);		
			glVertex2i(1840,900);			
			glEnd(); 					
		
	 // Bird-5 Wing-Left
		glBegin(GL_LINE_LOOP);
			glColor3f(0.0,0.0,0.0);
			glVertex2i(1750,930);
			glVertex2i(1770,910);		
			glVertex2i(1770,900);			
			glEnd();  	
			
		// Bird-5 Wing-Right	
			glBegin(GL_LINE_LOOP);
			glColor3f(0.0,0.0,0.0);
			glVertex2i(1770,900);
			glVertex2i(1770,910);		
			glVertex2i(1790,930);			
			glEnd(); 
			
		// Grass
		// Line1 
		p = 0;
		for(int i = 0; i<=11 ; i++)
		{
			glBegin(GL_LINE_LOOP);
			glColor3f(0.0,0.392,0.0);
			glVertex2i(50+p,670);
			glVertex2i(40+p,680);					
			glEnd();
			p += 70;
		}
		
		p += 210;
		for(int i = 0; i<=11 ; i++)
		{
			glBegin(GL_LINE_LOOP);
			glColor3f(0.0,0.392,0.0);
			glVertex2i(50+p,670);
			glVertex2i(40+p,680);					
			glEnd();
			p += 70;
		}
		
		p = 0;
		for(int i = 0; i<=11 ; i++)
		{
			glBegin(GL_LINE_LOOP);
			glColor3f(0.0,0.392,0.0);
			glVertex2i(50+p,670);
			glVertex2i(60+p,680);					
			glEnd();
			p += 70;
		}
		
		p += 210;
		for(int i = 0; i<=11 ; i++)
		{
			glBegin(GL_LINE_LOOP);
			glColor3f(0.0,0.392,0.0);
			glVertex2i(50+p,670);
			glVertex2i(60+p,680);					
			glEnd();
			p += 70;
		}
		
		p = 0;
		for(int i = 0; i<=11 ; i++)
		{
			glBegin(GL_LINE_LOOP);
			glColor3f(0.0,0.392,0.0);
			glVertex2i(50+p,670);
			glVertex2i(50+p,685);					
			glEnd();
			p += 70;
		}
		
		p += 210;
		for(int i = 0; i<=11 ; i++)
		{
			glBegin(GL_LINE_LOOP);
			glColor3f(0.0,0.392,0.0);
			glVertex2i(50+p,670);
			glVertex2i(50+p,685);					
			glEnd();
			p += 70;
		}
			
	glFlush();			
}

void sunmoon(int x,int y,bool day)
{
//glClear(GL_COLOR_BUFFER_BIT);
	float angle_theta;
	if(day != true)
	{
		glColor3f(1.0, 1.0, 0.0);
		glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++)
        {
            angle_theta = i * 3.142 / 180;
            glVertex3f(x + 100 * cos(angle_theta),
                       y + 100 * sin(angle_theta),1);
        }
        glEnd();
    	glFlush();
    }
    else
    {
    	glColor3f(1.0, 1.0, 0.0);
		glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++)
        {
            angle_theta = i * 3.142 / 180;
            glVertex3f(x + 100 * cos(angle_theta),
                       y + 100 * sin(angle_theta),1);
        }
        glEnd();
    	glFlush();
    }
}

void Background(bool day)
{
	if(day == true)
	{
		glBegin(GL_POLYGON);
		glColor3f(0.529,0.808,0.922);	// Sky Blue
		glVertex2i(0,0);
		glVertex2i(0,800);
		glVertex2i(800,800);
		glVertex2i(800,0);
		glEnd();
		//glFlush();
		
		glBegin(GL_POLYGON);
		glColor3f(0.529,0.808,0.922);	// Sky Blue
		glVertex2i(0,500);
		glColor3f(0.5f,0.8f,0.9f);
		glVertex2i(0,800);
		glColor3f(0.5f,0.8f,0.9f);
		glVertex2i(800,800);
		glColor3f(0.31f,0.70f,0.47f);
		glVertex2i(800,500);
		glEnd();
		//glFlush();
	}
	
	else
	{
		glBegin(GL_POLYGON);
		glColor3f(0.f,0.54f,0.0f);
		glVertex2i(0,0);
		glVertex2i(0,800);
		glVertex2i(800,800);
		glVertex2i(800,0);
		glEnd();
		glFlush();
		glColor3f(0.0f,0.0f,0.0f);
		glBegin(GL_POLYGON);
		glVertex2i(0,500);
		glVertex2i(0,800);
		glVertex2i(800,800);
		glVertex2i(800,500);
		glEnd();
		glFlush();
				
	}
		
		glBegin(GL_TRIANGLES);
		glColor3f(0.6f,0.8f,0.19f);
		glVertex2i(0,500);
		glColor3f(0.33f,0.25f,0.14f);
		glVertex2i(150,700);
		glColor3f(0.6f,0.8f,0.19f);
		glVertex2i(300,500);
		glEnd();
		glFlush();
		
		Scenery();

}

void Timer(int value) 
{
	//glClear(GL_COLOR_BUFFER_BIT);
    	globy -= 10;
    	glutPostRedisplay();
    	if(globy <= 540)
    	{
			globy = 700;
			globday = !globday;
    	}
    	glutTimerFunc(1000, Timer, value);
}
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	Background(globday);
	sunmoon(globx,globy,globday);
	glEnd();
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1920,1080);
	glutInitWindowPosition(100,150);
	glutCreateWindow(" SCENERY ");
	glutTimerFunc(1000, Timer, 1);
	glutDisplayFunc(Scenery);
	myInit();
	glutMainLoop();
	
	return 0;
}


