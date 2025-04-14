#ifndef OBJECTS_H
#define OBJECTS_H

/************** DRAW API ***************/
void obj_draw_goals(void (*draw_pixel)(int, int));

void obj_draw_field(void (*draw_pixel)(int, int));

void obj_draw_small_areas(void (*draw_pixel)(int, int));

void obj_draw_penalty_area(void (*draw_pixel)(int, int));

void obj_draw_ball(void (*draw_pixel)(int, int));

void obj_draw_scoreboard(void (*draw_pixel)(int, int));

void obj_draw_scores(void (*draw_string)(float, float, const char *));

void obj_draw_players(void (*draw_pixel_white)(int, int),
                      void (*draw_pixel_left_team)(int, int),
                      void (*draw_pixel_right_team)(int, int));

/************** MOVE API ***************/
void obj_move_ball(int x, int y);

#endif /* OBJECTS_H */
