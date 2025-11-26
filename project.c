#include <stdio.h>
#include <string.h>
#define MAX 100
#include <ctype.h>


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

struct Product Product1[MAX] = {
	{"P001", "Sua hop",      "Hop",   50,  1},
    {"P002", "Mi tom",       "Goi",   120, 1},  
    {"P008", "But bi",       "cay",   120, 1},
    {"P005", "Vo ke ngang",  "quyen", 50,  1},
    {"P003", "Thuoc nhuom",  "hop",   0,   1}
};
int size=5;
char key[20];

void toLower();
void printMenu();
void remoNewline ();
void addOrderForm();
void updateProduct();
void management();
void FindMaterial();
void listMaterial();
void sortingMaterial();
void printMaterial();
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
				management();
				break;
			case 4 :
				FindMaterial();
				break;
			case 5 :
				listMaterial();
				break;
			case 6 :
				sortingMaterial();
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

void toLower(char s[]){ // doi chua hoa thanh chu thuong
    int i=0;
    while(s[i]!='\0'){
        if(s[i]>='A'&&s[i]<='Z'){
            s[i]=s[i]+32;
        }
        i++;
    }
}

void addOrderForm  () {
	if(size == MAX) {
		printf("Danh sach day, Them moi hang hoa that bai !! \n");
		return;
	}
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

        printf("==> Da them thanh cong san pham , mang da co phan tu moi!\n");
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
        printf("Vat tu %s khong ton tai !\n",key);
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

        

        printf("==> Cap nhat hang hoa %s thanh cong  !\n",key);
    }
	
	void management() {
		printf("nhap ma vat tu can thay doi trang thai : \n");
		
		fgets(key,sizeof(key),stdin);
		remoNewline(key);
		int found = -1 ;
		
		for(int i = 0 ; i < size ; i++) {
			if(strcmp(Product1[i].productId,key)==0) {
			found = i;
			break;
		}
		}
		
		if(found== -1) {
			printf("Ma vat tu %s khong ton tai trong danh sach  !!! \n ",key);
			return;
		}
		if(Product1[found].status !=0) {
			Product1[found].status= 0;
			printf("Doi trang thai hang hoa %s thanh cong !! \n",key);
		} else {
			printf(" trang thai hang hoa %s dang o 0  !! \n",key);
		}
			
			
			
	}		
	void FindMaterial() {
		printf("Nhap ma vat tu hoac ten vat tu de tim kiem : \n ");
		fgets(key,sizeof(key),stdin);
		remoNewline(key);
		
	
		
		toLower(key);
		
		int found = 0;
		
		for(int i = 0 ; i <size ; i++) {
			
		// chuyen name cua san pham sang chua thuong de so sanh
		char nameLower[50];
		strcpy(nameLower, Product1[i].name);
		 toLower(nameLower);
        
		// So sanh:
        // 1) ID so sanh chinh xac
        // 2) Name so sánh khong phan biet hoa thuong
        if (strcmp(Product1[i].productId, key) == 0 ||
            strstr(nameLower, key) != NULL)
        {
        	
            printf("| Ten: %s | Don vi: %s | Ton kho: %d | Trang thai: %d |\n",
                   Product1[i].name, Product1[i].unit, Product1[i].qty, Product1[i].status);
            found++;
        }
    }

    if (found== 0) {
        printf("Khong tim thay san pham nao!\n");
    } else {
    	printf("Tim thay tong %d vat tu \n ",found);
	}
}

	void listMaterial() {
		int page = 1;
		int itemPerPage = 10;
		// tinh tong so trang 
		int numPage = size/itemPerPage; // tim xem so trang khong tinh le la bao nhieu 
		int total_page = (size % itemPerPage == 0 )? numPage : numPage+1; // kiem tra dieu kien chia het hay khong ? neu chia het numPage giua nguyen 
		// neu chia du thi numPage + 1 trang
		
		while(1) {
			
			printf("Moi ban chon so trang can xem (1-%d) : \n",total_page);
			scanf("%d",&page);
			// kiem tra dieu kien
			if(page < 0 || page > total_page) {
				printf("loi nhap sai so trang !! \n");
				continue;
			} else {
				int start = (page-1)*itemPerPage; 	// vi tri bat dau den ket thuc
			    int end = start + itemPerPage;
			    
				printf("Trang %d/%d :\n\n", page, total_page); // trang 1/5
  	            printf("+---+------------------------------+--------------------+----------+\n");
 		     	printf("|%-3s|%-30s|%-20s|%-10s|\n", "MA", "Ten vat pham","Don vi hang hoa","So luong ton kho");
     		 	printf("+---+------------------------------+--------------------+----------+\n");
     		 	
      			for (int i = start; i < end && i < size; i++) {
          		printf("|%-3s|%-30s|%-20d|%-10d|\n", Product1[i].productId, Product1[i].name, Product1[i].unit, Product1[i].qty);
      			 }
      			printf("+---+------------------------------+--------------------+----------+\n");
       			fflush(stdin);
      			printf("Ban co muon thoat hay ko ? (y/n)");
       			char ch = getchar();
    		  	if (ch == 'y' || ch == 'Y') {
    	      	break;
   			    	}
  				 }
			}
			
			
			
		
			

};

void printMaterial() {

    printf("+---+------------------------------+--------------------+----------+\n");
 	printf("|%-3s|%-30s|%-20s|%-10s|\n", "MA", "Ten vat pham","Don vi hang hoa","So luong ton kho");
    printf("+---+------------------------------+--------------------+----------+\n");
    for (int i = 0; i < size ; i++) {
    		printf("|%-3s|%-30s|%-20d|%-10d|\n", Product1[i].productId, Product1[i].name, Product1[i].unit, Product1[i].qty);
      			 }
      			 printf("+---+------------------------------+--------------------+----------+\n");
       			 
}

void sortingMaterial(){
	struct Product temp;
	if(size==0) {
		printf("Danh sach hang hoa rong \n");
		return;
	}
	int choice;
	
		printf("Sap xep theo ten hoac so luong : \n");
		printf("chon 1 de sap xep theo so luong  \n  Chon 2 de sap xep theo ten \n");
		while(1) {
			scanf("%d",&choice); 
			if(choice==1 || choice == 2) {
				break;
			} else {
				printf("LOI !!!");
				continue;
			}
		}
	
		
		switch(choice) {
			case 1:
				for(int i =0 ; i < size ; i++){
					for(int j=0 ; j < size - i - 1 ;j++){
						if(Product1[j].qty > Product1[j+1].qty  ) {
							temp = Product1[j];
							Product1[j] = Product1[j+1];
							Product1[j+1]= temp;
						}
					}	
				}
				printf("da sap xep thanh cong \n");
				printMaterial();
				
				break;
			case 2:
				for(int i =0 ; i < size ; i++){
					for(int j=0 ; j < size - i - 1 ;j++){
						if(strcmp(Product1[j].name, Product1[j+1].name)>0  ) {
							temp = Product1[j];
							Product1[j] = Product1[j+1];
							Product1[j+1]= temp;
						}
					}	
				}
				printf("da sap xep thanh cong \n");
				printMaterial();
				break;
					
			
		}
	
	
	
}
	
	


