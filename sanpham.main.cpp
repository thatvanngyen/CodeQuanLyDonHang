#include "Product.h"

int main() {
    int n;
    cout << "Nhap so luong san pham: ";
    cin >> n;

    Product** list = new Product*[n];
    for (int i = 0; i < n; ++i) {
        int type;
        cout << "\nSan pham thu " << i + 1 << ", loai (1 = thuong, 2 = dien tu): ";
        cin >> type;

        if (type == 2)
            list[i] = new ElectronicProduct();
        else
            list[i] = new Product();

        list[i]->input();
    }

    cout << "\n=== Danh sach san pham ===\n";
    for (int i = 0; i < n; ++i) {
        list[i]->output();
        cout << endl;
    }

    int maxIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (*list[i] > *list[maxIndex])
            maxIndex = i;
    }

    cout << "\nSan pham co gia cao nhat:\n";
    list[maxIndex]->output();
    cout << endl;

    for (int i = 0; i < n; ++i)
        delete list[i];
    delete[] list;

    return 0;
}
