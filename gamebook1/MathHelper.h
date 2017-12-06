// Copyright (c) 2018 Weyr Software
#pragma once
#include "Window.h"
//
class Matrix4Helper final
{
public:
	Matrix4Helper();
	//Matrix4Helper() = delete;
	Matrix4Helper(const Matrix4Helper&) = delete;
	Matrix4Helper& operator=(const Matrix4Helper&) = delete;
	Matrix4Helper(Matrix4Helper&&) = delete;
	Matrix4Helper& operator=(Matrix4Helper&&) = delete;
	~Matrix4Helper();
	//~Matrix4Helper() = default;
	//
	static void viGetForward(viMathSDK::_sMatrix4& p_Matrix, viMathSDK::_sVector3& p_Vector);
	static void viGetUp(viMathSDK::_sMatrix4& p_Matrix, viMathSDK::_sVector3& p_Vector);
	static void viGetRight(viMathSDK::_sMatrix4& p_Matrix, viMathSDK::_sVector3& p_Vector);
	static void viGetTranslation(viMathSDK::_sMatrix4& p_Matrix, viMathSDK::_sVector3& p_Vector);
	static void viSetForward(viMathSDK::_sMatrix4& p_Matrix, viMathSDK::_sVector3& p_Forward);
	static void viSetUp(viMathSDK::_sMatrix4& p_Matrix, viMathSDK::_sVector3& p_Up);
	static void viSetRight(viMathSDK::_sMatrix4& p_Matrix, viMathSDK::_sVector3& p_Right);
	static void viSetTranslation(viMathSDK::_sMatrix4& p_Matrix, viMathSDK::_sVector3& p_Translation);
};
//
class Vector2Helper final
{
public:
	Vector2Helper();
	//Vector2Helper() = delete;
	Vector2Helper(const Vector2Helper&) = delete;
	Vector2Helper& operator=(const Vector2Helper&) = delete;
	Vector2Helper(Vector2Helper&&) = delete;
	Vector2Helper& operator=(Vector2Helper&&) = delete;
	~Vector2Helper();
	//~Vector2Helper() = default;
	//
	static const viMathSDK::_sVector2 Zero;
	static const viMathSDK::_sVector2 One;
	static const viMathSDK::_sVector2 Forward;
	static const viMathSDK::_sVector2 Backward;
	static const viMathSDK::_sVector2 Up;
	static const viMathSDK::_sVector2 Down;
	static const viMathSDK::_sVector2 Right;
	static const viMathSDK::_sVector2 Left;
	//
	static std::string viToString(const viMathSDK::_sVector2& p_Vector);
};
//
class Vector3Helper final
{
public:
	Vector3Helper();
	//Vector3Helper() = delete;
	Vector3Helper(const Vector3Helper&) = delete;
	Vector3Helper& operator=(const Vector3Helper&) = delete;
	Vector3Helper(Vector3Helper&&) = delete;
	Vector3Helper& operator=(Vector3Helper&&) = delete;
	~Vector3Helper();
	//~Vector3Helper() = default;
	//
	static const viMathSDK::_sVector3 Zero;
	static const viMathSDK::_sVector3 One;
	static const viMathSDK::_sVector3 Forward;
	static const viMathSDK::_sVector3 Backward;
	static const viMathSDK::_sVector3 Up;
	static const viMathSDK::_sVector3 Down;
	static const viMathSDK::_sVector3 Right;
	static const viMathSDK::_sVector3 Left;
	//
	static std::string viToString(const viMathSDK::_sVector3& p_Vector);
};
//
class Vector4Helper final
{
public:
	Vector4Helper();
	//Vector4Helper() = delete;
	Vector4Helper(const Vector4Helper&) = delete;
	Vector4Helper& operator=(const Vector4Helper&) = delete;
	Vector4Helper(Vector4Helper&&) = delete;
	Vector4Helper& operator=(Vector4Helper&&) = delete;
	~Vector4Helper();
	//~Vector4Helper() = default;
	//
	static const viMathSDK::_sVector4 Zero;
	static const viMathSDK::_sVector4 One;
	//
	static std::string viToString(const viMathSDK::_sVector4& p_Vector);
};
