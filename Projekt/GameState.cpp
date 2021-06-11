//
//  GameState.cpp
//  Projekt
//
//  Created by Michał Wołoszyński on 23/05/2021.
//  Copyright © 2021 KACPER. All rights reserved.
//

#include "GameState.hpp"

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states) : State(window, states)
{
    this->initGui();
    selectedItemIndex = 0;
}

GameState::~GameState()
{
    
}

void GameState::drawText()
{
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS3; i++)
    {
        //window.draw(menu[i]);
    }
}

void GameState::initGui(){
    int width = 200;
    int height = 200;
    

    
    
    
    background.setPosition(100, 100);
    if (!font.loadFromFile(resourcePath() + "space_invaders.ttf"))
    {
        // handle error
    }
    
    text.setFont(font);
    text.setColor(sf::Color::White);
    text.setString("PAUSE");
    text.setCharacterSize(120);
    text.setPosition(300,300);
}

void GameState::MoveUp()
{
//    if (selectedItemIndex - 1 >= 0)
//    {
//        text[selectedItemIndex].setColor(sf::Color::Green);
//        selectedItemIndex--;
//        text[selectedItemIndex].setColor(sf::Color::White);
//    }
}

void GameState::MoveDown()
{
    background.move(0, 0.5f);
}

void GameState::update(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        this->states->push(new Pause(this->window, this->states));
    }
    player.move();
    invs.spawn();
    invs.move();
    invs.colision(player.bullets);
    if(invs.colisionWithP(player.returnPlayer()) == true){
            this->states->push(new GameOver(this->window, this->states));
        }
        if(invs.invadersWin() == true){
            this->states->push(new GameOver(this->window, this->states));
        }
}

void GameState::render(sf::RenderTarget* target){
    if(!target)
        target = this->window;
    
    this->window->clear();
    this->player.draw(target);
    this->invs.draw(target);
    
}

void GameState::endState(){
    
}

void GameState::keyboardInput(){
    p->move();
}
