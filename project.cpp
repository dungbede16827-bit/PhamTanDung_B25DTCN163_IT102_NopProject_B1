#include <stdio.h>
#include <string.h>
#define MAX 100


struct Product {
	
		char productId[10];
		char name[50];
		char unit[10];
		int qty;
		int status; // 1 = active
};
struct Transaction {
	char transId[20];
	char productId[10];
	char type[5];
	char date[15];

};
int size=0;
struct Product Product1[MAX];
char key[20];


void printMenu();
void remoNewline ();
void addOrderForm();
void updateProduct();
int main() {
	int choice ;
	
	while (1) {
		printMenu();
		printf("Moi ban nhap vao lua chon cua minh : \n");
		scanf("%d",&choice);
		fflush(stdin);
		switch (choice) {
			case 1 :
				addOrderForm() ;
				break;
			case 2 :
				updateProduct() ;
				break;
			case 3 :
				break;
			case 4 :
				break;
			case 5 :
				break;
			case 6 :
				break;
			case 7 :
				break;
			case 8 :
				break;
			case 9 :
				break;
					default:
						printf("Lua chon khong hop le vui long nhap lai !!! \n ");
			
			
		}
		
		
	}
	
	
	return 0;
}

void printMenu() {
	printf("____________MENU LUA CHON______________ \n");
	printf("|%-37s|\n","1.Them Ma hang moi .");
	printf("|%-37s|\n","2.Cap nhat thong tin .");
	printf("|%-37s|\n","3.Quan ly trang thai (khoa/xoa)");
	printf("|%-37s|\n","4.Tra cuu tim kiem ");
	printf("|%-37s|\n","5.Danh sach phan trang ");
	printf("|%-37s|\n","6.Sap xep danh sach ");
	printf("|%-37s|\n","7.Giao dich xuat/nhap mang hang hoa ");
	printf("|%-37s|\n","8.Lich su xuat nhap ");
	printf("|%-37s|\n","9.Thoat chuong trinh .");
	printf("+_____________________________________+ \n");
}
int coincideId(char id[]) {
    for (int i = 0; i < size; i++) {
        if (strcmp(Product1[i].productId, id) == 0) {
            return 1; // trung
        }
    }
    return 0; // khong trung
}

void remoNewline (char str[]) { // xoa ki tu enter
	str[strcspn(str,"\n")]='\0';
};


void addOrderForm  () {
	int n;
	printf("_________ Them Ma hang moi _________ \n");

	printf("moi ban nhap so luong ma hang moi can them vao \n ");
	scanf("%d",&n);
	fflush(stdin);
	
	if(n <= 0 || n > MAX - size) {
		printf("So luong can them vao khong hop le !!!. \n");
		return;
	}
	
	
	for (int i = 0; i < n; i++) {
		 printf("\n--- NHAP SAN PHAM THU %d ---\n", i + 1);
		
	  // productId	
 	 struct Product p;
        
        
        while (1) {
            printf("Nhap ma san pham: ");
            fgets(p.productId, sizeof(p.productId), stdin);
            remoNewline(p.productId);

            if (strlen(p.productId) == 0) {
                printf("Ma san pham khong duoc rong!\n");
                continue;
            }
            if (coincideId(p.productId)) {
                printf("Ma san pham bi trung, vui long nhap lai!\n");
                continue;
            }
            break;
    }
	
	

	while (1) {
            printf("Nhap ten hang hoa: ");
            fgets(p.name, sizeof(p.name), stdin);
            remoNewline(p.name);

            if (strlen(p.name) == 0) {
                printf("Ten hang hoa khong duoc rong!\n");
                continue;
            }
            break;
        }
	 while (1) {
            printf("Nhap don vi (Cai/Kg/Hop): ");
            fgets(p.unit, sizeof(p.unit), stdin);
            remoNewline(p.unit);

            if (strlen(p.unit) == 0) {
                printf("Don vi khong duoc rong!\n");
                continue;
            }
            break;
        }
	 while (1) {
            printf("Nhap so luong ton kho: ");
            if (scanf("%d", &p.qty) != 1 || p.qty < 0) {
                printf("So luong phai >= 0 !\n");
                fflush(stdin);
                continue;
            }
            fflush(stdin);
            break;
        }

        // status  = 1
        p.status = 1;

        // Luu sp vào mang
        Product1[size] = p;
        size++;

        printf("==> Da them thanh cong san pham!\n");
    }
}
	void updateProduct () {
		printf("moi ban nhap vao ma hang hoa can cap nhat : \n");
		fgets(key,sizeof(key),stdin);
		remoNewline(key);
		
		int found = -1;
		for( int i = 0  ;i<size;i++) {
			if(strcmp(Product1[i].productId,key)==0) {
			found = i;	
			
            break;
        }
    }
        if (found == -1) {
        printf("Khong tim thay san pham voi ma hang nay!\n");
        return;
    }
        while (1) {
        printf("cap nhat ten hang hoa: ");
        fgets(Product1[found].name, sizeof(Product1[found].name), stdin);
        remoNewline(Product1[found].name);

        if (strlen(Product1[found].name) == 0) {
            printf("Ten hang hoa khong duoc rong!\n");
            continue;
            }
            break;
      }
	 while (1) {
            printf("cap nhat lai don vi (Cai/Kg/Hop): ");
            fgets(Product1[found].unit, sizeof(Product1[found].unit), stdin);
            remoNewline(Product1[found].unit);

            if (strlen(Product1[found].unit) == 0) {
                printf("Don vi khong duoc rong!\n");
                continue;
            }
            break;
        }
	 while (1) {
            printf("cap nhat lai so luong ton kho: ");
            if (scanf("%d", &Product1[found].qty) != 1 || Product1[found].qty < 0) {
                printf("So luong phai >= 0 !\n");
                fflush(stdin);
                continue;
            }
            fflush(stdin);
            break;
        }

        // status  = 1
        Product1[found].status = 1;

        

        printf("==> Da cap nhat thanh cong san pham!\n");
    }

			
		



