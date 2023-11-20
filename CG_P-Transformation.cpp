#include<iostream>
#include<GL/glut.h>
using namespace std;
#define h 700
#define w 700
 
int mati[30][40], k = 0, c; 
int x, y, x1, y11, x2, y2;

void myInit(void)
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,0.0);
	glPointSize(3.0);
	glLineWidth(3.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w/2,w/2,-h/2,h/2);
}

void Plot(float x, float y)
{
	glVertex2i(x, y);
}

void MouseClick(int button, int state, int x, int y)
{
	int p, q;
	
	if(state == GLUT_DOWN)
	{
		if(button == GLUT_LEFT_BUTTON)
		{
			mati[k][0] = (float)(x-350);
			mati[k][1] = (float)(350-y);
			
			glColor3f(0.0, 1.0, 1.0);
			glBegin(GL_POINTS);
			glVertex2f(mati[k][0], mati[k][1]);
			glEnd();
			k++;
			glFlush();
		}
		
		if(button == GLUT_RIGHT_BUTTON)
		{
			glBegin(GL_LINE_LOOP);
			for(int i = 0; i<k; i++)
			{
				glVertex2f(mati[i][0], mati[i][1]);
			}
			glEnd();
			//c = k;
			k = 0;
			glFlush();
		}
	}		
}	

void Menu(int n)
{
	switch(n)
	{
		case 1:
			exit(0);
	}	
}	

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	glColor3f(0.0, 0.0, 0.0);
	
	for(int i=-w; i<=w; i++)
	{
		Plot(i, 0);
		Plot(0, i);
	}	
		
	glEnd();
	glFlush();
}
		
int main(int argc, char **argv)
{				
		cout<<"\n\n\t\t ========================= \n";
		cout<<"\t\t ||  Mouse Interfacing  || \n";
		cout<<"\t\t ========================= \n\n";
				
			glutInit(&argc,argv);
			glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
			glutInitWindowSize(700,700);
			glutInitWindowPosition(50,100);
			glutCreateWindow("Mouse Interfacing");
			glutDisplayFunc(myDisplay);
			myInit();
			glutMouseFunc(MouseClick);
			//Menu Creation
			glutCreateMenu(Menu); 
				glutAddMenuEntry(" 1. Exit ", 1);
			glutAttachMenu(GLUT_MIDDLE_BUTTON);
			glutMainLoop();
	
	return 0;	
}


	
