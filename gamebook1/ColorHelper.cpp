// Copyright (c) 2018 Weyr Software
#include "ColorHelper.h"
//
std::random_device ColorHelper::sDevice;
std::default_random_engine ColorHelper::sGenerator(sDevice());
std::uniform_real_distribution<float> ColorHelper::sDistribution(0, 1);
//
const viMathSDK::_sVector4 ColorHelper::Black = viMathSDK::_sVector4(0.0f, 0.0f, 0.0f, 1.0f);
const viMathSDK::_sVector4 ColorHelper::White = viMathSDK::_sVector4(1.0f, 1.0f, 1.0f, 1.0f);
const viMathSDK::_sVector4 ColorHelper::Red = viMathSDK::_sVector4(1.0f, 0.0f, 0.0f, 1.0f);
const viMathSDK::_sVector4 ColorHelper::Green = viMathSDK::_sVector4(0.0f, 1.0f, 0.0f, 1.0f);
const viMathSDK::_sVector4 ColorHelper::Blue = viMathSDK::_sVector4(0.0f, 0.0f, 1.0f, 1.0f);
const viMathSDK::_sVector4 ColorHelper::Yellow = viMathSDK::_sVector4(1.0f, 1.0f, 0.0f, 1.0f);
const viMathSDK::_sVector4 ColorHelper::BlueGreen = viMathSDK::_sVector4(0.0f, 1.0f, 1.0f, 1.0f);
const viMathSDK::_sVector4 ColorHelper::Purple = viMathSDK::_sVector4(1.0f, 0.0f, 1.0f, 1.0f);
const viMathSDK::_sVector4 ColorHelper::CornflowerBlue = viMathSDK::_sVector4(0.392f, 0.584f, 0.929f, 1.0f);
const viMathSDK::_sVector4 ColorHelper::Wheat = viMathSDK::_sVector4(0.961f, 0.871f, 0.702f, 1.0f);
const viMathSDK::_sVector4 ColorHelper::LightGray = viMathSDK::_sVector4(0.5f, 0.5f, 0.5f, 1.0f);
//
viMathSDK::_sVector4 ColorHelper::viRandomColor()
{
	float r = sDistribution(sGenerator);
	float g = sDistribution(sGenerator);
	float b = sDistribution(sGenerator);

	return viMathSDK::_sVector4(r, g, b, 1.0f);
}