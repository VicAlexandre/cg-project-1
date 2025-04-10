#ifndef BRESENHAM_H
#define BRESENHAM_H

void bresenham_draw_line(int x1, int y1, int x2, int y2,
                         void (*draw_pixel)(int, int));

#endif /* BRESENHAM_H */
