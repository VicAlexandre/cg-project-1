#include "objects.h"
#include "bresenham.h"

#define FIELD_WIDTH 700
#define FIELD_HEIGHT 400
#define FIELD_X 0
#define FIELD_Y 0

#define GOAL_WIDTH 100
#define GOAL_HEIGHT 200
#define GOAL_LEFT_X (FIELD_X - GOAL_WIDTH)
#define GOAL_LEFT_Y (FIELD_Y + FIELD_HEIGHT / 2 - GOAL_HEIGHT / 2)
#define GOAL_RIGHT_X (FIELD_X + FIELD_WIDTH)
#define GOAL_RIGHT_Y (FIELD_Y + FIELD_HEIGHT / 2 - GOAL_HEIGHT / 2)

void draw_goals(void (*draw_pixel)(int, int)) {
  bresenham_draw_line(GOAL_LEFT_X, GOAL_LEFT_Y, GOAL_LEFT_X + GOAL_WIDTH,
                      GOAL_LEFT_Y, draw_pixel);
  bresenham_draw_line(GOAL_LEFT_X, GOAL_LEFT_Y, GOAL_LEFT_X,
                      GOAL_LEFT_Y + GOAL_HEIGHT, draw_pixel);
  bresenham_draw_line(GOAL_LEFT_X + GOAL_WIDTH, GOAL_LEFT_Y,
                      GOAL_LEFT_X + GOAL_WIDTH, GOAL_LEFT_Y + GOAL_HEIGHT,
                      draw_pixel);
  bresenham_draw_line(GOAL_LEFT_X, GOAL_LEFT_Y + GOAL_HEIGHT,
                      GOAL_LEFT_X + GOAL_WIDTH, GOAL_LEFT_Y + GOAL_HEIGHT,
                      draw_pixel);

  bresenham_draw_line(GOAL_RIGHT_X, GOAL_RIGHT_Y, GOAL_RIGHT_X + GOAL_WIDTH,
                      GOAL_RIGHT_Y, draw_pixel);
  bresenham_draw_line(GOAL_RIGHT_X, GOAL_RIGHT_Y, GOAL_RIGHT_X,
                      GOAL_RIGHT_Y + GOAL_HEIGHT, draw_pixel);
  bresenham_draw_line(GOAL_RIGHT_X + GOAL_WIDTH, GOAL_RIGHT_Y,
                      GOAL_RIGHT_X + GOAL_WIDTH, GOAL_RIGHT_Y + GOAL_HEIGHT,
                      draw_pixel);
  bresenham_draw_line(GOAL_RIGHT_X, GOAL_RIGHT_Y + GOAL_HEIGHT,
                      GOAL_RIGHT_X + GOAL_WIDTH, GOAL_RIGHT_Y + GOAL_HEIGHT,
                      draw_pixel);
}

void draw_field(void (*draw_pixel)(int, int)) {
  bresenham_draw_line(FIELD_X, FIELD_Y, FIELD_X + FIELD_WIDTH, FIELD_Y,
                      draw_pixel);
  bresenham_draw_line(FIELD_X + FIELD_WIDTH, FIELD_Y, FIELD_X + FIELD_WIDTH,
                      FIELD_Y + FIELD_HEIGHT, draw_pixel);
  bresenham_draw_line(FIELD_X + FIELD_WIDTH, FIELD_Y + FIELD_HEIGHT, FIELD_X,
                      FIELD_Y + FIELD_HEIGHT, draw_pixel);
  bresenham_draw_line(FIELD_X, FIELD_Y + FIELD_HEIGHT, FIELD_X, FIELD_Y,
                      draw_pixel);
  bresenham_draw_line(FIELD_X + FIELD_WIDTH / 2, FIELD_Y,
                      FIELD_X + FIELD_WIDTH / 2, FIELD_Y + FIELD_HEIGHT,
                      draw_pixel);
}
