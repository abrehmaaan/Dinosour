#include <GL/glut.h>
#include<iostream>
#include<fstream>
using namespace std;

//void myInit(void) {
//
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0, (GLint)sw, 0, (GLint)sh);
//}

void readAndDrawHouse(const char* filename) {
    ifstream file(filename, ios::in);
    if (!file.is_open()) {
        exit(-1);
    }
    GLint polylines, innerlines, x, y;
    file >> polylines;
    for (int i = 0; i < polylines; i++) {
        file >> innerlines;
        glBegin(GL_LINE_STRIP);
        for (int j = 0; j < innerlines; j++) {
            file >> x >> y;
            glVertex2d(x, y);
        }glEnd();
    }
    file.close();
}

void window(int xs, int xe, int ys, int ye) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D((GLint)xs, (GLint)xe, (GLint)ys, (GLint)ye);
}


void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            window(0, 640, 0, 440);
            glViewport(i * 64, j * 44, 64, 44);
            readAndDrawHouse("dino.dat");
        }
    }

    for (int i = 8; i <= 12; i++) {
        for (int j = 1; j <= 5; j++) {
            if (j % 2 == 0) {
                window(0, 640, 0, 440);
            }
            else {
                window(0, 640, 440, 0);
            }
            glViewport(i * 64, j * 44, 64, 44);
            readAndDrawHouse("dino.dat");
        }
    }

    glFlush();
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900, 320);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("Dinosour");
    glutDisplayFunc(myDisplay);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(2.0);
    glutMainLoop();
}