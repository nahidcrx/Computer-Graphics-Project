#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include <windows.h>
#include <math.h>
#include <MMSystem.h>
#include <vector>
#include <cstdlib>

#include <GL/glut.h>

using namespace std;

float yx=0,y2=0,z1=0,z2=0,y3=0,z3,b=0,angle=0,keeperangle=0,keeperaxis=0;
float x=0,i=0,j=0,k=0,bp=0,bback=0,c=0,kms=0,km=0,gd=0,backagain=0,smove=0,smoveback=0;
int goalcounter=0,shot=0;
bool goalflag;
float _ang1 = 0.0;




void keyboard(unsigned char key, int x, int y);

void keyboard1(unsigned char key, int x, int y);

void keyboard2(unsigned char key, int x, int y);

void initRendering() {
	glEnable(GL_DEPTH_TEST);

}
//void initRendering();
//void handleResize(int w, int h);


//void drawScene();

void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float _angle = 0.0;
float _cameraAngle = 0.0;
float _ang_tri = 0.0;

const int FONT_TIMES_ROMAN_24 = (int)GLUT_BITMAP_TIMES_ROMAN_24;

///Draw strings
void DrawBitmapString(float x, float y, void *font,const char *string)
{
    const char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}


void display(void)
{
    /* clear all pixels */
    //glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
	glTranslatef(0.0, 0.0, -7.0);




	///gallery---------------------------------
    glBegin(GL_LINES);
    glVertex3f(-5., 01.5, 0.0);
    glVertex3f(5., 01.5, 0.0);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(-5., 01.85, 0.0);
    glVertex3f(5., 01.85, 0.0);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(-5., 02.15, 0.0);
    glVertex3f(5., 02.15, 0.0);
    glEnd();


	///gallery + man-----------------------------------------------------
    glPushMatrix();
   // glTranslatef(0.0, smove, 0.0);

    for(i=-5;i<=5;i=i+0.5f){
    glPushMatrix();
    glTranslatef(0.0, smove, 0.0);

    glTranslatef(i, 1.30, 0);
    ///body----------------------------
    glPushMatrix();
    glScalef(.5,.5,.5);
    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
	glVertex3f(-0.1, 1.2, 0.0);
	glVertex3f(-.12, 0.8, 0.0);
	glVertex3f(.12, 0.8, 0.0);
	glVertex3f(.1, 01.2, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1,1.,0);
	glVertex3f(-0.12, .8, 0.0);
	glVertex3f(0, 0.65, 0.0);
	glVertex3f(.12, 0.8, 0.0);
    glEnd();
///left leg part:1----------------------------
	glBegin(GL_POLYGON);
	glColor3f(1,1.3,0);
	glVertex3f(-.12, 0.8, 0.0);
	glVertex3f(-.2, 0.5, 0.0);
    glVertex3f(-.1, 0.5, 0.0);
	glVertex3f(0., 0.65, 0.0);
	glEnd();
///right leg part :1----------------------------
	glBegin(GL_POLYGON);
    glColor3f(1,1.3,0);
	glVertex3f(.12, 0.8, 0.0);
	glVertex3f(.2, 0.5, 0.0);
    glVertex3f(.1, 0.5, 0.0);
	glVertex3f(0., 0.65, 0.0);
	glEnd();
///left hand---------------------
	glBegin(GL_POLYGON);
    glColor3f(1,0,0);
	glVertex3f(-.1, 01.2, 0.0);
	glVertex3f(-.3, 0.89, 0.0);
	glVertex3f(-.22, 0.82, 0.0);
	glVertex3f(-.1, 01., 0.0);
    glEnd();
    glPushMatrix();
    glColor3f(01,01,1);
	glTranslatef(-0.29, .8, 0.0);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
	///right hand---------------------
	glBegin(GL_POLYGON);
    glColor3f(1,0,0);
	glVertex3f(.1, 01., 0.0);
	glVertex3f(.22, 0.82, 0.0);
	glVertex3f(.3, 0.89, 0.0);
	glVertex3f(.1, 01.2, 0.0);
	glEnd();
	///fingre--------
	glPushMatrix();
    glColor3f(01,01,1);
	glTranslatef(0.3, .8, 0.0);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
	///head---------------------------------
	glPushMatrix();
    glColor3f(01,01,1);
	glTranslatef(0.0, 1.35, 0.0);
	glutSolidSphere(.13,10,10);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	}

	//glPopMatrix();


    for(j=-4.75;j<=5;j=j+0.5f){
    glPushMatrix();
    glTranslatef(0.0, smove, 0.0);
    glTranslatef(j, 1.6, 0);
///body----------------------------
    glPushMatrix();
    glScalef(.5,.5,.5);
    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
	glVertex3f(-0.1, 1.2, 0.0);
	glVertex3f(-.12, 0.8, 0.0);
	glVertex3f(.12, 0.8, 0.0);
	glVertex3f(.1, 01.2, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,0,1);
	glVertex3f(-0.12, .8, 0.0);
	glVertex3f(0, 0.65, 0.0);
	glVertex3f(.12, 0.8, 0.0);
	glEnd();

///left leg part:1----------------------------
	glBegin(GL_POLYGON);
	glColor3f(0,0,1);
	glVertex3f(-.12, 0.8, 0.0);
	glVertex3f(-.2, 0.5, 0.0);
    glVertex3f(-.1, 0.5, 0.0);
	glVertex3f(0., 0.65, 0.0);
	glEnd();
///right leg part :1----------------------------
	glBegin(GL_POLYGON);
    glColor3f(0,0,1);
	glVertex3f(.12, 0.8, 0.0);
	glVertex3f(.2, 0.5, 0.0);
    glVertex3f(.1, 0.5, 0.0);
	glVertex3f(0., 0.65, 0.0);
    glEnd();
///left hand---------------------
	glBegin(GL_POLYGON);
    glColor3f(1,1.3,0);
	glVertex3f(-.1, 01.2, 0.0);
	glVertex3f(-.3, 0.89, 0.0);
	glVertex3f(-.22, 0.82, 0.0);
	glVertex3f(-.1, 01., 0.0);
	glEnd();

	glPushMatrix();
    glColor3f(01,01,1);
	glTranslatef(-0.29, .8, 0.0);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
///right hand---------------------
	glBegin(GL_POLYGON);
    glColor3f(1,1.3,0);
	glVertex3f(.1, 01.,0.0);
	glVertex3f(.22, 0.82, 0.0);
	glVertex3f(.3, 0.89, 0.0);
	glVertex3f(.1, 01.2, 0.0);
	glEnd();
///fingre--------
    glPushMatrix();
    glColor3f(01,01,1);
	glTranslatef(0.3, .8, 0.0);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
///head---------------------------------
	glPushMatrix();
    glColor3f(01,01,1);
	glTranslatef(0.0, 1.35, 0.0);
	glutSolidSphere(.13,10,10);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
    }



    for(k=-5;k<=5;k=k+0.5f){
    glPushMatrix();
    glTranslatef(0.0, smove, 0.0);
    glTranslatef(k, 1.9, 0);
    glScalef(.5,.5,.5);

    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
	glVertex3f(-0.1, 1.2, 0.0);
	glVertex3f(-.12, 0.8, 0.0);
	glVertex3f(.12, 0.8, 0.0);
	glVertex3f(.1, 01.2, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,0,1);
	glVertex3f(-0.12, .8, 0.0);
	glVertex3f(0, 0.65, 0.0);
	glVertex3f(.12, 0.8, 0.0);
	glEnd();

///left leg part:1----------------------------
	glBegin(GL_POLYGON);
	glColor3f(0,0,1);
	glVertex3f(-.12, 0.8, 0.0);
	glVertex3f(-.2, 0.5, 0.0);
    glVertex3f(-.1, 0.5, 0.0);
	glVertex3f(0., 0.65, 0.0);
	glEnd();
///right leg part :1----------------------------
	glBegin(GL_POLYGON);
    glColor3f(0,0,1);
	glVertex3f(.12, 0.8, 0.0);
	glVertex3f(.2, 0.5, 0.0);
    glVertex3f(.1, 0.5, 0.0);
	glVertex3f(0., 0.65, 0.0);
	glEnd();
///left hand---------------------
	glBegin(GL_POLYGON);
    glColor3f(1,0,0);
	glVertex3f(-.1, 01.2, 0.0);
	glVertex3f(-.3, 0.89, 0.0);
	glVertex3f(-.22, 0.82, 0.0);
	glVertex3f(-.1, 01., 0.0);
	glEnd();

	glPushMatrix();
    glColor3f(01,01,1);
	glTranslatef(-0.29, .8, 0.0);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
///right hand---------------------
	glBegin(GL_POLYGON);
    glColor3f(1,0,0);
	glVertex3f(.1, 01., 0.0);
	glVertex3f(.22, 0.82, 0.0);
	glVertex3f(.3, 0.89, 0.0);
	glVertex3f(.1, 01.2, 0.0);
	glEnd();
///fingre--------
	glPushMatrix();
    glColor3f(01,01,1);
	glTranslatef(0.3, .8, 0.0);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
///head---------------------------------
	glPushMatrix();
    glColor3f(01,01,1);
	glTranslatef(0.0, 1.35, 0.0);
	glutSolidSphere(.13,10,10);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
    }




        ///Laser


    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-5.0, 1.5, 0);
    glVertex3f(-5.0, 1., 0);
    glVertex3f(5.0, 1., 0);
    glVertex3f(5.0, 1.50, 0);
    glEnd();

    ///volswogan-----------------------------------------



   	glPushMatrix();

   	//glRotatef(30, 1.0, 0.0, 1.0);

    glTranslatef(_ang1, 0.0, 0.0);

    glTranslatef(0.0, 1.0, 0.0);

     glPushMatrix();

    glScalef(0.33, 0.33, 0.0);
    glTranslatef(-8, 0.2, 0.0);
     //glTranslatef(_ang3, 0.0, 0.0);

	//glColor3f(0.0, 1.0, 1.0);
	//glTranslatef(_ang3, 0.0, 0.0);

   // glPushMatrix();
    //glScalef(.65,.65,0);
    //glTranslatef(-1.0,1.10,0);

    //glPushMatrix(); //Save the current state of transformations
	//glScalef(0.33, 0.33, 0.0);

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(0.0, .50, 1.0); //Move to the center of the triangle
	glColor3f(1.0,1.0,1.0);
	//glRotatef(_angle, 0.0, 0.0, 1.0); //Rotate about the the vector (1, 2, 3)

	glBegin(GL_LINE_LOOP);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.7;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(0.0, .50, 1.0); //Move to the center of the triangle
	//glRotatef(_angle, 0.0, 0.0, 1.0); //Rotate about the the vector (1, 2, 3)

	glBegin(GL_LINE_LOOP);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.75;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

