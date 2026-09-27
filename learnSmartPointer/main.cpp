#include <iostream>

using namespace std;

// Hàm gây leak loại "definitely lost"
void ham_bi_leak_definitely() {
    // Cấp phát 1 mảng 10 số nguyên trên Heap
    int* arr = new int[10]; 
    
    // Gán giá trị để tránh cảnh báo của trình biên dịch
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }
    
    cout << "Da cap phat mang 10 phan tu tai ham_bi_leak_definitely" << endl;
    // KẾT THÚC HÀM: Biến 'arr' (con trỏ) bị hủy, nhưng vùng nhớ Heap vẫn còn.
    // Không có 'delete[] arr;' -> Rò rỉ bộ nhớ!

	delete[] arr;
}

// Hàm gây leak loại "definitely lost" với đối tượng
void ham_bi_leak_object() {
    // Cấp phát 1 đối tượng string
    string* str = new string("Hello Valgrind");
    
    cout << "Da cap phat string: " << *str << endl;
    // KẾT THÚC HÀM: Không có 'delete str;' -> Rò rỉ!

	delete str;
}

// Hàm gây leak loại "still reachable" (thường ít nguy hiểm hơn)
int* con_tro_toan_cuc = nullptr;

void ham_bi_leak_still_reachable() {
    // Cấp phát và gán cho con trỏ toàn cục
    con_tro_toan_cuc = new int(999);
    cout << "Da cap phat bien toan cuc: " << *con_tro_toan_cuc << endl;
    // Khi kết thúc chương trình, con trỏ này vẫn giữ địa chỉ,
    // nhưng không bao giờ được giải phóng.
}

int main() {
    cout << "--- Bat dau chuong trinh ---" << endl;

    ham_bi_leak_definitely();
    ham_bi_leak_object();
    ham_bi_leak_still_reachable();

    cout << "--- Ket thuc chuong trinh ---" << endl;
    return 0;
}