# Force Car
สำหรับกลุ่มของเรา ได้เขียนโปรแกรมเพื่อควบคุมรถบังคับผ่าน Wifi ด้วยแอพ Blynk บนโทรศัพท์มือถือ มีเสียงเตือนหากใกล้ชน และเราได้เพิ่ม Auto Mode ให้รถบังคับเคลื่อนที่เองโดยไม่ชนสิ่งกีดขวาง โดยใช้ภาษา C ในการเขียนโปรแกรม และใช้ NodeMCU ในการควบคุม

---

# Equipment

* รถ ประกอบด้วย ฐานรถ ล้อรถ 2 ข้าง มอเตอร์ล้อรถ 2 ข้าง ล้อช่วยข้างหน้า สวิตซ์ น็อต มาประกอบกันจนเป็นรถ (จากรูปกลุ่มของเราเปลี่ยนไปใช้รางถ่าน 18650)<br>
![Car](/pic/car.jpg)
* รางถ่าน 18650 - 2 ก้อน<br>
![Rangtan](/pic/rangtan.jpg)
* ถ่านชาร์จ 18650 Panasonic NCR18650B 3.7v 3400mAh 2 ก้อน<br>
![Battery](/pic/bat.jpg)
* Jumper F2F, Jumper M2M, Jumper F2M<br>
![Jumper](/pic/jumper.jpg)
* Motor Driver Module L298N<br>
![MotorModule](/pic/module.jpg)
* NodeMCU V3 CH340G Lua WIFI ESP8266 ESP-12E<br>
![mcu](/pic/nodemcu.jpg)
* NodeMcu Breadboard for NodeMCU V3<br>
![bbmcu](/pic/breadboard.jpg)
* HY-SRF05 SRF05 Ultrasonic Distance Sensor Module<br>
![Censor](/pic/censor.jpg)
* Buzzer Module<br>
![Buzzer](/pic/buzzer.jpg)

---

# Library
* \#include <ESP8266WiFi.h> ทำการติดตั้งลงแพลตฟอร์มในโปรแกรม Arduino
* \#include <NewPing.h> [NewPing](https://bitbucket.org/teckel12/arduino-new-ping/downloads/)
* \#include <BlynkSimpleEsp8266.h> [Blynk](https://github.com/blynkkk/blynk-library/releases/tag/v0.5.2)

---

