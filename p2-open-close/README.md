# Nguyên lý open/closed

*Các thực thể phần mềm cần được để mở khả năng mở rộng, nhưng được đóng đối với thay đổi.*

<p align="right">[Bertrand Meyer]</p>

*"Khả năng mở rộng được để mở" / "Open for extension". Có nghĩa là hành vi của 1 mô-đun có thể được mở rộng khi yêu cầu ứng dụng thay đổi, chúng ta có thể mở rộng mô-đun với các hành vi mới để đáp ứng các thay đổi đó. Diễn đạt theo cách khác, chúng ta có thể thay đổi những gì mà 1 mô-đun làm*

*"Khả năng thay đổi bị loại bỏ" / "Closed for modification". Mở rộng hành vi của 1 mô-đun không dẫn đến thay đổi mã nguồn hoặc mã nhị phân của mô-đun đó. Phiên bản nhị phân thực thi của mô-đun đó, dù là 1 thư viện, 1 DLL, hoặc 1 tệp jar của Java, được giữ nguyên không thay đổi.*

<p align="right">[Robert C.Martin]</p>