#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Sach { //Dinh nghia cau truc Sach
    char maSach[10];
    char tenSach[100];
    char tacGia[50];
    char ngayXB[15];
    int soLuong;
    int giaSach;
    struct Sach* next;
} Sach;

typedef struct NguoiMuon { //Dinh nghia cau truc NguoiMuon
	char mttv[10];
	char hoTen[50];
	char sdt[10];
	char maSach[10];
	char tenSach[100];
	int soLuong;
	char ngayMuon[15];
	char ngayTra[15];
	struct NguoiMuon* next;
} NguoiMuon;

// Ham tao nut Sach moi
Sach* taoNodeSach(char* maSach, char* tenSach, char* tacGia, char* ngayXB, int soLuong, int giaSach) {
    Sach* newNode = (Sach*)malloc(sizeof(Sach));
    strcpy(newNode->maSach, maSach);
    strcpy(newNode->tenSach, tenSach);
    strcpy(newNode->tacGia, tacGia);
    strcpy(newNode->ngayXB, ngayXB);
    newNode->soLuong = soLuong;
    newNode->giaSach = giaSach;
    newNode->next = NULL;
    return newNode;
}

// Ham tao nut NguoiMuon moi
NguoiMuon* taoNodeNguoiMuon(char* mttv, char* hoTen, char* sdt, char* maSach, char* tenSach, int soLuong, char* ngayMuon, char* ngayTra) {
    NguoiMuon* newNode = (NguoiMuon*)malloc(sizeof(NguoiMuon));
    strcpy(newNode->mttv, mttv);
    strcpy(newNode->hoTen, hoTen);
    strcpy(newNode->sdt, sdt);
    strcpy(newNode->maSach, maSach);
    strcpy(newNode->tenSach, tenSach);
    strcpy(newNode->ngayMuon, ngayMuon);
    strcpy(newNode->ngayTra, ngayTra);
    newNode->soLuong = soLuong;
    newNode->next = NULL;
    return newNode;
}

// Ham them sach
void themSach(Sach** head) {
    char tiepTucThemSach;
    do {
        char maSach[10], tenSach[100], tacGia[50], ngayXB[15];
        int soLuong, giaSach;
        printf("Nhap ma sach: ");
        scanf("%s", maSach);
        getchar();
        printf("Nhap ten sach: ");
        fgets(tenSach, 100, stdin);
        tenSach[strcspn(tenSach, "\n")] = 0;
        printf("Nhap tac gia: ");
        fgets(tacGia, 50, stdin);
        tacGia[strcspn(tacGia, "\n")] = 0;
        printf("Nhap ngay xuat ban: ");
        scanf("%s", ngayXB);
        printf("Nhap so luong: ");
        scanf("%d", &soLuong);
        printf("Nhap gia sach: ");
        scanf("%d", &giaSach);
        Sach* newNode = taoNodeSach(maSach, tenSach, tacGia, ngayXB, soLuong, giaSach);
        Sach* current = *head;
        Sach* prev = NULL;

        while (current != NULL && strcmp(current->maSach, maSach) < 0) {
            prev = current;
            current = current->next;
        }

        if (prev == NULL) {
            newNode->next = *head;
            *head = newNode;
        } else {
            newNode->next = current;
            prev->next = newNode;
        }

        printf("Da them sach ma so %s\n", maSach);
        printf("Ban co muon them sach nua khong?: ");
        getchar();
        scanf("%c", &tiepTucThemSach);
        getchar();

    } while (tiepTucThemSach == 'y' || tiepTucThemSach == 'Y');
}

