#ifndef CYLINDERTORUS_H
#define CYLINDERTORUS_H

#include <windows.h>
#include <freeglut.h>
#include"Constatnts.h"


static void resize_ct(int width, int height)
{
	const float ar = (float)width / (float)height;

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


static void display_ct(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3d(0, 1, 0);

	glPushMatrix();
	glTranslated(1.4, -1.4, -10);
	glRotated(65, 1.0, 0.0, 0.0);
	glutSolidCylinder(1, 2.5, 16, 16);
	glPopMatrix();

	glPushMatrix();
	glTranslated(2.0, 2.0, -8);
	glRotated(65, 1.0, 0.0, 0.0);
	glutSolidTorus(0.1, 0.5, 16, 16);
	glPopMatrix();

	glutSwapBuffers();
}

void keyboard_ct(unsigned char key, int x, int y)
{
	switch (key) {
	case 27: /* escape */
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glColor3d(0, 1, 0);

		glPushMatrix();
		glTranslated(1.4, -1.4, -10);
		glRotated(65, 1.0, 0.0, 0.0);
		glutSolidCylinder(1, 2.5,16,16);
		glPopMatrix();

		glPushMatrix();
		glTranslated(2.0, 2.0, -8);
		glRotated(65, 1.0, 0.0, 1.0);
		glutSolidTorus(0.1, 0.5, 16, 16);
		glPopMatrix();

		glutSwapBuffers();
		break;
	}
	glFlush();
}

void CylinderTorus()
{
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(10, 10);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	glutCreateWindow("CylinderTorus");

	glutReshapeFunc(resize_ct);
	glutDisplayFunc(display_ct);

	glClearColor(1, 1, 1, 1);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

	glutKeyboardFunc(keyboard_ct);

	glutMainLoop();
}
#endif