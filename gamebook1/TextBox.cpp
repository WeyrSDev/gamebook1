// Copyright (c) 2018 Weyr Software
#include "TextBox.h"
//
TextBox::TextBox()
{
	viSetup(5, 9, 200, sf::Vector2f(0, 0));
}
//
TextBox::TextBox(int p_Visible, int p_CharSize,int p_Width, sf::Vector2f p_ScreenPos)
{
	viSetup(p_Visible, p_CharSize, p_Width, p_ScreenPos);
}
//
TextBox::~TextBox()
{ 
	viClear();
}
//
void TextBox::viSetup(int p_Visible, int p_CharSize, int p_Width, sf::Vector2f p_ScreenPos)
{
	m_NumVisible = p_Visible;
	sf::Vector2f offset(2.0f, 2.0f);
	m_Font.loadFromFile("arial.ttf");
	m_Content.setFont(m_Font);
	m_Content.setString("");
	m_Content.setCharacterSize(p_CharSize);
	m_Content.setColor(sf::Color::Red);
	m_Content.setPosition(p_ScreenPos + offset);
	m_Backdrop.setSize(sf::Vector2f(p_Width, (p_Visible * (p_CharSize * 1.2f))));
	m_Backdrop.setFillColor(sf::Color(90, 90, 90, 90));
	m_Backdrop.setPosition(p_ScreenPos);
}
//
void TextBox::viAdd(std::string p_Message)
{
	m_Messages.push_back(p_Message);
	if (m_Messages.size() < 6)
	{
		return; 
	}
	m_Messages.erase(m_Messages.begin());
}
//
void TextBox::viClear()
{
	m_Messages.clear();
}
//
void TextBox::viRender(sf::RenderWindow & p_Window)
{
	std::string content;
	//
	for (auto &itr : m_Messages) 
	{
		content.swap(itr + "\n");
	}
	//
	if (content != "") 
	{
		m_Content.setString(content);
		p_Window.draw(m_Backdrop);
		p_Window.draw(m_Content);
	}

}