
/**********************************************************************
 * Name: Kyle Karthauser
 * Date: 1/28/18
 * Description: 
 * This function takes a double variable as input                    *
 * (time in seconds) and returns the distance an object               *
 * would fall due to earth's gravity. It uses 9.8 as                  *
 * the gravitational constant G                                       *
 * ******************************************************************/
double fallDistance(double time){
    const double G = 9.8; // Gravitational constant
    double distance;

    distance = .5*G*pow(time, 2);
    return distance;
}