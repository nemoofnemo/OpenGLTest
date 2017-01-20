#include <gl/glut.h>
#include <Windows.h>

static GLfloat spin = 0.0;

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glRotatef(spin, 0, 0, 1.0f);
	glColor3f(0.5, 0.5, 0.5);
	glRectf(-25, -25, 25, 25);
	glPopMatrix();
	glutSwapBuffers();
}

void spinDisplay(void) {
	spin += 2.0;
	if (spin > 360) {
		spin -= 360;
	}
	Sleep((int)((float)1000 / (float)60));
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN) {
			glutIdleFunc(spinDisplay);
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN) {
			glutIdleFunc(NULL);
		}
		break;
	default:
		break;
	}

}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("hello opengl");

	glClearColor(0, 0, 0, 0);
	glShadeModel(GL_FLAT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50, 50, -50, 50, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();

	return 0;
}