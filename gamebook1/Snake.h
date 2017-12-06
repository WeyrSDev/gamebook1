// Copyright (c) 2018 Weyr Software
#pragma once
#include "Window.h"
#include "TextBox.h"
//
struct _sSnakeSegment 
{
	_sSnakeSegment(int p_XPos, int p_YPos) : position(p_XPos, p_YPos) 
	{
	}
	sf::Vector2i position;
};
//
using SnakeContainer = std::vector<_sSnakeSegment>;
//
enum class eDirection 
{ 
	eNone, eUp, eDown, eLeft, eRight 
};
//
class Snake 
{
public:
	Snake();
	//Snake() = delete;
	Snake(const Snake&) = delete;
	Snake& operator=(const Snake&) = delete;
	Snake(Snake&&) = delete;
	Snake& operator=(Snake&&) = delete;
	Snake(int p_BlockSize, TextBox* p_Log);
	~Snake();
	//~Snake() = default;
	//
	void viSetDirection(eDirection p_Dir);
	eDirection viGetDirection();
	int viGetSpeed();
	sf::Vector2i viGetPosition();
	int viGetLives();
	int viGetScore();
	void viIncreaseScore();
	bool viHasLost();
	void viLose();
	void ToggleLost();
	eDirection viGetPhysicalDirection();
	void viExtend();
	void viReset();
	void viMove();
	void viTick();
	void viCut(int p_Segments);
	void viRender(sf::RenderWindow& p_Window);
private:
	void viCheckCollision();
	//
	SnakeContainer m_SnakeBody;
	int m_Size;
	eDirection m_Dir;
	int m_Speed;
	int m_Lives;
	int m_Score; 
	bool m_Lost;
	sf::RectangleShape m_BodyRect;
	TextBox* m_Log;
};