#include<print>

struct Vector
{
	int x, y, z;

	Vector* add(const Vector& vec)
	{
		this->x += vec.x;
		this->y += vec.y;
		this->z += vec.z;

		return this;
	}

	void print()
	{
		std::println("x: {}, y: {}, z: {}", x, y, z);
	}

	bool isLinearlyDependentWith(const Vector& vec)
	{
		return this->x / vec.x == this->y / vec.y && this->x % vec.x == this->y % vec.y
			&& this->y / vec.y == this->z / vec.z && this->y % vec.y == this->z % vec.z;
	}
};

int main()
{
	Vector vec1{ 1, 2, 3 };
	Vector vec2{ 4, 5, 6 };

	vec1.add(vec2);

	vec1.print();

	std::println("{}", vec1.isLinearlyDependentWith(vec2));

	return 0;
}