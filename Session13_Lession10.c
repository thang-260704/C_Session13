#include <stdio.h>
#include <stdlib.h>


int arr[100];
int n = 0;

void nhapMang() {
    printf("Nhap so phan tu can nhap (toi da 100): ");
    scanf("%d", &n);
    if (n > 100) {
        printf("So phan tu khong duoc vuot qua 100.\n");
        return;
    }
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void inMang() {
    if (n == 0) {
        printf("Mang hien tai rong.\n");
        return;
    }
    printf("Cac phan tu trong mang la:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void themPhanTu() {
    if (n == 100) {
        printf("Mang da day, khong the them phan tu.\n");
        return;
    }
    int viTri, giaTri;
    printf("Nhap vi tri muon them (0 den %d): ", n);
    scanf("%d", &viTri);
    if (viTri < 0 || viTri > n) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    printf("Nhap gia tri phan tu muon them: ");
    scanf("%d", &giaTri);
    for (int i = n; i > viTri; i--) {
        arr[i] = arr[i - 1];
    }
    arr[viTri] = giaTri;
    n++;
}

void suaPhanTu() {
    int viTri, giaTri;
    printf("Nhap vi tri phan tu muon sua (0 den %d): ", n - 1);
    scanf("%d", &viTri);
    if (viTri < 0 || viTri >= n) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    printf("Nhap gia tri moi cho phan tu: ");
    scanf("%d", &giaTri);
    arr[viTri] = giaTri;
}

void xoaPhanTu() {
    int viTri;
    printf("Nhap vi tri phan tu muon xoa (0 den %d): ", n - 1);
    scanf("%d", &viTri);
    if (viTri < 0 || viTri >= n) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    for (int i = viTri; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

void sapXep() {
    int chon;
    printf("Chon kieu sap xep:\n");
    printf("1. Giam dan\n");
    printf("2. Tang dan\n");
    printf("Nhap lua chon: ");
    scanf("%d", &chon);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((chon == 1 && arr[i] < arr[j]) || (chon == 2 && arr[i] > arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Mang da duoc sap xep.\n");
}

void timKiemTuyenTinh() {
    int giaTri;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &giaTri);
    for (int i = 0; i < n; i++) {
        if (arr[i] == giaTri) {
            printf("Tim thay phan tu %d tai vi tri %d.\n", giaTri, i);
            return;
        }
    }
    printf("Khong tim thay phan tu %d.\n", giaTri);
}

void timKiemNhiPhan() {
    int giaTri, left = 0, right = n - 1;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &giaTri);
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == giaTri) {
            printf("Tim thay phan tu %d tai vi tri %d.\n", giaTri, mid);
            return;
        } else if (arr[mid] < giaTri) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("Khong tim thay phan tu %d.\n", giaTri);
}

void hienThiMenu() {
    int luaChon;
    do {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. Them mot phan tu vao vi tri chi dinh\n");
        printf("4. Sua mot phan tu o vi tri chi dinh\n");
        printf("5. Xoa mot phan tu o vi tri chi dinh\n");
        printf("6. Sap xep cac phan tu\n");
        printf("7. Tim kiem phan tu nhap vao\n");
        printf("8. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                nhapMang();
                break;
            case 2:
                inMang();
                break;
            case 3:
                themPhanTu();
                break;
            case 4:
                suaPhanTu();
                break;
            case 5:
                xoaPhanTu();
                break;
            case 6: {
                int chon;
                printf("Chon kieu sap xep:\n");
                printf("1. Giam dan\n");
                printf("2. Tang dan\n");
                printf("Nhap lua chon: ");
                scanf("%d", &chon);
                switch (chon) {
                    case 1:
                        sapXep();
                        break;
                    case 2:
                        sapXep();
                        break;
                    default:
                        printf("Lua chon khong hop le.\n");
                        break;
                }
                break;
            }
            case 7: {
                int chon;
                printf("Chon kieu tim kiem:\n");
                printf("1. Tim kiem tuyen tinh\n");
                printf("2. Tim kiem nhi phan\n");
                printf("Nhap lua chon: ");
                scanf("%d", &chon);
                switch (chon) {
                    case 1:
                        timKiemTuyenTinh();
                        break;
                    case 2:
                        timKiemNhiPhan();
                        break;
                    default:
                        printf("Lua chon khong hop le.\n");
                        break;
                }
                break;
            }
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (luaChon != 8);
}

int main() {
    hienThiMenu();
    return 0;
}
