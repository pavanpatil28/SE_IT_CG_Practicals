#include<iostream>
#include<GL/glut.h>
using namespace std;
#define h2 500
#define w2 500

int h, k, r, d, x, y, no,diff;

void myInit(void)
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,0.0);
	glPointSize(3.0);
	glLineWidth(3.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w2/2,w2/2,-h2/2,h2/2);
}

void SetPixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

void Simple_Circle(int r){
	d=3-2*r;
	x=0;
	y=r;
	
	SetPixel(x,y);
	
	while(x<=y){
		if(d<=0){
			d=d+4*x+6;
			x++;
		}
		else{
			d=d+4*(x-y)+10;
			x++;
			y--;
		}
		
		SetPixel(x+h,y+k);
		SetPixel(-x+h,-y+k);
		SetPixel(y+h,x+k);
		SetPixel(-y+h,-x+k);
		SetPixel(-y+h,x+k);
		SetPixel(y+h,-x+k);
		SetPixel(-x+h,y+k);
		SetPixel(x+h,-y+k);		
	}			
}

void Olympic_Ring(int r, int h, int k){
	d=3-2*r;
	x=0;
	y=r;
	
	SetPixel(x,y);
	
	while(x<=y)
	{
		if(d<=0)
		{
			d = d + 4*x + 6;
			x++;
		}
		else
		{
			d = d + 4*(x-y) + 10;
			x++;
			y--;
		}
		
		SetPixel(x+h,y+k);
		SetPixel(-x+h,-y+k);
		SetPixel(y+h,x+k);
		SetPixel(-y+h,-x+k);
		SetPixel(-y+h,x+k);
		SetPixel(y+h,-x+k);
		SetPixel(-x+h,y+k);
		SetPixel(x+h,-y+k);
	}			
}

void Spiral_Curve_1(int r, int h, int k){
	d=3-2*r;
	x=0;
	y=r;
	
	SetPixel(x,y);
	
	while(x<=y){
		if(d<0){
			d=d+4*x+6;
			x++;
		}
		else{
			d=d+4*(x-y)+10;
			x++;
			y--;
		}
		SetPixel(x+h,y+k);
	//	SetPixel(-x+h,-y+k);
		SetPixel(y+h,x+k);
	//	SetPixel(-y+h,-x+k);
		SetPixel(-y+h,x+k);
	//	SetPixel(y+h,-x+k);
		SetPixel(-x+h,y+k);
	//	SetPixel(x+h,-y+k);		
	}			
}

void Spiral_Curve_2(int r, int h, int k){
	d=3-2*r;
	x=0;
	y=r;
	
	SetPixel(x,y);
	while(x<=y){
		if(d<0){
			d=d+4*x+6;
			x++;
		}
		else{
			d=d+4*(x-y)+10;
			x++;
			y--;
		}
		
	//	SetPixel(x+h,y+k);
		SetPixel(-x+h,-y+k);
	//	SetPixel(y+h,x+k);
		SetPixel(-y+h,-x+k);
	//	SetPixel(-y+h,x+k);
		SetPixel(y+h,-x+k);
	//	SetPixel(-x+h,y+k);
		SetPixel(x+h,-y+k);		
	}			
}

