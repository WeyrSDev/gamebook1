// Copyright (c) 2018 Weyr Software
#include "Game.h"

Game::Game() : m_Window("Snakes on a Rampage", sf::Vector2u(800, 600)), 
             m_Snake(m_World.viGetBlockSize(), &m_TextBox), m_World(sf::Vector2u(800, 600))
{
	m_SystemClock.restart();
	srand(time(nullptr));
	m_TextBox.viSetup(5, 10, 350, sf::Vector2f(225, 300));
	m_ElapsedTime = 0.0f;
	m_TextBox.viAdd("Seeded random number generator with: " + std::to_string(time(nullptr)));
}

Game::~Game() 
{ 
}

sf::Time Game::viGetElapsed() 
{ 
	return m_SystemClock.getElapsedTime();
}

void Game::viRestartClock() 
{ 
	m_ElapsedTime += m_SystemClock.restart().asSeconds();
}

Window* Game::viGetWindow() 
{ 
	return &m_Window;
}

void Game::viHandleInput()
{
	// Input handling.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_Snake.viGetPhysicalDirection() != eDirection::eDown)
	{
		m_Snake.viSetDirection(eDirection::eUp);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_Snake.viGetPhysicalDirection() != eDirection::eUp)
	{
		m_Snake.viSetDirection(eDirection::eDown);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_Snake.viGetPhysicalDirection() != eDirection::eRight)
	{
		m_Snake.viSetDirection(eDirection::eLeft);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && m_Snake.viGetPhysicalDirection() != eDirection::eLeft)
	{
		m_Snake.viSetDirection(eDirection::eRight);
	}

}

void Game::viUpdate()
{
	m_Window.viUpdate();
	float timestep = 1.0f / m_Snake.viGetSpeed();
	//
	if (m_ElapsedTime >= timestep)
	{
		m_Snake.viTick();
		m_World.viUpdate(m_Snake);
		m_ElapsedTime -= timestep;
		if (m_Snake.viHasLost())
		{
			m_TextBox.viAdd("GAME OVER! Score: " + std::to_string((long long)m_Snake.viGetScore()));
			m_Snake.viReset();
		}
	}
}

void Game::viRender() 
{
	m_Window.viBeginDraw();
	//
	m_World.viRender(*m_Window.viGetRenderWindow());
	m_Snake.viRender(*m_Window.viGetRenderWindow());
	m_TextBox.viRender(*m_Window.viGetRenderWindow());
	//
	m_Window.viEndDraw();
}
