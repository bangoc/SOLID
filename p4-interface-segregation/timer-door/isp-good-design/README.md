## Thiết kế đáp ứng được nguyên lý phân tách giao diện

<p align="center">
  <img source="isp-good1.png" /> <br />
  Mở rộng <a href="timed_door.hpp">TimedDoor</a> với tính năng cảnh báo bằng quan hệ tổng hợp
</p>

Cửa hẹn giờ phát tín hiệu cảnh báo sau khi được để mở 5s.

Trong thiết kế này, TimerClient được tổng hợp vào TimedDoor, lớp Door được giữ nguyên, vì vậy không làm rối giao diện của OriginalDoor.

## Một giải pháp khác sử dụng đa kế thừa
<p align="center">
  <img source="isp-good2.png" /> <br />
  Mở rộng <a href="timed_door.hpp">TimedDoor</a> bằng cách kế thừa <a href="timer_client.hpp">TimerClient</a>
</p>