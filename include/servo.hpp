#ifndef servo_hpp
#define servo_hpp
#include <ESP32Servo.h>
#include <HXCthread.hpp>
#define SERVO_PIN 2        // 舵机连接引脚
#define DEGREES 50        // 舵机旋转的最大角度
#define DELAY_TIME 1000      // 控制舵机移动的延时


Servo myservo;  // 创建一个舵机对象

//这个函数用于实现舵机的相关功能
class servo_func{
    public:
    void servo_opendoor(){
        // 指纹识别成功，执行开门操作
        // 控制舵机从 0 度转到指定角度（例如 50 度）
        for (int pos = 0; pos <= DEGREES; pos++) {
            myservo.write(pos);
            delay(10);
        }
        delay(DELAY_TIME);  // 适当延时确保舵机完成移动
        // 舵机从指定角度转回 0 度
        for (int pos = DEGREES; pos >= 0; pos--) {
            myservo.write(pos);
            delay(10);
        }
    }
};

#endif