/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#include <cstring>
#include <iostream>
#include "../../../include/engine/Engine.hpp"
#include "../../../include/game/Game.hpp"

static const std::string CURSOR = "./bonus/resources/Cursor.png";
static const std::string COREWAR_BACKGROUND =
    "./bonus/resources/CorewarBackground.png";
static const std::string DIOGO_FONT_PATH = "./bonus/resources/diogo.ttf";

void cg::GameScene::fillChampionsProperties()
{
    list_t *champion = this->corewar->champions;
    int y = 200;

    while (champion) {
        std::cout << "champion->name: "
                  << "youhou" << std::endl;
        champion_t *champ = (champion_t *) champion->value;
        std::shared_ptr<cg::TextComponent> nameProp =
            std::make_shared<cg::TextComponent>(
                cg::TextComponent("champ name " + std::string(champ->name),
                    std::string(champ->name), DIOGO_FONT_PATH));
        std::shared_ptr<cg::TextComponent> progNb =
            std::make_shared<cg::TextComponent>(cg::TextComponent("progNb " + std::to_string(champ->id), std::string("0"), DIOGO_FONT_PATH));
        std::shared_ptr<cg::TextComponent> carry =
            std::make_shared<cg::TextComponent>(cg::TextComponent("carry " + std::to_string(champ->id), std::string("1"), DIOGO_FONT_PATH));
        std::shared_ptr<cg::TextComponent> couldown =
            std::make_shared<cg::TextComponent>(cg::TextComponent("couldown " + std::to_string(champ->id), std::string("2"), DIOGO_FONT_PATH));
        std::shared_ptr<cg::TextComponent> registers =
            std::make_shared<cg::TextComponent>(cg::TextComponent("registers " + std::to_string(champ->id), std::string("3"), DIOGO_FONT_PATH));
        std::shared_ptr<cg::TextComponent> live =
            std::make_shared<cg::TextComponent>(cg::TextComponent("live " + std::to_string(champ->id), std::string("4"), DIOGO_FONT_PATH));



        nameProp->setPosition(sf::Vector2f(120, y)); y += 41;
        progNb->setPosition(sf::Vector2f(135, y)); y += 20;
        carry->setPosition(sf::Vector2f(120, y)); y += 20;
        couldown->setPosition(sf::Vector2f(145, y)); y += 20;
        registers->setPosition(sf::Vector2f(145, y)); y += 40;
        live->setPosition(sf::Vector2f(110, y));
        nameProp->setCharacterSize(7);progNb->setCharacterSize(7);
        carry->setCharacterSize(7);couldown->setCharacterSize(7);
        registers->setCharacterSize(7);live->setCharacterSize(7);
        this->addComponent(nameProp);
        this->addComponent(progNb);
        this->addComponent(carry);
        this->addComponent(couldown);
        this->addComponent(registers);
        this->addComponent(live);
        champion = champion->next;
        y += 100;
    }
}

void cg::GameScene::fillVmProperties()
{
    std::shared_ptr<cg::TextComponent> cycleProp =
        std::make_shared<cg::TextComponent>(cg::TextComponent("cycle count prop",
            std::to_string(corewar->vm->cycles), DIOGO_FONT_PATH));
    std::shared_ptr<cg::TextComponent> checkIntervalProp =
        std::make_shared<cg::TextComponent>(cg::TextComponent("check interval prop",
            std::to_string(corewar->vm->check_interval), DIOGO_FONT_PATH));

    cycleProp->setFillColor(sf::Color::White);
    checkIntervalProp->setFillColor(sf::Color::White);
    cycleProp->setCharacterSize(30);
    checkIntervalProp->setCharacterSize(30);
    cycleProp->setPosition(sf::Vector2f(700, 102));
    checkIntervalProp->setPosition(sf::Vector2f(885, 102));
    cycleProp->setOrigin(sf::Vector2f(cycleProp->getLocalBounds().width / 2,
        cycleProp->getLocalBounds().height / 2));
    checkIntervalProp->setOrigin(sf::Vector2f(checkIntervalProp->getLocalBounds().width / 2,
        checkIntervalProp->getLocalBounds().height / 2));
    this->addComponent(cycleProp);
    this->addComponent(checkIntervalProp);
}

void cg::GameScene::onInit(sf::RenderWindow &window)
{
    std::shared_ptr<cg::SpriteComponent> gui =
        std::make_shared<cg::SpriteComponent>(
            cg::SpriteComponent("gui", COREWAR_BACKGROUND));
    gui->setPosition(sf::Vector2f(31, 28));

    std::shared_ptr<cg::SpriteComponent> cursor =
        std::make_shared<cg::SpriteComponent>(
            cg::SpriteComponent("Cursor", CURSOR));
    cursor->setTextureRect(sf::IntRect(0, 0, 22, 31));

    this->addComponent(gui);
    for (int i = 0; i < 96; i++) {
        for (int j = 0; j < 64; j++) {
            std::shared_ptr<cg::TextComponent> byte =
                std::make_shared<cg::TextComponent>(cg::TextComponent(
                    "byte " + std::to_string(i) + ":" + std::to_string(j),
                    "00", DIOGO_FONT_PATH));

            byte->setCharacterSize(8);
            byte->setOutlineColor(sf::Color::White);
            byte->setPosition(
                sf::Vector2f(400 + (i * 15.5), 200 + (j * 13.2)));
            byte->setFillColor(sf::Color(92, 92, 92, 255));
            byte->setOrigin(sf::Vector2f(byte->getLocalBounds().width / 2,
                byte->getLocalBounds().height / 2));
            this->addComponent(byte);
        }
    }
    this->fillChampionsProperties();
    this->fillVmProperties();
    this->addComponent(cursor);
}

int cg::GameScene::onUpdate(sf::RenderWindow &window)
{
    // GET cursor
    std::shared_ptr<cg::SpriteComponent> cursor =
        std::dynamic_pointer_cast<cg::SpriteComponent>(
            this->getComponentFromTag("Cursor"));

    // UPDATE CURSOR
    cursor->setPosition(
        sf::Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y));
    cursor->setTextureRect(sf::IntRect(0, 0, 22, 31));
    return -1;
}
void cg::GameScene::onDelete()
{
}

int cg::GameScene::onEvent(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape)
            exit(0);
    } else if (event.type == sf::Event::MouseButtonPressed) {
        if (selectedByte != nullptr) {
            selectedByte->setFillColor(sf::Color(92, 92, 92, 255));
            selectedByte = nullptr;
        }
        for (const auto &item : getComponents()) {
            if (item.first.find("byte ") != std::string::npos
                && isComponentHovered(item.second)) {
                std::dynamic_pointer_cast<cg::TextComponent>(item.second)
                    ->setFillColor(sf::Color::Red);
                selectedByte =
                    std::dynamic_pointer_cast<cg::TextComponent>(item.second);
            }
        }
    }
    return -1;
}

void cg::GameScene::onChange()
{
}