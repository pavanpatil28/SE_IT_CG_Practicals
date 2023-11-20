#include<iostream>
#include<GL/glut.h>

using namespace std;
#define h 1300
#define w 1300

float x1, x2, y11, y2;
float dx, dy, length, x, y;

void myInit(void)
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,0.0);
	glPointSize(3.0);
	glLineWidth(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w/2,w/2,-h/2,h/2);
}

void SetPixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}	

void Plot(float x, float y)
{
	glVertex2i(x, y);
}

int Sign(int x)
{
 	if(x>0)
 	{
 		return 1;
 	}
 	else if(x==0)
 	{
 		return 0;
 	}
 	else
 	{
 		return -1;
 	}

}	

void DDA_Line(float x1,float y11,float x2,float y2)
{	
	
	int i = 1;

	if(abs(x2-x1) >= abs(y2-y11))
	{
		length = abs(x2-x1);
	}	

	else
	{
		length = abs(y2-y11);
	}

	dx = (x2-x1)/length; 
	dy = (y2-y11)/length;
	
	x = x1 + 0.5*Sign(dx);
	y = y11 + 0.5*Sign(dy);
	
	glBegin(GL_POINTS);
	
	Plot(x,y);

	while ( i <= length )
	{
		x = x + dx;
		y = y + dy;
			
		Plot(x,y);
		
		i++;
	}
}

void DDA_Dotted_Line(float x1,float y11,float x2,float y2)
{	
	
	int i = 1;

	if(abs(x2-x1) >= abs(y2-y11))
	{
		length = abs(x2-x1);
	}	

	else
	{
		length = abs(y2-y11);
	}

	dx = (x2-x1)/length; 
	dy = (y2-y11)/length;
	
	x = x1 + 0.5*Sign(dx);
	y = y11 + 0.5 *Sign(dy);
	
	glBegin(GL_POINTS);
	
	Plot(x,y);

	while ( i <= length )
	{
		x = x + dx;
		y = y + dy;
			
		if(i%20 == 0)
		{	
			Plot(x,y);
		}
		
		i++;
	}
}

void DDA_Dashed_Line(float x1,float y11,float x2,float y2)
{	
	
	int i = 1;

	if(abs(x2-x1) >= abs(y2-y11))
	{
		length = abs(x2-x1);
	}	

	else
	{
		length = abs(y2-y11);
	}

	dx = (x2-x1)/length; 
	dy = (y2-y11)/length;
	
	x = x1 + 0.5*Sign(dx);
	y = y11 + 0.5 *Sign(dy);
	
	glBegin(GL_POINTS);
	
	Plot(x,y);

	while ( i <= length )
	{
		x = x + dx;
		y = y + dy;
		
		if(i%4==0 && i%20!=0)
		{
			Plot(x,y);
		}
		
		i++;
	}
}

void DDA_Center_Dot_Line(float x1,float y11,float x2,float y2)
{	
	
	int i = 1;

	if(abs(x2-x1) >= abs(y2-y11))
	{
		length = abs(x2-x1);
	}	

	else
	{
		length = abs(y2-y11);
	}

	dx = (x2-x1)/length; 
	dy = (y2-y11)/length;
	
	x = x1 + 0.5*Sign(dx);
	y = y11 + 0.5*Sign(dy);
	
	glBegin(GL_POINTS);
	
	Plot(x,y);

	while ( i <= length )
	{
		x = x + dx;
		y = y + dy;
			
		
		if(i%20<=10 || i%20==15)
		{
			Plot(x,y);
		}	
		
		i++;
	}
}

// Menu
void Menu(int n)
{
	switch(n)
	{
		case 1:
			DDA_Line(x1,y11,x2,y2);
			break;
				
		case 2:
			DDA_Dotted_Line(x1,y11,x2,y2);			
			break;
			
		case 3:
			DDA_Dashed_Line(x1,y11,x2,y2);	
			break;
			
		case 4:
			DDA_Center_Dot_Line(x1,y11,x2,y2);	
			break;
			
		case 5:
			DDA_Line(50.0f,200.0f,100.0f,50.0f);
			DDA_Line(100.0f,50.0f,450.0f,50.0f);
			DDA_Line(450.0f,50.0f,500.0f,200.0f);
			DDA_Line(500.0f,200.0f,50.0f,200.0f);
			DDA_Line(200.0f,200.0f,300.0f,500.0f);
			DDA_Line(300.0f,500.0f,300.0f,200.0f);
			break;		
			
		case 6:
			exit(0);
	}	
	
}	

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	
	for(int i=-w; i<=w; i++)
	{
		SetPixel(i, 0);
		SetPixel(0, i);
	}		
		
	glEnd();
	glFlush();
}

int main(int argc, char **argv)
{			
		cout<<"\n\n\t\t ============================== \n";
		cout<<"\t\t ||  DDA Line Drawing Algo  || \n";
		cout<<"\t\t ============================== \n\n";
		
			cout<<"\n Enter The Start Point :: \n\n >> x1 = ";
			cin>>x1;
			cout<<" >> y1 = ";
			cin>>y11;
			
			cout<<"\n Enter The End Point :: \n\n >> x2 = ";
			cin>>x2;
			cout<<" >> y2 = ";
			cin>>y2;
				
			glutInit(&argc,argv);
			glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
			glutInitWindowSize(1300,1300);
			glutInitWindowPosition(350,50);
			glutCreateWindow("DDA Line With Axis");
			myInit();
			glutDisplayFunc(myDisplay);
			glutCreateMenu(Menu); //Menu Creation
				glutAddMenuEntry(" 1. Simple Line ", 1);
				glutAddMenuEntry(" 2. Dotted Line ", 2);
				glutAddMenuEntry(" 3. Dashed Line ", 3);
				glutAddMenuEntry(" 4. Center Dotted Line ", 4);
				glutAddMenuEntry(" 5. Draw Boat ", 5);
				glutAddMenuEntry(" 6. Exit ", 6);
			glutAttachMenu(GLUT_RIGHT_BUTTON);
			glutMainLoop();
	
	return 0;	
}