void Menu(int n){	
	switch(n){
		case 1:
			Simple_Circle(r);
			break;
				
		case 2:
			for(int i =0; i<no; i++){
				Simple_Circle(r);
				r +=diff;
				glColor3f(1.0f,1.0f,0.0f);
			}	
			break;
			
		case 3:
		
			// To draw Upper Rings 
			glColor3f(0.0,0.0,1.0);
			Olympic_Ring(r, 2*r, 6*r);
			glColor3f(0.0, 0.0, 0.0);
			Olympic_Ring(r, 4.15*r, 6*r);
			glColor3f(1.0,0.0,0.0);
			Olympic_Ring(r, 6.3*r, 6*r);
			
			// To draw Lower Rings
			
			glColor3f(1.0,1.0,0.0);
			Olympic_Ring(r, 2.9*r, 4.8*r);
			glColor3f(0.0,1.0,0.0);
			Olympic_Ring(r, 5.1*r, 4.8*r);
			glColor3f(0.0,0.0,0.0);
			break;	
			
		case 4:
			int temp;//clockWise
				Spiral_Curve_1(r,h,k);
				temp=r;
				h=-r;
				temp=temp+(r);
				k=0;
				glColor3f(0.0,1.0,0.0);
				Spiral_Curve_2(temp,h,k);
				h=0;
				temp=temp+(r);
				Spiral_Curve_1(temp,h,k);
				h=-(r);
				temp=temp+(r);
				k=0;
				glColor3f(1.0,1.0,0.0);
				Spiral_Curve_2(temp,h,k);
				h=0;
				temp=temp+(r);
				glColor3f(1.0,0.0,0.0);
				Spiral_Curve_1(temp,h,k);
				h=-(r);
				temp=temp+r;
				k=0;
					glColor3f(0.0,1.0,1.0);
				Spiral_Curve_2(temp,h,k);
		
			break;	
		case 5:
				//AnticlockWise
				Spiral_Curve_2(r,h,k);
				temp=r;
				h=-r;
				temp=temp+(r);
				k=0;
				glColor3f(0.0,1.0,0.0);
				Spiral_Curve_1(temp,h,k);
				h=0;
				temp=temp+(r);
				Spiral_Curve_2(temp,h,k);
				h=-(r);
				temp=temp+(r);
				k=0;
				glColor3f(1.0,1.0,0.0);
				Spiral_Curve_1(temp,h,k);
				h=0;
				temp=temp+(r);
				glColor3f(1.0,0.0,0.0);
				Spiral_Curve_2(temp,h,k);
				h=-(r);
				temp=temp+r;
				k=0;
					glColor3f(0.0,1.0,1.0);
				Spiral_Curve_1(temp,h,k);
		
			break;	
			
		case 6:
			exit(0);
	}	
	
}	

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	
	for(int i=-w2; i<=w2; i++)
	{
		SetPixel(i, 0);
		SetPixel(0, i);
	}	
		
	glEnd();
	glFlush();
}	
		
int main(int argc, char **argv){
			cout<<"________________________________________________________________________\n\n";
			cout<<"			BRESENHAM CIRCLE DRAWING ALGORITHM        \n\n";
			cout<<"_________________________________________________________________________\n";
			bool choice;
			do{				
				cout<<"Enter the Radius of the Circle r=";
				cin>>r;
				if(r==0){//CHECKING VALIDATION
					cout<<"\n\nCan't Draw circle,Please Enter a Nonzero radius: r!=0\n\n";
					choice=true;
				}
				else{
					choice=false;
				}
			}while(choice==true);
			cout<<"\nEnter the difference between each two circles to draw concentric circles:";
			cin>>diff;
			cout<<"\nEnter the No of Circles you want:";
			cin>>no;  
			glutInit(&argc,argv);
			glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
			glutInitWindowSize(1080,720);
			glutInitWindowPosition(50,100);
			glutCreateWindow("Bresenham Circle Drawing Algorithm");
			myInit();
			glutDisplayFunc(myDisplay);
			glutCreateMenu(Menu); //Menu Creation
				glutAddMenuEntry(" 1. Simple Circle ", 1);
				glutAddMenuEntry(" 2. Concentric Circle ", 2);
				glutAddMenuEntry(" 3. Olympic Ring ", 3);
				glutAddMenuEntry(" 4. Spiral Curve-Clockwise ", 4);
				glutAddMenuEntry(" 5. Spiral Curve-AntiClockwise ", 5);
				glutAddMenuEntry(" 6. Exit",6);
			glutAttachMenu(GLUT_RIGHT_BUTTON);
			glutMainLoop();
	return 0;	
}


	

