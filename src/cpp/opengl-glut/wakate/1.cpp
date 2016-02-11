// g++ 1.cpp -lglut -lGL
// http://www-sens.sys.es.osaka-u.ac.jp/wakate/tutorial/group3/glui/glui4.html
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glutWireTeapot(0.5);
    glutSwapBuffers();
    glutPostRedisplay();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    glClearColor(0.0, 0.0, 1.0, 0.0);

    glutMainLoop();
    return 0;
}
