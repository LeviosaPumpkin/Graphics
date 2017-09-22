#include <windows.h>
#include <freeglut.h>
#include <glut.h>
#include <GL/glaux.h>
#include <vector>
#include"Constatnts.h"

AUX_RGBImageRec* photo_image;
GLuint texture;

static void resize(int width, int height)
{
	const float ar = (float)width / (float)height;

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

static void display(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3d(1, 1, 0);

	glPushMatrix();
	glTranslated(2.0, 2.0, -10);
	glRotated(65, 1.0, 0.0, 0.0);
	glutWireCone(1, 2.5, 16, 16);
	glPopMatrix();

	glPushMatrix();
	glTranslated(2.0, 2.0, -10);
	glRotated(65, 1.0, 0.0, 0.0);
	glutWireCone(1, 5, 16, 16);
	glPopMatrix();

	glutSwapBuffers();

	glColor3d(0, 1, 0);

	glPushMatrix();
	glTranslated(-1.4, -1.4, -10);
	glRotated(65, 1.0, 0.0, 0.0);
	glutSolidCylinder(1, 2.5, 16, 16);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-2.0, 2.0, -8);
	glRotated(65, 1.0, 0.0, 0.0);
	glutSolidTorus(0.1, 0.5, 16, 16);
	glPopMatrix();

	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 27: /* escape */
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glColor3d(1, 1, 0);

		glPushMatrix();
		glTranslated(2.0, 2.0, -10);
		glRotated(65, 1.0, -2.0, 0.0);
		glutWireCone(1, 2.5, 16, 16);
		glPopMatrix();

		glPushMatrix();
		glTranslated(2.0, 2.0, -10);
		glRotated(65, 1.0, -2.0, 0.0);
		glutWireCone(1, 5, 16, 16);
		glPopMatrix();

		glutSwapBuffers();

		glColor3d(0, 1, 0);

		glEnable(GL_TEXTURE_2D);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
		glBindTexture(GL_TEXTURE_2D, texture);

		glPushMatrix();
		glTranslated(-1.4, -1.4, -10);
		glRotated(65, 1.0, 0.0, 0.0);
		glScalef(2.0, 2.0, 2.0);
		glutSolidCylinder(1, 2.5, 16, 16);
		glPopMatrix();

		glPushMatrix();
		glTranslated(-2.0, 2.0, -8);
		glRotated(65, 1.0, 0.0, 1.0);
		glScalef(1.0, 1.0, 1.0);
		glutSolidTorus(0.1, 0.5, 16, 16);
		glPopMatrix();

		glutSwapBuffers();
		break;
	case 32:
		double r = 1;
		GLUquadricObj * cylinder;
		cylinder = gluNewQuadric();
		while (r > 0)
		{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glColor3d(1, 1, 0);

		glPushMatrix();
		glTranslated(2.0, 2.0, -10);
		glRotated(65, 1.0, 0.0, 0.0);
		glutWireCone(1, 2.5, 16, 16);
		glPopMatrix();

		glPushMatrix();
		glTranslated(2.0, 2.0, -10);
		glRotated(65, 1.0, 0.0, 0.0);
		glutWireCone(1, 5, 16, 16);
		glPopMatrix();

		glutSwapBuffers();

		glColor3d(0, 1, 0);

		glPushMatrix();
		glTranslated(-1.4, -1.4, -10);
		glRotated(65, 1.0, 0.0, 0.0);
		gluCylinder(cylinder, r, 1, 2.5, 16, 16);
		glPopMatrix();

		glPushMatrix();
		glTranslated(-2.0, 2.0, -8);
		glRotated(65, 1.0, 0.0, 0.0);
		glutSolidTorus(0.1, 0.5, 16, 16);
		glPopMatrix();

		glutSwapBuffers();
		r -= 0.01;
		}
	//	//сфера для морфинга
	//	glMatrixMode(GL_PROJECTION);
	//	glLoadIdentity();

	//	glMatrixMode(GL_MODELVIEW);
	//	glLoadIdentity();

	//	std::vector<double> cyl_x;
	//	std::vector<double> cyl_y;
	//	std::vector<double> cyl_z;

	//	glBegin(GL_POINTS);
	//	glColor3ub(0, 0, 255);
	//	int R = 30;
	//	for (int a = 0; a < 1000; a = a + 10)
	//	{
	//		for (int b = -30; b < 30; b = b + 10)
	//		{
	//			glVertex3d(R * cos(a), R * sin(a), b);
	//			cyl_x.push_back(R * cos(b));
	//			cyl_y.push_back(R * sin(a));
	//			cyl_z.push_back(b);

	//		}
	//	}
	//	glEnd();

	//	glBegin(GL_POINTS);
	//	glColor3ub(255, 0, 0);

	//	std::vector<double> con_x;
	//	std::vector<double> con_y;
	//	std::vector<double> con_z;

	//	R = 30;
	//	for (int a = 0; a < 1000; a = a + 10)
	//	{
	//		for (int b = -30; b < 30; b = b + 1)
	//		{
	//			//glVertex3d(R * cos(a), R * sin(a), b);
	//			con_x.push_back(R*cos(a));
	//			con_y.push_back(R * sin(a));
	//			con_z.push_back(b);

	//		}
	//	}
	//	glEnd();
	//	glFlush();
	//	Sleep(500);

	//	//морфинг
	//	int count = 10;
	//	int delay_ = 500;

	//	//для каждой точки сферы надо вычислить dx, dy, dz
	//	std::vector<double> dx;
	//	std::vector<double> dy;
	//	std::vector<double> dz;

	//	for (int i = 0; i < cyl_x.size(); i++)
	//	{
	//		dx.push_back((con_x[cyl_x.size() - i - 1] - cyl_x[i]) / count);
	//		dy.push_back((con_y[cyl_x.size() - i - 1] - cyl_y[i]) / count);
	//		dz.push_back((con_z[cyl_x.size() - i - 1] - cyl_z[i]) / count);
	//	}

	//	for (int i = 0; i < count; i++)		//цикл по итерациям
	//	{
	//		//отрисовка с новыми координатами
	//		glClearColor(0.0, 0.0, 0.0, 0.0);
	//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//		glBegin(GL_POINTS);
	//		glColor3ub(0, 255, 0);
	//		int R = 30;
	//		for (int j = 0; j < cyl_x.size(); j++)
	//		{
	//			glVertex3d(cyl_x[j] + dx[j] * (i + 1), cyl_y[j] + dy[j] * (i + 1), cyl_z[j] + dz[j] * (i + 1));
	//		}

	//		glEnd();
	//		glFlush();
	//		Sleep(delay_);
	//		break;
	//	}
	//	glFlush();
	//	glDisable(GL_TEXTURE_2D);
	}
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);

	glutInitWindowSize(640, 640);
	glutInitWindowPosition(10, 10);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	glutCreateWindow("Graph1");

	glutReshapeFunc(resize);
	glutDisplayFunc(display);

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

	photo_image = auxDIBImageLoad(L"texture.bmp");
	
	glGenTextures(1, &texture); // присваивает имя объекту текстуры
	glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, 3,
		photo_image->sizeX,
		photo_image->sizeY,
		0, GL_RGB, GL_UNSIGNED_BYTE,
		photo_image->data);	glutKeyboardFunc(keyboard);

	glutMainLoop();
	
	return EXIT_SUCCESS;
}
