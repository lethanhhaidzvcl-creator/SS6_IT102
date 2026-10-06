#include <stdio.h>
#include <string.h>

int main() {
    char maPhieu[50][20] = {"PM101", "PM102", "PM103"};
    int ngayQuaHan[50] = {0, 3, 5};
    int soLuong = 3;

    int choice;

    do {
        printf("\n--- HE THONG QUAN LY MUON TRA SACH (LIBRARY_WMS) ---\n");
        printf("1. Xem danh sach phieu muon\n");
        printf("2. Them moi phieu muon\n");
        printf("3. Cap nhat so ngay qua han\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        while (getchar() != '\n');

        switch (choice) {
            case 1: {
                printf("\n--- DANH SACH PHIEU MUON SACH ---\n");
                printf("STT | Ma Phieu | So Ngay Qua Han | Tien Phat (VND)\n");
                printf("--------------------------------------------------\n");

                for (int i = 0; i < soLuong; i++) {
                    int tienPhat = ngayQuaHan[i] * 5000;

                    printf("%d | %s | %d ngay | %d VND\n",
                           i + 1, maPhieu[i], ngayQuaHan[i], tienPhat);
                }

                printf("--------------------------------------------------\n");
                printf("Tong so phieu: %d\n", soLuong);
                break;
            }

            case 2: {
                if (soLuong >= 50) {
                    printf("Loi: Danh sach phieu muon da day, khong the them!\n");
                    break;
                }

                printf("Nhap ma phieu muon moi: ");
                scanf("%s", maPhieu[soLuong]);

                while (getchar() != '\n');

                ngayQuaHan[soLuong] = 0;
                soLuong++;

                printf("Them phieu muon thanh cong!\n");
                break;
            }

            case 3: {
                char maCanTim[20];
                int timThay = -1;
                int ngayMoi;

                printf("Nhap ma phieu muon can cap nhat: ");
                scanf("%s", maCanTim);

                while (getchar() != '\n');

                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maCanTim) == 0) {
                        timThay = i;
                        break;
                    }
                }

                if (timThay == -1) {
                    printf("Khong tim thay phieu muon!\n");
                } else {
                    printf("Tim thay phieu muon '%s' tai vi tri index %d.\n",
                           maPhieu[timThay], timThay);

                    do {
                        printf("Nhap so ngay qua han moi: ");
                        scanf("%d", &ngayMoi);

                        if (ngayMoi < 0) {
                            printf("Loi: So ngay qua han khong duoc am!\n");
                        }
                    } while (ngayMoi < 0);

                    while (getchar() != '\n');

                    ngayQuaHan[timThay] = ngayMoi;

                    printf("Cap nhat thanh cong! So ngay qua han moi cua %s la %d ngay.\n",
                           maPhieu[timThay], ngayQuaHan[timThay]);
                }

                break;
            }

            case 0:
                printf("Cam on ban da su dung chuong trinh!\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (choice != 0);

    return 0;
}