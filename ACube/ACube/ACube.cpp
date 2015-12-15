
#include <GL/glut.h>
#include <GL/GL.h>
#include <glew.h>


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDrawArrays(GL_TRIANGLES, 0, NumVertices);
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 033: case 'q': case 'Q':
		exit(EXIT_SUCCESS);
		break;
	}
}

int main( int argc, char **argv )
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(512, 512);
	glutCreateWindow("Color Cube");

	glewInit();
	init();

	glutDisplayFunc(display);  // a callback
	glutKeyboardFunc(keyboard); // a callback
	glutMainLoop();

	return 0;
}