///w left
    glBegin(GL_POLYGON);
    glVertex3f(-.7,.7,0.);
    glVertex3f(-.8,.6,0.);
    glVertex3f(-.3,.0,0.);
    glVertex3f(-.3,.2,0.);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-.3,.2,0.);
    glVertex3f(-.3,.0,0.);
    glVertex3f(0,.4,0.);
    glVertex3f(-.1,.5,0.);
    glEnd();

    ///w right
    glBegin(GL_POLYGON);
    glVertex3f(.7,.7,0.);
    glVertex3f(.8,.6,0.);
    glVertex3f(.3,.0,0.);
    glVertex3f(.3,.2,0.);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(.3,.2,0.);
    glVertex3f(.3,.0,0.);
    glVertex3f(0,.4,0.);
    glVertex3f(.1,.5,0.);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-.1,.5,0.);
    glVertex3f(.0,.4,0.);
    glVertex3f(.1,.5,0.);
    glEnd();

///v left
    glBegin(GL_POLYGON);
    glVertex3f(-.35,1.20,0.);
    glVertex3f(-.45,1.20,0.);
    glVertex3f(.0,.5,0.);
    glVertex3f(0,.7,0.);
   // glVertex3f(.1,.5,0.);
    glEnd();

    ///v right
    glBegin(GL_POLYGON);
    glVertex3f(.35,1.20,0.);
    glVertex3f(.45,1.20,0.);
    glVertex3f(.0,.5,0.);
    glVertex3f(0,.7,0.);
   // glVertex3f(.1,.5,0.);
    glEnd();

    ////glPopMatrix();
    //glPopMatrix();
    //glPopMatrix();



	glPopMatrix();







	 ///audi-------------------------------

     glPushMatrix();
     glScalef(.33,.33,0);
     glTranslatef(0.0, 0.7, 0.0);
     //glTranslatef(_ang2, 0.0, 0.0);
	//glColor3f(0.0, 1.0, 1.0);
	//glTranslatef(_ang2, 0.0, 0.0);

   // glPushMatrix();
   // glScalef(.25,.25,0);
	//glTranslatef(0.0,5.90,0);
    glPushMatrix(); //Save the current state of transformations
	glTranslatef(-1.0, 0.0, 0.0); //Move to the center of the triangle
	//glRotatef(_angle, 0.0, 0.0, 1.0); //Rotate about the the vector (1, 2, 3)

	glBegin(GL_LINE_LOOP);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();


	glPopMatrix();



    glPushMatrix(); //Save the current state of transformations
	glTranslatef(-0.3, 0.0, 0.0); //Move to the center of the triangle
	//glRotatef(_angle, 0.0, 0.0, 1.0); //Rotate about the the vector (1, 2, 3)

	glBegin(GL_LINE_LOOP);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();


	glPopMatrix();


	glPushMatrix(); //Save the current state of transformations
	glTranslatef(0.4, 0.0, 0.0); //Move to the center of the triangle
	//glRotatef(_angle, 0.0, 0.0, 1.0); //Rotate about the the vector (1, 2, 3)

	glBegin(GL_LINE_LOOP);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();


	glPopMatrix();



    glPushMatrix(); //Save the current state of transformations
	glTranslatef(1.1, 0.0, 0.0); //Move to the center of the triangle
	//glRotatef(_angle, 0.0, 0.0, 1.0); //Rotate about the the vector (1, 2, 3)

	glBegin(GL_LINE_LOOP);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();


	glPopMatrix();

	glPopMatrix();






    glPushMatrix();



	glColor3f(1.0, 1.0, 1.0);

	glScalef(0.33,0.33,0.0);

	glTranslatef(8, -0.5, 0.0);

	//glTranslatef(_ang1, 0.0, 0.0);
	 //Undo the move to the center of the triangle
    ///adidas
    //glPushMatrix();

	glBegin(GL_POLYGON);

	//Trapezoid
	glVertex3f(0., 0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.32, .99, 0.0);
	glVertex3f(0.32,.99,0.0);
	glVertex3f(0,0.5,0.0);

	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.6, 0.5, 0.0);
	glVertex3f(1.1, 0.5, 0.0);
	glVertex3f(1.1, 0.5, 0.0);
	glVertex3f(.7, 1.53, 0.0);
	glVertex3f(0.7,1.53,0.0);
	glVertex3f(0.4,1.1,0.0);
    glVertex3f(0.4,1.1,0.0);
	glVertex3f(0.6,0.5,0.0);
	glEnd();

    glBegin(GL_POLYGON);
	glVertex3f(1.2, 0.5, 0.0);
	glVertex3f(1.7, 0.5, 0.0);
	glVertex3f(1.7, 0.5, 0.0);
	glVertex3f(1.09, 2.0, 0.0);
	glVertex3f(1.09,2.0,0.0);
	glVertex3f(.79,1.6,0.0);
    glVertex3f(.79,1.6,0.0);
	glVertex3f(1.2,0.5,0.0);
	glEnd();

    glPopMatrix();

    glPopMatrix();









    ///field----------------------------------------
    glBegin(GL_QUADS);
    glColor3f(.0, 1., 0.);
    glVertex3f(-5.0, 1.0, 0);
    glVertex3f(-5.0, -5., 0);
    glVertex3f(5.0, -5., 0);
    glVertex3f(5.0, 1.0, 0);
    glEnd();



