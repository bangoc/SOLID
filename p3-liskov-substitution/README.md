# Nguyên lý khả thay Liskov

Nguyên lý khả thay Liskov / Liskov Substitution Principle

*Nếu S là 1 lớp con của T, thì chương trình vẫn hoạt động được khi thay thế các đối tượng kiểu T bằng các tượng kiểu S.*

<p align="right">[Barbara Liskov]</p>

Các định hướng:

* Không tăng cường các tiền điều kiện trong lớp con.
* Không nới lỏng hậu điều kiện trong lớp con.
* Các bất biến của lớp cha cần được duy trì trong lớp con.

...