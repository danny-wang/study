/* 
 * File:   Noisy.h
 * Author: danny
 *
 * Created on April 22, 2015, 10:12 AM
 */

#ifndef NOISY_H
#define	NOISY_H
#include <iostream>
class Noisy {
private:
    static long create, assign, copycons, destroy;
    long id;
public:
    Noisy():id(create++)
    {
        std::cout<<"d["<<id<<"]";
        
    }
    Noisy(const Noisy& orig):id(orig.id)
    {
        std::cout<<"c["<<id<<"]";
        copycons++;
    }

    Noisy& operator=(const Noisy& rv) 
    {
        std::cout << "(" << id << ")=[" <<
                rv.id << "]";
        id = rv.id;
        assign++;
        return *this;
    }

    friend bool
    operator<(const Noisy& lv, const Noisy& rv) 
    {
        return lv.id < rv.id;
    }

    friend bool
    operator==(const Noisy& lv, const Noisy& rv) 
    {
        return lv.id == rv.id;
    }
    ~Noisy()
    {
        std::cout<<"~["<<id<<"]";
        destroy++;
    }
    friend std::ostream&
    operator<<(std::ostream &os, const Noisy &n)
    {
        return os<<n.id;
    }
    friend class NoisyReport;

};

/*struct NoisyGen
{
       Noisy operator()() { return Noisy(); }
};
*/
#endif	/* NOISY_H */

