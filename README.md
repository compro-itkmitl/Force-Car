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
ฟังก์ชันที่เขียนในโค้ดทำอะไรบ้าง

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
   ![](/pic/setting.jpg)
  * และนี่คือแอพ Blynk ที่พร้อมในการควบคุมรถบังคับ<br>
   ![](/pic/control.jpg)

  * เมื่อทำการตั้งค่าเสร็จให้เปิดไฟล์ของเราในโปรแกรม Arduino
  * ในส่วนของสามบรรทัดนี้ ก่อนการอัพโหลดให้ทำการแก้ไขเป็นข้อมูลของผู้ใช้<br>
  ![](/pic/data.png)<br>
  **char auth[] = "auth_token";** ให้เปลี่ยน auth_token เป็น Auth Token ซึ่งจะได้รับใน E-mail ที่ทำการเชื่อมต่อกับแอพ Blynk<br>
  **char ssid[] = "user_wifi";** ให้เปลี่ยน user_wifi เป็น ชื่อ Wifi ของผู้ใช้<br>
  **char pass[] = "password_wifi";** ให้เปลี่ยน password_wifi เป็น รหัส Wifi ของผู้ใช้<br>
  * จากนั้นทำการอัพโหลดโค้ดผ่านสาย Micro USB เข้า NodeMCU ของรถบังคับ \* อย่าลืมคลิก Tools แล้วเลือก Port ของสาย
  * เมื่ออัพโหลดเสร็จ ให้ลองบังคับรถผ่านแอพ Blynk ได้เลย

---

# ![](/img/Supervisor.png) Assistant Teacher<br>

| ผศ. ดร. กิติ์สุชาติ พสุภา	| ผศ. ดร. ปานวิทย์ ธุวะนุติ  |
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