// Ham xoa sach theo MS sach
void xoaSach(Sach** head) {
	char tiepTucXoaSach;
	do {
		char maSachCanXoa[10];
        printf("Nhap ma sach can xoa: ");
        scanf("%s", maSachCanXoa);
    Sach* current = *head;
    Sach* prev = NULL;
    
    while (current != NULL && strcmp(current->maSach, maSachCanXoa) != 0) {
        prev = current;
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Khong tim thay sach voi MS %s\n", maSachCanXoa);
        return;
    }
    
    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }
    
    free(current);
    printf("Da xoa sach voi MS %s\n", maSachCanXoa); // Thong bao xoa sach thanh cong
    printf("Ban co muon xoa sach nua khong?: ");
        getchar();
        scanf("%c", &tiepTucXoaSach);
        getchar();
    } while (tiepTucXoaSach == 'y' || tiepTucXoaSach == 'Y');
}

// Ham them nguoi muon
void themNguoiMuon(NguoiMuon** head){
	char mttv[10];
	char tiepTucThemNguoiMuon;
	do {
	char hoTen[50], sdt[10], maSach[10], tenSach[100], ngayMuon[15], ngayTra[15];
    int soLuong;
    printf("Nhap ma the thu vien: ");
    scanf("%s", mttv);
    getchar(); // Xoa bo dem
    printf("Nhap ho ten: ");
    fgets(hoTen, 50, stdin);
    hoTen[strcspn(hoTen, "\n")] = 0;
    printf("Nhap so dien thoai: ");
    scanf("%s", sdt);
    getchar();
    printf("Nhap ma sach: ");
    scanf("%s", maSach);
    getchar();
    printf("Nhap ten sach: ");
    fgets(tenSach, 100, stdin);
    tenSach[strcspn(tenSach, "\n")] = 0; // Xoa ky tu xuong dong
    printf("Nhap so luong: ");
    scanf("%d", &soLuong);
    getchar();
    printf("Nhap ngay muon: ");
    scanf("%s", ngayMuon);
    getchar();
    printf("Nhap ngay tra: ");
    scanf("%s", ngayTra);
    getchar();
    NguoiMuon* newNode = taoNodeNguoiMuon(mttv, hoTen, sdt, maSach, tenSach, soLuong, ngayMuon, ngayTra);
    NguoiMuon* current = *head;
    NguoiMuon* prev = NULL;
    
    // Tim vi tri chen
    while (current != NULL && strcmp(current->mttv, mttv) < 0) {
        prev = current;
        current = current->next;
    }
    
    // Chen nut
    if (prev == NULL) {
        newNode->next = *head;
        *head = newNode;
    } else {
        newNode->next = current;
        prev->next = newNode;
    }
    
    printf("Da them nguoi muon voi ma the %s\n", mttv); // Thong bao them nguoi muon thanh cong
    printf("Ban co muon them nguoi muon nua khong?: ");
    getchar();
    scanf(" %c", &tiepTucThemNguoiMuon);
     } while (tiepTucThemNguoiMuon == 'y' || tiepTucThemNguoiMuon == 'Y');
}
    

// Ham xoa nguoi muon theo ma the thu vien
void xoaNguoiMuon(NguoiMuon** head) {
	char tiepTucXoaNguoiMuon;
    do {
        char mttvCanXoa[10];
        printf("Nhap ma the thu vien can xoa: ");
        scanf("%s", mttvCanXoa);
    NguoiMuon* current = *head;
    NguoiMuon* prev = NULL;
    
    while (current != NULL && strcmp(current->mttv, mttvCanXoa) != 0) {
        prev = current;
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Khong tim thay nguoi muon voi ma the %s\n", mttvCanXoa);
        return;
    }
    
    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }
    
    free(current);
    printf("Da xoa nguoi muon voi ma the %s\n", mttvCanXoa); // Thong bao xoa nguoi muon thanh cong
    printf("Ban co muon xoa nguoi muon nua khong?: ");
        getchar();
        scanf("%c", &tiepTucXoaNguoiMuon);
        getchar();
    } while (tiepTucXoaNguoiMuon == 'y' || tiepTucXoaNguoiMuon == 'Y');
}

// Ham tim kiem sach theo ma so sach
Sach* timSach(Sach* head, char* maSach) {
    while (head != NULL) {
        if (strcmp(head->maSach, maSach) == 0)
            return head;
        head = head->next;
    }
    return NULL;
}

