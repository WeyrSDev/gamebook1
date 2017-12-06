// Copyright (c) 2018 Weyr Software
#include "Snake.h"
//
Snake::Snake(int p_BlockSize, TextBox* p_Log) 
{
	m_Log = p_Log;
	m_Size = p_BlockSize;
	m_BodyRect.setSize(sf::Vector2f(m_Size - 1, m_Size - 1));
	viReset();
}
//
Snake::~Snake() 
{
}
//
void Snake::viSetDirection(eDirection p_Dir)
{
	m_Dir = p_Dir;
}
//
eDirection Snake::viGetDirection()
{
	return m_Dir;
}
//
int Snake::viGetSpeed()
{
	return m_Speed;
}
//
sf::Vector2i Snake::viGetPosition()
{
	return (!m_SnakeBody.empty() ? m_SnakeBody.front().position : sf::Vector2i(1, 1));
}
//
int Snake::viGetLives()
{
	return m_Lives;
}
//
int Snake::viGetScore()
{
	return m_Score;
}
//
void Snake::viIncreaseScore()
{
	m_Score += 1;
	m_Log->viAdd("You ate an apple. Score: " + std::to_string((long long)m_Score));
}

bool Snake::viHasLost()
{
	return m_Lost;
}
//
void Snake::viLose()
{
	m_Lost = true;
}

void Snake::ToggleLost()
{
	m_Lost = !m_Lost;
}
//
eDirection Snake::viGetPhysicalDirection()
{
	if (m_SnakeBody.size() <= 1)
	{
		return eDirection::eNone;
	}
	_sSnakeSegment& head = m_SnakeBody[0];
	_sSnakeSegment& neck = m_SnakeBody[1];

	if (head.position.x == neck.position.x) 
	{
		return (head.position.x > neck.position.y ? eDirection::eDown : eDirection::eUp);
	}
	else if (head.position.y == neck.position.y) 
	{
		return (head.position.x > neck.position.x ? eDirection::eRight : eDirection::eLeft);
	}
	return eDirection::eNone;
}
//
void Snake::viExtend()
{
	if (m_SnakeBody.empty()) 
	{ 
		return;
	}
	_sSnakeSegment& tail_head = m_SnakeBody[m_SnakeBody.size() - 1];
	//
	if (m_SnakeBody.size() > 1)
	{
		_sSnakeSegment& tail_bone = m_SnakeBody[m_SnakeBody.size() - 2];
		//
		if (tail_head.position.x == tail_bone.position.x)
		{
			if (tail_head.position.y > tail_bone.position.y) 
			{
				m_SnakeBody.push_back(_sSnakeSegment(tail_head.position.x, tail_head.position.y + 1));
			}
			else 
			{
				m_SnakeBody.push_back(_sSnakeSegment(tail_head.position.x, tail_head.position.y - 1));
			}
		}
		else if (tail_head.position.y == tail_bone.position.y) 
		{
			if (tail_head.position.x > tail_bone.position.x)
			{
				m_SnakeBody.push_back(_sSnakeSegment(tail_head.position.x + 1, tail_head.position.y));
			}
			else 
			{
				m_SnakeBody.push_back(_sSnakeSegment(tail_head.position.x - 1, tail_head.position.y));
			}
		}
	}
	else 
	{
		if (m_Dir == eDirection::eUp) 
		{
			m_SnakeBody.push_back(_sSnakeSegment(tail_head.position.x, tail_head.position.y + 1));
		}
		else if (m_Dir == eDirection::eDown)
		{
			m_SnakeBody.push_back(_sSnakeSegment(tail_head.position.x, tail_head.position.y - 1));
		}
		else if (m_Dir == eDirection::eLeft)
		{
			m_SnakeBody.push_back(_sSnakeSegment(tail_head.position.x + 1, tail_head.position.y));
		}
		else if (m_Dir == eDirection::eRight)
		{
			m_SnakeBody.push_back(_sSnakeSegment(tail_head.position.x - 1, tail_head.position.y));
		}
	}

}
//
void Snake::viReset()
{
	m_SnakeBody.clear();
	m_SnakeBody.push_back(_sSnakeSegment(5, 7));
	m_SnakeBody.push_back(_sSnakeSegment(5, 6));
	m_SnakeBody.push_back(_sSnakeSegment(5, 5));
	//
	viSetDirection(eDirection::eNone);
	//
	m_Speed = 15;
	m_Lives = 3;
	m_Score = 0;
	m_Lost = false;
}
//
void Snake::viMove()
{
	for (int i = m_SnakeBody.size() - 1; i > 0; --i)
	{
		m_SnakeBody[i].position = m_SnakeBody[i - 1].position;
	}
	if (m_Dir == eDirection::eLeft) 
	{
		--m_SnakeBody[0].position.x;
	}
	else if (m_Dir == eDirection::eRight)
	{
		++m_SnakeBody[0].position.x;
	}
	else if (m_Dir == eDirection::eUp)
	{
		--m_SnakeBody[0].position.y;
	}
	else if (m_Dir == eDirection::eDown)
	{
		++m_SnakeBody[0].position.y;
	}

}
//
void Snake::viTick()
{
	if (m_SnakeBody.empty()) 
	{ 
		return; 
	}
	if (m_Dir == eDirection::eNone) 
	{ 
		return; 
	}
	viMove();
	viCheckCollision();
}
//
void Snake::viCut(int p_Segments)
{
	for (int i = 0; i < p_Segments; ++i) 
	{
		m_SnakeBody.pop_back();
	}
	--m_Lives;
	if (!m_Lives)
	{ 
		viLose(); return; 
	}
	m_Log->viAdd("You have lost a life! Lives left: " + std::to_string((long long)m_Lives));
}
//
void Snake::viRender(sf::RenderWindow & p_Window)
{
	if (m_SnakeBody.empty())
	{ 
		return; 
	}

	auto head = m_SnakeBody.begin();
	m_BodyRect.setFillColor(sf::Color::Red);
	m_BodyRect.setPosition(head->position.x * m_Size,head->position.y * m_Size);
	p_Window.draw(m_BodyRect);

	m_BodyRect.setFillColor(sf::Color::Green);
	for (auto itr = m_SnakeBody.begin() + 1;
		itr != m_SnakeBody.end(); ++itr) 
	{
		m_BodyRect.setPosition(itr->position.x * m_Size,itr->position.y * m_Size);
		p_Window.draw(m_BodyRect);
	}
}
//
void Snake::viCheckCollision()
{
	if (m_SnakeBody.size() < 5) 
	{ 
		return; 
	}
	_sSnakeSegment& head = m_SnakeBody.front();
	//
	for (auto itr = m_SnakeBody.begin() + 1;
		itr != m_SnakeBody.end(); ++itr)
	{
		if (itr->position == head.position) 
		{
			int segments = m_SnakeBody.end() - itr;
			viCut(segments);
			break;
		}
	}
}