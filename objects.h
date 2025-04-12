#ifndef OBJECTS_H
#define OBJECTS_H

void obj_draw_goals(void (*draw_pixel)(int, int));

void obj_draw_field(void (*draw_pixel)(int, int));

void obj_draw_small_areas(void (*draw_pixel)(int, int));

void obj_draw_penalty_area(void (*draw_pixel)(int, int));

void obj_move_ball(int x, int y);

void obj_draw_ball(void (*draw_pixel)(int, int));

#endif /* OBJECTS_H */
