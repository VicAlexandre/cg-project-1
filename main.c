#include "objects.h"

#include <GL/gl.h>
#include <GL/glut.h>

#define VIEWPORT_WIDTH 1400
#define VIEWPORT_HEIGHT 900

void draw_pixel(int x, int y) {
  glBegin(GL_POINTS);
  glVertex2i(x, y);
  glEnd();
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);

  draw_field(draw_pixel);
  draw_goals(draw_pixel);

  glFlush();
}

void init() {
  glClearColor(0.1, 200.0, 0.2, 0.5);
  glColor3f(1.0, 1.0, 1.0);
  glPointSize(2.0);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  /* center the viewport (gluOrtho2D(-w/2, w/2, h/2, -h/2);) */
  gluOrtho2D(-VIEWPORT_WIDTH / 2.0, VIEWPORT_WIDTH, -VIEWPORT_HEIGHT,
             VIEWPORT_HEIGHT);
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(VIEWPORT_WIDTH, VIEWPORT_HEIGHT);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Campo de Futebol");

  init();
  glutDisplayFunc(display);
  glutMainLoop();

  return 0;
}
