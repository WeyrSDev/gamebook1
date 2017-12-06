// Copyright (c) 2018 Weyr Software
#pragma once
#include "Window.h"
#include "Snake.h"
//
class World 
{
public:
	//World();
	//World() = delete;
	World(const World&) = delete;
	World& operator=(const World&) = delete;
	World(World&&) = delete;
	World& operator=(World&&) = delete;
	World(sf::Vector2u p_WorldSize);
	~World();
	//~World() = default;
	//
	int viGetBlockSize();
	void viRespawnApple();
	void viUpdate(Snake& p_Player);
	void viRender(sf::RenderWindow& p_Window);
private:
	sf::Vector2u m_WindowSize;
	sf::Vector2i m_Item;
	int m_BlockSize;
	sf::CircleShape m_AppleShape;
	sf::RectangleShape m_Bounds[4];
};