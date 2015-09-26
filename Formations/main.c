#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>
#include<GL/glut.h>
#include<math.h>
#include<windows.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 500
#define JET_END_TOP 1000
#define HELI_END_RIGHT 1000

GLfloat theta = 0.0, theta1 = 0.0, theta2 = 0.0, theta3 = 0.0;
GLfloat i, cosine, sine;

char title[50] = "Miltiry Formations";  // Title of Project
int x = 400, y = 200; // Position of Jet
int p = 130, q = 500; //Position of Heli
int total_jet = 5,total_heli = 3; // Default 3 formation
int helemenu, jetmenu;   
int CURRENT_ITEM = 1;   // 0-jet   1-helicopter
int StartScreen = 1;	// Always show start screen
int wingRotation = 0; // Wing spinning 

void dispchar(int x, int y, char *s)
{
	int len, i;
	glRasterPos2f(x, y);
	len = (int)strlen(s);
	for (i = 0; i<len; i++)												//to display text
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s[i]);
}

void helicopter(int a, int b)
{

	GLint r = 35, k = 55, m = 20;
	glPushMatrix();
	//glTranslatef(i,0,0);
	glColor3f(1., 1., 1.);
	glBegin(GL_POLYGON);
	glVertex2f(a, b + 5);
	glVertex2f(a + 75, b + 20);
	glVertex2f(a + 75, b - 20);
	glVertex2f(a, b - 5);
	glEnd();

	//head
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (i = 0; i<360; i++)
	{
		cosine = (a + 100) + (r*cos(i));
		sine = b + (r*sin(i));
		glVertex2f(cosine, sine);
	}
	glEnd();

	//black line (seperator)
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(a + 75, b - 20);
	glVertex2f(a + 75, b + 20);
	glEnd();



	glColor3f(.3, .5, .8);
	glBegin(GL_POLYGON);
	glVertex2f(a + 85, b - 20);
	glVertex2f(a + 85, b + 5);
	glVertex2f(a + 97, b + 5);
	glVertex2f(a + 97, b - 20);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(a + 105, b - 20);
	glVertex2f(a + 105, b);
	glVertex2f(a + 115, b);
	glVertex2f(a + 115, b - 20);
	glEnd();

	//wing big
	glColor3f(.0, .0, .0);
	glPushMatrix();
	glTranslatef(a + 90, b + 30, 0);
	glRotatef(-60 +wingRotation, 0.0, 0.0, 1.0);
	glRotatef(theta + wingRotation, 0.0, 0.0, 1.0);
	glTranslatef(-(a + 90), -(b + 30), 0);
	glBegin(GL_POLYGON);
		glVertex2i(a + 90, b + 30);
		glVertex2i(a + 80, b + 100);
		glVertex2i(a + 100, b + 100);
	glEnd();
	glPopMatrix();

	glPushMatrix();

	glTranslatef(a + 90, b + 30, 0);
	glRotatef(-60 + wingRotation, 0.0, 0.0, 1.0);
	glRotatef(theta1 + wingRotation, 0.0, 0.0, 1.0);
	glTranslatef(-(a + 90), -(b + 30), 0);
	glBegin(GL_POLYGON);
	glVertex2i(a + 90, b + 30);
	glVertex2i(a + 80, b - 40);
	glVertex2i(a + 100, b - 40);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(a + 90, b + 30, 0);
	glRotatef(-80 + wingRotation, 0.0, 0.0, 1.0);
	glRotatef(theta2 + wingRotation, 0.0, 0.0, 1.0);
	glTranslatef(-(a + 90), -(b + 30), 0);
	glBegin(GL_POLYGON);
	glVertex2i(a + 90, b + 30);
	glVertex2i(a + 30, b - 10);
	glVertex2i(a + 30, b + 10);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(a + 90, b + 30, 0);
	glRotatef(-80 + wingRotation, 0.0, 0.0, 1.0);
	glRotatef(theta3 + wingRotation, 0.0, 0.0, 1.0);
	glTranslatef(-(a + 90), -(b + 30), 0);
	glBegin(GL_POLYGON);
	glVertex2i(a + 160, b + 50);
	glVertex2i(a + 90, b + 30);
	glVertex2i(a + 160, b + 70);
	glEnd();
	glPopMatrix();

	/*   glPushMatrix();
	glBegin(GL_POINTS);
	for(i=0;i<360;i++)
	{

	cosine=(a+90)+(k*cos(i));
	sine=(b+10)+(k*sin(i));
	glVertex2f(cosine,sine);


	}
	glEnd();
	glPopMatrix();*/

	//wing small
	glPushMatrix();
	glTranslatef(a, b + 10, 0);
	glRotatef(-60 + wingRotation, 0.0, 0.0, 1.0);
	glRotatef(theta + wingRotation, 0.0, 0.0, 1.0);
	glTranslatef(-(a), -(b + 10), 0);
	glBegin(GL_POLYGON);
	glVertex2i(a, b + 10);
	glVertex2i(a, b + 30);
	glVertex2i(a - 10, b + 30);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(a, b + 10, 0);
	glRotatef(-60 + wingRotation, 0.0, 0.0, 1.0);
	glRotatef(theta1 + wingRotation, 0.0, 0.0, 1.0);
	glTranslatef(-(a), -(b + 10), 0);
	glBegin(GL_POLYGON);
	glVertex2i(a, b + 10);
	glVertex2i(a, b - 10);
	glVertex2i(a - 10, b - 10);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(a, b + 10, 0);
	glRotatef(-60 + wingRotation, 0.0, 0.0, 1.0);
	glRotatef(theta2 + wingRotation, 0.0, 0.0, 1.0);
	glTranslatef(-(a), -(b + 10), 0);
	glBegin(GL_POLYGON);
	glVertex2i(a, b + 10);
	glVertex2i(a + 20, b + 10);
	glVertex2i(a + 20, b);
	glEnd();
	glPopMatrix();

	glBegin(GL_POINTS);
	for (i = 0; i<360; i++)
	{

		cosine = (a)+(m*cos(i));
		sine = (b + 10) + (m*sin(i));
		glVertex2f(cosine, sine);


	}
	glEnd();


	glColor3f(1.0, 1.0, 0.0);
	//foot
	glBegin(GL_LINE_LOOP);
	glVertex2i(a + 80, b - 45);
	glVertex2i(a + 80, b - 40);
	glVertex2i(a + 120, b - 40);
	glVertex2i(a + 120, b - 45);
	glEnd();

	//foot line
	glBegin(GL_LINES);
	glVertex2i(a + 100, b - 35);
	glVertex2i(a + 90, b - 40);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(a + 100, b - 35);
	glVertex2i(a + 110, b - 40);
	glEnd();


	glPopMatrix();
	glutPostRedisplay();
}

