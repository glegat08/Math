#include <iostream>
#include <cmath>

struct Point
{
	float x, y, z;
};

struct Vector
{
	float x, y, z;
};

struct Lines
{
	Point point;
	Vector direction;
};

Vector Vect_Coor(const Point& a, const Point& b)
{
	Vector resultat;
	resultat.x = b.x - a.x;
	resultat.y = b.y - a.y;
	resultat.z = b.z - a.z;
	return resultat;
}

float Vect_Norm(const Point& a, const Point& b)
{
	Vector v = Vect_Coor(a, b);
	return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

bool Vect_Collinear(const Vector& vec1, const Vector& vec2)
{
	float cross_x = vec1.y * vec2.z - vec1.z * vec2.y;
	float cross_y = vec1.z * vec2.x - vec1.x * vec2.z;
	float cross_z = vec1.x * vec2.y - vec1.y * vec2.x;

	return (fabs(cross_x) < 0.0001 && fabs(cross_y) < 0.0001 && fabs(cross_z) < 0.0001);
}

bool Point_Aligned(const Point& a, const Point& b, const Point& c)
{
	Vector AB = Vect_Coor(a, b);
	Vector AC = Vect_Coor(a, c);
	return Vect_Collinear(AB, AC);
}

bool Lines_Parallel(const Lines& line1, const Lines& line2)
{
	return Vect_Collinear(line1.direction, line2.direction);
}

int main()
{
	std::cout << "=== PROGRAMME DE CALCUL VECTORIEL ===" << std::endl << std::endl;

	std::cout << "Test 1 : Coordonnees d'un vecteur" << std::endl;
	Point A = { 1, 2, 3 };
	Point B = { 4, 6, 8 };
	Vector AB = Vect_Coor(A, B);
	std::cout << "A(" << A.x << "," << A.y << "," << A.z << ")";
	std::cout << " B(" << B.x << "," << B.y << "," << B.z << ")" << std::endl;
	std::cout << "Vecteur AB = (" << AB.x << ", " << AB.y << ", " << AB.z << ")" << std::endl << std::endl;

	std::cout << "Test 2 : Norme d'un vecteur" << std::endl;
	float norme = Vect_Norm(A, B);
	std::cout << "Norme de AB = " << norme << std::endl << std::endl;

	std::cout << "Test 3 : Vecteurs colineaires" << std::endl;
	Vector v1 = { 2, 4, 6 };
	Vector v2 = { 1, 2, 3 };
	std::cout << "v1(" << v1.x << "," << v1.y << "," << v1.z << ")";
	std::cout << " v2(" << v2.x << "," << v2.y << "," << v2.z << ")" << std::endl;
	if (Vect_Collinear(v1, v2))
		std::cout << "Les vecteurs SONT colineaires" << std::endl;
	else
		std::cout << "Les vecteurs NE SONT PAS colineaires" << std::endl;
	std::cout << std::endl;

	std::cout << "Test 4 : Points alignes" << std::endl;
	Point P1 = { 0, 0, 0 };
	Point P2 = { 1, 1, 1 };
	Point P3 = { 2, 2, 2 };
	std::cout << "P1(" << P1.x << "," << P1.y << "," << P1.z << ")";
	std::cout << " P2(" << P2.x << "," << P2.y << "," << P2.z << ")";
	std::cout << " P3(" << P3.x << "," << P3.y << "," << P3.z << ")" << std::endl;
	if (Point_Aligned(P1, P2, P3))
		std::cout << "Les points SONT alignes" << std::endl;
	else
		std::cout << "Les points NE SONT PAS alignes" << std::endl;
	std::cout << std::endl;

	std::cout << "Test 5 : Droites paralleles" << std::endl;
	Lines d1 = { {0, 0, 0}, {1, 2, 4} };
	Lines d2 = { {5, 5, 5}, {2, 4, 6} };
	std::cout << "d1 : point(" << d1.point.x << "," << d1.point.y << "," << d1.point.z << ") | direction(" << d1.direction.x << "," << d1.direction.y << "," << d1.direction.z << ")" << std::endl;
	std::cout << "d2 : point(" << d2.point.x << "," << d2.point.y << "," << d2.point.z << ") | direction(" << d2.direction.x << "," << d2.direction.y << "," << d2.direction.z << ")" << std::endl;
	if (Lines_Parallel(d1, d2))
		std::cout << "Les droites SONT paralleles" << std::endl;
	else
		std::cout << "Les droites NE SONT PAS paralleles" << std::endl;

	return 0;
}