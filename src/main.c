#include "objects.h"

#include <GL/gl.h>
#include <GL/glut.h>
#include <stdbool.h>

#define VIEWPORT_W 1300
#define VIEWPORT_H 900

/********** Callbacks used in Bresenham **********/
void white_pixel_cb(int x, int y) {
  glBegin(GL_POINTS);
  glVertex2i(x, y);
  glEnd();
}

void yellow_pixel_cb(int x, int y) {
  glColor3f(1.0, 1.0, 0.0);
  white_pixel_cb(x, y);
  glColor3f(1.0, 1.0, 1.0);
}
/************************************************/

void draw_string(float x, float y, const char *str) {
  glRasterPos2f(x, y);
  for (const char *c = str; *c != '\0'; c++) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
  }
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);

  obj_draw_field(white_pixel_cb);
  obj_draw_goals(white_pixel_cb);
  obj_draw_small_areas(white_pixel_cb);
  obj_draw_penalty_area(white_pixel_cb);
  obj_draw_scoreboard(white_pixel_cb);
  obj_draw_ball(yellow_pixel_cb);
  obj_draw_scores(draw_string);

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
