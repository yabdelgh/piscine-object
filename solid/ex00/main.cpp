#include "Car.hpp"

int main() {
    Car myCar;

    std::cout << "=== Starting Car ===" << std::endl;
    myCar.start();
    std::cout << "Engine status: " << (myCar.engine_running() ? "Running" : "Off") << std::endl;

    std::cout << "\n=== Accelerating ===" << std::endl;
    myCar.accelerate(160);
    std::cout << "Current speed: " << myCar.current_speed() << " km/h" << std::endl;

    std::cout << "\n=== Shifting Gears ===" << std::endl;
    myCar.shift_gears_up();
    myCar.shift_gears_up();
    std::cout << "Current gear: " << myCar.current_gear() << std::endl;

    std::cout << "\n=== Steering ===" << std::endl;
    myCar.turn_wheel(45);
    std::cout << "Wheel angle: " << myCar.wheel_angle() << " degrees" << std::endl;

    std::cout << "\n=== Braking ===" << std::endl;
    myCar.apply_force_on_brakes(50);
    // std::cout << "Brake force applied: " << myCar.brake_force() << "%" << std::endl;
    std::cout << "Speed after braking: " << myCar.current_speed() << " km/h" << std::endl;

    std::cout << "\n=== Emergency Stop ===" << std::endl;
    myCar.apply_emergency_brakes();
    // std::cout << "Brake force: " << myCar.brake_force() << "%" << std::endl;
    std::cout << "Speed after emergency stop: " << myCar.current_speed() << " km/h" << std::endl;

    std::cout << "\n=== Stopping Car ===" << std::endl;
    myCar.stop();
    std::cout << "Engine status: " << (myCar.engine_running() ? "Running" : "Off") << std::endl;
    // std::cout << "Brake force: " << myCar.brake_force() << "%" << std::endl;

    std::cout << "\n=== Reverse Gear ===" << std::endl;
    myCar.reverse();
    std::cout << "In reverse: " << (myCar.in_reverse() ? "Yes" : "No") << std::endl;

    return 0;
}