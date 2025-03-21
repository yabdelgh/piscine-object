#ifndef __CAR_HPP__
#define __CAR_HPP__

#include <iostream>

class Engine {
private:
    bool isRunning;
public:
    Engine() : isRunning(false) {}
    
    void start() { isRunning = true; }
    void stop() { isRunning = false; }
    bool isOn() const { return isRunning; }
};

class Transmission {
private:
    int currentGear;
    bool isReverse;
public:
    Transmission() : currentGear(0), isReverse(false) {}
    
    void shift_gears_up() {
        if (!isReverse && currentGear < 5) currentGear++;
    }
    
    void shift_gears_down() {
        if (!isReverse && currentGear > 0) currentGear--;
    }
    
    void reverse() {
        if (isReverse) {
            isReverse = false;
            currentGear = 0;
        } else {
            isReverse = true;
            currentGear = -1;
        }
    }
    
    int get_gear() const { return currentGear; }
    bool in_reverse() const { return isReverse; }
};

class Control {
private:
    int speed;
public:
    Control() : speed(0) {}
    
    void apply_force(int force) { 
        if ((speed * force / 100) > speed)
            speed = 0;
        else
            speed -= (speed * force / 100); 
    }
    void accelerate(int amount) { speed += amount; }
    void apply_emergency_brakes() {  speed = 0; }
    int get_speed() const { return speed; }
};

class Steering {
private:
    int wheelAngle;
public:
    Steering() : wheelAngle(0) {}
    
    void turn_wheel(int angle) { wheelAngle = angle; }
    void straighten_wheels() { wheelAngle = 0; }
    int get_angle() const { return wheelAngle; }
};

class Car {
private:
    Engine engine;
    Transmission transmission;
    Control control;
    Steering steering;

public:
    
    void start() { engine.start(); }
    void stop() {
        engine.stop();
        control.apply_force(70);
    }

    void accelerate(int amount) { control.accelerate(amount); }
    int current_speed() const { return control.get_speed(); }

    void shift_gears_up() { transmission.shift_gears_up(); }
    void shift_gears_down() { transmission.shift_gears_down(); }
    void reverse() { transmission.reverse(); }
    int current_gear() const { return transmission.get_gear(); }
    bool in_reverse() const { return transmission.in_reverse(); }

    void turn_wheel(int angle) { steering.turn_wheel(angle); }
    void straighten_wheels() { steering.straighten_wheels(); }
    int wheel_angle() const { return steering.get_angle(); }

    void apply_force_on_brakes(int force) { control.apply_force(force); }
    void apply_emergency_brakes() { control.apply_emergency_brakes(); }
    bool engine_running() const { return engine.isOn(); }
};

#endif