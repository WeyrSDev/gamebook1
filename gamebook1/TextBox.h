// Copyright (c) 2018 Weyr Software
#pragma once
#include "Window.h"
#include "ColorHelper.h"
//
using MessageContainer = std::vector<std::string>;
//
class TextBox
{
public:
	TextBox();
	//TextBox() = delete;
	TextBox(const TextBox&) = delete;
	TextBox& operator=(const TextBox&) = delete;
	TextBox(TextBox&&) = delete;
	TextBox& operator=(TextBox&&) = delete;
	TextBox(int p_Visible, int p_CharSize, int p_Width, sf::Vector2f p_ScreenPos);
	~TextBox();
	//~TextBox() = default;
	//
	void viSetup(int p_Visible, int p_CharSize,int p_Width, sf::Vector2f p_ScreenPos);
	void viAdd(std::string p_Message);
	void viClear();
	void viRender(sf::RenderWindow& p_Window);
private:
	MessageContainer m_Messages;
	int m_NumVisible;
	sf::RectangleShape m_Backdrop;
	sf::Font m_Font;
	sf::Text m_Content;
};