//goal line---------------------------
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-5.0, 0.5, 0);
    glVertex3f(-5.0, 0.4, 0);
    glVertex3f(5.0, 0.4, 0);
    glVertex3f(5.0, 0.5, 0);
    glEnd();

//panalty box-----------------------------
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-1.90, 0.4, 0);
    glVertex3f(-2.3, -0.5, 0);
    glVertex3f(-2.3, -0.5, 0);
    glVertex3f(2.3, -0.5, 0);
    glVertex3f(2.3, -0.5, 0);
    glVertex3f(1.9, 0.4, 0);
    glEnd();

//d box-----------------------------------------------------
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-2.50, 0.4, 0);
    glVertex3f(-4.7, -2.5, 0);
    glVertex3f(-4.7, -2.5, 0);
    glVertex3f(4.7, -2.5, 0);
    glVertex3f(4.7, -2.5, 0);
    glVertex3f(2.5, 0.4, 0);
    glEnd();

//ball point-------------------------------------------
    glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0, -1.3, 0.0);
	glRotatef(-70, 1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();



    ///Net
    ///goal post back left-----------

glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-1, .8, 0.0);
	glVertex3f(-1., 1.7, 0.0);
	glEnd();




///goal post back right---------
	glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(1, 0.8, 0.0);
	glVertex3f(1, 1.7, 0.0);
	glEnd();
/// goal post back connection--------

	glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-1, 1.7, 0.0);
	glVertex3f(1., 1.7, 0.0);
	glEnd();

	glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-1.4, 1.9, 0.0);
	glVertex3f(-1.0, 1.7, 0.0);
	glEnd();

    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(1.4, 1.9, 0.0);
	glVertex3f(1., 1.7, 0.0);
	glEnd();

	glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-1, .8, 0.0);
	glVertex3f(-1.4,0.5, 0.0);
	glEnd();

	glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(1, .8, 0.0);
	glVertex3f(1.4,0.5, 0.0);
	glEnd();

///goal post net----------
///left side---------------

///ynet-----------------

 glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-1.3, 1.86, 0.0);
	glVertex3f(-1.3, .55, 0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-1.2, 1.80, 0.0);
	glVertex3f(-1.2, .63, 0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-1.1, 1.74, 0.0);
	glVertex3f(-1.1, .70, 0.0);
    glEnd();
///ynet ends------------------
///left side---------------
    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-1.4, 1.8, 0.0);
	glVertex3f(-1., 1.6, 0.0);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-1.4, 1.7, 0.0);
	glVertex3f(-1., 1.5, 0.0);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-1.4, 1.6, 0.0);
	glVertex3f(-1., 1.4, 0.0);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-1.4, 1.45, 0.0);
	glVertex3f(-1., 1.35, 0.0);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-1.4, 1.3, 0.0);
	glVertex3f(-1., 1.3, 0.0);
    glEnd();
