#include <stdio.h>
#include <stdlib.h>

int main()
{
    // a. Điền vào điều kiện dừng trong mã lệnh của hàm tính a luỹ thừa b (a^b)
    /*
        int luyThua(int a, int b)
        {
            if (b == 0) return 1;
            return a * luyThua(a, b - 1);
        }
    */
    // b.  Điền vào điều kiện dừng trong mã lệnh của hàm đếm số ký tự trong chuỗi:
    /*
        int demKyTu(char* s)
        {
            if (*s == '\0') return 0;
            return 1 + demKyTu(s + 1);
        }
    */
   // c.   Điền vào biểu thức đệ quy trong mã lệnh của hàm tính tổng các số từ 1 đến n:
   /*
        int tong(int n)
        {   
            if (n == 0) return 0;
            return n + tong(n - 1);
        }
    */
    // d. Điền vào biểu thức đệ quy trong mã lệnh của hàm đếm số kỹ tự chữ cái thường trong chuỗi:
    /*
        int demKTThuong(const char* s)
        {
            if (*s == '\0') return 0; // ket thuc chuoi
            int dem = (*s >= 'a' && *s <= 'z') ? 1 : 0;
            return dem + demKTThuong(s + 1);
        }
    */
    return 0;
}