// Copyright (c) 2018 Weyr Software
#pragma once
#include <string>
#include <random>
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <Kairos.hpp>
#include <pugixml.hpp>
#include <TLFXEffectsLibrary.h>
#include <TLFXParticleManager.h>
#include <TLFXEffect.h>
#include <viMathLib.h>

class Window 
{
public:
	Window();
	//Window() = delete;
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;
	Window(Window&&) = delete;
	Window& operator=(Window&&) = delete;
	Window(const std::string& p_Title, const sf::Vector2u& p_Size);
	~Window();
	//~Window() = default;
	//
	void viBeginDraw();
	void viEndDraw();
	void viUpdate();
	bool viIsDone();
	bool viIsFullscreen();
	sf::Vector2u viGetWindowSize();
	sf::RenderWindow* viGetRenderWindow();
	void viToggleFullscreen();
	void viDraw(sf::Drawable& p_Drawable);
private:
	void viSetup(const std::string p_Title, const sf::Vector2u& p_Size);
	void viCreate();
	void viDestroy();
	//
	sf::RenderWindow m_Window;
	sf::Vector2u m_WindowSize;
	std::string m_WindowTitle;
	bool m_IsDone;
	bool m_IsFullscreen;
};