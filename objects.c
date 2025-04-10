#include "objects.h"
#include "bresenham.h"

#define FIELD_W 700
#define FIELD_H 400
#define FIELD_X 0
#define FIELD_Y 0

#define GOAL_W 100
#define GOAL_H 200
#define GOAL_L_X (FIELD_X - GOAL_W)
#define GOAL_L_Y (FIELD_Y + FIELD_H / 2 - GOAL_H / 2)
#define GOAL_R_X (FIELD_X + FIELD_W)
#define GOAL_R_Y (FIELD_Y + FIELD_H / 2 - GOAL_H / 2)

void draw_goals(void (*draw_pixel)(int, int)) {
  bresenham_draw_line(GOAL_L_X, GOAL_L_Y, GOAL_L_X + GOAL_W,
                      GOAL_L_Y, draw_pixel);
  bresenham_draw_line(GOAL_L_X, GOAL_L_Y, GOAL_L_X,
                      GOAL_L_Y + GOAL_H, draw_pixel);
  bresenham_draw_line(GOAL_L_X + GOAL_W, GOAL_L_Y,
                      GOAL_L_X + GOAL_W, GOAL_L_Y + GOAL_H,
                      draw_pixel);
  bresenham_draw_line(GOAL_L_X, GOAL_L_Y + GOAL_H,
                      GOAL_L_X + GOAL_W, GOAL_L_Y + GOAL_H,
                      draw_pixel);

  bresenham_draw_line(GOAL_R_X, GOAL_R_Y, GOAL_R_X + GOAL_W,
                      GOAL_R_Y, draw_pixel);
  bresenham_draw_line(GOAL_R_X, GOAL_R_Y, GOAL_R_X,
                      GOAL_R_Y + GOAL_H, draw_pixel);
  bresenham_draw_line(GOAL_R_X + GOAL_W, GOAL_R_Y,
                      GOAL_R_X + GOAL_W, GOAL_R_Y + GOAL_H,
                      draw_pixel);
  bresenham_draw_line(GOAL_R_X, GOAL_R_Y + GOAL_H,
                      GOAL_R_X + GOAL_W, GOAL_R_Y + GOAL_H,
                      draw_pixel);
}

void draw_field(void (*draw_pixel)(int, int)) {
  bresenham_draw_line(FIELD_X, FIELD_Y, FIELD_X + FIELD_W, FIELD_Y,
                      draw_pixel);
  bresenham_draw_line(FIELD_X + FIELD_W, FIELD_Y, FIELD_X + FIELD_W,
                      FIELD_Y + FIELD_H, draw_pixel);
  bresenham_draw_line(FIELD_X + FIELD_W, FIELD_Y + FIELD_H, FIELD_X,
                      FIELD_Y + FIELD_H, draw_pixel);
  bresenham_draw_line(FIELD_X, FIELD_Y + FIELD_H, FIELD_X, FIELD_Y,
                      draw_pixel);
  bresenham_draw_line(FIELD_X + FIELD_W / 2, FIELD_Y,
                      FIELD_X + FIELD_W / 2, FIELD_Y + FIELD_H,
                      draw_pixel);
}
