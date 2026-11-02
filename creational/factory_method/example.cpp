#include <iostream>
#include <memory>

class Transport {
public:
    virtual ~Transport() = default;
    virtual void deliver() const = 0;
};

class Truck final : public Transport {
public:
    void deliver() const override {
        std::cout << "Delivering by road with a truck.\n";
    }
};

class Ship final : public Transport {
public:
    void deliver() const override {
        std::cout << "Delivering by sea with a ship.\n";
    }
};

class Logistics {
public:
    virtual ~Logistics() = default;

    void planDelivery() const {
        auto transport = createTransport();
        transport->deliver();
    }

protected:
    virtual std::unique_ptr<Transport> createTransport() const = 0;
};

class RoadLogistics final : public Logistics {
protected:
    std::unique_ptr<Transport> createTransport() const override {
        return std::make_unique<Truck>();
    }
};

class SeaLogistics final : public Logistics {
protected:
    std::unique_ptr<Transport> createTransport() const override {
        return std::make_unique<Ship>();
    }
};

void arrangeDelivery(const Logistics& logistics) {
    logistics.planDelivery();
}

int main() {
    RoadLogistics road;
    SeaLogistics sea;

    arrangeDelivery(road);
    arrangeDelivery(sea);
}
