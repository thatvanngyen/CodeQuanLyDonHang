#include "OrderModule.h"
int main() {
    OrderManager manager;
    int choice;
    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Them don\n";
        cout << "2. Sua don\n";
        cout << "3. Xoa don\n";
        cout << "4. Hien thi tat ca\n";
        cout << "0. Thoat\n";
        cout << "Chon chuc nang: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int loai;
                cout << "Chon loai don (1: Normal, 2: Express, 3: Online): ";
                cin >> loai;

                OrderBase* don = nullptr;
                if (loai == 1) don = new NormalOrder();
                else if (loai == 2) don = new ExpressOrder();
                else if (loai == 3) don = new OnlineOrder();
                else {
                    cout << "Loai khong hop le.\n";
                    break;
                }

                don->NhapDon();
                manager.ThemDon(don);
                break;
            }
            case 2: {
                string id;
                cout << "Nhap ID don can sua: ";
                cin >> id;
                manager.SuaDon(id);
                break;
            }
            case 3: {
                string id;
                cout << "Nhap ID don can xoa: ";
                cin >> id;
                manager.XoaDon(id);
                break;
            }
            case 4:
                manager.HienThiTatCa();
                break;
            case 0:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le.\n";
        }
    } while (choice != 0);

    return 0;
}