// Ham tim kiem nguoi muon theo ma the thu vien
NguoiMuon* timNguoiMuon(NguoiMuon* head, char* mttv) {
    while (head != NULL) {
        if (strcmp(head->mttv, mttv) == 0)
            return head;
        head = head->next;
    }
    return NULL;
}

// Ham hien thi danh sach sach
void hienthiSach(Sach* head) {
    printf("\nDanh sach sach\n");
    printf("%-10s %-50s %-30s %-20s %-10s %-10s\n", "MS sach", "Ten sach", "Tac gia", "Ngay xuat ban", "So luong", "Gia sach");
    while (head != NULL) {
        printf("%-10s %-50s %-30s %-20s %-10d %-10lld\n", head->maSach, head->tenSach, head->tacGia, head->ngayXB, head->soLuong, head->giaSach);
        head = head->next;
    }
}

// Ham hien thi danh sach nguoi muon
void hienthiNguoiMuon(NguoiMuon* head) {
    printf("\nDanh sach nguoi muon\n");
    printf("%-10s %-50s %-20s %-10s %-50s %-10s %-20s %-20s\n", "Ma the", "Ten nguoi muon", "SDT", "MS sach", "Ten sach", "So Luong", "Ngay muon", "Ngay tra");
    while (head != NULL) {
        printf("%-10s %-50s %-20s %-10s %-50s %-10d %-20s %-20s\n", head->mttv, head->hoTen, head->sdt, head->maSach, head->tenSach, head->soLuong, head->ngayMuon, head->ngayTra);
        head = head->next;
    }
}

// Ham ghi danh sach ra file text
void ghifileSach(Sach* head, const char* filename) {
    FILE* f = fopen(filename, "w");
    if (f == NULL) {
        printf("Khong the mo file %s\n", filename);
        return;
    }
    
    while (head != NULL) {
        fprintf(f, "%-10s %-50s %-30s %-20s %-10d %-10lld\n", head->maSach, head->tenSach, head->tacGia, head->ngayXB, head->soLuong, head->giaSach);
        head = head->next;
    }
    
    fclose(f);
    printf("Da ghi danh sach vao file %s\n", filename);
}

// Ham ghi danh sach ra file text
void ghifileNguoiMuon(NguoiMuon* head, const char* filename) {
    FILE* f = fopen(filename, "w");
    if (f == NULL) {
        printf("Khong the mo file %s\n", filename);
        return;
    }
    
    while (head != NULL) {
        fprintf(f, "%-10s %-50s %-20s %-10s %-50s %-10d %-20s %-20s\n", head->mttv, head->hoTen, head->sdt, head->maSach, head->tenSach, head->soLuong, head->ngayMuon, head->ngayTra);
        head = head->next;
    }
    
    fclose(f);
    printf("Da ghi danh sach vao file %s\n", filename);
}

void sapXepSachTheoMaSach(Sach** head, int tangDanMS) {
    if (*head == NULL || (*head)->next == NULL) return;

    for (Sach* i = *head; i != NULL; i = i->next) {
        for (Sach* j = i->next; j != NULL; j = j->next) {
            int cmp = strcmp(i->maSach, j->maSach);
            if ((tangDanMS && cmp > 0) || (!tangDanMS && cmp < 0)) {
                char tempMS[10], tempTenSach[100], tempTacGia[50], tempNgayXB[15];
                int tempSL, tempGiaSach;

                strcpy(tempMS, i->maSach);
                strcpy(tempTenSach, i->tenSach);
                strcpy(tempTacGia, i->tacGia);
                strcpy(tempNgayXB, i->ngayXB);
                tempSL = i->soLuong;
                tempGiaSach = i->giaSach;

                strcpy(i->maSach, j->maSach);
                strcpy(i->tenSach, j->tenSach);
                strcpy(i->tacGia, j->tacGia);
                strcpy(i->ngayXB, j->ngayXB);
                i->soLuong = j->soLuong;
                i->giaSach = j->giaSach;

                strcpy(j->maSach, tempMS);
                strcpy(j->tenSach, tempTenSach);
                strcpy(j->tacGia, tempTacGia);
                strcpy(j->ngayXB, tempNgayXB);
                j->soLuong = tempSL;
                j->giaSach = tempGiaSach;
            }
        }
    }
}

