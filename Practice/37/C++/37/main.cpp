#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
double sqr(double a);
bool equal(double a, double b, double e = 1E-10);
class Point {
    enum system_coord{Cartesian, Polar};
    double a1, a2;
    system_coord coord_system;
    std::string thing;
public:
    Point(double x1 = 0, double y2 = 0, system_coord coord_system = Cartesian) {
        this->a1 = x1;
        this->a2 = y2;
        this->coord_system = coord_system;
    }

    bool operator ==( Point& other) {

        double x1, y1, x2, y2;

        x1=get_x();
        y1= get_y();

        x2=other.get_x();
        y2=other.get_y();

        if(fabs(x1-x2)<10e-10 && fabs(y1-y2)<10e-10) return true;
        return false;
    }

    bool operator !=( Point& other) {
        return !(*this == other);
    }

    friend std::istream& operator >> (std::istream &what, Point &that){
        std::string::size_type sz;
        what >> that.thing;
        std::string os= that.thing;
        that.a1 = std::stod(os.substr(os.find('(',0)+1,os.find(',',0)-1),&sz);
        that.a2 = std::stod(os.substr(os.find(',',0)+1,os.find(')',0)-1),&sz);
        that.coord_system = Cartesian;
        what.unget();
        return what;
    }

    friend std::ostream& operator << (std::ostream &what,Point &that){
        std::cout << '('<<that.a1 << ','<<that.a2 << ')' ;
        return what;
    }

     double get_x(){
        if (coord_system == Cartesian) {
            return a1;
        }
        return get_r()*cos(get_phi());
    }
    double get_y(){
        if (coord_system == Cartesian) {
            return a2;
        }
        return get_r()*sin(get_phi());
    }
    double get_r(){
        if (coord_system == Polar) {
            return a1;
        }
        return hypot(a1, a2);
    }
    double get_phi(){
        if (coord_system == Polar) {
            return a2;
        }
        return atan2(a2, a1);
    }
    void set_x(double x){
        if (coord_system == Cartesian) {
            a1 = x;
            return;
        }

        double y = get_y();
        a1 = x;
        a2 = y;
        coord_system = Cartesian;
    }
    void set_y(double y){
        if (coord_system == Cartesian) {
            a2 = y;
            return;
        }

        double x = get_x();
        a1 = x;
        a2 = y;
        coord_system = Cartesian;
    }
    void set_r(double r){
            if (coord_system == Polar) {
                a1 = r;
                return;
            }

            double phi = get_phi();
            a1 = r;
            a2 = phi;
            coord_system = Polar;
        }
    void set_phi(double phi){
        if (coord_system == Polar) {
            a2 = phi;
            return;
        }

        double r = get_r();
        a1 = r;
        a2 = phi;
        coord_system = Polar;
    }
};
class Vector {
    vector<double> V{1,0};
    public:
        Vector (){
            this->V={1,0};
        }
        Vector( Point end){
            this->V[0]=end.get_x();
            this->V[1]=end.get_y();
        }
        Vector(Point begin, Point end){
            this->V[0] = end.get_x()-begin.get_x();
            this->V[1]= end.get_y()-begin.get_y();
        }
        bool operator == (Vector other){
            return (this->V==other.V);
        }
        Vector operator -(){
            Vector s;
            s.V[0]=-1*this->V[0];
            s.V[1]=-1*this->V[1];
            return s;
        }
        Vector operator +(Vector other){
            Vector o;
            o.V[0]=this->V[0]+other.V[0];
            o.V[1]=this->V[1]+other.V[1];
            return o;
        }
        Vector operator -(Vector other){
            Vector l;
            l.V[0]=this->V[0]-other.V[0];
            l.V[1]=this->V[1]-other.V[1];
            return l;
        }
        Vector operator *(double num){
            Vector o;
            o.V[0]=this->V[0]*num;
            o.V[1]=this->V[1]*num;
            return o;
        }
        double length(){
            return (hypot(this->V[0],this->V[1]));
        }
        double operator *(Vector right){
            double H;
            H=hypot(this->V[0],this->V[1])*hypot(right.V[0],right.V[1])*((this->V[0]*right.V[0]+this->V[1]*right.V[1])/(hypot(this->V[0],this->V[1])*hypot(right.V[0],right.V[1])));
            return H;
        }
};
int main()
{
    Vector a(Point(1, 2)), b(Point(-2, 0), Point(-1, 2));
    if (a == b && b == a) cout << "Equality test passed\n";
    else cout << "Equality test failed\n";

    Vector na(Point(-1, -2)), ox(Point(1, 0)), nox(Point(-1, 0)), oy(Point(0, 1)), noy(Point(0, -1));
    if (a == -na && na == -a && -ox == nox && -oy == noy) cout << "Invert test passed\n";
    else cout << "Invert test failed\n";

    if (ox + oy + oy == a && -ox == -a + oy + oy) cout << "Summation test passed\n";
    else cout << "Summation test failed\n";

    if (-ox + oy == oy - ox && -oy + ox == ox - oy) cout << "Subtraction test passed\n";
    else cout << "Subtraction test failed\n";

    if (ox * 3 == ox + ox + ox &&
        oy * 3 == oy + oy + oy &&
        ox * (-3) == -ox - ox - ox &&
        oy * (-3) == -oy - oy - oy) cout << "Multiplication by number test passed\n";
    else cout << "Multiplication by number test failed\n";

    if (equal(ox.length(), 1) &&
        equal(oy.length(), 1) &&
        equal((ox * 3 + oy * 4).length(), 5)) cout << "Length test passed\n";
    else cout << "Length test failed\n";

    if (equal(ox*ox, sqr(ox.length())) &&
        equal(oy*oy, sqr(oy.length())) &&
        equal((ox*3 + oy*4)*(ox*3 + oy*4), sqr((ox*3 + oy*4).length()))) cout << "Multiplication by Vector test passed\n";
    else cout << "Multiplication by Vector test failed\n";
}

bool equal(double a, double b, double e) {
    if (-e < a - b && a - b < e) return true;
    else return false;
}

double sqr(double a) {
    return a * a;
}
