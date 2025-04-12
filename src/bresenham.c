#include "bresenham.h"

#define ABS(x) ((x) < 0 ? -(x) : (x))

static inline void draw_eight_way_symmetry(int xc, int yc, int x, int y,
                                           void (*draw_pixel)(int, int)) {
  draw_pixel(xc + x, yc + y);
  draw_pixel(xc - x, yc + y);
  draw_pixel(xc + x, yc - y);
  draw_pixel(xc - x, yc - y);
  draw_pixel(xc + y, yc + x);
  draw_pixel(xc - y, yc + x);
  draw_pixel(xc + y, yc - x);
  draw_pixel(xc - y, yc - x);
}

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

void bresenham_draw_circle(int xc, int yc, int r,
                           void (*draw_pixel)(int, int)) {
  int x = 0;
  int y = r;
  int d = 3 - 2 * r;

  while (x <= y) {
    draw_eight_way_symmetry(xc, yc, x, y, draw_pixel);
    if (d <= 0) {
      d = d + 4 * x + 6;
    } else {
      d = d + 4 * (x - y) + 10;
      y--;
    }
    x++;
  }
}

void bresenham_draw_circle_filled(int xc, int yc, int r,
                                  void (*draw_pixel)(int, int)) {
  for (int i = 0; i <= r; i++) {
    bresenham_draw_circle(xc, yc, i, draw_pixel);
  }
}

void bresenham_draw_semi_circle_left(int xc, int yc, int r,
                                     void (*draw_pixel)(int, int)) {
  int x = 0;
  int y = r;
  int d = 3 - 2 * r;

  while (x <= y) {
    draw_pixel(xc - x, yc + y);
    draw_pixel(xc - x, yc - y);
    draw_pixel(xc - y, yc + x);
    draw_pixel(xc - y, yc - x);
    if (d <= 0) {
      d = d + 4 * x + 6;
    } else {
      d = d + 4 * (x - y) + 10;
      y--;
    }
    x++;
  }
}

void bresenham_draw_semi_circle_right(int xc, int yc, int r,
                                      void (*draw_pixel)(int, int)) {
  int x = 0;
  int y = r;
  int d = 3 - 2 * r;

  while (x <= y) {
    draw_pixel(xc + x, yc + y);
    draw_pixel(xc + x, yc - y);
    draw_pixel(xc + y, yc + x);
    draw_pixel(xc + y, yc - x);
    if (d <= 0) {
      d = d + 4 * x + 6;
    } else {
      d = d + 4 * (x - y) + 10;
      y--;
    }
    x++;
  }
}
