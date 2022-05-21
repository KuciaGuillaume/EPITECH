/*
** EPITECH PROJECT, 2021
** template
** File description:
** template
*/

#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "../../engine/Engine.hpp"
extern "C" {
  #include "../../../../corewar/include/corewar.h"
}

namespace cg
{
    class GameScene : public Scene {
      private:
        std::shared_ptr<TextComponent> selectedByte;
        corewar_t *corewar;

      public:
        GameScene(
            corewar_t *corewar, int id_, std::string name_ = std::string("Default Scene Name"))
            : Scene(id_, name_), corewar(corewar)
        {
            selectedByte = nullptr;
        }

        int onUpdate(sf::RenderWindow &window);

        void onInit(sf::RenderWindow &window);

        void onChange();

        void onDelete();

        int onEvent(sf::Event event);

        void fillChampionsProperties();

        void fillVmProperties();

    };
} // namespace cg

#endif // GAMESCENE_H