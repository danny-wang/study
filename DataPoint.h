/* 
 * File:   DataPoint.h
 * Author: danny
 *
 * Created on April 16, 2015, 5:27 PM
 */

#ifndef DATAPOINT_H
#define	DATAPOINT_H
#include <iostream>
#include <ctime>
class DataPoint {
    std::tm time; // Time & day
    static const int bsz = 10;
    // Ascii degrees (*) minutes (') seconds ("):
    char latitude[bsz], longitude[bsz];
    double depth, temperature;
public:
    std::tm getTime();
    void setTime(std::tm t);
    const char* getLatitude();
    void setLatitude(const char* l);
    const char* getLongitude();
    void setLongitude(const char* l);
    double getDepth();
    void setDepth(double d);
    double getTemperature();
    void setTemperature(double t);
    void print(std::ostream& os);

};

#endif	/* DATAPOINT_H */

