// Copyright (c) 2018 Weyr Software
#pragma once
#include "Window.h"

class ColorHelper final
{
public:
	ColorHelper();
	//ColorHelper() = delete;
	ColorHelper(const ColorHelper&) = delete;
	ColorHelper& operator=(const ColorHelper&) = delete;
	ColorHelper(ColorHelper&&) = delete;
	ColorHelper& operator=(ColorHelper&&) = delete;
	~ColorHelper();
	//~ColorHelper() = default;
	//
	static const viMathSDK::_sVector4 Black;
	static const viMathSDK::_sVector4 White;
	static const viMathSDK::_sVector4 Red;
	static const viMathSDK::_sVector4 Green;
	static const viMathSDK::_sVector4 Blue;
	static const viMathSDK::_sVector4 Yellow;
	static const viMathSDK::_sVector4 BlueGreen;
	static const viMathSDK::_sVector4 Purple;
	static const viMathSDK::_sVector4 CornflowerBlue;
	static const viMathSDK::_sVector4 Wheat;
	static const viMathSDK::_sVector4 LightGray;
	//
	static viMathSDK::_sVector4 viRandomColor();
private:
	static std::random_device sDevice;
	static std::default_random_engine sGenerator;
	static std::uniform_real_distribution<float> sDistribution;
};