# Function
* NewPing sonar(TRIG_PIN, ECHO_PIN); // เป็นการประกาศขาของอัลตราโซนิค ที่จะนำมาใช้ในคำสั่งต่างๆของ library NewPing.h
* void setup() // เป็นฟังก์ชันในการเริ่มตั้งค่าเริ่มต้น ของตัวแปรและอุปกรณ์ต่างๆ
* Blynk.begin(auth, ssid, pass); // เป็นการเริ่มใช้งาน blynk application โดยใช้ auth(auth token), ssid(user wifi), pass(password wifi)
* pinMode(pinA1, OUTPUT); // เป็นฟังก์ชันในการกำหนดค่าส่งออก ลงตามขาที่ pin ต่างๆได้ตั้งค่าไว้
* param.asInt() //เป็นคำสั่งการตรวจสอบว่าค่าใน vต่างๆใน blynk application มีการกดหรือไม่
* BLYNK_WRITE(11) // เป็นฟังก์ชันในการสั่งการทำงานเมื่อกดปุ่ม V11 ใน Blynk Application ซึ่งในที่นี้คือคำสั่งเดินหน้า
* BLYNK_WRITE(12) // เป็นฟังก์ชันในการสั่งการทำงานเมื่อกดปุ่ม V12 ใน Blynk Application ซึ่งในที่นี้คือคำสั่งเลี้ยวขวา
* BLYNK_WRITE(13) // เป็นฟังก์ชันในการสั่งการทำงานเมื่อกดปุ่ม V13 ใน Blynk Application ซึ่งในที่นี้คือคำสั่งถอยหลัง
* BLYNK_WRITE(14) // เป็นฟังก์ชันในการสั่งการทำงานเมื่อกดปุ่ม V14 ใน Blynk Application ซึ่งในที่นี้คือคำสั่งเลี้ยวซ้าย
* BLYNK_WRITE(16) // เป็นฟังก์ชันในการสั่งการทำงานเมื่อ เปิด-ปิด ปุ่ม V16 ใน Blynk Application ซึ่งในที่นี้คือคำสั่งวิ่งอัตโนมัติ
* void loop() // เป็นฟังก์ชันในการทำงานแบบทำซ้ำอย่างต่อเนื่อง
* Blynk.run() // เป็นการเริ่มการทำงานของ Blynk Application ให้สามารถทำงานร่วมกันกับรถยนต์บังคับได้
* sonar.ping_cm(); // เป็นคำสั่งในการรับค่าระยะทางที่อ่านได้จากอัลตราโซนิค โดยมีหน่วยเป็นเซนติเมตร
* tone(buzzer, fequency); //เป็นคำสั่งในการสั่งให้ buzzer ตามขาที่กำหนดใน buzzer ส่งเสียงออกมาตามความถี่ fequency
* noTone(buzzer); //เป็นคำสั่งในการทำ buzzer ตามขาที่กำหนด ไม่ส่งเสียงใดๆออกมา
* void forward(int time) // เป็นฟังก์ชันที่ใช้สั่งให้รถเคลื่อนที่ไปข้างหน้า หน่วงตามเวลาที่กำหนดให้ในค่า time
* void backward(int time) // เป็นฟังก์ชันที่ใช้สั่งให้รถเคลื่อนที่ถอยหลัง หน่วงตามเวลาที่กำหนดให้ในค่า time
* void turnLeft(int time) // เป็นฟังก์ชันที่ใช้สั่งให้รถเคลื่อนที่ไปข้างซ้าย หน่วงตามเวลาที่กำหนดให้ในค่า time
* void turnRight(int time) // เป็นฟังก์ชันที่ใช้สั่งให้รถเคลื่อนที่ไปข้างขวา หน่วงตามเวลาที่กำหนดให้ในค่า time
* void coast(int time) // เป็นฟังก์ชันที่ใช้สั่งให้รถหยุดอย่างช้าๆ หน่วงตามเวลาที่กำหนดให้ในค่า time
* void motorAForward() // เป็นฟังก์ชันที่ใช้สั่งให้ล้อฝั่งขวาหมุนไปข้างหน้า
* void motorABackward() // เป็นฟังก์ชันที่ใช้สั่งให้ล้อฝั่งขวาหมุนไปข้างหลัง
* void motorBForward() // เป็นฟังก์ชันที่ใช้สั่งให้ล้อฝั่งซ้ายหมุนไปข้างหน้า
* void motorBBackward() // เป็นฟังก์ชันที่ใช้สั่งให้ล้อฝั่งซ้ายหมุนไปข้างหน้า
* void motorACoast() // เป็นฟังก์ชันที่ใช้สั่งให้ล้อฝั่งขวาค่อยๆหยุดหมุน
* void motorBCoast() // เป็นฟังก์ชันที่ใช้สั่งให้ล้อฝั่งซ้ายค่อยๆหยุดหมุน
* digitalWrite(pinA1, HIGH); // เป็นฟังก์ชันที่ใช้ในการส่งค่าออกไปตามขา pin ที่กำหนดไว้
* delay(time); // เป็นฟังก์ชันในการหน่วงเวลาตามค่า time ในหน่วย ms
---

