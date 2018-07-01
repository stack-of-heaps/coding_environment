#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal {

    const double BASE_FOOD_COST = 50.00;

    protected:
        int age = 0;
        double cost = 0;
        int babies = 0;
        double food = BASE_FOOD_COST * animalMultiplier * qualityMultiplier;
        double payoff = cost * payoffMultiplier;
        double animalMultiplier = 0.0;  //Each animal consumes a different amount of food
        double qualityMultiplier = 0.0; //food quality multiplier
                                        //.5 is bad quality; 1 is normal; 2 is high
        double payoffMultiplier;

    public:
//        Animal();
        Animal(int a, double c, int b, double aMultiplier, double qMultiplier, double poMultiplier);
        double getBaseFoodCost();
        double getPayoff();
        int getBabies();
        bool isAdult();

        double getFoodQuality();
        double setFoodQualityMultiplier(double qMultiplier);

        double getCost();

        void setAge(int a);

        double feed();

        void info();
};

#endif
