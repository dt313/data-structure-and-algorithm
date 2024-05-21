# Greatest common divisor (Ước chung lớn nhất)

> Tìm ước chung lớn nhất của 2 số nguyên

- `input` : 2 số ngẫu nhiên
- `output` : ước chung của 2 số

Thuật toán :
ví dụ `a = 10`, `b = 2`;
kiểm tra:
- nếu b bằng 0 thì a là ước chung lớn nhất (vì ước chung của một số và 0 là chính nó)
- nếu không thì 
    - đệ quy `gcd(b, a % b)`  ---> `gcd(2, 0)`
    - Lúc này `b = 0`--->  ước chung lớn nhất là `a = 2`