///down part----------------

    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-1.4, 1.14, 0.0);
	glVertex3f(-1., 1.23, 0.0);
    glEnd();


     glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-1.4, 0.99, 0.0);
	glVertex3f(-1., 1.13, 0.0);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-1.4, 0.89, 0.0);
	glVertex3f(-1., 1.03, 0.0);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-1.4, .73, 0.0);
	glVertex3f(-1., .93, 0.0);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-1.4, 0.5, 0.0);
	glVertex3f(-1., .8, 0.0);
    glEnd();


///right part---------------

///ynet----------
    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(1.3, 1.86, 0.0);
	glVertex3f(1.3, .55, 0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(1.2, 1.80, 0.0);
	glVertex3f(1.2, .63, 0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(1.1, 1.74, 0.0);
	glVertex3f(1.1, .70, 0.0);
    glEnd();


///ynet ends----------------
///right side---------------
   glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(1.4, 1.8, 0.0);
	glVertex3f(1., 1.6, 0.0);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(1.4, 1.7, 0.0);
	glVertex3f(1., 1.5, 0.0);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(1.4, 1.6, 0.0);
	glVertex3f(1., 1.4, 0.0);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(1.4, 1.45, 0.0);
	glVertex3f(1., 1.35, 0.0);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(1.4, 1.3, 0.0);
	glVertex3f(1., 1.3, 0.0);
    glEnd();
///down part----------------

    glBegin(GL_LINES);
    glColor3f(01,01,01);
	//glVertex3f(-1.4, 1.14, 0.0);
	glVertex3f(1., 1.23, 0.0);
	glVertex3f(1.4,1.14,0.0);
    glEnd();


     glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(1.4, 0.99, 0.0);
	glVertex3f(1., 1.13, 0.0);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(1.4, 0.89, 0.0);
	glVertex3f(1., 1.03, 0.0);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(1.4, .73, 0.0);
	glVertex3f(1., .93, 0.0);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(1.4, 0.5, 0.0);
	glVertex3f(1., .8, 0.0);
    glEnd();

///net middle part connecting----------------
/// x axis------------------------
  glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-1., 1.6, 0.0);
	glVertex3f(1., 1.6, 0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-1., 1.5, 0.0);
	glVertex3f(1., 1.5, 0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-1., 1.4, 0.0);
	glVertex3f(1., 1.4, 0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-1., 1.3, 0.0);
	glVertex3f(1., 1.3, 0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-1., 1.23, 0.0);
	glVertex3f(1., 1.23, 0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-1., 1.13, 0.0);
	glVertex3f(1., 1.13, 0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-1., 1.03, 0.0);
	glVertex3f(1., 1.03, 0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-1., 0.93, 0.0);
	glVertex3f(1., 0.93, 0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-1., 0.8, 0.0);
	glVertex3f(1., 0.8, 0.0);
    glEnd();

/// y axis-----------------------

    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-.9, 1.7, 0.0);
	glVertex3f(-.9, 0.8, 0.0);
    glEnd();


     glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-.8, 1.7, 0.0);
	glVertex3f(-.8, 0.8, 0.0);
    glEnd();

 glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-.7, 1.7, 0.0);
	glVertex3f(-.7, 0.8, 0.0);
    glEnd();


 glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-.6, 1.7, 0.0);
	glVertex3f(-.6, 0.8, 0.0);
    glEnd();


 glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-.5, 1.7, 0.0);
	glVertex3f(-.5, 0.8, 0.0);
    glEnd();


 glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-.4, 1.7, 0.0);
	glVertex3f(-.4, 0.8, 0.0);
    glEnd();


     glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-.3, 1.7, 0.0);
	glVertex3f(-.3, 0.8, 0.0);
    glEnd();

     glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-.2, 1.7, 0.0);
	glVertex3f(-.2, 0.8, 0.0);
    glEnd();


     glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-.1, 1.7, 0.0);
	glVertex3f(-.1, 0.8, 0.0);
    glEnd();


     glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(0, 1.7, 0.0);
	glVertex3f(0, 0.8, 0.0);
    glEnd();



      glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(.1, 1.7, 0.0);
	glVertex3f(.1, 0.8, 0.0);
    glEnd();

  glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(.2, 1.7, 0.0);
	glVertex3f(.2, 0.8, 0.0);
    glEnd();

      glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(.3, 1.7, 0.0);
	glVertex3f(.3, 0.8, 0.0);
    glEnd();

      glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(.4, 1.7, 0.0);
	glVertex3f(.4, 0.8, 0.0);
    glEnd();

      glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(.5, 1.7, 0.0);
	glVertex3f(.5, 0.8, 0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(.6, 1.7, 0.0);
	glVertex3f(.6, 0.8, 0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(.7, 1.7, 0.0);
	glVertex3f(.7, 0.8, 0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(.8, 1.7, 0.0);
	glVertex3f(.8, 0.8, 0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(.9, 1.7, 0.0);
	glVertex3f(.9, 0.8, 0.0);
    glEnd();


///net z axis-----------------------
/// y axis-------------------------
///left side------------------------

    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-1.3, 1.9, 0.0);
	glVertex3f(-.9, 1.7, 0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-1.2, 1.9, 0.0);
	glVertex3f(-.8, 1.7, 0.0);
	glEnd();

    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-1.1, 1.9, 0.0);
	glVertex3f(-.7, 1.7, 0.0);
	glEnd();

    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-0.875, 1.9, 0.0);
	glVertex3f(-.6, 1.7, 0.0);
	glEnd();

    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-.755, 1.9, 0.0);
	glVertex3f(-.5, 1.7, 0.0);
	glEnd();

    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-.6, 1.9, 0.0);
	glVertex3f(-.4, 1.7, 0.0);
	glEnd();

    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-.5, 1.9, 0.0);
	glVertex3f(-.3, 1.7, 0.0);
	glEnd();

    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-.4, 1.9, 0.0);
	glVertex3f(-.2, 1.7, 0.0);
	glEnd();

    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-.2, 1.9, 0.0);
	glVertex3f(-.1, 1.7, 0.0);
	glEnd();



    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(.0, 1.9, 0.0);
	glVertex3f(.0, 1.7, 0.0);
    glEnd();





