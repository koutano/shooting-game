#pragma once

//弧度法 => 度数法
#define RadToDeg(rad) (rad * 180.0f / 3.14f)
//度数法 => 弧度法
#define DegToRad(deg) (deg / 180.0f * 3.14f)

//float x,yのメンバを持つ構造体
struct Vector2
{
	//デフォルトコンストラクタ
	Vector2() :
		x(0),
		y(0)
	{
	}

	/*
		初期値設定用コンストラクタ
	*/
	Vector2(float x_, float y_) :
		x(x_),
		y(y_)
	{
	}

	float x;
	float y;

	Vector2& operator += (float val)
	{
		this->x += val;
		this->y += val;
		return *this;
	}

	Vector2& operator -= (float val)
	{

		this->x -= val;
		this->y -= val;
		return *this;
	}

	Vector2& operator *= (float val)
	{
		this->x *= val;
		this->y *= val;
		return *this;
	}

	Vector2& operator /= (float val)
	{
		this->x /= val;
		this->y /= val;
		return *this;
	}


	Vector2& operator += (Vector2 val)
	{
		this->x += val.x;
		this->y += val.y;
		return *this;
	}

	Vector2& operator -= (Vector2 val)
	{
		this->x -= val.x;
		this->y -= val.y;
		return *this;
	}

	Vector2& operator *= (Vector2 val)
	{
		this->x *= val.x;
		this->y *= val.y;
		return *this;
	}

	Vector2& operator /= (Vector2 val)
	{
		this->x /= val.x;
		this->y /= val.y;
		return *this;
	}


	Vector2 operator + (const float& val)const
	{
		Vector2 returnVal{ this->x + val,this->y + val };
		return returnVal;
	}

	Vector2 operator - (const float& val)const
	{
		Vector2 returnVal{ this->x - val,this->y - val };
		return returnVal;
	}

	Vector2 operator * (const float& val)const
	{
		Vector2 returnVal{ this->x * val,this->y * val };
		return returnVal;
	}

	Vector2 operator / (const float& val)const
	{
		Vector2 returnVal{ this->x / val,this->y / val };
		return returnVal;
	}

	Vector2 operator + (const Vector2& val)const
	{
		Vector2 returnVal{ this->x + val.x,this->y + val.y };
		return returnVal;
	}

	Vector2 operator - (const Vector2& val)const
	{
		Vector2 returnVal{ this->x - val.x,this->y - val.y };
		return returnVal;
	}

	Vector2 operator * (const Vector2& val)const
	{
		Vector2 returnVal{ this->x * val.x,this->y * val.y };
		return returnVal;
	}

	Vector2 operator / (const Vector2& val)const
	{
		Vector2 returnVal{ this->x / val.x,this->y / val.y };
		return returnVal;
	}
};

//float x,y,zのメンバを持つ構造体
struct Vector3
{
	/*
		デフォルトコンストラクタ
	*/
	Vector3() :
		x(0),
		y(0),
		z(0)
	{
	}

	/*
		初期値設定用コンストラクタ
	*/
	Vector3(float x_, float y_, float z_) :
		x(x_),
		y(y_),
		z(z_)
	{
	}

	float x;
	float y;
	float z;

	Vector3 &operator += (float val)
	{
		this->x += val;
		this->y += val;
		this->z += val;
		return *this;
	}

	Vector3 &operator -= (float val)
	{

		this->x -= val;
		this->y -= val;
		this->z -= val;
		return *this;
	}

	Vector3 &operator *= (float val)
	{
		this->x *= val;
		this->y *= val;
		this->z *= val;
		return *this;
	}

	Vector3& operator /= (float val)
	{
		this->x /= val;
		this->y /= val;
		this->z /= val;
		return *this;
	}

	Vector3 &operator += (Vector3 val)
	{
		this->x += val.x;
		this->y += val.y;
		this->z += val.z;
		return *this;
	}

	Vector3 &operator -= (Vector3 val)
	{
		this->x -= val.x;
		this->y -= val.y;
		this->z -= val.z;
		return *this;
	}

	Vector3 &operator *= (Vector3 val)
	{
		this->x *= val.x;
		this->y *= val.y;
		this->z *= val.z;
		return *this;
	}

	Vector3& operator /= (Vector3 val)
	{
		this->x /= val.x;
		this->y /= val.y;
		this->z /= val.z;
		return *this;
	}


	Vector3 operator + (const float& val)const
	{
		Vector3 returnVal{ this->x + val,this->y + val ,this->z + val };
		return returnVal;
	}

	Vector3 operator - (const float& val)const
	{
		Vector3 returnVal{ this->x - val,this->y - val ,this->z - val };
		return returnVal;
	}

	Vector3 operator * (const float& val)const
	{
		Vector3 returnVal{ this->x * val,this->y * val ,this->z * val };
		return returnVal;
	}

	Vector3 operator / (const float& val)const
	{
		Vector3 returnVal{ this->x / val,this->y / val ,this->z / val };
		return returnVal;
	}

	Vector3 operator + (const Vector3& val)const
	{
		Vector3 returnVal{ this->x + val.x,this->y + val.y ,this->z + val.z };
		return returnVal;
	}

	Vector3 operator - (const Vector3& val)const
	{
		Vector3 returnVal{ this->x - val.x,this->y - val.y ,this->z - val.z };
		return returnVal;
	}

	Vector3 operator * (const Vector3& val)const
	{
		Vector3 returnVal{ this->x * val.x,this->y * val.y ,this->z * val.z };
		return returnVal;
	}

	Vector3 operator / (const Vector3& val)const
	{
		Vector3 returnVal{ this->x / val.x,this->y / val.y ,this->z / val.z };
		return returnVal;
	}
};

//ベクトルの長さを返す関数(Vector2用)
float Norm(Vector2 vec);

//ベクトルの長さを返す関数(Vector3用)
float Norm(Vector3 vec);

//二点間の座標の長さを求める関数(Vector2用)
float Length(Vector2 pos1, Vector2 pos2);

//二点間の座標の長さを求める関数(Vector3用)
float Length(Vector3 pos1, Vector3 pos2);

//単位ベクトルを求める関数(Vector2用)
Vector2 Normalize(Vector2 vec);

//単位ベクトルを求める関数(Vector3用)
Vector3 Normalize(Vector3 vec);
