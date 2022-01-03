/*
** EPITECH PROJECT, 2021
** DAY13
** File description:
** window.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

struct framebuffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
};
typedef struct framebuffer framebuffer_t;

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);

void my_put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y, sfColor color);


int main()
{
    sfVideoMode mode = {800, 600, 32}; // 32 bits == 4 octets
    sfRenderWindow *window;
    sfTexture *texture;
    sfEvent event;
    sfSprite *sprite;

    window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
    texture = sfTexture_create(800, 600);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
            if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
                sfRenderWindow_close(window);
            }
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }

    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);
    return 0;
}
