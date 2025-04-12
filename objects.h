#ifndef OBJECTS_H
#define OBJECTS_H

void draw_goals(void (*draw_pixel)(int, int));

void draw_field(void (*draw_pixel)(int, int));

void draw_small_areas(void (*draw_pixel)(int, int));

void draw_penalty_area(void (*draw_pixel)(int, int));

#endif /* OBJECTS_H */
