#include "bresenham.h"

#define ABS(x) ((x) < 0 ? -(x) : (x))

void bresenham_draw_line(int x1, int y1, int x2, int y2,
                         void (*draw_pixel)(int, int)) {
  int dx = ABS(x2 - x1);
  int dy = ABS(y2 - y1);
  int sx = (x1 < x2) ? 1 : -1;
  int sy = (y1 < y2) ? 1 : -1;
  int err = dx - dy;

  while (1) {
    draw_pixel(x1, y1);

    if (x1 == x2 && y1 == y2) {
      break;
    }

    int e2 = 2 * err;

    if (e2 > -dy) {
      err -= dy;
      x1 += sx;
    }

    if (e2 < dx) {
      err += dx;
      y1 += sy;
    }
  }
}
