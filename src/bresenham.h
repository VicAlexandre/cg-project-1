#ifndef BRESENHAM_H
#define BRESENHAM_H

void bresenham_draw_line(int x1, int y1, int x2, int y2,
                         void (*draw_pixel)(int, int));

void bresenham_draw_circle(int xc, int yc, int r, void (*draw_pixel)(int, int));

void bresenham_draw_circle_filled(int xc, int yc, int r,
                                  void (*draw_pixel)(int, int));

void bresenham_draw_semi_circle_left(int xc, int yc, int r,
                                     void (*draw_pixel)(int, int));

void bresenham_draw_semi_circle_right(int xc, int yc, int r,
                                      void (*draw_pixel)(int, int));
#endif /* BRESENHAM_H */
