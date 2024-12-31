#include "function.h"
#include <stdio.h>
#include <string.h>

void hienThiDanhSachSach(Sach *thuVien, int soLuongSach) {
    if (soLuongSach == 0) {
        printf("Thu vien hien khong co sach nao.\n");
        return;
    }

    printf("===============================================================\n");
    printf(" ID  | Ten sach             | Tac gia             | Gia (VND)  \n");
    printf("===============================================================\n");

    for (int i = 0; i < soLuongSach; i++) {
        printf(" %-3d | %-20s | %-20s | %-10.2f\n",
               thuVien[i].id, thuVien[i].ten, thuVien[i].tacGia, thuVien[i].gia);
    }

    printf("===============================================================\n");
}

void themSach(Sach *thuVien, int *soLuongSach) {
    Sach sachMoi;
    sachMoi.id = *soLuongSach + 1;

    printf("Nhap ten sach: ");
    getchar();
    fgets(sachMoi.ten, sizeof(sachMoi.ten), stdin);
    sachMoi.ten[strcspn(sachMoi.ten, "\n")] = '\0';

    printf("Nhap ten tac gia: ");
    fgets(sachMoi.tacGia, sizeof(sachMoi.tacGia), stdin);
    sachMoi.tacGia[strcspn(sachMoi.tacGia, "\n")] = '\0';

    printf("Nhap gia sach (VND): ");
    scanf("%f", &sachMoi.gia);

    thuVien[*soLuongSach] = sachMoi;
    (*soLuongSach)++;

    printf("Them sach thanh cong!\n");
}


void suaSach(Sach *thuVien, int soLuongSach) {
    int id;
    printf("Nhap ID sach can sua: ");
    scanf("%d", &id);

    if (id <= 0 || id > soLuongSach) {
        printf("ID sach khong ton tai.\n");
        return;
    }

    Sach *sach = &thuVien[id - 1];
    printf("\nThong tin hien tai cua sach:\n");
    printf("ID: %d\n", sach->id);
    printf("Ten sach: %s\n", sach->ten);
    printf("Tac gia: %s\n", sach->tacGia);
    printf("Gia: %.2f VND\n", sach->gia);

  
    printf("\nNhap thong tin moi cho sach (nhan Enter de giu nguyen):\n");

    printf("Nhap ten moi: ");
    getchar(); 
    char tenMoi[50];
    fgets(tenMoi, sizeof(tenMoi), stdin);
    if (strlen(tenMoi) > 1) { 
        tenMoi[strcspn(tenMoi, "\n")] = '\0'; 
        strcpy(sach->ten, tenMoi); 
    }

    printf("Nhap tac gia moi: ");
    char tacGiaMoi[50];
    fgets(tacGiaMoi, sizeof(tacGiaMoi), stdin);
    if (strlen(tacGiaMoi) > 1) { 
        tacGiaMoi[strcspn(tacGiaMoi, "\n")] = '\0'; 
        strcpy(sach->tacGia, tacGiaMoi); 
    }

    printf("Nhap gia moi (nhap 0 de giu nguyen): ");
    float giaMoi;
    scanf("%f", &giaMoi);
    if (giaMoi != 0) { 
        sach->gia = giaMoi;
    }

    printf("\nSua thong tin sach thanh cong!\n");
    printf("Thong tin moi cua sach:\n");
    printf("ID: %d\n", sach->id);
    printf("Ten sach: %s\n", sach->ten);
    printf("Tac gia: %s\n", sach->tacGia);
    printf("Gia: %.2f VND\n", sach->gia);
}

void xoaSach(Sach *thuVien, int *soLuongSach) {
    int id;
    printf("Nhap ID sach can xoa: ");
    scanf("%d", &id);

    if (id <= 0 || id > *soLuongSach) {
        printf("ID sach khong ton tai.\n");
        return;
    }

    printf("Xoa sach thanh cong: ID=%d, Ten='%s', Tac gia='%s', Gia=%.2f VND\n",
           thuVien[id - 1].id, thuVien[id - 1].ten, thuVien[id - 1].tacGia, thuVien[id - 1].gia);

    for (int i = id - 1; i < *soLuongSach - 1; i++) {
        thuVien[i] = thuVien[i + 1];
    }
    (*soLuongSach)--;
}

