#include <iostream>

using namespace std;


template <class T>
class vec3
{
public:
	vec3() {}
	vec3(T x, T y, T z) { _x = x; _y = y; _z = z; }
	vec3(const vec3& v) { _x = v._x; _y = v._y; _z = v._z; }

	vec3 operator+(const vec3& v) {
		return vec3(_x + v._x, _y + v._y, _z + v._z);
	}

	vec3 operator-(const vec3& v) {
		return vec3(_x - v._x, _y - v._y, _z - v._z);
	}


	void operator+=(const vec3& v) {
		_x += v.x;
		_y += v.y;
		_z += v.z;
	}

	void operator-=(const vec3& v) {
		_x -= v.x;
		_y -= v.y;
		_z -= v.z;
	}

	void operator=(const vec3& v) {
		_x = v._x;
		_y = v._y;
		_z = v._z;
	}

	bool operator==(const vec3& v1) { return v1._x == _x && v1._y == _y && v1._z == _z; }


	//methods
	void Normalize() {

		T mag = sqrt((_x * _x) + (_y * _y) + (_z * _z));

		if (mag != 0) {
			_x = _x / mag;
			_y = _y / mag;
			_z = _z / mag;
		}

	}

	void Zero() {
		_x = _y = _z = 0;
	}

	bool isZero() {
		return _x == _y == _z == 0;
	}


	int DistanceTo(const vec3 &v) {
		T x,y,z;
		x = v._x - _x;
		y = v._y - _y;
		z = v._z - _z;


		return sqrt((x * x) + (y * y) + (z * z));
	}

private:
	T _x, _y, _z;

};

int main() {

	vec3 <int>a;
	vec3 <int>b(1, 2, 3);
	vec3 <int>c(5, 5, 5);
	vec3 <int>d(c);

	cout << c.DistanceTo(b);

	c.Normalize();
	b.isZero();



	system("pause");
	return 0;

}