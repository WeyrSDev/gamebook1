// Copyright (c) 2018 Weyr Software
#pragma once
#include "Window.h"
#include "World.h"
#include "Snake.h"
#include "TextBox.h"
#include "ColorHelper.h"
#include "MathHelper.h"
//
class Game 
{
public:
	Game();
	//Game() = delete;
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	Game(Game&&) = delete;
	Game& operator=(Game&&) = delete;
	~Game();
	//~Game() = default;
	//
	void viHandleInput();
	void viUpdate();
	void viRender();
	Window* viGetWindow();
	sf::Time viGetElapsed();
	void viRestartClock();
private:
	Window m_Window;
	sf::Clock m_SystemClock;
	float m_ElapsedTime;
	World m_World;
	Snake m_Snake;
	TextBox m_TextBox;
};