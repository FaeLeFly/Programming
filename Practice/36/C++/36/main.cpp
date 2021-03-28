#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

#include <cmath>

const auto PI = 3.141592653589793;

class Point{
    enum system_coord{Cartesian, Polar};
    double a1, a2;
    system_coord coord_system;
    std::string thing;
public:

    Point(double a1 = 0, double a2 = 0, system_coord coord_system = Cartesian) {
        this->a1 = a1;
        this->a2 = a2;
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


int main() {
    std::vector<Point> original;
    std::ifstream fin("data.txt");
    if (!fin.is_open()) {
        std::cout << "Can't open file" << std::endl;
        return 1;
    } else {
        while (!fin.eof()) {
            Point p;
            fin >> p;
            fin.ignore(2);
            original.push_back(p);
        }
        fin.close();
    }

    std::vector<Point> simulacrum(original);
    for (auto& p : simulacrum) {
        std::cout << p;
        p.set_x(p.get_x() + 10);
        p.set_phi(p.get_phi() + 180*PI/180);
        p.set_y(-p.get_y());
        p.set_x(-p.get_x() - 10);
        std::cout << p << std::endl;
    }


    if (std::equal(original.begin(), original.end(), simulacrum.begin()))
        std::cout << "\nIt works!\n";
    else
        std::cout << "\nIt not works!\n";
}
