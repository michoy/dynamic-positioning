#include <stdio.h>
#include <string.h>
#include <GL/freeglut.h>

#include "animate.h"

GLfloat boatPosition;
GLfloat thrustLevel;
GLfloat targetPosition = 40.0;
char tmp1[16];
char tmp2[16];
char tmp3[16];
FILE* f;

static void sleep_ms(int milliseconds) {
#ifdef WIN32
    Sleep((DWORD) milliseconds);
#elif _POSIX_C_SOURCE >= 199309L
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;
    nanosleep(&ts, NULL);
#else
    usleep(milliseconds * 1000);
#endif
}

void Draw() {
    // update boats position and thrust
    if (fscanf(f, "%s %s %s", &tmp1, &tmp2, &tmp3) != 3) {
        printf("Reached end of file");
        glEnd();
        glFlush();
        return;
    }
    boatPosition = strtof(&tmp2, NULL);
    thrustLevel = strtof(&tmp3, NULL);

    // draw stationary background lines
    glColor3f(0.9, 0.9, 0.9);
    glBegin(GL_LINES);

    glVertex2d(0.0, 25.0);
    glVertex2d(67, 25.0);

    glVertex2d(targetPosition, 22);
    glVertex2d(targetPosition, 24);

    glVertex2d(targetPosition, 26);
    glVertex2d(targetPosition, 28);

    glVertex2d(-30.0, 10.0);
    glVertex2d(-20.0, 10.0);

    glVertex2d(-30.0, 40.0);
    glVertex2d(-20.0, 40.0);

    glVertex2d(-30.0, 10.0);
    glVertex2d(-30.0, 40.0);

    glVertex2d(-20.0, 10.0);
    glVertex2d(-20.0, 40.0);

    // draw adaptive foreground lines
    glBegin(GL_LINES);
    glColor3f(0.6, 0.3, 0.3);

    for (double i = 10.5; i<=0.25*thrustLevel; i += 0.1) {            // 0.25 because max thrust is 160 and max y is 40
        glVertex2d(-29.0, i);
        glVertex2d(-21.1, i);
    }
    for (double i=boatPosition-2.5; i<=boatPosition+2.5; i += 0.1) {  // 0.25 because max thrust is 160 and max y is 40
        glVertex2d(i, 23);
        glVertex2d(i, 27);
    }

    // prepare for next iteration
    sleep_ms(50);
    glEnd();
    glFlush();
    glClear(GL_COLOR_BUFFER_BIT);
    glutPostRedisplay();
}

void Initialize() {
    // Reset background color with dark grey
    glClearColor(0.2, 0.2, 0.2, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Set window size
    glOrtho(-50.0, 100.0, 0.0, 50.0, -1.0, 1.0);

    // Initiate input from log
    f = fopen("../logs/log.dat", "r");
    if (!f) fprintf(stderr, "can't open log");
}

int animate(int iArgc, char** cppArgv) {
    glutInit(&iArgc, cppArgv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("DP Animation");
    Initialize();
    glutDisplayFunc(Draw);
    glutMainLoop();
    fclose(f);
    return 0;
}
