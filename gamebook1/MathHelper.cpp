// Copyright (c) 2018 Weyr Software
#include "MathHelper.h"

const viMathSDK::_sVector2 Vector2Helper::Zero = viMathSDK::_sVector2 (0.0f, 0.0f);
const viMathSDK::_sVector2 Vector2Helper::One = viMathSDK::_sVector2(1.0f, 1.0f);
const viMathSDK::_sVector2 Vector2Helper::Forward = viMathSDK::_sVector2(0.0f, -1.0f);
const viMathSDK::_sVector2 Vector2Helper::Backward = viMathSDK::_sVector2(0.0f, 1.0f);
const viMathSDK::_sVector2 Vector2Helper::Right = viMathSDK::_sVector2(-1.0f, 0.0f);
const viMathSDK::_sVector2 Vector2Helper::Left = viMathSDK::_sVector2(1.0f, 0.0f);


std::string Vector2Helper::viToString(const viMathSDK::_sVector2& p_Vector)
{
	std::stringstream stream;

	stream << "{" << p_Vector.x << ", " << p_Vector.y << "}";

	return stream.str();
}

const viMathSDK::_sVector3 Vector3Helper::Zero = viMathSDK::_sVector3(0.0f, 0.0f, 0.0f);
const viMathSDK::_sVector3 Vector3Helper::One = viMathSDK::_sVector3(1.0f, 1.0f, 1.0f);
const viMathSDK::_sVector3 Vector3Helper::Forward = viMathSDK::_sVector3(0.0f, 0.0f, -1.0f);
const viMathSDK::_sVector3 Vector3Helper::Backward = viMathSDK::_sVector3(0.0f, 0.0f, 1.0f);
const viMathSDK::_sVector3 Vector3Helper::Up = viMathSDK::_sVector3(0.0f, 1.0f, 0.0f);
const viMathSDK::_sVector3 Vector3Helper::Down = viMathSDK::_sVector3(0.0f, -1.0f, 0.0f);
const viMathSDK::_sVector3 Vector3Helper::Right = viMathSDK::_sVector3(1.0f, 0.0f, 0.0f);
const viMathSDK::_sVector3 Vector3Helper::Left = viMathSDK::_sVector3(-1.0f, 0.0f, 0.0f);

std::string Vector3Helper::viToString(const viMathSDK::_sVector3& p_Vector)
{
	std::stringstream stream;

	stream << "{" << p_Vector.x << ", " << p_Vector.y << ", " << p_Vector.z << "}";

	return stream.str();
}

const viMathSDK::_sVector4 Vector4Helper::Zero = viMathSDK::_sVector4(0.0f, 0.0f, 0.0f, 0.0f);
const viMathSDK::_sVector4 Vector4Helper::One = viMathSDK::_sVector4(1.0f, 1.0f, 1.0f, 1.0f);

std::string Vector4Helper::viToString(const viMathSDK::_sVector4& p_Vector)
{
	std::stringstream stream;

	stream << "{" << p_Vector.x << ", " << p_Vector.y << ", " << p_Vector.z << ", " << p_Vector.w << "}";

	return stream.str();
}

void Matrix4Helper::viGetForward(viMathSDK::_sMatrix4& p_Matrix, viMathSDK::_sVector3& p_Vector)
{
	viMathSDK::_sVector4 m3 = p_Matrix[2];

	p_Vector.x = -m3.x;
	p_Vector.y = -m3.y;
	p_Vector.z = -m3.z;
}

void Matrix4Helper::viGetUp(viMathSDK::_sMatrix4& p_Matrix, viMathSDK::_sVector3& p_Vector)
{
	viMathSDK::_sVector4 m2 = p_Matrix[1];

	p_Vector.x = m2.x;
	p_Vector.y = m2.y;
	p_Vector.z = m2.z;
}

void Matrix4Helper::viGetRight(viMathSDK::_sMatrix4& p_Matrix, viMathSDK::_sVector3& p_Vector)
{
	viMathSDK::_sVector4 m1 = p_Matrix[0];

	p_Vector.x = m1.x;
	p_Vector.y = m1.y;
	p_Vector.z = m1.z;
}

void Matrix4Helper::viGetTranslation(viMathSDK::_sMatrix4& p_Matrix, viMathSDK::_sVector3& p_Vector)
{
	viMathSDK::_sVector4 m4 = p_Matrix[3];

	p_Vector.x = m4.x;
	p_Vector.y = m4.y;
	p_Vector.z = m4.z;
}

void Matrix4Helper::viSetForward(viMathSDK::_sMatrix4& p_Matrix, viMathSDK::_sVector3& p_Forward)
{
	viMathSDK::_sVector4 m3 = p_Matrix[2];

	m3.x = -p_Forward.x;
	m3.y = -p_Forward.y;
	m3.z = -p_Forward.z;

	p_Matrix[2] = m3;
}

void Matrix4Helper::viSetUp(viMathSDK::_sMatrix4& p_Matrix, viMathSDK::_sVector3& p_Up)
{
	viMathSDK::_sVector4 m2 = p_Matrix[1];

	m2.x = p_Up.x;
	m2.y = p_Up.y;
	m2.z = p_Up.z;

	p_Matrix[1] = m2;
}

void Matrix4Helper::viSetRight(viMathSDK::_sMatrix4& p_Matrix, viMathSDK::_sVector3& p_Right)
{
	viMathSDK::_sVector4 m1 = p_Matrix[0];

	m1.x = p_Right.x;
	m1.y = p_Right.y;
	m1.z = p_Right.z;

	p_Matrix[0] = m1;
}

void Matrix4Helper::viSetTranslation(viMathSDK::_sMatrix4& p_Matrix, viMathSDK::_sVector3& p_Translation)
{
	viMathSDK::_sVector4 m4 = p_Matrix[3];

	m4.x = p_Translation.x;
	m4.y = p_Translation.y;
	m4.z = p_Translation.z;

	p_Matrix[3] = m4;
}
