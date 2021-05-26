//
//  GameState.hpp
//  Projekt
//
//  Created by Michał Wołoszyński on 23/05/2021.
//  Copyright © 2021 KACPER. All rights reserved.
//

#ifndef GameState_hpp
#define GameState_hpp


#include "State.hpp"
#include "Player.hpp"

const int MAX_NUMBER_OF_ITEMS3 = 3;

using namespace std;
using namespace sf;

class GameState : public State{
public:
    GameState(sf::RenderWindow* window, std::stack<State*>* states);
    ~GameState();
    
    void drawText();
    void MoveUp();
    void MoveDown();
    int getPressedItem() {return selectedItemIndex;}
    
    
    void initGui();
    void keyboardInput();
    void update();
    void update(sf::Event ev);
    void render(sf::RenderTarget* target=nullptr);
    void endState();
private:
    int selectedItemIndex;
    sf::Font font;
    //sf::Text menu[MAX_NUMBER_OF_ITEMS];
    
    sf::Text text[3];
    
    Player player;
    
    Player *p = new Player();
    
    sf::RectangleShape background;

};

#endif /* GameState_hpp */
