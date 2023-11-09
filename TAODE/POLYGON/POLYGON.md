# POLYGON
## Cho tập n điểm A1, A2,..., An. Hãy tìm đa giác lồi nhỏ nhât(theo diện tích) chứa tất cả các điểm của tập đó. 
### Dữ liệu vào:
#### • Dòng đầu tiên ghi số nguyên dương n(3 <= n <= 2*10^4);
#### • n dòng tiếp theo, dòng thứ i ghi hai số thực xi, yi là hoành độ và tung độ của điểm Ai (|xi|, |yi| <= 10^6).
### Dữ liệu ra:
#### • Gồm hai số m, S. Trong đó m là số đỉnh của đa giác (đoạn thẳng trong trường hợp suy biến) và S là diện tích của đa giác. Nếu có nhiều đa giác thì chọn m là số đỉnh của đa giác có ít đỉnh nhất.
CHÚ Ý: Nếu diện tích không quá 10^6 thì làm tròn đến hai chữ số thập phân, ngược lại, làm tròn đến hàng đơn vị của phần nguyên. 
### Ví dụ:
|Input|Output|
|-|-|
|8   |5|
|2 3 |12.50|
|2 2 ||
|4 1 ||
|6 3 ||
|5 6 ||
|4 3 ||
|2 3 ||
|2 4 ||
### Hình minh họa:
![image](https://github.com/vudinhkhoa0/DE_C-/assets/126996254/196559e0-6d52-4243-8e81-2ec1dd366535)
