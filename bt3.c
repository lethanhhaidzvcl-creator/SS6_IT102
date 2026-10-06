#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char maPhieu[MAX][20];
    char maSach[MAX][20];
    int soNgayMuon[MAX];

    int soLuong = 0;
    int choice;

    do {
        printf("\n========== HE THONG QUAN LY MUON TRA SACH ==========\n");
        printf("1. Them moi phieu muon sach\n");
        printf("2. Hien thi danh sach phieu muon\n");
        printf("3. Cap nhat so ngay muon sach\n");
        printf("4. Xac nhan tra sach / Xoa phieu muon\n");
        printf("5. Thoat\n");
        printf("=====================================================\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        while (getchar() != '\n');

        switch (choice) {

            // ================= THEM =================
            case 1: {
                if (soLuong >= MAX) {
                    printf("Bo nho danh sach da day, khong the them moi!\n");
                    break;
                }

                char maPhieuMoi[20];
                int trung = 0;

                printf("\n--- THEM MOI PHIEU MUON ---\n");

                printf("Nhap ma phieu: ");
                scanf("%s", maPhieuMoi);

                while (getchar() != '\n');

                // Kiem tra trung ma phieu
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maPhieuMoi) == 0) {
                        trung = 1;
                        break;
                    }
                }

                if (trung == 1) {
                    printf("Ma phieu da ton tai trong he thong!\n");
                    break;
                }

                strcpy(maPhieu[soLuong], maPhieuMoi);

                printf("Nhap ma sach: ");
                scanf("%s", maSach[soLuong]);

                while (getchar() != '\n');

                do {
                    printf("Nhap so ngay muon: ");
                    scanf("%d", &soNgayMuon[soLuong]);

                    if (soNgayMuon[soLuong] <= 0) {
                        printf("So ngay muon phai > 0!\n");
                    }

                } while (soNgayMuon[soLuong] <= 0);

                while (getchar() != '\n');

                soLuong++;

                printf("Them moi phieu muon thanh cong!\n");

                break;
            }

            // ================= HIEN THI =================
            case 2: {
                if (soLuong == 0) {
                    printf("Danh sach phieu muon hien dang rong!\n");
                    break;
                }

                printf("\n================ DANH SACH PHIEU MUON ================\n");

                printf("%-5s %-12s %-15s %-10s %-15s %-15s\n",
                       "STT", "MA PHIEU", "MA SACH",
                       "SO NGAY", "TRANG THAI", "TIEN PHAT");

                printf("--------------------------------------------------------------------------\n");

                for (int i = 0; i < soLuong; i++) {

                    int ngayQuaHan;
                    int tienPhat;

                    if (soNgayMuon[i] > 14) {
                        ngayQuaHan = soNgayMuon[i] - 14;
                        tienPhat = ngayQuaHan * 5000;

                        printf("%-5d %-12s %-15s %-10d %-15s %-15d\n",
                               i + 1,
                               maPhieu[i],
                               maSach[i],
                               soNgayMuon[i],
                               "QUA HAN",
                               tienPhat);
                    } else {
                        tienPhat = 0;

                        printf("%-5d %-12s %-15s %-10d %-15s %-15d\n",
                               i + 1,
                               maPhieu[i],
                               maSach[i],
                               soNgayMuon[i],
                               "DUNG HAN",
                               tienPhat);
                    }
                }

                printf("--------------------------------------------------------------------------\n");

                break;
            }

            // ================= CAP NHAT =================
            case 3: {
                char maNhap[20];
                int pos = -1;
                int ngayMoi;

                printf("\n--- CAP NHAT SO NGAY MUON ---\n");

                printf("Nhap ma phieu can cap nhat: ");
                scanf("%s", maNhap);

                while (getchar() != '\n');

                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maNhap) == 0) {
                        pos = i;
                        break;
                    }
                }

                if (pos == -1) {
                    printf("Khong tim thay ma phieu trong he thong!\n");
                    break;
                }

                printf("So ngay muon hien tai cua phieu %s la: %d\n",
                       maPhieu[pos], soNgayMuon[pos]);

                do {
                    printf("Nhap so ngay muon moi: ");
                    scanf("%d", &ngayMoi);

                    if (ngayMoi <= 0) {
                        printf("So ngay muon phai > 0!\n");
                    }

                } while (ngayMoi <= 0);

                soNgayMuon[pos] = ngayMoi;

                while (getchar() != '\n');

                printf("Cap nhat so ngay muon thanh cong!\n");

                break;
            }

            // ================= XOA =================
            case 4: {
                char maNhap[20];
                int pos = -1;

                printf("\n--- XAC NHAN TRA SACH / XOA PHIEU ---\n");

                printf("Nhap ma phieu xac nhan tra/xoa: ");
                scanf("%s", maNhap);

                while (getchar() != '\n');

                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maNhap) == 0) {
                        pos = i;
                        break;
                    }
                }

                if (pos == -1) {
                    printf("Khong tim thay ma phieu can xoa!\n");
                    break;
                }

                // Don mang
                for (int i = pos; i < soLuong - 1; i++) {
                    strcpy(maPhieu[i], maPhieu[i + 1]);
                    strcpy(maSach[i], maSach[i + 1]);
                    soNgayMuon[i] = soNgayMuon[i + 1];
                }

                soLuong--;

                printf("Xac nhan tra sach va xoa phieu muon thanh cong!\n");

                break;
            }

            // ================= THOAT =================
            case 5:
                printf("Cam on ban da su dung chuong trinh!\n");
                break;

            default:
                printf("Lua chon khong hop le, vui long chon lai!\n");
        }

    } while (choice != 5);

    return 0;
}