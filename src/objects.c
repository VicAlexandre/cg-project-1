#include "objects.h"
#include "bresenham.h"
#include "dimensions.h"

#include <stdbool.h>
#include <stdio.h>

struct ball_pos {
  int x;
  int y;
};

struct scoreboard {
  unsigned int left_team;
  unsigned int right_team;
};

static struct {
  struct ball_pos ball;
  struct scoreboard scoreboard;
} self = {
    .ball =
        {
            BALL_X,
            BALL_Y,
        },
    .scoreboard =
        {
            .left_team = 0,
            .right_team = 0,
        },
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
    self.scoreboard.right_team++;
    return true;
  } else if (x > GOAL_R_X && y > GOAL_R_Y && y < GOAL_R_Y + GOAL_H) {
    self.scoreboard.left_team++;
    return true;
  }
  return false;
}

void obj_move_ball(int x, int y) {
  self.ball.x += x;
  self.ball.y += y;

  if ((self.ball.x < FIELD_X) || (self.ball.x > FIELD_X + FIELD_W)) {
    if (check_goal(self.ball.x, self.ball.y)) {
      self.ball.x = FIELD_X + FIELD_W / 2;
      self.ball.y = FIELD_Y + FIELD_H / 2;
      return;
    }
    self.ball.x -= x;
  }

  if (self.ball.y < FIELD_Y) {
    self.ball.y = FIELD_Y;
  } else if (self.ball.y > FIELD_Y + FIELD_H) {
    self.ball.y = FIELD_Y + FIELD_H;
  }
}

void obj_draw_ball(void (*draw_pixel)(int, int)) {
  bresenham_draw_circle_filled(self.ball.x, self.ball.y, BALL_RADIUS,
                               draw_pixel);
}

void obj_draw_scoreboard(void (*draw_pixel)(int, int)) {
  /* scoreboard rectangle */
  bresenham_draw_line(SCOREBOARD_X, SCOREBOARD_Y, SCOREBOARD_X + SCOREBOARD_W,
                      SCOREBOARD_Y, draw_pixel);
  bresenham_draw_line(SCOREBOARD_X, SCOREBOARD_Y, SCOREBOARD_X,
                      SCOREBOARD_Y + SCOREBOARD_H, draw_pixel);
  bresenham_draw_line(SCOREBOARD_X + SCOREBOARD_W, SCOREBOARD_Y,
                      SCOREBOARD_X + SCOREBOARD_W, SCOREBOARD_Y + SCOREBOARD_H,
                      draw_pixel);
  bresenham_draw_line(SCOREBOARD_X, SCOREBOARD_Y + SCOREBOARD_H,
                      SCOREBOARD_X + SCOREBOARD_W, SCOREBOARD_Y + SCOREBOARD_H,
                      draw_pixel);

  /* scoreboard split line */
  bresenham_draw_line(SCOREBOARD_X + SCOREBOARD_W / 2, SCOREBOARD_Y,
                      SCOREBOARD_X + SCOREBOARD_W / 2,
                      SCOREBOARD_Y + SCOREBOARD_H, draw_pixel);
}

void obj_draw_scores(void (*draw_string)(float, float, const char *)) {
  char left_team_score[3] = {};
  char right_team_score[3] = {};

  snprintf(left_team_score, sizeof(left_team_score), "%d",
           self.scoreboard.left_team);
  snprintf(right_team_score, sizeof(right_team_score), "%d",
           self.scoreboard.right_team);

  draw_string(SCOREBOARD_X + SCOREBOARD_W / 4.0,
              SCOREBOARD_Y + SCOREBOARD_H / 2.0, left_team_score);
  draw_string(SCOREBOARD_X + SCOREBOARD_W * 3.0 / 4.0,
              SCOREBOARD_Y + SCOREBOARD_H / 2.0, right_team_score);
}
