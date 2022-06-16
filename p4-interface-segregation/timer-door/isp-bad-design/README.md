## Thiết kế vi phạm nguyên lý phân tách giao diện

<p align="center">
  <img source="isp-bad.png" /> <br />
  Giao diện <a href="timer_client.hpp">TimerClient</a> là dư thừa đối với <a href="original_door.hpp">OriginalDoor</a>
</p>

Cửa hẹn giờ phát tín hiệu cảnh báo sau khi được để mở 5s.

Trong thiết kế này, để triển khai lớp TimedDoor (cửa hẹn giờ) lớp Door đã kế thừa lớp TimerClient để đối tượng Timer có thể gọi ngược phương thức Timeout của TimedDoor.

Tuy nhiên giải pháp này có hiệu ứng phụ là tất cả các lớp khác kế thừa Door cũng phải triển khai các giao diện TimerClient dù không cần. Như lớp OriginalDoor không có tính năng đếm thời gian, vì vậy các giao diện có trong TimerClient là không cần thiết đối với lớp này, ví dụ như Timeout không có ý nghĩa đối với OriginalDoor.
