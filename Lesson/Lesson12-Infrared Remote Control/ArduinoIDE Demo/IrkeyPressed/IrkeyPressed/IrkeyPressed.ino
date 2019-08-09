/***********************************************************************
 *       __                                                          _
 *      / /        _____  __    __  _          _   (_)   ________   | |
 *     / /____   / _____) \ \  / / | |   __   | |  | |  (  ______)  | |_____
 *    / / ___/  | |_____   \ \/ /  | |  /  \  | |  | |  | |______   |  ___  |
 *   / /\ \     | |_____|   \  /   | | / /\ \ | |  | |  (_______ )  | |   | |
 *  / /  \ \__  | |_____    / /    | |/ /  \ \| |  | |   ______| |  | |   | |
 * /_/    \___\  \______)  /_/      \__/    \__/   |_|  (________)  |_|   |_|
 *
 *
 * KeyWay Tech firmware
 *
 * Copyright (C) 2015-2020
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, in version 3.
 * learn more you can see <http://www.gnu.org/licenses/>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.
 *
 *
 * [Title]      Infrared transmitter module
 * [Diagram]
 *         Arduino PIN 11   ===================  Infrared transmitter module pin Y
 *         Arduino PIN GND  ===================  Infrared transmitter module pin G
 *         Arduino PIN +5V  ===================  Infrared transmitter module pin R
 */
//本例来自于红外接收模块的IRremote自带范例
//已经作出了修改

/*电路连接
 *红外接收器的VOUT接在数字引脚11上,GND接控制板的GND,VCC接控制板上+5V

*/
#include "IRremote.h"
  
int RECV_PIN = 12; //定义红外接收器的引脚为12

IRrecv irrecv(RECV_PIN);
  
decode_results results;
  
void setup()
{
    Serial.begin(9600);
    irrecv.enableIRIn();     // 初始化红外接收器

}

void loop() {
    if (irrecv.decode(&results)) {
        Serial.println(results.value, HEX);
        irrecv.resume(); // 接收下一个值
    }
    delay(120);
}
