/*********************************************************************
** Author: Scott Hung
** Date: 4-29-2018
** Description: this is the implementation file for the setTime
                function

*********************************************************************/

#include "timeset.hpp"

/*********************************************************************
** Description: ensures that each time a roll is made, the number is
                random and each time this program is run, the numbers
                that appear will be different.
*********************************************************************/
void setTime(){

    srand(time(0));

}
