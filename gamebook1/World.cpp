// Copyright (c) 2018 Weyr Software
#include "World.h"
//
World::World(sf::Vector2u p_WorldSize)
{
	m_BlockSize = 16;
	m_WindowSize = p_WorldSize;
	//
	viRespawnApple();
	//
	m_AppleShape.setFillColor(sf::Color::Yellow);
	m_AppleShape.setRadius(m_BlockSize / 2.0f);
	//
	for (int i = 0; i < 4; ++i) 
	{
		m_Bounds[i].setFillColor(sf::Color::White);
		if (!((i + 1) % 2)) 
		{
			m_Bounds[i].setSize(sf::Vector2f(m_WindowSize.x, m_BlockSize));
		}
		else 
		{
			m_Bounds[i].setSize(sf::Vector2f(m_BlockSize, m_WindowSize.y));
		}
		if (i < 2) 
		{
			m_Bounds[i].setPosition(0, 0);
		}
		else 
		{
			m_Bounds[i].setOrigin(m_Bounds[i].getSize());
			m_Bounds[i].setPosition(sf::Vector2f(m_WindowSize));
		}
	}
}
//
World::~World() 
{
}
//
int World::viGetBlockSize()
{
	return m_BlockSize;
}
//
void World::viRespawnApple()
{
	int maxX = (m_WindowSize.x / m_BlockSize) - 2;
	int maxY = (m_WindowSize.y / m_BlockSize) - 2;
	m_Item = sf::Vector2i(rand() % maxX + 1, rand() % maxY + 1);
	m_AppleShape.setPosition(m_Item.x * m_BlockSize, m_Item.y * m_BlockSize);
}
//
void World::viUpdate(Snake & p_Player)
{
	if (p_Player.viGetPosition() == m_Item)
	{
		p_Player.viExtend();
		p_Player.viIncreaseScore();
		viRespawnApple();
	}
	//
	int gridSize_x = m_WindowSize.x / m_BlockSize;
	int gridSize_y = m_WindowSize.y / m_BlockSize;
	//
	if (p_Player.viGetPosition().x <= 0 ||
		p_Player.viGetPosition().y <= 0 ||
		p_Player.viGetPosition().x >= gridSize_x - 1 ||
		p_Player.viGetPosition().y >= gridSize_y - 1)
	{
		p_Player.viLose();
	}
}
//
void World::viRender(sf::RenderWindow & p_Window)
{
	for (int i = 0; i < 4; ++i) 
	{
		p_Window.draw(m_Bounds[i]);
	}
	p_Window.draw(m_AppleShape);
}