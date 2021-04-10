
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


