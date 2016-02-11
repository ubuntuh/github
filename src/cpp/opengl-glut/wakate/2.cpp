#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <glui.h>

float rotate[16] = {
    1,0,0,0,
    0,1,0,0,
    0,0,1,0,
    0,0,0,1
};

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glMultMatrixf(rotate);
    glutWireTeapot(0.5);
    glPopMatrix();
    glutSwapBuffers();
    glutPostRedisplay();
}

void gluiCallback(int num) {
    exit(0);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    glClearColor(0.0, 0.0, 1.0, 0.0);
    GLUI *glui = GLUI_Master.create_glui("controll");
    GLUI_Rotation *view_rot = glui->add_rotation("Rotation", rotate);
    glui->add_button("Exit", 0, gluiCallback);

    glutMainLoop();
    return 0;
}