///right side---------------

    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(.2, 1.9, 0.0);
	glVertex3f(.1, 1.7, 0.0);
	glEnd();


    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(.4, 1.9, 0.0);
	glVertex3f(.2, 1.7, 0.0);
	glEnd();


    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(.5, 1.9, 0.0);
	glVertex3f(.3, 1.7, 0.0);
	glEnd();

    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(.6, 1.9, 0.0);
	glVertex3f(.4, 1.7, 0.0);
	glEnd();

        glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(.755, 1.9, 0.0);
	glVertex3f(.5, 1.7, 0.0);
	glEnd();



    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(.875, 1.9, 0.0);
	glVertex3f(.6, 1.7, 0.0);
	glEnd();

    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(1.1, 1.9, 0.0);
	glVertex3f(.7, 1.7, 0.0);
	glEnd();


    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(1.2, 1.9, 0.0);
	glVertex3f(.8, 1.7, 0.0);
	glEnd();

    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(1.3, 1.9, 0.0);
	glVertex3f(.9, 1.7, 0.0);
    glEnd();

///net z axis--------------------

/// x axis-------------------------


    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-1.3, 1.86, 0.0);
	glVertex3f(1.3, 1.86, 0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-1.2, 1.80, 0.0);
	glVertex3f(1.2, 1.80, 0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(01,01,01);
	glVertex3f(-1.1, 1.74, 0.0);
	glVertex3f(1.1, 1.74, 0.0);
    glEnd();



    ///goal post----------------------------------------
    //left
    glBegin(GL_POLYGON);
    glColor3f(01,01,01);
	glVertex3f(-1.5, 2., 0.0);
	glVertex3f(-1.5, 0.5, 0.0);
	glVertex3f(-1.4, 0.5, 0.0);
	glVertex3f(-1.4, 01.9, 0.0);
	glEnd();

	//glEnd();

	///right------------

	 glBegin(GL_POLYGON);
    glColor3f(01,01,01);
	glVertex3f(1.5, 2., 0.0);
	glVertex3f(1.5, 0.5, 0.0);
	glVertex3f(1.4, 0.5, 0.0);
	glVertex3f(1.4, 01.9, 0.0);
	glEnd();

	//top----------------

    glBegin(GL_POLYGON);
    glColor3f(01,01,01);
	glVertex3f(-1.5, 2., 0.0);
	glVertex3f(-1.4, 01.9, 0.0);
	glVertex3f(1.4, 01.9, 0.0);
	glVertex3f(1.5, 2., 0.0);

	glEnd();




/// goal keeper------------------------------------------

    glPushMatrix();

    glTranslatef(km,0.0,0.0);

    glRotatef(keeperangle, 0.0, 0.0, 1.0);

	glPushMatrix();

    glScalef(.8,.8,.8);

    glBegin(GL_POLYGON);
    glColor3f(1,1.3,0);
	glVertex3f(-0.1, 1.2, 0.0);
	glVertex3f(-.12, 0.8, 0.0);
	glVertex3f(.12, 0.8, 0.0);
	glVertex3f(.1, 01.2, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,0,1);
	glVertex3f(-0.12, .8, 0.0);
	glVertex3f(0, 0.65, 0.0);
	glVertex3f(.12, 0.8, 0.0);
	glEnd();

//left leg part:1----------------------------
	glBegin(GL_POLYGON);
	glColor3f(0,0,1);
	glVertex3f(-.12, 0.8, 0.0);
	glVertex3f(-.2, 0.5, 0.0);
    glVertex3f(-.1, 0.5, 0.0);
	glVertex3f(0., 0.65, 0.0);
	glEnd();

//left leg part:2------------------------
	glBegin(GL_POLYGON);
	glColor3f(1,1,1);
	glVertex3f(-.2, 0.5, 0.0);
	glVertex3f(-.3, 0.3, 0.0);
    glVertex3f(-.25, 0.25, 0.0);
    glVertex3f(-.1, 0.5, 0.0);
	glEnd();
//right leg part :1----------------------------
	glBegin(GL_POLYGON);
    glColor3f(0,0,1);
	glVertex3f(.12, 0.8, 0.0);
	glVertex3f(.2, 0.5, 0.0);
    glVertex3f(.1, 0.5, 0.0);
	glVertex3f(0., 0.65, 0.0);
	glEnd();

//right leg part :2---------------
	glBegin(GL_POLYGON);
	glColor3f(1,1,1);
	glVertex3f(.2, 0.5, 0.0);
	glVertex3f(.3, 0.3, 0.0);
    glVertex3f(.25, 0.25, 0.0);
    glVertex3f(.1, 0.5, 0.0);
	glEnd();

//left hand---------------------
	glBegin(GL_POLYGON);
    glColor3f(1,1.3,0);
	glVertex3f(-.1, 01.2, 0.0);
	glVertex3f(-.3, 0.89, 0.0);
	glVertex3f(-.22, 0.82, 0.0);
	glVertex3f(-.1, 01., 0.0);
	glEnd();
//finger-----------------
	glPushMatrix(); //Save the current state of transformations
    glColor3f(01,01,1);
	glTranslatef(-0.270, .72, 1.0); //Move to the center of the triangle
	glutSolidSphere(.05,10,10);
	glPopMatrix();

///right hand---------------------
	glBegin(GL_POLYGON);
    glColor3f(1,1.3,0);
	glVertex3f(.1, 01., 0.0);
	glVertex3f(.22, 0.82, 0.0);
	glVertex3f(.3, 0.89, 0.0);
	glVertex3f(.1, 01.2, 0.0);
	glEnd();

//finger---------------
	glPushMatrix(); //Save the current state of transformations
    glColor3f(01,01,1);
	glTranslatef(0.270, .72, 1.0); //Move to the center of the triangle
	glutSolidSphere(.05,10,10);
	glPopMatrix();


///left foot------------
	glBegin(GL_POLYGON);
    glColor3f(01,0,0);
	glVertex3f(-.3, 0.3, 0.0);
	glVertex3f(-.45, 0.25, 0.0);
	glVertex3f(-.25, 0.25, 0.0);
	glEnd();

///right foot------------
    glBegin(GL_POLYGON);
    glColor3f(01,0,0);
	glVertex3f(.3, 0.3, 0.0);
	glVertex3f(.45, 0.25, 0.0);
	glVertex3f(.25, 0.25, 0.0);
	glEnd();

///head---------------------------------
	glPushMatrix(); //Save the current state of transformations
    glColor3f(01,01,1);
	glTranslatef(0.0, 1.2, 1.0); //Move to the center of the triangle
	glutSolidSphere(.15,10,10);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


///ball-----------------------------------------------



    glPushMatrix();
    glTranslatef(0.0, -1.15, 0.0);
    glPushMatrix();
    glRotatef(angle, 1.0, 0.0, 1.0);
    glTranslatef(0.0,b, 0.0);


    glPushMatrix(); //Save the current state of transformations
    glColor3f(1,0,0);

	glutSolidSphere(.15,20,10);

	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	///ball kicker----------------------------------------------






     glPushMatrix();
     //glRotatef(10, 0.0, 0.0, 1.00);
     //glTranslatef(2.5,-1.20, 1.0);
    glPushMatrix();

    glTranslatef(0.0, y3 , 0.0);
   // glRotatef(-45, .0, .0, 1.00);

   //cout<<y3<<endl;
//body----------------------------
    glPushMatrix();
    glTranslatef(-0.25, -2.20, 1.0); //Move forward 5 units


    //glPushMatrix();
    glScalef(.8,.8,.8);
    //glTranslatef(.0, -2.20, 1.); //Move forward 5 units

    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
	glVertex3f(-0.1, 1.2, 0.0);
	glVertex3f(-.12, 0.8, 0.0);
	glVertex3f(.12, 0.8, 0.0);
	glVertex3f(.1, 01.2, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex3f(-0.12, .8, 0.0);
	glVertex3f(0, 0.65, 0.0);
	glVertex3f(.12, 0.8, 0.0);
	//glVertex3f(.1, 01.2, 0.0);
	glEnd();

//left leg part:1----------------------------

	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex3f(-.12, 0.8, 0.0);
	glVertex3f(-.2, 0.5, 0.0);
    glVertex3f(-.1, 0.5, 0.0);
	glVertex3f(0., 0.65, 0.0);
	glEnd();



//left leg part:2------------------------
    glPushMatrix();
	glTranslatef(0.0, y2, z2);
	glBegin(GL_POLYGON);
	glColor3f(1,1,1);
	glVertex3f(-.2, 0.5, 0.0);
	glVertex3f(-.3, 0.3, 0.0);
    glVertex3f(-.25, 0.25, 0.0);
    glVertex3f(-.1, 0.5, 0.0);
	glEnd();

///left foot------------
    glPushMatrix();
	glBegin(GL_POLYGON);
    glColor3f(0,0,0);
	glVertex3f(-.3, 0.3, 0.0);
	//glVertex3f(-.45, 0.35, 0.0);
	glVertex3f(-.4, 0.23, 0.0);
	glVertex3f(-.28, 0.2, 0.0);
	glVertex3f(-.25, 0.25, 0.0);
	glEnd();
	glPopMatrix();
	glPopMatrix();


	//right leg part :1----------------------------
	glBegin(GL_POLYGON);

    glColor3f(0,0,0);
	glVertex3f(.12, 0.8, 0.0);
	glVertex3f(.2, 0.5, 0.0);
    glVertex3f(.1, 0.5, 0.0);
	glVertex3f(0., 0.65, 0.0);

	glEnd();


	//right leg part :2---------------
	glPushMatrix();

	glTranslatef(0.0, yx, z1);

	glBegin(GL_POLYGON);
	glColor3f(1,1,1);
	glVertex3f(.2, 0.5, 0.0);
	glVertex3f(.3, 0.3, 0.0);
    glVertex3f(.25, 0.25, 0.0);
    glVertex3f(.1, 0.5, 0.0);

	glEnd();

	    ///right foot------------

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex3f(.3, 0.3, 0.0);
	//glVertex3f(-.45, 0.35, 0.0);
	glVertex3f(.4, 0.23, 0.0);
	glVertex3f(.28, 0.2, 0.0);
	glVertex3f(.25, 0.25, 0.0);
	glEnd();
	glPopMatrix();

	glPopMatrix();


	//left hand---------------------
	glBegin(GL_POLYGON);

    glColor3f(1,0,0);
	glVertex3f(-.1, 01.2, 0.0);
	glVertex3f(-.3, 0.89, 0.0);

	glVertex3f(-.22, 0.82, 0.0);
	glVertex3f(-.1, 01., 0.0);

	glEnd();

	glPushMatrix(); //Save the current state of transformations
    glColor3f(01,01,1);
	glTranslatef(-0.29, .8, 0.0); //Move to the center of the triangle
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();

	///right hand---------------------
	glBegin(GL_POLYGON);
    glColor3f(1,0,0);
	glVertex3f(.1, 01., 0.0);
	glVertex3f(.22, 0.82, 0.0);
	glVertex3f(.3, 0.89, 0.0);
	glVertex3f(.1, 01.2, 0.0);

	glEnd();
	//fingre--------

	glPushMatrix(); //Save the current state of transformations
    glColor3f(01,01,1);
	glTranslatef(0.3, .8, 0.0); //Move to the center of the triangle
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();







	///head---------------------------------

	glPushMatrix(); //Save the current state of transformations
    glColor3f(01,01,1);
	glTranslatef(0.0, 1.35, 0.0); //Move to the center of the triangle
	//glBegin(GL_POLYGON);
	glutSolidSphere(.15,10,10);
	/*for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.15;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}*/
	//glEnd();
	glPopMatrix();









	glPopMatrix();

	glPopMatrix();
	glPopMatrix();




	///score board------------------------------------------------------------
	glPushMatrix();
    glTranslated(3,-3,0);
    glScaled(.5,.5,0);

    glPushMatrix();
        glColor3f(1,1,0);

        DrawBitmapString(-1.0,2.0,(void *)FONT_TIMES_ROMAN_24,"Score Board");
        glColor3f(0,1,1);
        //DrawBitmapString(-2.0, 1.5, (void *)FONT_TIMES_ROMAN_24, "Goal :");

        char buffer3 [50];
        sprintf (buffer3, "Your Score Is : %d", goalcounter);
        DrawBitmapString(-1.0, 1.5, (void *)FONT_TIMES_ROMAN_24, buffer3);


        //DrawBitmapString(-2.0, 1.2, (void *)FONT_TIMES_ROMAN_24, "player 1:");
        //DrawBitmapString(-2.0, 0.9, (void *)FONT_TIMES_ROMAN_24, "player 2:");
        glPopMatrix();
        glPopMatrix();



	glutSwapBuffers();

    glFlush();


}


void GameOverMenu()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ///camera setup
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(-_cameraAngle, 0.0, 1.0, 0.0);
	glTranslatef(0.0, 0.0, -7.0);


    glColor3f(1,1,0);
    glColor3f(1,0,0);
    DrawBitmapString(-1.0, 1.0, (void *)FONT_TIMES_ROMAN_24, "!!!...GAME OVER...!!!");
    glColor3f(1,1,0);

        char buffer3 [50];
        sprintf (buffer3, "Your Score Is : %d", goalcounter);
        DrawBitmapString(-1.0, 0.7, (void *)FONT_TIMES_ROMAN_24, buffer3);
   // char buffer3 [50];
    //sprintf (buffer3, "Your Score is : %d");
   // DrawBitmapString(-1.0, 0.7, (void *)FONT_TIMES_ROMAN_24, buffer3);
    glColor3f(0,1,0);
    DrawBitmapString(-1.0, 0.2, (void *)FONT_TIMES_ROMAN_24, "Press r to START Again");
    DrawBitmapString(-1.0, 0.0, (void *)FONT_TIMES_ROMAN_24, "Press ESC to EXIT");

     glutSwapBuffers();
}


