#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <tuple>
#include "vp.hpp"
#include "px.hpp"

class object{
    private:
        px k_a, k_d, k_s;   //intensity of ambient, difuse ans specular light_reflection
        double specular;    //object's shineness
    
    public:
        object(); 
        object(px k_a, px k_d, px k_s, double specular);
    
        virtual std::tuple<double, double> intersection_with_ray(vp O, vp D) = 0;
        virtual vp normal(vp P) = 0;

        //Getters and Setters
        px get_k_a();
        void set_k_a(px k_a);
        px get_k_d();
        void set_k_d(px k_d);
        px get_k_s();
        void set_k_s(px k_s);
        double get_specular();
        void set_specular(double specular);
};

#endif