void menuSapXepSach(Sach** head) {
    int luaChon;
    printf("\n--- SAP XEP SACH THEO MA SACH---\n");
    printf("1. Tang dan\n");
    printf("2. Giam dan\n");
    printf("Chon cach sap xep: ");
    scanf("%d", &luaChon);
    if (luaChon == 1 || luaChon == 2) {
        sapXepSachTheoMaSach(head, luaChon == 1);
        printf("Da sap xep sach theo ma %s dan.\n", luaChon == 1 ? "tang" : "giam");
    } else {
        printf("Lua chon khong hop le.\n");
    }
}

void sapXepNguoiMuonTheoMTTV(NguoiMuon** head, int tangDanMTTV) {
    if (*head == NULL || (*head)->next == NULL) return;

    for (NguoiMuon* i = *head; i != NULL; i = i->next) {
        for (NguoiMuon* j = i->next; j != NULL; j = j->next) {
            int cmp = strcmp(i->mttv, j->mttv);
            if ((tangDanMTTV && cmp > 0) || (!tangDanMTTV && cmp < 0)) {
                char tempMTTV[10], tempHoTen[100], tempSDT[50], tempMS[10], tempTenSach[100], tempNgayMuon[15], tempNgayTra[15];
                int tempSL;

                strcpy(tempMTTV, i->mttv);
                strcpy(tempHoTen, i->hoTen);
                strcpy(tempSDT, i->sdt);
                strcpy(tempMS, i->maSach);
                strcpy(tempTenSach, i->tenSach);
                strcpy(tempNgayMuon, i->ngayMuon);
                strcpy(tempNgayTra, i->ngayTra);
                tempSL = i->soLuong;

                strcpy(i->mttv, j->mttv);
                strcpy(i->hoTen, j->hoTen);
                strcpy(i->sdt, j->sdt);
                strcpy(i->maSach, j->maSach);
                strcpy(i->tenSach, j->tenSach);
                strcpy(i->ngayMuon, j->ngayMuon);
                strcpy(i->ngayTra, j->ngayTra);
                i->soLuong = j->soLuong;

                strcpy(j->mttv, tempMTTV);
                strcpy(j->hoTen, tempHoTen);
                strcpy(j->sdt, tempSDT);
                strcpy(j->maSach, tempMS);
                strcpy(j->tenSach, tempTenSach);
                strcpy(j->ngayMuon, tempNgayMuon);
                strcpy(j->ngayTra, tempNgayTra);
                j->soLuong = tempSL;
            }
        }
    }
}

void menuSapXepNguoiMuon(NguoiMuon** head) {
    int luachon;
    printf("\n--- SAP XEP NGUOI MUON THEO MA THE THU VIEN---\n");
    printf("1. Tang dan\n");
    printf("2. Giam dan\n");
    printf("Chon cach sap xep: ");
    scanf("%d", &luachon);
    if (luachon == 1 || luachon == 2) {
        sapXepNguoiMuonTheoMTTV(head, luachon == 1);
        printf("Da sap xep sach theo ma %s dan.\n", luachon == 1 ? "tang" : "giam");
    } else {
        printf("Lua chon khong hop le.\n");
    }
}


