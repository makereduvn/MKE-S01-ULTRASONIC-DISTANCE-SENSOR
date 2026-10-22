# Cảm biến siêu âm MKE-S01 Ultrasonic Distance Sensor

## Giới thiệu

MKE-S01 Ultrasonic Distance Sensor là cảm biến đo khoảng cách sử dụng sóng siêu âm để xác định khoảng cách đến vật cản trong phạm vi từ 3cm đến 200cm với độ ổn định và độ chính xác cao. Cảm biến được tích hợp mạch xử lý chuyên dụng cùng thạch anh chất lượng tốt, giúp tăng độ bền, giảm nhiễu và đảm bảo kết quả đo tin cậy trong nhiều điều kiện hoạt động khác nhau.

Cảm biến được ứng dụng rộng rãi trong nhiều hệ thống thực tế như: robot tránh vật cản, robot dò đường, xe tự hành AGV, hệ thống chống trộm, đo mức nước trong bồn chứa, cảm biến đỗ xe, thùng rác thông minh, cửa tự động, hệ thống cảnh báo va chạm và nhiều dự án IoT khác.

Sản phẩm đặc biệt phù hợp cho các mô hình robot, dự án STEM, đồ án học tập và thực hành điện – điện tử, giúp người học dễ dàng tiếp cận nguyên lý đo khoảng cách bằng sóng siêu âm, kỹ thuật xử lý tín hiệu số và ứng dụng cảm biến trong các hệ thống tự động hóa thực tế. Đây là lựa chọn lý tưởng cho học sinh, sinh viên, giáo viên giảng dạy STEM và những người yêu thích nghiên cứu sáng tạo.

MKE-S01 Ultrasonic Distance Sensor hỗ trợ điện áp giao tiếp 3.3V và 5VDC, cho phép kết nối trực tiếp và an toàn với Arduino, Raspberry Pi, NVIDIA Jetson, Micro:bit và nhiều nền tảng điều khiển khác. Sản phẩm đi kèm cáp kết nối 4P XH2.54 – Dupont, đảm bảo kết nối chắc chắn, ổn định và thuận tiện trong quá trình lắp đặt và sử dụng.

## Thông số kỹ thuật

- Điện áp hoạt động: 5VDC
- Chuẩn giao tiếp: Digital
- Điện áp giao tiếp: TTL 3.3VDC / 5VDC
- Dòng điện hoạt động: 65mA
- Tần số hoạt động: 40kHz
- Khoảng cách đo: 3 – 200cm
- Góc quét: 15°
- Tín hiệu Trigger đầu vào: Xung TTL 10μs
- Khả năng tương thích:
  - Arduino
  - Raspberry Pi
  - Jetson Nano
  - Micro:bit
  - Và các board điều khiển 3.3/5VDC khác
- Thiết kế mạch:
  - Hoạt động ổn định, chống nhiễu tốt
  - Giao tiếp đơn giản chỉ với 2 dây tín hiệu
  - Phù hợp cho ứng dụng học tập và thực tế
- Đi kèm cáp kết nối: 4P XH2.54 – Dupont

## Các chân tín hiệu
<table><thead>
  <tr>
    <th>MKE-S01</th>
    <th>Ghi chú</th>
  </tr></thead>
<tbody>
  <tr>
    <td>GND</td>
    <td>Chân cấp nguồn âm 0VDC</td>
  </tr>
  <tr>
    <td>5V</td>
    <td>Chân cấp nguồn dương 5VDC</td>
  </tr>
  <tr>
    <td>TRIG</td>
    <td>Chân tín hiệu ngõ vào Trigger</td>
  </tr>
  <tr>
    <td>ECHO</td>
    <td>Chân tín hiệu ngõ ra Echo</td>
  </tr>
</tbody>
</table>

## Hướng dẫn sử dụng
### Hướng dẫn kết nối
- Cấp nguồn 5VDC cho mạch qua hai chân GND và 5V.
- kết nối chân TRIG và ECHO của Sensor với chân điều khiển được khai báo trong chương trình.

### Hướng dẫn sử dụng với Arduino / ESP32
- Trong Github của bộ thư viện, chọn **<> Code / Download ZIP** để tải về bộ thư viện.
- Mở chương trình Arduino, chọn **Sketch / Include Library / Add .ZIP Library** để cài đặt bộ thư viện.
- Mở chương trình mẫu tại **File / Examples / MKE_S01_Ultrasonic**
- Cấu hình board mạch tương ứng là **Arduino Uno / ESP32**, chọn đúng cổng **COM Port** của mạch và nhấn **Upload** để nạp chương trình.
- Cấp nguồn 5VDC cho mạch, kết nối chân TRIG và ECHO của Sensor với chân điều khiển được khai báo trong chương trình.
- Xem kết quả mạch hoạt động theo chương trình đã nạp.

