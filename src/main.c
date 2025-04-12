#include "objects.h"

#include <GL/gl.h>
#include <GL/glut.h>
#include <stdbool.h>

#define VIEWPORT_W 1400
#define VIEWPORT_H 900

void draw_pixel(int x, int y) {
  glBegin(GL_POINTS);
  glVertex2i(x, y);
  glEnd();
}

void draw_yellow_pixel(int x, int y) {
  glColor3f(1.0, 1.0, 0.0);
  draw_pixel(x, y);
  glColor3f(1.0, 1.0, 1.0);
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);

  obj_draw_field(draw_pixel);
  obj_draw_goals(draw_pixel);
  obj_draw_small_areas(draw_pixel);
  obj_draw_penalty_area(draw_pixel);
  obj_draw_ball(draw_yellow_pixel);

  glFlush();
}

void init() {
  glClearColor(0.05, 0.168, 0.082, 0.3);
  glColor3f(1.0, 1.0, 1.0);
  glPointSize(2.0);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-50, VIEWPORT_W + 50, 50, VIEWPORT_H + 50);
}

void keyboard(unsigned char key, int x, int y) {
  switch (key) {
  case 27:
    exit(0);
    break;
  case 'w':
    obj_move_ball(0, 10);
    break;
  case 's':
    obj_move_ball(0, -10);
    break;
  case 'a':
    obj_move_ball(-10, 0);
    break;
  case 'd':
    obj_move_ball(10, 0);
    break;
  default:
    return;
  }

  display();
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(VIEWPORT_W, VIEWPORT_H);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Campo de Futebol");

  init();
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutMainLoop();

  return 0;
}
