#include <stdio.h>
#include "function.h"

void hienThiMenuChinh() {
    printf("\n=== He Thong Quan Ly Thu Vien ===\n");
    printf("[1]. Hien thi danh sach sach\n");
    printf("[2]. Them sach moi\n");
    printf("[3]. Sua thong tin sach\n");
    printf("[4]. Xoa sach\n");
    printf("0. Thoat chuong trinh\n");
    printf("Nhap lua chon cua ban: ");
}

void manHinhHienThiDanhSach(Sach *thuVien, int soLuongSach) {
    while (1) {
        printf("\n--- Hien Thi Danh Sach ---\n");
        hienThiDanhSachSach(thuVien, soLuongSach);
        printf("Nhap [1] de quay lai menu: ");
        int luaChon;
        scanf("%d", &luaChon);
        if (luaChon == 1) break;
        else printf("Lua chon khong hop le. Vui long thu lai.\n");
    }
}

void manHinhThemSach(Sach *thuVien, int *soLuongSach) {
    while (1) {
        printf("\n--- Them Sach Moi ---\n");
        themSach(thuVien, soLuongSach);
        printf("1. Quay lai menu chinh\n");
        printf("Nhap lua chon cua ban: ");
        int luaChon;
        scanf("%d", &luaChon);
        if (luaChon == 1) break;
        else printf("Lua chon khong hop le. Vui long thu lai.\n");
    }
}

void manHinhSuaSach(Sach *thuVien, int soLuongSach) {
    while (1) {
        printf("\n--- Sua Thong Tin Sach ---\n");
        suaSach(thuVien, soLuongSach);
        printf("1. Quay lai menu chinh\n");
        printf("Nhap lua chon cua ban: ");
        int luaChon;
        scanf("%d", &luaChon);
        if (luaChon == 1) break;
        else printf("Lua chon khong hop le. Vui long thu lai.\n");
    }
}

void manHinhXoaSach(Sach *thuVien, int *soLuongSach) {
    while (1) {
        printf("\n--- Xoa Sach ---\n");
        xoaSach(thuVien, soLuongSach);
        printf("1. Quay lai menu chinh\n");
        printf("Nhap lua chon cua ban: ");
        int luaChon;
        scanf("%d", &luaChon);
        if (luaChon == 1) break;
        else printf("Lua chon khong hop le. Vui long thu lai.\n");
    }
}

int main() {
    Sach thuVien[100];
    int soLuongSach = 0;

    while (1) {
        hienThiMenuChinh();
        int luaChon;
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                manHinhHienThiDanhSach(thuVien, soLuongSach);
                break;
            case 2:
                manHinhThemSach(thuVien, &soLuongSach);
                break;
            case 3:
                manHinhSuaSach(thuVien, soLuongSach);
                break;
            case 4:
                manHinhXoaSach(thuVien, &soLuongSach);
                break;
            case 0:
                printf("Thoat chuong trinh. Tam biet!\n");
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    }

    return 0;
}

