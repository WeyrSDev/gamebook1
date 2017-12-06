// Copyright (c) 2018 Weyr Software
#include "Window.h"

Window::Window() 
{ 
	viSetup("Window", sf::Vector2u(640, 480)); 
}

Window::Window(const std::string& p_Title, const sf::Vector2u& p_Size)
{ 
	viSetup(p_Title, p_Size);
}

Window::~Window() 
{
	viDestroy(); 
}

void Window::viSetup(const std::string p_Title, const sf::Vector2u& p_Size)
{
	m_WindowTitle = p_Title;
	m_WindowSize = p_Size;
	m_IsFullscreen = false;
	m_IsDone = false;
	m_Window.setFramerateLimit(60);
	viCreate();
}

void Window::viCreate() 
{
	auto style = (m_IsFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
	m_Window.create({ m_WindowSize.x, m_WindowSize.y, 32 }, m_WindowTitle, style);
}

void Window::viDestroy() 
{
	m_Window.close();
}

void Window::viBeginDraw() 
{ 
	m_Window.clear(sf::Color::Black);
}

void Window::viEndDraw() 
{ 
	m_Window.display();
}

bool Window::viIsDone() 
{ 
	return m_IsDone;
}

bool Window::viIsFullscreen() 
{ 
	return m_IsFullscreen;
}

void Window::viDraw(sf::Drawable& p_Drawable)
{
	m_Window.draw(p_Drawable);
}

sf::Vector2u Window::viGetWindowSize() 
{ 
	return m_WindowSize;
}

sf::RenderWindow* Window::viGetRenderWindow()
{
	return &m_Window;
}

void Window::viToggleFullscreen()
{
	m_IsFullscreen = !m_IsFullscreen;
	viDestroy();
	viCreate();
}

void Window::viUpdate() 
{
	sf::Event event;
	while (m_Window.pollEvent(event)) 
	{
		if (event.type == sf::Event::Closed)
		{
			m_IsDone = true;
		}
		else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		{ 
			m_IsDone = true; 
		}
		else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5)
		{ 
			viToggleFullscreen(); 
		}
	}

}