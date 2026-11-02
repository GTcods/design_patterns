#include <iostream>
#include <optional>
#include <string>
#include <utility>

struct Meal {
    std::string mainCourse;
    std::optional<std::string> side;
    std::optional<std::string> drink;

    void describe() const {
        std::cout << "Meal: " << mainCourse;
        if (side) {
            std::cout << ", " << *side;
        }
        if (drink) {
            std::cout << ", " << *drink;
        }
        std::cout << '\n';
    }
};

class MealBuilder {
public:
    virtual ~MealBuilder() = default;
    virtual void reset() = 0;
    virtual void buildMainCourse() = 0;
    virtual void buildSide() = 0;
    virtual void buildDrink() = 0;
    virtual Meal takeMeal() = 0;
};

class VegetarianMealBuilder final : public MealBuilder {
public:
    void reset() override {
        meal_ = Meal{};
    }

    void buildMainCourse() override {
        meal_.mainCourse = "vegetable curry";
    }

    void buildSide() override {
        meal_.side = "rice";
    }

    void buildDrink() override {
        meal_.drink = "water";
    }

    Meal takeMeal() override {
        return std::exchange(meal_, Meal{});
    }

private:
    Meal meal_;
};

class MealDirector {
public:
    Meal buildFullMeal(MealBuilder& builder) const {
        builder.reset();
        builder.buildMainCourse();
        builder.buildSide();
        builder.buildDrink();
        return builder.takeMeal();
    }
};

int main() {
    VegetarianMealBuilder builder;
    MealDirector director;

    const Meal fullMeal = director.buildFullMeal(builder);
    fullMeal.describe();

    builder.buildMainCourse();
    const Meal mainOnly = builder.takeMeal();
    mainOnly.describe();
}
