#include "objects.h"

#include <GL/gl.h>
#include <GL/glut.h>

#define VIEWPORT_W 1400
#define VIEWPORT_H 900

void draw_pixel(int x, int y) {
  glBegin(GL_POINTS);
  glVertex2i(x, y);
  glEnd();
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);

  draw_field(draw_pixel);
  draw_goals(draw_pixel);
  draw_small_areas(draw_pixel);
  draw_penalty_area(draw_pixel);

  glFlush();
}

void init() {
  glClearColor(0.05, 0.168, 0.082, 0.3);
  glColor3f(1.0, 1.0, 1.0);
  glPointSize(2.0);

  /* Set up the viewport */
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-50, VIEWPORT_W + 50, 50, VIEWPORT_H + 50);
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(VIEWPORT_W, VIEWPORT_H);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Campo de Futebol");

  init();
  glutDisplayFunc(display);
  glutMainLoop();

  return 0;
}