# How to use
* ดาวน์โหลดโปรแกรม Arduino เมื่อเรียบร้อย ให้ติดตั้งแพลตฟอร์ม ESP8266
  * เลือกแถบ File -> Preferences
  * ไปที่ช่อง Additional Boards Manager URLs: ป้อน URL นี้
    http://arduino.esp8266.com/stable/package_esp8266com_index.json แล้ว click OK
  * เลือกแถบ Tools -> Board: แล้วเลือกที่ Boards Manager...
  * เลื่อนหา esp8266 by ESP8266 Community จากนั้นกด Install 
  * เมื่อติดตั้งเสร็จให้เลือก Board : NodeMCU 1.0 (ESP-12E Module)
* หลังจากนั้นให้ติดตั้ง Library ตามข้างบนให้ครบ ดังนี้
  * เลือกแถบ Sketch --> Include Library --> Add .ZIP Library...
* ให้ทำการดาวน์โหลดแอพ Blynk ในโทรศัพท์มือถือ
  * เมื่อติดตั้งเสร็จให้เข้าแอพ Blynk แล้วทำการ Log In
  * จากนั้นเลือก New Project และทำการตั้งค่าตามรูปภาพ แล้วกด Create<br>
  ![](/pic/create.jpg)
  * จากนั้นจะได้รับ Auth Token ตาม E-mail ที่ใช้เชื่อมต่อกับแอพ เพื่อนำไปใส่ในโค้ดของเรา
  * ทำการเพิ่มปุ่มกด Button และตั้งค่า PIN เป็น Virtual และตั้งค่าตามภาพดังนี้ <br>
   ![](/pic/setting1.jpg)
  * และนี่คือแอพ Blynk ที่พร้อมในการควบคุมรถบังคับ<br>
   ![](/pic/control1.jpg)

  * เมื่อทำการตั้งค่าเสร็จให้เปิดไฟล์ของเราในโปรแกรม Arduino
  * ในส่วนของสามบรรทัดนี้ ก่อนการอัพโหลดให้ทำการแก้ไขเป็นข้อมูลของผู้ใช้<br>
  ตัวอย่างโค้ด<br>
  ![](/pic/data.png)<br>
  **char auth[] = "auth_token";**   ให้เปลี่ยน auth_token เป็น Auth Token ซึ่งจะได้รับใน E-mail ที่ทำการเชื่อมต่อกับแอพ Blynk<br>
  **char ssid[] = "user_wifi";**   ให้เปลี่ยน user_wifi เป็น ชื่อ Wifi ของผู้ใช้<br>
  **char pass[] = "password_wifi";**   ให้เปลี่ยน password_wifi เป็น รหัส Wifi ของผู้ใช้<br>
  * จากนั้นทำการอัพโหลดโค้ดผ่านสาย Micro USB เข้า NodeMCU ของรถบังคับ \* อย่าลืมคลิก Tools แล้วเลือก Port ของสาย
  * เมื่ออัพโหลดเสร็จ ให้ลองบังคับรถผ่านแอพ Blynk ได้เลย

---

# ![](/img/Supervisor.png) Assistant Teacher<br>

| ผศ. ดร. กิติ์สุชาต พสุภา	| ผศ. ดร. ปานวิทย์ ธุวะนุติ  |
| :-------------: |:-------------:|
| ![Image](/pic/ajaong.jpg)      | ![Image](/pic/ajpanwit.jpg) | $1600 |<br>

รายงานนี้เป็นส่วนหนึ่งของวิชา Computer Programming<br>
คณะเทคโนโลยีสารสนเทศ สถาบันเทคโนโลยีพระจอมเกล้าเจ้าคุณทหารลาดกระบัง

---


# ![](/img/member.png) Team Members
|  |ชื่อ|นามสกุล|GitHub Username|รหัสนักศึกษา|
|:-:|--|------|---------------|---------|
|![](/pic/meak.jpg)| สุภวัช | กลิ่นขจร | [@60070106](https://github.com/60070106) | 60070106 |
|![](/pic/jiw.jpg)| อรฤทัย | ธรรมสาหาญ | [@jongjiw](https://github.com/jongjiw) | 60070115 |

