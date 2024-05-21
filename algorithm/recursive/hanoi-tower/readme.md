# HanoiTower Problem

`Problem`:

- Chỉ có 3 cột để di chuyển.
- Một lần chỉ được di chuyển một đĩa (không được di chuyển đĩa nằm giữa).
- Một đĩa chỉ có thể được đặt lên một đĩa lớn hơn (không nhất thiết hai đĩa này phải có kích thước liền kề, tức là đĩa nhỏ nhất có thể nằm trên đĩa lớn nhất).

`Implement`:

- chuyển đĩa 1 sang cọc C
- chuyển đĩa 2 sang cọc B
- chuyển đĩa 1 từ C sang B sao cho nó nằm lên 2
  -> Vậy ta hiện có 2 đĩa đã nằm trên cọc B, cọc C hiện thời trống

- chuyển đĩa 3 sang cọc C
- lặp lại 3 bước trên để chuyển 1 & 2 cho nằm lên 3

![image](./tower.jpg)
