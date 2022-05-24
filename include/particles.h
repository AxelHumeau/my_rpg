/*
** EPITECH PROJECT, 2022
** particles
** File description:
** Blank
*/

#ifndef MY_RPG_PARTICLES_H
    #define MY_RPG_PARTICLES_H

    #include <SFML/Graphics.h>

typedef struct framebuffer {
    unsigned int width;
    unsigned int height;
    sfTexture *texture;
    sfSprite *sprite;
    sfUint8 *pixels;
} fbr_t;

fbr_t *create_framebuffer(unsigned int width, unsigned int height);
void clear_framebuffer(fbr_t *framebuffer);
void destroy_framebuffer(fbr_t *fbuffer);

sfUint8 *cmaker(unsigned char r, unsigned char g, unsigned char b);
int my_ppixel(fbr_t *fbuffer, unsigned int x, unsigned int y, sfUint8 *clr);
int my_psquare(fbr_t *fbuffer, unsigned int x, unsigned int y, int size);

int draw_line(fbr_t *framebuffer, sfVector2i point_a,
sfVector2i point_b, sfUint8 *color);
#endif //MY_RPG_PARTICLES_H