void plane(int x, int y)
{

	glColor3f(1, 1, 1);

	glPushMatrix();
	glBegin(GL_POLYGON);
//	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(x - 20, y);
	glVertex2f(x - 20, y + 5);
	glVertex2f(x + 20, y + 5);
	glVertex2f(x + 20, y);
	glEnd();

	glBegin(GL_POLYGON);
//	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(x - 10, y + 5);
	glVertex2f(x - 10, y + 40);
	glVertex2f(x + 10, y + 40);
	glVertex2f(x + 10, y + 5);
	glEnd();

	glBegin(GL_POLYGON);
//	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(x - 15, y + 40);
	glVertex2f(x - 15, y + 60);
	glVertex2f(x + 15, y + 60);
	glVertex2f(x + 15, y + 40);
	glEnd();

	glBegin(GL_POLYGON);
//	glColor3f(0.2, 1.0, 0.7);
	glVertex2f(x - 10, y + 60);
	glVertex2f(x - 10, y + 70);
	glVertex2f(x + 10, y + 70);
	glVertex2f(x + 10, y + 60);
	glEnd();

	glBegin(GL_POLYGON);
//	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(x - 8, y + 70);
	glVertex2f(x - 8, y + 75);
	glVertex2f(x + 8, y + 75);
	glVertex2f(x + 8, y + 70);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x - 8, y + 75);
	glVertex2f(x + 8, y + 75);
	glVertex2f(x, y + 80);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex2f(x - 45, y + 13);
	glVertex2f(x - 45, y + 27);
	glVertex2f(x - 15, y + 55);
	glVertex2f(x - 15, y + 45);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x + 45, y + 13);
	glVertex2f(x + 45, y + 27);
	glVertex2f(x + 15, y + 55);
	glVertex2f(x + 15, y + 45);
	glEnd();

	glPopMatrix();

	glutPostRedisplay();
}

void mybackground(){

	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.4, 0.1, 0.7, 1.0);
	glutPostRedisplay();
}

void startscreen()
{

	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.5, 0.2, 0.1, 1.0);
	glColor3f(1, 1, 0);

	dispchar(200, 850, "BAPUJI INSTITUTE OF ENGINEERING AND TECHNOLOGY");
	dispchar(400, 800, "CG MINI PROJECT");
	dispchar(0, 750, "___________________________________________________________________________________________________________________________________________________");

	glColor3f(1, 0, 0);
	dispchar(50, 680, "The project on:-");

	glColor3f(0.9, 0.0, 0.1);
	dispchar(550, 680, title);

	glColor3f(0.8, 0.5, 0.1);
	dispchar(0, 600, "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");


	glColor3f(0.3, 0.7, 0.2);
	dispchar(350, 550, "PROJECT GUIDE");
	dispchar(350, 540, "_______________");
	dispchar(350, 480, "NAVEEN SIR");

	glColor3f(0.3, 0.7, 0.2);
	dispchar(50, 300, "PROJECT ASSOCIATES");
	dispchar(50, 300, "____________________");

	glColor3f(0.1, 0.9, 0.7);
	dispchar(50, 250, "ADITYA S LADWA       4BD12CS006");
	dispchar(50, 200, " B.S OMKARAPPA        4BD12CS028");





	glColor3f(1, 0, 0);
	dispchar(50, 100, "PRESS C TO CONTINUE");
	glFlush();
}

