#include <cmath>
#include "../header/sphere.hpp"

sphere::sphere(){}
sphere::sphere(vp center, double r, px k_a, px k_d, px k_s, double s) : center(center), radio(r), object(k_a, k_d, k_s, s){}

std::tuple<double, double> sphere::intersection_with_ray(vp O, vp D){
    vp CO = O - this->center;

    double a = D*D;
    double b = 2*(CO*D);
    double c = CO*CO - this->radio*this->radio;
    double delta = b*b - 4*a*c;
    
    if(delta < 0) return {INF, INF};        //there are no intessection
    double t1 = (-b + sqrt(delta))/(2*a);
    double t2 = (-b - sqrt(delta))/(2*a);

    return {t1, t2};
}

vp sphere::normal(vp P){
    return (P-this->get_center())/this->get_radio();
}

//Getters and Setters
vp sphere::get_center(){ return this->center; }
void sphere::set_center(vp center){ this->center = center; }
double sphere::get_radio(){ return this->radio; }
void sphere::set_radio(double radio){ this->radio = radio; }
