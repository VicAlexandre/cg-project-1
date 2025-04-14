#ifndef DIMENSIONS_H
#define DIMENSIONS_H

enum field_dimensions {
  FIELD_W = 1300,
  FIELD_H = 900,
  FIELD_X = 50,
  FIELD_Y = 50,

  FIELD_C_X = FIELD_X + FIELD_W / 2,
  FIELD_C_Y = FIELD_Y + FIELD_H / 2,
};

enum goal_dimensions {
  GOAL_W = 50,
  GOAL_H = 100,

  /* left goal */
  GOAL_L_X = FIELD_X - GOAL_W,
  GOAL_L_Y = FIELD_Y + FIELD_H / 2 - GOAL_H / 2,

  /* right goal */
  GOAL_R_X = FIELD_X + FIELD_W,
  GOAL_R_Y = FIELD_Y + FIELD_H / 2 - GOAL_H / 2,
};

enum small_area_dimensions {
  SMALL_AREA_W = 100,
  SMALL_AREA_H = 300,

  /* left small area */
  SMALL_AREA_L_X = FIELD_X,
  SMALL_AREA_L_Y = FIELD_Y + FIELD_H / 2 - SMALL_AREA_H / 2,

  /* right small area */
  SMALL_AREA_R_X = FIELD_W - SMALL_AREA_W + FIELD_X,
  SMALL_AREA_R_Y = FIELD_Y + FIELD_H / 2 - SMALL_AREA_H / 2,
};

enum penalty_area_dimensions {
  PENALTY_AREA_W = 200,
  PENALTY_AREA_H = 450,

  /* left penalty area */
  PENALTY_AREA_L_X = FIELD_X,
  PENALTY_AREA_L_Y = FIELD_Y + FIELD_H / 2 - PENALTY_AREA_H / 2,
  PENALTY_POINT_L_X = FIELD_X + PENALTY_AREA_W - SMALL_AREA_L_X,
  PENALTY_POINT_L_Y = FIELD_Y + FIELD_H / 2,

  /* right penalty area */
  PENALTY_AREA_R_X = FIELD_W + FIELD_X - PENALTY_AREA_W,
  PENALTY_AREA_R_Y = FIELD_Y + FIELD_H / 2 - PENALTY_AREA_H / 2,
  PENALTY_POINT_R_X = FIELD_X + FIELD_W - PENALTY_AREA_W + (SMALL_AREA_W / 2),
  PENALTY_POINT_R_Y = FIELD_Y + FIELD_H / 2,
};

enum semi_circle_dimensions {
  SEMI_CIRCLE_RADIUS = 100,

  RIGHT_SEMI_CIRCLE_X = FIELD_X + PENALTY_AREA_W,
  RIGHT_SEMI_CIRCLE_Y = FIELD_Y + FIELD_H / 2,

  LEFT_SEMI_CIRCLE_X = FIELD_X + FIELD_W - PENALTY_AREA_W,
  LEFT_SEMI_CIRCLE_Y = FIELD_Y + FIELD_H / 2,
};

enum soccer_ball_dimensions {
  BALL_RADIUS = 4,
  BALL_X = FIELD_X + FIELD_W / 2,
  BALL_Y = FIELD_Y + FIELD_H / 2,
};

enum scoreboard_dimensions {
  SCOREBOARD_W = 200,
  SCOREBOARD_H = 80,

  SCOREBOARD_X = FIELD_X + FIELD_W / 2 - SCOREBOARD_W / 2,
  SCOREBOARD_Y = FIELD_Y + FIELD_H + 30,
};

enum base_player_dimensions {
  PLAYER_W = 20,
  PLAYER_H = 20,
  PLAYER_R = 10,
};

enum goalkeeper_pos {
  GK_L_X = GOAL_L_X + GOAL_W + 20,
  GK_L_Y = GOAL_L_Y + GOAL_H / 2,

  GK_R_X = GOAL_R_X - 20,
  GK_R_Y = GOAL_R_Y + GOAL_H / 2,
};

enum defender_pos {
  DEF_L_X = SMALL_AREA_L_X + SMALL_AREA_W + 20,
  DEF_L_Y = SMALL_AREA_L_Y + SMALL_AREA_H / 2,

  DEF_R_X = SMALL_AREA_R_X - 20,
  DEF_R_Y = SMALL_AREA_R_Y + SMALL_AREA_H / 2,
};

enum midfielder_pos {
  MID_L_X = (PENALTY_AREA_L_X + FIELD_C_X + PENALTY_AREA_W) / 2,
  MID_L_Y = FIELD_C_Y,

  MID_R_X = (PENALTY_AREA_R_X + FIELD_C_X) / 2,
  MID_R_Y = FIELD_C_Y,
};

enum forward_pos {
  FWD_L_X = MID_L_X + 50,
  FWD_L_Y = FIELD_C_Y,

  FWD_R_X = MID_R_X - 50,
  FWD_R_Y = FIELD_C_Y,
};

#endif /* DIMENSIONS_H */
