// OrderModule.h
#ifndef ORDER_MODULE_H
#define ORDER_MODULE_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ==== Abstract Base Class ====
class OrderBase {
protected:
    string id;
    string customerName;
    float amount;
public:
    OrderBase() : id(""), customerName(""), amount(0) {}
    OrderBase(string id, string name, float amt) : id(id), customerName(name), amount(amt) {}
    virtual ~OrderBase() {}

    virtual void NhapDon() = 0;
    virtual void XuatDon() = 0;
    virtual void SuaDon() = 0;

    string getId() const { return id; }

    bool operator==(const OrderBase& other) const {
        return id == other.id;
    }
};

// ==== Normal Order ====
class NormalOrder : public OrderBase {
private:
    string deliveryDate;
public:
    NormalOrder() : OrderBase(), deliveryDate("") {}
    NormalOrder(string id, string name, float amt, string date)
        : OrderBase(id, name, amt), deliveryDate(date) {}

    void NhapDon() override {
        cout << "Nhap ID: "; cin >> id;
        cout << "Nhap ten khach: "; cin.ignore(); getline(cin, customerName);
        cout << "Nhap so tien: "; cin >> amount;
        cout << "Nhap ngay giao: "; cin >> deliveryDate;
    }

    void XuatDon() override {
        cout << "[Normal] ID: " << id << ", Ten: " << customerName << ", So tien: " << amount << ", Ngay giao: " << deliveryDate << endl;
    }

    void SuaDon() override {
        cout << "Sua ten khach moi: "; cin.ignore(); getline(cin, customerName);
        cout << "Sua so tien moi: "; cin >> amount;
        cout << "Sua ngay giao moi: "; cin >> deliveryDate;
    }
};

// ==== Express Order ====
class ExpressOrder : public OrderBase {
private:
    float shippingFee;
public:
    ExpressOrder() : OrderBase(), shippingFee(0) {}
    ExpressOrder(string id, string name, float amt, float fee)
        : OrderBase(id, name, amt), shippingFee(fee) {}

    void NhapDon() override {
        cout << "Nhap ID: "; cin >> id;
        cout << "Nhap ten khach: "; cin.ignore(); getline(cin, customerName);
        cout << "Nhap so tien: "; cin >> amount;
        cout << "Nhap phi ship: "; cin >> shippingFee;
    }

    void XuatDon() override {
        cout << "[Express] ID: " << id << ", Ten: " << customerName << ", So tien: " << amount << ", Phi ship: " << shippingFee << endl;
    }

    void SuaDon() override {
        cout << "Sua ten khach moi: "; cin.ignore(); getline(cin, customerName);
        cout << "Sua so tien moi: "; cin >> amount;
        cout << "Sua phi ship moi: "; cin >> shippingFee;
    }
};

// ==== Online Order ====
class OnlineOrder : public OrderBase {
private:
    string website;
    string email;
public:
    OnlineOrder() : OrderBase(), website(""), email("") {}
    OnlineOrder(string id, string name, float amt, string site, string mail)
        : OrderBase(id, name, amt), website(site), email(mail) {}

    void NhapDon() override {
        cout << "Nhap ID: "; cin >> id;
        cout << "Nhap ten khach: "; cin.ignore(); getline(cin, customerName);
        cout << "Nhap so tien: "; cin >> amount;
        cout << "Nhap website: "; cin.ignore(); getline(cin, website);
        cout << "Nhap email: "; getline(cin, email);
    }

    void XuatDon() override {
        cout << "[Online] ID: " << id << ", Ten: " << customerName << ", So tien: " << amount << ", Website: " << website << ", Email: " << email << endl;
    }

    void SuaDon() override {
        cout << "Sua ten khach moi: "; cin.ignore(); getline(cin, customerName);
        cout << "Sua so tien moi: "; cin >> amount;
        cout << "Sua website moi: "; cin.ignore(); getline(cin, website);
        cout << "Sua email moi: "; getline(cin, email);
    }
};

// ==== Order Manager ====
class OrderManager {
private:
    vector<OrderBase*> orders;
public:
    ~OrderManager() {
        for (auto o : orders) delete o;
    }

    void ThemDon(OrderBase* don) {
        orders.push_back(don);
    }

    void XoaDon(const string& id) {
        for (auto it = orders.begin(); it != orders.end(); ++it) {
            if ((*it)->getId() == id) {
                delete *it;
                orders.erase(it);
                cout << "Da xoa don." << endl;
                return;
            }
        }
        cout << "Khong tim thay don." << endl;
    }

    void SuaDon(const string& id) {
        for (auto o : orders) {
            if (o->getId() == id) {
                o->SuaDon();
                return;
            }
        }
        cout << "Khong tim thay don." << endl;
    }

    void HienThiTatCa() {
        for (auto o : orders) o->XuatDon();
    }
};

#endif
