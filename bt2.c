#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char maPhieu[MAX][15];
    char tenSach[MAX][50];
    int soNgayMuon[MAX];
    int tienPhat[MAX];

    int soLuong = 0;
    int choice;

    do {
        printf("\n================ LIBRARY_WMS ================\n");
        printf("1. Them luot muon sach\n");
        printf("2. Hien thi danh sach\n");
        printf("3. Cap nhat so ngay muon\n");
        printf("4. Xoa luot muon\n");
        printf("5. Thong ke phieu bi phat\n");
        printf("6. Thoat\n");
        printf("==============================================\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        while (getchar() != '\n');

        switch (choice) {

            // ================= THEM =================
            case 1: {
                if (soLuong >= MAX) {
                    printf("He thong day, khong the them phieu muon moi!\n");
                    break;
                }

                char maNhap[15];
                int trung = 0;

                printf("\n=== THEM LUOT MUON SACH MOI ===\n");

                printf("Nhap ma phieu muon: ");
                scanf("%s", maNhap);

                while (getchar() != '\n');

                // Kiem tra trung ma
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maNhap) == 0) {
                        trung = 1;
                        break;
                    }
                }

                if (trung == 1) {
                    printf("Ma phieu da ton tai!\n");
                    break;
                }

                strcpy(maPhieu[soLuong], maNhap);

                printf("Nhap ten sach: ");
                fgets(tenSach[soLuong], 50, stdin);

                if (tenSach[soLuong][strlen(tenSach[soLuong]) - 1] == '\n') {
                    tenSach[soLuong][strlen(tenSach[soLuong]) - 1] = '\0';
                }

                do {
                    printf("Nhap so ngay muon thuc te: ");
                    scanf("%d", &soNgayMuon[soLuong]);

                    if (soNgayMuon[soLuong] <= 0) {
                        printf("So ngay muon phai > 0!\n");
                    }
                } while (soNgayMuon[soLuong] <= 0);

                if (soNgayMuon[soLuong] > 14) {
                    tienPhat[soLuong] =
                        (soNgayMuon[soLuong] - 14) * 5000;
                } else {
                    tienPhat[soLuong] = 0;
                }

                soLuong++;

                printf("Them luot muon sach thanh cong!\n");
                break;
            }

            // ================= XEM =================
            case 2: {
                if (soLuong == 0) {
                    printf("Danh sach muon sach hien dang rong!\n");
                    break;
                }

                int tongTienPhat = 0;

                printf("\n================ DANH SACH MUON SACH ================\n");
                printf("%-5s | %-10s | %-30s | %-10s | %-15s\n",
                       "STT", "Ma Phieu", "Ten Sach",
                       "So Ngay", "Tien Phat");
                printf("---------------------------------------------------------------\n");

                for (int i = 0; i < soLuong; i++) {
                    printf("%-5d | %-10s | %-30s | %-10d | %-15d\n",
                           i + 1,
                           maPhieu[i],
                           tenSach[i],
                           soNgayMuon[i],
                           tienPhat[i]);

                    tongTienPhat += tienPhat[i];
                }

                printf("---------------------------------------------------------------\n");
                printf("Tong tien phat: %d VND\n", tongTienPhat);

                break;
            }

            // ================= CAP NHAT =================
            case 3: {
                char maNhap[15];
                int index = -1;
                int ngayMoi;

                printf("\n=== CAP NHAT SO NGAY MUON ===\n");

                printf("Nhap ma phieu muon can cap nhat: ");
                scanf("%s", maNhap);

                while (getchar() != '\n');

                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maNhap) == 0) {
                        index = i;
                        break;
                    }
                }

                if (index == -1) {
                    printf("Khong tim thay phieu muon co ma: %s\n", maNhap);
                    break;
                }

                printf("Tim thay sach: %s\n", tenSach[index]);
                printf("So ngay hien tai: %d\n", soNgayMuon[index]);

                do {
                    printf("Nhap so ngay muon moi: ");
                    scanf("%d", &ngayMoi);

                    if (ngayMoi <= 0) {
                        printf("So ngay muon phai > 0!\n");
                    }
                } while (ngayMoi <= 0);

                soNgayMuon[index] = ngayMoi;

                if (soNgayMuon[index] > 14) {
                    tienPhat[index] =
                        (soNgayMuon[index] - 14) * 5000;
                } else {
                    tienPhat[index] = 0;
                }

                printf("Tien phat moi: %d VND\n", tienPhat[index]);
                printf("Cap nhat so ngay muon thanh cong!\n");

                break;
            }

            // ================= XOA =================
            case 4: {
                char maNhap[15];
                int index = -1;

                printf("\n=== XOA LUOT MUON SACH ===\n");

                printf("Nhap ma phieu muon can xoa: ");
                scanf("%s", maNhap);

                while (getchar() != '\n');

                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maNhap) == 0) {
                        index = i;
                        break;
                    }
                }

                if (index == -1) {
                    printf("Khong tim thay phieu muon co ma: %s\n", maNhap);
                    break;
                }

                // Don mang
                for (int i = index; i < soLuong - 1; i++) {
                    strcpy(maPhieu[i], maPhieu[i + 1]);
                    strcpy(tenSach[i], tenSach[i + 1]);
                    soNgayMuon[i] = soNgayMuon[i + 1];
                    tienPhat[i] = tienPhat[i + 1];
                }

                soLuong--;

                printf("Xoa phieu muon thanh cong!\n");

                break;
            }

            // ================= THONG KE =================
            case 5: {
                int coPhieuPhat = 0;

                printf("\n=== DANH SACH PHIEU BI PHAT ===\n");

                for (int i = 0; i < soLuong; i++) {
                    if (soNgayMuon[i] > 14) {
                        printf("%d. %s | %s | %d ngay | %d VND\n",
                               i + 1,
                               maPhieu[i],
                               tenSach[i],
                               soNgayMuon[i],
                               tienPhat[i]);

                        coPhieuPhat = 1;
                    }
                }

                if (coPhieuPhat == 0) {
                    printf("Khong co luot muon nao bi qua han phat!\n");
                }

                break;
            }

            // ================= THOAT =================
            case 6:
                printf("Cam on ban da su dung chuong trinh!\n");
                break;

            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
        }

    } while (choice != 6);

    return 0;
}