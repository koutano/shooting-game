#include"Mathematics.h"
#include<math.h>

float Norm(Vector2 vec)
{
	return sqrtf(vec.x * vec.x + vec.y * vec.y);
}

float Norm(Vector3 vec)
{
	return sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

float Length(Vector2 pos1, Vector2 pos2) 
{
	pos1 -= pos2;
	return Norm(pos1);
}

float Length(Vector3 pos1, Vector3 pos2)
{
	pos1 -= pos2;
	return Norm(pos1);
}

Vector2 Normalize(Vector2 vec)
{
	return vec /= Norm(vec);
}

Vector3 Normalize(Vector3 vec)
{
	return vec /= Norm(vec);
}

