# Factory Method

Factory Method defines a creation operation in a base class and lets subclasses
choose the concrete product.

`Logistics::planDelivery()` uses the factory method `createTransport()` without
knowing the transport type. `RoadLogistics` creates a `Truck`, while `SeaLogistics`
creates a `Ship`. Both work with the same client function through `Logistics`.

Run from the repository root after building:

```sh
./build/factory_method
```