void MainMenu()
{


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ///camera setup
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(-_cameraAngle, 0.0, 1.0, 0.0);
	glTranslatef(0.0, 0.0, -7.0);


    glColor3f(1,1,1);

        DrawBitmapString(-1.0,2.0,(void *)FONT_TIMES_ROMAN_24,"__||_PENALTY SHOOT OUT_||__");

        glColor3f(0,1,0);
        DrawBitmapString(-2.0, 1.5, (void *)FONT_TIMES_ROMAN_24, "Press ENTER to START");
        DrawBitmapString(-2.0, 1.2, (void *)FONT_TIMES_ROMAN_24, "Press ESC to EXIT ");
        DrawBitmapString(-2.0, 0.9, (void *)FONT_TIMES_ROMAN_24, "Double Player Game ");

        glColor3f(1,0,0);
        DrawBitmapString(-2.0, 0.4, (void *)FONT_TIMES_ROMAN_24, "*****#  Instructions  #****");
        DrawBitmapString(-2.0, 0.1, (void *)FONT_TIMES_ROMAN_24, "1. Use J,K,L Keys to Move The Goalkeeper");
        DrawBitmapString(-2.0, -0.2,(void *)FONT_TIMES_ROMAN_24, "2. Press 2 Keys to Shoot The Ball");
        DrawBitmapString(-2.0, -0.5,(void *)FONT_TIMES_ROMAN_24, "3. Press * Keys to Set The Player & Ball Again");

        glColor3f(1,1,0);
        DrawBitmapString(-3.50, -1.5,(void *)FONT_TIMES_ROMAN_24, " Suppose You Are Penalty Taker. So Let's Play A Game And Watch Who Is The Boss..!!! ");



         glutSwapBuffers();
}







