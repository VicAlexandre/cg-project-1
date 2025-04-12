#include "objects.h"
#include "bresenham.h"
#include "dimensions.h"

void draw_goals(void (*draw_pixel)(int, int)) {
  /* left goal */
  bresenham_draw_line(GOAL_L_X, GOAL_L_Y, GOAL_L_X + GOAL_W, GOAL_L_Y,
                      draw_pixel);
  bresenham_draw_line(GOAL_L_X, GOAL_L_Y, GOAL_L_X, GOAL_L_Y + GOAL_H,
                      draw_pixel);
  bresenham_draw_line(GOAL_L_X + GOAL_W, GOAL_L_Y, GOAL_L_X + GOAL_W,
                      GOAL_L_Y + GOAL_H, draw_pixel);
  bresenham_draw_line(GOAL_L_X, GOAL_L_Y + GOAL_H, GOAL_L_X + GOAL_W,
                      GOAL_L_Y + GOAL_H, draw_pixel);

  /* right goal */
  bresenham_draw_line(GOAL_R_X, GOAL_R_Y, GOAL_R_X + GOAL_W, GOAL_R_Y,
                      draw_pixel);
  bresenham_draw_line(GOAL_R_X, GOAL_R_Y, GOAL_R_X, GOAL_R_Y + GOAL_H,
                      draw_pixel);
  bresenham_draw_line(GOAL_R_X + GOAL_W, GOAL_R_Y, GOAL_R_X + GOAL_W,
                      GOAL_R_Y + GOAL_H, draw_pixel);
  bresenham_draw_line(GOAL_R_X, GOAL_R_Y + GOAL_H, GOAL_R_X + GOAL_W,
                      GOAL_R_Y + GOAL_H, draw_pixel);
}

void draw_field(void (*draw_pixel)(int, int)) {
  bresenham_draw_line(FIELD_X, FIELD_Y, FIELD_X + FIELD_W, FIELD_Y, draw_pixel);
  bresenham_draw_line(FIELD_X + FIELD_W, FIELD_Y, FIELD_X + FIELD_W,
                      FIELD_Y + FIELD_H, draw_pixel);
  bresenham_draw_line(FIELD_X + FIELD_W, FIELD_Y + FIELD_H, FIELD_X,
                      FIELD_Y + FIELD_H, draw_pixel);
  bresenham_draw_line(FIELD_X, FIELD_Y + FIELD_H, FIELD_X, FIELD_Y, draw_pixel);
  bresenham_draw_line(FIELD_X + FIELD_W / 2, FIELD_Y, FIELD_X + FIELD_W / 2,
                      FIELD_Y + FIELD_H, draw_pixel);

  bresenham_draw_circle(FIELD_C_X, FIELD_C_Y, 100, draw_pixel);
  bresenham_draw_circle_filled(FIELD_C_X, FIELD_C_Y, 5, draw_pixel);
}

void draw_small_areas(void (*draw_pixel)(int, int)) {
  /* left small area */
  bresenham_draw_line(SMALL_AREA_L_X, SMALL_AREA_L_Y,
                      SMALL_AREA_L_X + SMALL_AREA_W, SMALL_AREA_L_Y,
                      draw_pixel);
  bresenham_draw_line(SMALL_AREA_L_X + SMALL_AREA_W, SMALL_AREA_L_Y,
                      SMALL_AREA_L_X + SMALL_AREA_W,
                      SMALL_AREA_L_Y + SMALL_AREA_H, draw_pixel);
  bresenham_draw_line(SMALL_AREA_L_X, SMALL_AREA_L_Y + SMALL_AREA_H,
                      SMALL_AREA_L_X + SMALL_AREA_W,
                      SMALL_AREA_L_Y + SMALL_AREA_H, draw_pixel);

  /* right small area */
  bresenham_draw_line(SMALL_AREA_R_X, SMALL_AREA_R_Y,
                      SMALL_AREA_R_X + SMALL_AREA_W, SMALL_AREA_R_Y,
                      draw_pixel);
  bresenham_draw_line(SMALL_AREA_R_X, SMALL_AREA_R_Y, SMALL_AREA_R_X,
                      SMALL_AREA_R_Y + SMALL_AREA_H, draw_pixel);
  bresenham_draw_line(SMALL_AREA_R_X, SMALL_AREA_R_Y + SMALL_AREA_H,
                      SMALL_AREA_R_X + SMALL_AREA_W,
                      SMALL_AREA_R_Y + SMALL_AREA_H, draw_pixel);
}

void draw_penalty_area(void (*draw_pixel)(int, int)) {
  bresenham_draw_line(PENALTY_AREA_L_X, PENALTY_AREA_L_Y,
                      PENALTY_AREA_L_X + PENALTY_AREA_W, PENALTY_AREA_L_Y,
                      draw_pixel);
  bresenham_draw_line(PENALTY_AREA_L_X + PENALTY_AREA_W, PENALTY_AREA_L_Y,
                      PENALTY_AREA_L_X + PENALTY_AREA_W,
                      PENALTY_AREA_L_Y + PENALTY_AREA_H, draw_pixel);
  bresenham_draw_line(PENALTY_AREA_L_X, PENALTY_AREA_L_Y + PENALTY_AREA_H,
                      PENALTY_AREA_L_X + PENALTY_AREA_W,
                      PENALTY_AREA_L_Y + PENALTY_AREA_H, draw_pixel);

  bresenham_draw_line(PENALTY_AREA_R_X, PENALTY_AREA_R_Y,
                      PENALTY_AREA_R_X + PENALTY_AREA_W, PENALTY_AREA_R_Y,
                      draw_pixel);
  bresenham_draw_line(PENALTY_AREA_R_X, PENALTY_AREA_R_Y, PENALTY_AREA_R_X,
                      PENALTY_AREA_R_Y + PENALTY_AREA_H, draw_pixel);
  bresenham_draw_line(PENALTY_AREA_R_X, PENALTY_AREA_R_Y + PENALTY_AREA_H,
                      PENALTY_AREA_R_X + PENALTY_AREA_W,
                      PENALTY_AREA_R_Y + PENALTY_AREA_H, draw_pixel);

  bresenham_draw_circle_filled(PENALTY_POINT_L_X, PENALTY_POINT_L_Y, 5,
                               draw_pixel);
  bresenham_draw_circle_filled(PENALTY_POINT_R_X, PENALTY_POINT_R_Y, 5,
                               draw_pixel);

  bresenham_draw_semi_circle_left(LEFT_SEMI_CIRCLE_X, LEFT_SEMI_CIRCLE_Y,
                                  SEMI_CIRCLE_RADIUS, draw_pixel);
  bresenham_draw_semi_circle_right(RIGHT_SEMI_CIRCLE_X, RIGHT_SEMI_CIRCLE_Y,
                                   SEMI_CIRCLE_RADIUS, draw_pixel);
}