#### Chương trình mẫu cho Arduino Uno:
```ino
// Thêm bộ thư viện
// Add the library.
#include <MKE_S01.h>

// Đặt tên cho chân kết nối cảm biến
#define TRIG_PIN 13
#define ECHO_PIN 12

// Cấu hình chân kết nối tín hiệu cho cảm biến.
// Configure the signal connection pins for the sensor.
MKE_S01 ultra(TRIG_PIN, ECHO_PIN);

// Tạo biến số nguyên lưu giá trị cảm biến
// value read from the sensor
float sensorValue = 0;  

void setup()
{
  // Khởi động kết nối Serial UART ở tốc độ 115200 để truyền dữ liệu lên máy tính.
  // Start the Serial UART connection at 115200 to transfer data to the computer.
  Serial.begin(115200);
}

void loop()
{

  // Đọc giá trị cảm biến
  // read the analog in value:
  sensorValue = ultra.dist();

  // Truyền khoảng cách đo được của cảm biến lên máy tính.
  // Show the sensor value on Arduno Serial Monitor
  Serial.print("Value: ");
  Serial.println(sensorValue);
  
  // Chờ 200ms
  // Wait 200ms
  delay(200);
}
```

#### Chương trình mẫu cho ESP32:
```ino
// Thêm bộ thư viện
// Add the library.
#include <MKE_S01.h>

// Đặt tên cho chân kết nối cảm biến
#define ECHO_PIN 19 // IO19
#define TRIG_PIN 18 // IO18

// Cấu hình chân kết nối tín hiệu cho cảm biến.
// Configure the signal connection pins for the sensor.
MKE_S01 ultra(TRIG_PIN, ECHO_PIN);

// Tạo biến số nguyên lưu giá trị cảm biến
// value read from the sensor
float sensorValue = 0;  

void setup()
{
  // Khởi động kết nối Serial UART ở tốc độ 115200 để truyền dữ liệu lên máy tính.
  // Start the Serial UART connection at 115200 to transfer data to the computer.
  Serial.begin(115200);
}

void loop()
{

  // Đọc giá trị cảm biến
  // read the analog in value:
  sensorValue = ultra.dist();

  // Truyền khoảng cách đo được của cảm biến lên máy tính.
  // Show the sensor value on Arduno Serial Monitor
  Serial.print("Value: ");
  Serial.println(sensorValue);
  
  // Chờ 200ms
  // Wait 200ms
  delay(200);
}
```
### Hướng dẫn lập trình với Micro:bit (kéo thả khối)

- Khởi động [Microsoft MakeCode](https://makecode.microbit.org/) và **Import** chương trình theo đường link sau: `https://github.com/makereduvn/mke_s01_ultrasonic_microbit/`
- Kết nối mạch Micro:bit và **Download** chương trình.
- Cấp nguồn 5VDC cho mạch, kết nối chân TRIG và ECHO của Sensor với chân điều khiển được khai báo trong chương trình.
- Xem kết quả mạch hoạt động theo chương trình đã nạp.

Nếu bắt đầu tự án mới cần cài đặt Extension **MKE_ONE_MICROBIT** trên [Microsoft MakeCode](https://makecode.microbit.org/) theo [hướng dẫn tại đây](https://github.com/makereduvn/MKE_ONE_MICROBIT). Sau khi cài đặt thành công, các khối lệnh của Extension **MKE_ONE_MICROBIT** sẽ xuất hiện trong danh sách block và sẵn sàng để sử dụng.

## Kích thước sản phẩm
![MKE-S01 Ultrasonic](/extras/MKE-S01_1.jpg)

## Hình ảnh sản phẩm
![MKE-S01 Ultrasonic](/extras/MKE-S01_2.png)
![MKE-S01 Ultrasonic](/extras/MKE-S01_3.png)

## Miễn trừ trách nhiệm
Sản phẩm này là bo mạch phát triển được thiết kế phục vụ cho mục đích nghiên cứu, thử nghiệm và học tập, không phải là một thiết bị hoàn chỉnh. Trong trường hợp người dùng kết hợp mạch này với các linh kiện, thiết bị hoặc phần mềm khác để tạo thành một hệ thống hoặc sản phẩm hoàn chỉnh, mọi chức năng và tính phù hợp của sản phẩm sau cùng đều thuộc trách nhiệm của người dùng.