void supportersmovemetnt(int value) {
    smove=smove+0.01;

    if(smove>=0.2)
    {
        smove=0;
    }
    else
    {
        glutTimerFunc(25, supportersmovemetnt, 0);
    }




}

void repositionball(int value) {
    y3=0;
    b=0;

    glutPostRedisplay();
}

void updatekeepermovement(int value) {

    //km=km+0.1;

    if(kms==1 && km<0.4f)
    {
            km=km+0.08;
            //cout<<"KM"<<km<<endl;
            //cout<<" b :" <<b<<endl;
            if(km==0.4f)
            {

            keeperangle=-35;
       //keeperaxis=1;

            }
            else
            {
            glutTimerFunc(75, updatekeepermovement, 0);
            glutPostRedisplay();
            }

    }
    else if(kms==-1 && km>-0.4f)
    {
            km=km-0.08;
           // cout<<"KM"<<km<<endl;
            if(km==-0.4f)
            {


            keeperangle=35;
       //keeperaxis=1;

            }
            else
            {
            glutTimerFunc(75, updatekeepermovement, 0);
            glutPostRedisplay();}
            }

    }




void updateballback(int value) {


    b-=0.15f;


    if(b<=bback)
        {}
    else
    {
    glutTimerFunc(75, updateballback, 0);
    }


}

void reposition(int value) {


    if(b==bback)
    {
            //cout<<"Reposition Working"<<endl;
            glutTimerFunc(25, repositionball, 0);
    }

}

void updateball(int value) {


    b+=0.15f;

    if(km==-0.4f)
        {

            if(gd==1 && b>=1.8f )
                {
                   // cout<<"Enter"<<endl;
                            //backagain=1.5f;
                    b=1.65f;
                   // cout<<"Not Goal"<<endl;
                    goalflag=0;
                    gd=0;
                    glutTimerFunc(25, updateballback, 0);
                }

            else if(b>=bp)
                {


                if(goalflag==1){
                goalcounter=goalcounter+1;

                glutTimerFunc(25, supportersmovemetnt, 0);

                    //smove=0.2;

                }
                glutTimerFunc(25, updateballback, 0);
                }

                else{
                glutTimerFunc(15, updateball, 0);
                }
    }

    else  if(km==0.4f)
        {


            if(gd==3 && b>=2.1f )
            {
                //cout<<"Enter"<<endl;
                b=1.65f;
                //cout<<"Not Goal"<<endl;
                gd=0;
                goalflag=0;
                glutTimerFunc(25, updateballback, 0);
            }

            else if(b>=bp)
            {


                if(goalflag==1){
                goalcounter=goalcounter+1;
                //smove=0.2;
                glutTimerFunc(25, supportersmovemetnt, 0);
                }
                glutTimerFunc(25, updateballback, 0);
            }

            else
            {
                glutTimerFunc(10, updateball, 0);
            }
    }

    else  if(km==0)
        {


            if(gd==5 && b>=1.95f ){
            //cout<<"Enter"<<endl;
            b=1.65f;
            //cout<<"Not Goal"<<endl;
            goalflag=0;
            gd=0;
            glutTimerFunc(25, updateballback, 0);
        }

            else if(b>=bp)
            {


                if(goalflag==1){
                goalcounter=goalcounter+1;
                //smove=0.2;
                glutTimerFunc(25, supportersmovemetnt, 0);
                }
                glutTimerFunc(25, updateballback, 0);
            }


            else
            {
                glutTimerFunc(15, updateball, 0);
            }
    }


    else if(b>=bp)
    {

        glutTimerFunc(25, updateballback, 0);
    }
    else
    {
        glutTimerFunc(10, updateball, 0);
    }


}


