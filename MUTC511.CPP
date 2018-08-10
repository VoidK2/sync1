#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const double eps = 1e-8;
const double PI = atan(1.0) * 4;

struct Point
{
    double x, y;
    inline Point(double x = 0, double y = 0) :x(x), y(y) {}
};

typedef Point Vector;

struct Circle
{
    Point c;
    double r;
    inline Circle(const Point &c, const double r) :c(c), r(r) {}
    inline Point point(const double a) const { return Point(c.x + cos(a)*r, c.y + sin(a)*r); }
};
int dcmp(double x) { if (fabs(x) < eps) return 0; else return x < 0 ? -1 : 1; }

Vector operator + (const Vector &A, const Vector &B) { return Vector(A.x + B.x, A.y + B.y); }
Vector operator - (const Vector &A, const Vector &B) { return Vector(A.x - B.x, A.y - B.y); }
Vector operator * (const Vector &A, const double p) { return Vector(A.x*p, A.y*p); }
Vector operator / (const Vector &A, const double p) { return Vector(A.x / p, A.y / p); }
bool operator < (const Point &a, const Point &b) { return a.x < b.x || (dcmp(a.x - b.x) == 0 && a.y < b.y); }
bool operator == (const Point &a, const Point &b) { return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0; }

double Dot(const Vector &A, const Vector &B) { return A.x*B.x + A.y*B.y; }

double Length(const Vector &A) { return sqrt(Dot(A, A)); }

double angle(const Vector &v) { return atan2(v.y, v.x); }

double Angle(const Vector &A, const Vector &B) { return acos(Dot(A, B) / Length(A) / Length(B)); }

int Get_Circle_CircleIntersection(const Circle &C1, const Circle &C2, vector<Point>&sol)//圆与圆求交点
{
    double d = Length(C1.c - C2.c);
    if (dcmp(d) == 0)
    {
        if (dcmp(C1.r - C2.r) == 0) return -1;
        return 0;
    }
    if (dcmp(C1.r + C2.r - d) < 0) return 0;
    if (dcmp(fabs(C1.r - C2.r) - d) > 0) return 0;
    double a = angle(C2.c - C1.c);
    double da = acos((C1.r*C1.r + d*d - C2.r*C2.r) / (2 * C1.r*d));//C1C2到C1P1的角
    Point p1 = C1.point(a - da), p2 = C1.point(a + da);
    sol.push_back(p1);
    if (p1 == p2) return 1;
    sol.push_back(p2);
    return 2;
}

double Cross(const Vector &A, const Vector &B) { return A.x*B.y - A.y*B.x; }

double Distance_To_Line(const Point &P, const Point &A, const Point &B)//点到直线的距离
{
    Vector v1 = B - A, v2 = P - A;
    return fabs(Cross(v1, v2) / Length(v1));
}

double Distance_To_Point(const Point &a, const Point &b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T --)
    {
        int m, R;
        scanf("%d%d", &m, &R);
        Circle dayuan = Circle(Point(0, 0), R);
        double S = 2 * PI * R;
        while(m --)
        {
            int x, y, r;
            scanf("%d%d%d", &x, &y, &r);
            vector<Point> vec;
            Circle cnow = Circle(Point(x, y), r);
            if(Get_Circle_CircleIntersection(dayuan, cnow, vec) == 1)
            {
                double RL = Distance_To_Point(dayuan.c, vec[0]);
                double rL = Distance_To_Point(cnow.c, vec[0]);
                double c2c = Distance_To_Point(cnow.c, dayuan.c);
                if(dcmp(RL + rL - c2c) != 0)
                    S += 2 * PI * r;
            }
            else if(Get_Circle_CircleIntersection(dayuan, cnow, vec) == 2)
            {
                double RL = Distance_To_Line(dayuan.c, vec[0], vec[1]);
                double rL = Distance_To_Line(cnow.c, vec[0], vec[1]);
                double c2c = Distance_To_Point(dayuan.c, cnow.c);
                double jiaodu = Angle(vec[0]-cnow.c, vec[1]-cnow.c);
                double djiaodu = Angle(vec[0]-dayuan.c, vec[1]-dayuan.c);

                if(dcmp(RL + rL - c2c) == 0)
                {
                    S -= djiaodu * R;
                    S += jiaodu * r;
                }
                else if(dcmp(RL - rL - c2c) == 0)
                {
                    S -= djiaodu * R;
                    S += 2*PI*r - jiaodu * r;
                }
                else if(dcmp(rL - RL - c2c) == 0)
                {
                    S -= 2*PI*R - djiaodu * R;
                    S += jiaodu * r;
                }
            }
        }
        printf("%.20f\n", S);
    }
    return 0;
}