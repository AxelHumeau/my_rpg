/*
** EPITECH PROJECT, 2022
** World of Washcraft
** File description:
** draw_lines
*/

#include "particles.h"
#include <math.h>

static void exchange_point(sfVector2i *point_a, sfVector2i *point_b,
sfVector2i *tmp)
{
    if (point_a->x > point_b->x) {
        *point_a = *point_b;
        *point_b = *tmp;
        *tmp = *point_a;
    }
}

static int draw_line_vertical(fbr_t *framebuffer, sfVector2i point_a,
sfVector2i point_b, sfUint8 *color)
{
    float a;
    float b;
    sfVector2i tmp = point_a;
    int step = 1;

    a = (point_b.y - point_a.y) / (float) (point_b.x - point_a.x);
    b = point_b.y - a * point_b.x;
    if (point_b.y - point_a.y < 0)
        step = -1;
    for (int i = 0; i < fabs(point_b.y - point_a.y); i++) {
        my_ppixel(framebuffer, tmp.x, tmp.y, color);
        tmp.y += step;
        tmp.x = (tmp.y - b) / a;
    }
    return (0);
}

static int draw_line_only_vertical(fbr_t *framebuffer, sfVector2i point_a,
sfVector2i point_b, sfUint8 *color)
{
    sfVector2i tmp = point_a;
    int step = 1;

    if (point_b.y - point_a.y < 0)
        step = -1;
    for (int i = 0; i < fabs(point_b.y - point_a.y); i++) {
        my_ppixel(framebuffer, tmp.x, tmp.y, color);
        tmp.y += step;
    }
    return (0);
}

int draw_line(fbr_t *framebuffer, sfVector2i point_a,
sfVector2i point_b, sfUint8 *color)
{
    float a_b[2] = {0, 0};
    sfVector2i tmp = point_a;

    exchange_point(&point_a, &point_b, &tmp);
    if (point_a.x == point_b.x && point_a.y == point_b.y)
        return (my_ppixel(framebuffer, tmp.x, tmp.y, color));
    a_b[0] = (point_b.y - point_a.y) / (float)(point_b.x - point_a.x);
    if (point_a.x == point_b.x) {
        draw_line_only_vertical(framebuffer, point_a, point_b, color);
        return (0);
    } else if (a_b[0] > 1 || a_b[0] < -1) {
        draw_line_vertical(framebuffer, point_a, point_b, color);
        return (0);
    }
    a_b[1] = point_b.y - a_b[0] * point_b.x;
    for (int i = 0; i < point_b.x - point_a.x; i++, tmp.x++) {
        my_ppixel(framebuffer, tmp.x, tmp.y, color);
        tmp.y = a_b[0] * tmp.x +a_b[1];
    }
    return (0);
}