void updateleg(int value) {

	yx = yx + 0.05f;

	if (yx == 0.1f)
    {

        y2 += 0.1f;
        yx=0;

	}

    if(y2 == 0.2f){

        y2=0;

    }


        y3=y3+0.12f;

        if(y3 == 0.84f)
        {
            y3=0.84;
            //cout<<"y3"<<y3<<endl;
            //break;
            //glutPostRedisplay();
           glutTimerFunc(1000000, updateleg, 0);
           glutTimerFunc(0, updateball, 0);

		}
		else
        {
            glutPostRedisplay(); //Tell GLUT that the display has changed

            //Tell GLUT to call update again in 25 milliseconds
	        glutTimerFunc(150, updateleg, 0);
		}



}



void keyboard(unsigned char key, int x, int y)
{
        int key1=0;





        switch (key)
        {
        //case:

            case 'j':


            //keeperangle=-30;
            kms=-1;
            //keeperaxis=1.0;
            //updatekeepermovement();

            glutTimerFunc(25, updatekeepermovement, 0);
            glutPostRedisplay();

            break;

            case 'k':

            keeperangle= 0;
            km=0;
            keeperaxis=1.0;


            break;

            case 'l':

            //keeperangle= 30;
            kms=1;
            //keeperaxis=1.0;
            glutTimerFunc(25, updatekeepermovement, 0);
            glutPostRedisplay();

            break;

            case 27:     // ESC key
            exit(0);
            break;

            default:
            break;

       // glutPostRedisplay();

    }



    if(shot==10)
        {
            //cout<<"Game Over";

            glutDisplayFunc(GameOverMenu);

            //glutTimerFunc(25, GameOverMenu, 0);

            glutKeyboardFunc(keyboard2);
            shot=0;

        }

    else
        {


       // cout<<y3<<" "<<b<<endl;

        if(y3==0 && b==0){

        // cout<<y3<<" "<<b<<endl;







        if(key=='2') {

        shot++;

        //cout<<y3<<" "<<b<<endl;
        key1=rand() % 7 + 1;

        //cout<<"Random Key1:"<<key1;
        //cout<<"Key"<<key;

       // case '2':


    if(key1==1)
    {
        glutTimerFunc(25, updateleg, 0);
        angle=30;
        gd=1;
        bp=2.25f;
        bback=1.5f;
        goalflag=1;

        glutPostRedisplay();
    }
    //break;

    else if(key1==5)
    {
        //case '5':
        glutTimerFunc(25, updateleg, 0);
        angle=0;
        gd=5;
        bp=2.25f;
        bback=1.5f;
        goalflag=1;

        glutPostRedisplay();
    //break;
    }
    else if(key1==3)
    {
        //case '3':
        glutTimerFunc(25, updateleg, 0);
        angle=-40;
        gd=3;
        bp=2.55f;
        bback=1.5f;
        goalflag=1;
        glutPostRedisplay();
        //break;
    }

    else if(key1==4)
    { //Left Bar
        //case '4':
        glutTimerFunc(25, updateleg, 0);
        angle=40;
        bp=2.4f;
        bback=1.5f;
        goalflag=0;
        glutPostRedisplay();
        //break;
    }

    else if(key1==6)
    {//Right Bar

       // case '6':
        glutTimerFunc(25, updateleg, 0);
        angle=-50;
        bp=3.3f;
        bback=1.5f;
        goalflag=0;
        glutPostRedisplay();
       // break;
    }

	else if(key1==7)
    { //Upper Left

       // case '6':
        glutTimerFunc(25, updateleg, 0);
        angle=28;
        bp=2.85f;
        bback=1.5f;
        goalflag=1;
        glutPostRedisplay();
       // break;
    }

	else if(key1==8)
    { //Upper Right

       // case '6':
        glutTimerFunc(25, updateleg, 0);
        angle=-35;
        bp=3.9f;
        bback=1.5f;
        goalflag=1;
        glutPostRedisplay();
       // break;
    }


	else if(key1==2)
    { //Outside

       // case '6':
        //goalflag=0;
        glutTimerFunc(25, updateleg, 0);
        angle=55;
        bp=3.3f;
        bback=2.1f;
        goalflag=0;
        glutPostRedisplay();
   // break;
    }
    }


    }



    else if(y3>0 || b!=0)
    {

                //cout<<"keep agle"<<keeperangle<<endl;

        switch (key)
        {

            case '*':
           // cout<<"Case Work Case 5"<<endl;
            glutTimerFunc(25, reposition, 0);
            glutPostRedisplay();
            break;



            default:
                glutPostRedisplay();
            break;
        }
    }
    }
//}
}



void update(int value) {
	_angle += 2.0f;
	if (_angle > 360) {
		_angle -= 360;
	}
	_ang_tri += 2.0f;
	if (_ang_tri > 360) {
		_ang_tri -= 360;
	}



		_ang1 += 0.05f;
	if (_ang1 >8) {
		_ang1 = -8.0f;
	}






	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(50, update, 0);
}

void keyboard1(unsigned char key, int x, int y)
{
    int key1=0;





    switch (key)
    {
        case 27:
        exit(0);
        break;

        case 13:


        //display();
        glutDisplayFunc(display);
        glutKeyboardFunc(keyboard);
        glutPostRedisplay();



        break;


        default:
        break;

    }
}

void keyboard2(unsigned char key, int x, int y)
{
    int key1=0;





    switch (key)
    {

        case 27:
        exit(0);
        break;


        case 'r':


        //display();
        glutDisplayFunc(MainMenu);
        glutKeyboardFunc(keyboard1);
        glutPostRedisplay();
        y3=0;
        b=0;
        keeperangle= 0;
        km=0;
        keeperaxis=1.0;
        goalcounter=0;
        goalflag=0;



        break;


        default:
        break;

    }
}



int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
glutInitWindowSize(1000, 600);
glutInitWindowPosition(100, 100);
glutCreateWindow("Penalty-Shootout");




glutDisplayFunc(MainMenu);
//glutDisplayFunc(display);

glutReshapeFunc(handleResize);
glutTimerFunc(50, update, 0);




glutKeyboardFunc(keyboard1);
//glutKeyboardFunc(keyboard1);
glutFullScreen();

PlaySound("Chearing.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);

//cout<<"Goal:"<<goalcounter;

glutMainLoop();

//cout<<"Goal:"<<goalcounter;
return 0; /* ISO C requires main to return int. */
}

