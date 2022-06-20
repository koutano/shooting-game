#pragma once

//�ʓx�@ => �x���@
#define RadToDeg(rad) (rad * 180.0f / 3.14f)
//�x���@ => �ʓx�@
#define DegToRad(deg) (deg / 180.0f * 3.14f)

//float x,y�̃����o�����\����
struct Vector2
{
	Vector2() :
		x(0),
		y(0)
	{
	}

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


	Vector2& operator + (float val)
	{
		this->x += val;
		this->y += val;
		return *this;
	}

	Vector2& operator - (float val)
	{

		this->x -= val;
		this->y -= val;
		return *this;
	}

	Vector2& operator * (float val)
	{
		this->x *= val;
		this->y *= val;
		return *this;
	}

	Vector2& operator / (float val)
	{
		this->x /= val;
		this->y /= val;
		return *this;
	}

	Vector2& operator + (Vector2 val)
	{
		this->x += val.x;
		this->y += val.y;
		return *this;
	}

	Vector2& operator - (Vector2 val)
	{
		this->x -= val.x;
		this->y -= val.y;
		return *this;
	}

	Vector2& operator * (Vector2 val)
	{
		this->x *= val.x;
		this->y *= val.y;
		return *this;
	}

	Vector2& operator / (Vector2 val)
	{
		this->x /= val.x;
		this->y /= val.y;
		return *this;
	}
};

//float x,y,z�̃����o�����\����
struct Vector3
{
	Vector3() :
		x(0),
		y(0),
		z(0)
	{
	}

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


	Vector3& operator + (float val)
	{
		this->x += val;
		this->y += val;
		this->z += val;
		return *this;
	}

	Vector3& operator - (float val)
	{

		this->x -= val;
		this->y -= val;
		this->z -= val;
		return *this;
	}

	Vector3& operator * (float val)
	{
		this->x *= val;
		this->y *= val;
		this->z *= val;
		return *this;
	}

	Vector3& operator / (float val)
	{
		this->x /= val;
		this->y /= val;
		this->z /= val;
		return *this;
	}

	Vector3& operator + (Vector3 val)
	{
		this->x += val.x;
		this->y += val.y;
		this->z += val.z;
		return *this;
	}

	Vector3& operator - (Vector3 val)
	{
		this->x -= val.x;
		this->y -= val.y;
		this->z -= val.z;
		return *this;
	}

	Vector3& operator * (Vector3 val)
	{
		this->x *= val.x;
		this->y *= val.y;
		this->z *= val.z;
		return *this;
	}

	Vector3& operator / (Vector3 val)
	{
		this->x /= val.x;
		this->y /= val.y;
		this->z /= val.z;
		return *this;
	}

};

//�x�N�g���̒�����Ԃ��֐�(Vector2�p)
float Norm(Vector2 vec);

//�x�N�g���̒�����Ԃ��֐�(Vector3�p)
float Norm(Vector3 vec);

//��_�Ԃ̍��W�̒��������߂�֐�(Vector2�p)
float Length(Vector2 pos1, Vector2 pos2);

//��_�Ԃ̍��W�̒��������߂�֐�(Vector3�p)
float Length(Vector3 pos1, Vector3 pos2);

//�P�ʃx�N�g�������߂�֐�(Vector2�p)
Vector2 Normalize(Vector2 vec);

//�P�ʃx�N�g�������߂�֐�(Vector3�p)
Vector3 Normalize(Vector3 vec);