void timerCallback(int value)
{
	
	
	if (CURRENT_ITEM == 0) // For jet
	{
		if (y == JET_END_TOP)
			y = 0;
		else
			y += 2;
	}
	else if (CURRENT_ITEM == 1){ //For heli
		wingRotation += 7;  // Increment wing rotation
		if (p == HELI_END_RIGHT)
			p = 0;
		else
			p += 2;
	}
	glutPostRedisplay();
	glutTimerFunc(20, timerCallback, value);
}

void keyboardCallback(unsigned char k, int x2, int y2)
{
		
	if (k == 'w' || k == 'W'){
		y += 10;
	}
	if (k == 's' || k == 'S'){
		y -= 10;
	}
	if (k == 'a' || k == 'A'){
		x -= 10;
	}
	if (k == 'd' || k == 'D'){
		x += 10;
	}

	if (k == 'C' || k == 'c'){
		StartScreen = 0;
	}
	if (k == 27)
		exit(0);
}

void keyboardArrowCallback(int key, int x1, int y1){

	switch (key)
	{
	case GLUT_KEY_LEFT:
		p-= 10;
		break;
	case GLUT_KEY_RIGHT:
		p += 10;
		break;
	case GLUT_KEY_UP:
		q += 10;
		break;
	case GLUT_KEY_DOWN:
		q -= 10;
		break;
	}
}

void init()
{
	glClearColor(0, 0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1000.0, 0.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
}

void mainMenuCallback(int id)
{
	switch (id)
	{
	case 1:total_jet = 1;
		CURRENT_ITEM = 0;
		break;
	case 3:total_jet = 3;
		CURRENT_ITEM = 0;
		break;
	case 6:total_jet = 5;
		CURRENT_ITEM = 0;
		break;
	case 11:total_heli = 1;
		CURRENT_ITEM = 1;
		break;
	case 13:total_heli = 3;
		CURRENT_ITEM = 1;
		break;
	case 16:total_heli = 5;
		CURRENT_ITEM = 1;
		break;
	case 10:exit(0);
		break;
	}
}

void CreateMenuItems(){
	jetmenu = glutCreateMenu(mainMenuCallback);
	glutAddMenuEntry("One formation", 1);
	glutAddMenuEntry("Three formation", 3);
	glutAddMenuEntry("Six Formation", 6);

	helemenu = glutCreateMenu(mainMenuCallback);
	glutAddMenuEntry("One Formation", 11);
	glutAddMenuEntry("Three Formation", 13);
	glutAddMenuEntry("Six Formation", 16);

	glutCreateMenu(mainMenuCallback);
	glutAddSubMenu("Jet Formations", jetmenu);
	glutAddSubMenu("Helicopter Formations", helemenu);
	glutAddMenuEntry("Quit", 10);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	if (StartScreen){
		startscreen();
	}
	else
	{
		mybackground();



		if (CURRENT_ITEM == 0){
			//sndPlaySound("heli", SND_ASYNC);
			if (total_jet == 1){
				plane(x + 100, y + 80);//first plane
			}
			else if (total_jet == 3){
				plane(x + 100, y + 80); //first plane
				plane(x, y); //left plane
				plane(x + 200, y);//right plane
			}
			else if (total_jet == 5){
				plane(x + 100, y + 80); //first plane
				plane(x, y);//left plane
				plane(x - 100, y - 80);//second left plane
				plane(x + 200, y);//rght plane
				plane(x + 300, y - 80);//second right plane
				plane(x + 100, y - 80);
			}
		}
		else if (CURRENT_ITEM == 1){

			if (total_heli == 1){
				helicopter(p, q);
			}
			else if (total_heli == 3){
				helicopter(p, q); // Front heli
				helicopter(p - 120, q - 120); //bottom heli
				helicopter(p - 120, q + 120); //top heli
			}
			else if (total_heli == 5){
				helicopter(p, q); // Front heli
				helicopter(p - 120, q - 120); //bottom heli
				helicopter(p - 240, q - 260);	 //second bottom heli
				helicopter(p - 120, q + 120); //top heli
				helicopter(p - 240, q + 260); //second top heli
				helicopter(p - 240, q);
			}

		}
	}
	glutPostRedisplay();
	glFlush();
	glutSwapBuffers();
}

void main()
{
	
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow(title);
	CreateMenuItems();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboardCallback);
	glutSpecialFunc(keyboardArrowCallback);
	
	if (CURRENT_ITEM == 1)
		PlaySound("heli.wav", NULL, SND_ASYNC| SND_LOOP);
	else
		PlaySound("jet.wav", NULL, SND_ASYNC | SND_LOOP);
		
	glutTimerFunc(20, timerCallback, 0);
	glViewport(0, 0, 1000, 1000);
	init();
	glutMainLoop();
}