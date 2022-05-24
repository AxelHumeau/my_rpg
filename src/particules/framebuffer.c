/*
** EPITECH PROJECT, 2022
** framebuffer
** File description:
** Blank
*/

#include "my_rpg.h"
#include "particles.h"
#include "stdlib.h"

sfUint8 *cmaker(unsigned char r, unsigned char g, unsigned char b)
{
    sfUint8 *clr = malloc(sizeof(sfUint8) * 4);

    clr[0] = r;
    clr[1] = g;
    clr[2] = b;
    clr[3] = 255;
    return clr;
}

int my_ppixel(fbr_t *fbuffer, unsigned int x, unsigned int y, sfUint8 *clr)
{
    if (x > WIDTH - 1 || y > HEIGHT - 1 || x < 1 || y < 1)
        return (84);
    fbuffer->pixels[4 * (y * fbuffer->width + x)] = clr[0];
    fbuffer->pixels[4 * (y * fbuffer->width + x) + 1] = clr[1];
    fbuffer->pixels[4 * (y * fbuffer->width + x) + 2] = clr[2];
    fbuffer->pixels[4 * (y * fbuffer->width + x) + 3] = clr[3];
    return (0);
}

fbr_t *create_framebuffer(unsigned int width, unsigned int height)
{
    fbr_t *framebuffer = malloc(sizeof(fbr_t));

    framebuffer->width = width;
    framebuffer->height = height;
    framebuffer->pixels = malloc(width * height * 4);
    framebuffer->texture = sfTexture_create(width, height);
    framebuffer->sprite = sfSprite_create();
    clear_framebuffer(framebuffer);
    return framebuffer;
}

void clear_framebuffer(fbr_t *framebuffer)
{
    for (int i = 3; i < framebuffer->width * framebuffer->height * 4; i += 4)
        framebuffer->pixels[i] = 0;
}

void destroy_framebuffer(fbr_t *fbuffer)
{
    free(fbuffer->pixels);
    sfSprite_destroy(fbuffer->sprite);
    sfTexture_destroy(fbuffer->texture);
    free(fbuffer);
}