// Ham main
int main() {
    Sach* sachhead = NULL;
    NguoiMuon* muonhead = NULL;
    int choice;
    do {
        printf("\n[============== QUAN LY THU VIEN ==============]\n");
        printf("| 1. Them sach                                 |\n");
        printf("| 2. Xoa sach                                  |\n");
        printf("| 3. Tim kiem sach theo ma so sach             |\n");
        printf("| 4. Them nguoi muon                           |\n");
        printf("| 5. Xoa nguoi muon                            |\n");
        printf("| 6. Tim kiem nguoi muon theo ma the thu vien  |\n");
        printf("| 7. Hien thi danh sach sach                   |\n");
        printf("| 8. Hien thi danh sach nguoi muon             |\n");
        printf("| 9. Ghi danh sach sach ra file                |\n");
        printf("| 10. Ghi danh sach nguoi muon ra file         |\n");
        printf("| 11. Sap xep sach theo ma so                  |\n");
        printf("| 12. Sap xep nguoi muon theo mttv             |\n");
        printf("| 0. Thoat                                     |\n");
        printf("[==============================================]\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        getchar();
        
        switch (choice) {
            case 1:
                themSach(&sachhead);
                break;
            case 2:
            	if (sachhead == NULL) {
        			printf("Khong co sach de xoa.\n");
        		break;
			}
                 xoaSach(&sachhead);
                 break;
            case 3: {
            	if (sachhead == NULL) {
        			printf("Khong co sach de tim kiem.\n");
        		break;
			}
                char maSach[10];
                printf("Nhap MS sach can tim: ");
                scanf("%s", maSach);
                Sach* s = timSach(sachhead, maSach);
                if (s) {
                	printf("%-10s %-50s %-30s %-20s %-10d %-10d\n", "MaSach", "TenSach", "TacGia", "NgayXB", "SoLuong", "GiaSach");
                    printf("%-10s %-50s %-30s %-20s %-10d %-10d\n", s->maSach, s->tenSach, s->tacGia, s->ngayXB, s->soLuong, s->giaSach);
                } else {
                    printf("Khong tim thay sach\n"); }
                break;
            }
            case 4:
            	themNguoiMuon(&muonhead);
            	break;
            case 5: {
            	if (muonhead == NULL) {
        			printf("Khong co nguoi muon de xoa.\n");
        		break;
			}
            	xoaNguoiMuon(&muonhead);
				break;
			}
            case 6: {
            	if (muonhead == NULL) {
        			printf("Khong co nguoi muon de tim kiem.\n");
        		break;
			}
            	char mttv[10];
            	printf("Nhap ma the thu vien cua nguoi muon can tim: ");
            	scanf("%s", mttv);
            	NguoiMuon* nm = timNguoiMuon(muonhead, mttv);
            	if (nm) {
            	    printf("%-10s %-50s %-10s %-10s %-50s %-10d %-20s %-20s\n", nm->mttv, nm->hoTen, nm->sdt, nm->maSach, nm->tenSach, nm->soLuong, nm->ngayMuon, nm->ngayTra);
                } else {
            	    printf("Khong tim thay nguoi muon\n"); }
				break;
			}
			case 7:
				hienthiSach(sachhead);
                break;
            case 8:
            	hienthiNguoiMuon(muonhead);
            	break;
            case 9:
                ghifileSach(sachhead, "sach.txt");
                break;
            case 10:
                ghifileNguoiMuon(muonhead, "nguoi_muon.txt");
                break;
            case 11:
            	if (sachhead == NULL) {
        		printf("Khong co sach de sap xep.\n");
        		break;
        	}
    			menuSapXepSach(&sachhead);
    			break;
    		case 12:
    			if (muonhead == NULL) {
    			printf("Khong co nguoi muon de sap xep.\n");
				break;	
			}
    			menuSapXepNguoiMuon(&muonhead);
    			break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
                break;

    } 
} while (choice != 0);

    // Giai phong bo nho
    while (sachhead != NULL) {
        Sach* temp = sachhead;
        sachhead = sachhead->next;
        free(temp);
    }
    while (muonhead != NULL) {
    	NguoiMuon* temp = muonhead;
    	muonhead = muonhead->next;
    	free(temp);
	}
    
    return 0;
}
