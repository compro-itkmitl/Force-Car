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
* \#include <ESP8266WiFi.h>
* \#include <NewPing.h>
* \#include <BlynkSimpleEsp8266.h>


---

# Function
ฟังก์ชันที่เขียนในโค้ดทำอะไรบ้าง

---

# How to use
* ดาวน์โหลดโปรแกรม Arduino เมื่อเรียบร้อย ให้ติดตั้ง Library ตามข้างบน ดังนี้
  * กดที่แถบข้างบน Sketch --> Include Library --> Add .ZIP Library...
  * เมื่อทำการติดตั้งเสร็จให้เปิดไฟล์โค้ดเรา
  * ในส่วนของสามบรรทัดนี้ให้ทำการเปลี่ยนเป็นของผู้ใช้
  * char auth[] = "343e76bc3b1642f79cf0732a095cb5e8"; ให้เข้าเว็บแล้วทำการก๊อปของตัวเองมาใส่
  * char ssid[] = "..."; ใส่ชื่อ Wifi ของผู้ใช้
  * char pass[] = "meakmeak"; ใส่รหัส Wifi ของผู้ใหญ่
* ให้ทำการดาวน์โหลดแอพ Blynk ในโทรศัพท์มือถือ
* เมื่อติดตั้งเสร็จให้เข้าแอพ Blynk แล้วเลือก New Project ตั้งค่าเป็น NodeMCU เลือก Wifi
* ทำการเชื่อมบลาๆๆ เข้าไปเอา auth ใน?

![Setting](https://avatars.githubusercontent.com/u/11541426?v=3)
* ตั้งค่าตามรูป

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

