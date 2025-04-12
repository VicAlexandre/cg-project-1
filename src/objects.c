#include "objects.h"
#include "bresenham.h"
#include "dimensions.h"

#include <stdbool.h>

static struct {
  int x;
  int y;
} ball = {
    BALL_X,
    BALL_Y,
};

void obj_draw_goals(void (*draw_pixel)(int, int)) {
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

void obj_draw_field(void (*draw_pixel)(int, int)) {
  bresenham_draw_line(FIELD_X, FIELD_Y, FIELD_X + FIELD_W, FIELD_Y, draw_pixel);
  bresenham_draw_line(FIELD_X + FIELD_W, FIELD_Y, FIELD_X + FIELD_W,
                      FIELD_Y + FIELD_H, draw_pixel);
  bresenham_draw_line(FIELD_X + FIELD_W, FIELD_Y + FIELD_H, FIELD_X,
                      FIELD_Y + FIELD_H, draw_pixel);
  bresenham_draw_line(FIELD_X, FIELD_Y + FIELD_H, FIELD_X, FIELD_Y, draw_pixel);
  bresenham_draw_line(FIELD_X + FIELD_W / 2, FIELD_Y, FIELD_X + FIELD_W / 2,
                      FIELD_Y + FIELD_H, draw_pixel);

  bresenham_draw_circle(FIELD_C_X, FIELD_C_Y, 100, draw_pixel);
  bresenham_draw_circle_filled(FIELD_C_X, FIELD_C_Y, 10, draw_pixel);
}

void obj_draw_small_areas(void (*draw_pixel)(int, int)) {
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

void obj_draw_penalty_area(void (*draw_pixel)(int, int)) {
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

static inline bool check_goal(int x, int y) {
  if (x < GOAL_L_X + GOAL_W && y > GOAL_L_Y && y < GOAL_L_Y + GOAL_H) {
    return true;
  } else if (x > GOAL_R_X && y > GOAL_R_Y && y < GOAL_R_Y + GOAL_H) {
    return true;
  }
  return false;
}

void obj_move_ball(int x, int y) {
  ball.x += x;
  ball.y += y;

  if ((ball.x < FIELD_X) || (ball.x > FIELD_X + FIELD_W)) {
    if (check_goal(ball.x, ball.y)) {
      ball.x = FIELD_X + FIELD_W / 2;
      ball.y = FIELD_Y + FIELD_H / 2;
      return;
    }
    ball.x -= x;
  }

  if (ball.y < FIELD_Y) {
    ball.y = FIELD_Y;
  } else if (ball.y > FIELD_Y + FIELD_H) {
    ball.y = FIELD_Y + FIELD_H;
  }
}

void obj_draw_ball(void (*draw_pixel)(int, int)) {
  bresenham_draw_circle_filled(ball.x, ball.y, BALL_RADIUS, draw_pixel);
}
