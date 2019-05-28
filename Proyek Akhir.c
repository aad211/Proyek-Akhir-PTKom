#include <stdio.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <time.h>

int a, i, j;
int rak=0; //untuk mencatat banyaknya rak*/
int buku=0; //banyaknya buku saat ini*/
int lembar;
int data_user=0; //untuk default saat mulai aplikasi dia belum login

char peminjam[100]; //array untuk daftar peminjam, 2 dimensi, pertama isinya nama peminjam, di nama peminjam diisi dengan judul buku yang dipinjam
char nama_rak[100]; //pertama index rak, kedua nama rak, isinya nama rak perkarakter
char nama_buku[100]; //pertama index buku, kedua judul buku, isinya judul buku perkarakter
char cari[100];
FILE *b;
FILE *c;
int pinjam;
time_t waktu;

void judul();
void judul_menu();
void submenu();

int  arrow_menu();
void menu_login_daftar();
void lihat();
void menu();
void menu_buku_rak();
void menu_rak();
void menu_buku();

void login_logout();
void daftar();

void tambah_rak();
void ubah_rak();
void hapus_rak();

void ubah_buku();
void tambah_buku();
void hapus_buku();

void search();
void cek_buku();
void cek_buku_full();
void cek_rak();
void cek_rak_full();

void minjam();
void balikin();
void lihat_pinjam();

void keluar();

void underscore_kedip();

//---------------------------------------------------------------------------------------------------------------//
//                                                                                                               //
//                                    --------------------------------------                                     //
//                                    ||   FUNGSI UNTUK OPENING APLIKASI  ||                                     //
//                                    --------------------------------------                                     //
//                                                                                                               //
//---------------------------------------------------------------------------------------------------------------//

int main (){
	underscore_kedip(0);
	system("title Pijuk Indonesia");
	printf("\n\n\t\t\t\t\t       .--.                   .---.\n");
	printf("\t\t\t\t\t   .---|__|           .-.     |~~~|\n");
	printf("\t\t\t\t\t.--|===|--|_          |_|     |~~~|--.\n");
	printf("\t\t\t\t\t|  |===|  |'\\     .---!~|  .--|   |--|\n");
	printf("\t\t\t\t\t|  |   |  |.'\\    |===| |--|  |   |  |\n");
	printf("\t\t\t\t\t|  |   |  |\\.'\\   |   | |__|  |   |  |\n");
	printf("\t\t\t\t\t|  |   |  | \\  \\  |===| |==|  |   |  |\n");
	printf("\t\t\t\t\t|  |   |__|  \\.'\\ |   |_|__|  |~~~|__|\n");
	printf("\t\t\t\t\t|  |===|--|   \\.'\\|===|~|--|  |~~~|--|\n");
	printf("\t\t\t\t\t^--^---.--^    `-'`---^-^--^--^---'--'	\n");
	printf("\n\n\t\t\t\t\t\tSelamat datang di PIJUK!!");
	printf("\n\n\t\t\t\t     aplikasi perpustakaan online yang terintegrasi");
	printf("\n\t\t\t\t       dengan banyak perpustakaan di Indonesia\n\n\n\n\t\t\t\t\t    ");
	printf("initializing");
	b = fopen("nama rak.bin", "r");
	for (i=1; fscanf(b, "%[^\n]%*c\n", nama_rak)!=EOF; i++){
		printf(".");
		Sleep(500);
		if (i%5==0){printf("\b \b\b \b\b \b\b \b\b \b");}
		rak++;
	}
	fclose (b);
	b = fopen("nama buku.bin", "r");
	c = fopen("simpan", "w");
	for (i; fscanf(b, "%d %d %d %d %[^\n]%*c\n", &pinjam, &waktu, &j, &lembar, nama_buku)!=EOF; i++){
		printf(".");
		Sleep(500);
		if (i%5==0){printf("\b \b\b \b\b \b\b \b\b \b");}
		buku++;
		if (pinjam>=0){fprintf(c, "%d %d %d %d %s\n", pinjam, waktu, j, lembar, nama_buku);}
	}
	fclose(c);
	fclose(b);
	remove("nama buku.bin");
	rename("simpan", "nama buku.bin");
	if (pinjam<0){
		data_user = (pinjam*-1)-1;
	}
	printf("\r\t\t\t\t\t    ");
	system("pause");
	menu();
}

//---------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------//
//--------------------------------------------- AKHIR FUNGSI OPENING --------------------------------------------//
//---------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------//



//---------------------------------------------------------------------------------------------------------------//
//                                                                                                               //
//                                              ------------------                                               //
//                                              ||  FUNGSI MENU ||                                               //
//                                              ------------------                                               //
//                                                                                                               //
//---------------------------------------------------------------------------------------------------------------//

//------------------------------------------//
//                                          //
//      ------------------------------      //
//      ||  FORMAT PEMILIHAN MENU   ||      //
//      ------------------------------      //
//                                          //
//------------------------------------------//

int arrow_menu(int banyak_menu, char *list_menu[banyak_menu+2] , int z){
	int pilih=0;
	banyak_menu+=2;
	if (z==1){ //menu utama
		pilih=2;
		for (i=banyak_menu-1; i>=0; i--){
			list_menu[i]=list_menu[i-2];
		}

		if (data_user==0){
			list_menu[0]="Main menu\t\t\t\t\t\t\t\t\t\t\t\t";
			list_menu[1]="Login/Daftar\n\n";
		}
		else {
			list_menu[0]="Main menu\t\t\t\t\t\t\t\t\t\t\t\t      ";
			list_menu[1]="Logout\n\n";
		}

		while (1) {
		  	system("cls");
		  	judul();
		  	judul_menu();
		  	for (i=0; i<banyak_menu; i++){
				if (pilih==i){printf("--> ");}
				else {printf("   ");}
				if (i>1){
					printf("%s\n", list_menu[i]);
				}
				else {
					printf("\033[1;31m");
					printf("%s", list_menu[i]);
					printf("\033[0m");
				}
			}
		    switch ( getch() ) {
		    case '\r': //enter
		    	if (pilih==0){
		    		menu();
				}
	   			else if (pilih==1){
	   				if (data_user==0){
	   					menu_login_daftar();
					}
	   				login_logout();
				}
	   			else {
		    		for (i=0; i<banyak_menu; i++){
						if (pilih==i){
			    			return i-2;
						}
					}
				}
			case 72: //arrow atas
	    		pilih--;
	    		if (pilih<0){
	    			pilih=banyak_menu-1;
				}
				break;
			case 80: //arrow bawah
				pilih++;
				if (pilih>=banyak_menu){
					pilih=0;
				}
				break;
			case 27:
				keluar();
			}
		}
	}
	else if (z==2){ //submenu atau switch menu saat salah
		pilih=2;
		if (list_menu[0]==NULL){
			banyak_menu-=2;
			list_menu[banyak_menu];
		}
		while (1) {
		  	system("cls");
		  	if (list_menu[0]!=NULL){submenu(list_menu[0], 0);submenu(list_menu[1], 1);} //0 ->buat judul list menu 1->buat pertanyaan atau pernyataan diatas pilihan
		  	else {submenu(list_menu[1], 1);printf("  silahkan pilih apa yang ingin anda lakukan\n\n");}
		  	for (i=2; i<banyak_menu; i++){
				if (pilih==i){printf("--> ");}
				else {printf("   ");}
				if (list_menu[0]!=NULL){
					if (i<banyak_menu-2){
						printf("%s\n", list_menu[i]);
					}
					else {
						printf("\033[1;31m");
						printf("%s", list_menu[i]);
						printf("\033[0m");
					}
					if (pilih==banyak_menu-2){
						list_menu[banyak_menu-2]="Back (ESC)\t\t\t\t\t\t\t\t\t\t\t\t  ";
						list_menu[banyak_menu-1]="Main Menu\n\n";
					}
					else {
						list_menu[banyak_menu-2]="Back (ESC)\t\t\t\t\t\t\t\t\t\t\t\t  ";
						list_menu[banyak_menu-1]="Main Menu\n\n";
					}
				}
				else {
					if (i<banyak_menu){
						printf("%s\n", list_menu[i]);
					}
				}
			}
		    switch ( getch() ) {
		    case '\r': //enter
		    	if (pilih==banyak_menu-1&&list_menu[0]!=NULL){
		    		menu();
				}
	   			else {
		    		for (i=0; i<banyak_menu; i++){
						if (pilih==i){
			    			return i-2;
						}
					}
				}
			case 72: //arrow atas
	    		pilih--;
	    		if (pilih<2){
	    			pilih=banyak_menu-1;
				}
				break;
			case 80: //arrow bawah
				pilih++;
				if (pilih>=banyak_menu){
					pilih=2;
				}
				break;
			case 27:
				if (list_menu[0]!=NULL){return banyak_menu-4;}
				return banyak_menu-3;
			}
		}
	}
	else if (z==3){ //statement seperti ya atau tidak, lanjutkan atau tidak
		pilih=1;
		banyak_menu-=2;
		list_menu[banyak_menu];
		while (1) {
		  	system("cls");
		  	printf("\033[1;31m");
		  	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t%s\n\n", list_menu[0]);
		  	printf("\033[0m");
		  	for (j=1; j<banyak_menu; j++){
				if (pilih==j){printf("\t\t--> ");}
				else {printf("\t\t   ");}
				printf("%s", list_menu[j]);
				if (strcmp(list_menu[0], "Apakah anda yakin ingin keluar?")==0){
					if (pilih==1&&j==1){printf("\t\t\t:( :( :( *jangan dong :(");}
					else if (pilih!=1&&j!=1) {printf("\t\t:) :) :) *yeay :)");}
				}
				printf("\n\n");
			}
		    switch ( getch() ) {
		    case '\r': //enter
		    	for (j=0; j<banyak_menu; j++){
					if (pilih==j){
			    		return j-1;
					}
				}
			case 72: //arrow atas
	    		pilih--;
	    		if (pilih<1){
	    			pilih=banyak_menu-1;
				}
				break;
			case 80: //arrow bawah
				pilih++;
				if (pilih>=banyak_menu){
					pilih=1;
				}
				break;
			case 27:
				return banyak_menu-2;
			}
		}
	}
	else {

	}
}

//------------------------------------------//
//                                          //
//      ------------------------------      //
//      ||   DAFTAR MENU YANG ADA   ||      //
//      ------------------------------      //
//                                          //
//------------------------------------------//

void menu(){
	char *menu_utama[7];
	menu_utama[0]="1. mengubah data perpustakaan\n";
	menu_utama[1]="2. mencari data buku\n";
	menu_utama[2]="3. meminjam buku\n";
	menu_utama[3]="4. mengembalikan buku\n";
	menu_utama[4]="5. melihat seluruh data di perpustakaan\n";
	menu_utama[5]="6. melihat data pinjaman\n";
	menu_utama[6]="\033[1;31mexit program (ESC)\033[0m\n";
	switch (arrow_menu(7, menu_utama, 1)){
   		case 0:
			menu_buku_rak();
		case 1:
			search();
		case 2:
			minjam();
		case 3:
			balikin();
		case 4:
			lihat();
		case 5:
			lihat_pinjam();
		case 6:
			keluar();
	}
}

void menu_login_daftar(){
	char *pilih_menu[2];
	pilih_menu[0]="MENU AKUN";
	pilih_menu[1]="apa yang ingin anda lakukan?";
	pilih_menu[2]="1. login\n";
	pilih_menu[3]="2. daftar\n";
	switch (arrow_menu(4, pilih_menu, 2)){
		case 0:
			login_logout();
		case 1:
			daftar();
		case 2:
			menu();
	}
}

void menu_buku_rak(){
	char *pilih_menu[3];
	pilih_menu[0]="MENU ADMINISTRATOR";
	pilih_menu[1]="apa yang ingin anda lakukan?";
	pilih_menu[2]="1. mengubah data rak\n";
	pilih_menu[3]="2. mengubah data buku\n";
	switch (arrow_menu(4, pilih_menu, 2)){
		case 0:
			menu_rak();
		case 1:
			menu_buku();
		case 2:
			menu();
	}
}

void menu_rak(){
	char *pilih_menu[4];
	pilih_menu[0]="MENU RAK";
	pilih_menu[1]="apa yang ingin anda lakukan dengan rak?";
	pilih_menu[2]="1. menambahkan rak\n";
	pilih_menu[3]="2. mengubah nama rak\n";
	pilih_menu[4]="3. menghapus rak\n";
	switch (arrow_menu(5, pilih_menu, 2)){
		case 0:
			tambah_rak();
		case 1:
			ubah_rak();
		case 2:
			hapus_rak();
		case 3:
			menu_buku_rak();
	}
}

void menu_buku(){
	char *pilih_menu[4];
	pilih_menu[0]="MENU BUKU";
	pilih_menu[1]="apa yang ingin anda lakukan dengan buku?";
	pilih_menu[2]="1. menambahkan data buku\n";
	pilih_menu[3]="2. mengubah data buku yang sudah ada\n";
	pilih_menu[4]="3. menghapus data buku\n";
	switch (arrow_menu(5, pilih_menu, 2)){
		case 0:
			tambah_buku();
		case 1:
			ubah_buku();
		case 2:
			hapus_buku();
		case 3:
			menu_buku_rak();
	}
}

void lihat(){
	//judul buku, hanya judul saja
	//daftar rak, seluruh nama rak saja
	//data buku, seluruh buku beserta jumlah halaman, pengarang penerbit, tahun terbit, sinopsis(satu paragraf tanpa enter), dll (untuk saat ini hanya sampai jumlah halaman buku)
	//data rak dan buku, menampilkan seluruh rak dengan setiap raknya akan menampilkan data bukunya satu persatu..misal rak "a" bukunya a, b, c, d rak "b" bukunya e, f, g, h..dst
	char *pilih_menu[4];
	pilih_menu[0]="MENU DATA PERPUSTAKAAN";
	pilih_menu[1]="data apa yang ingin anda lihat?";
	pilih_menu[2]="1. judul buku\n";
	pilih_menu[3]="2. daftar rak\n";
	pilih_menu[4]="3. data buku\n";
	pilih_menu[5]="4. data rak dan buku\n";
	switch (arrow_menu(6, pilih_menu, 2)){
		case 0:
			cek_buku();
			lihat();
		case 1:
			cek_rak();
			lihat();
		case 2:
			cek_buku_full();
			lihat();
		case 3:
			cek_rak_full();
			lihat();
		case 4:
			menu();
	}
}

//---------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------//
//---------------------------------------------- AKHIR FUNGSI MENU ----------------------------------------------//
//---------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------//



//---------------------------------------------------------------------------------------------------------------//
//                                                                                                               //
//                                              ------------------                                               //
//                                              ||	FUNGSI AKUN	||                                               //
//                                              ------------------                                               //
//                                                                                                               //
//---------------------------------------------------------------------------------------------------------------//

void login_logout(){
	system("cls");
	memset(cari, 0, sizeof cari);
	if (data_user==0){
		//fungsi untuk login
		fflush(stdin);
		printf("Silahkan masukkan user name anda :");
		scanf("%[^\n]%*c", &cari);
		if (strlen(cari)==0){login_logout();}
		printf("%s", cari);
		printf("Silahkan masukkan password anda :");
		char password[100]={};
		int x=1, y=1;
		char z;
		i=0;
		while(1){
	    	z=getch();
			if(z==13&&strlen(password)!=0){break;} //sama dengan enter, password masuk
			else if(z==8){ //8 sama dengan backspace, delete yang salah
				if(strlen(password)!=0){
					i--;
					password[i]=0;
					printf("\b \b");
				}
			}
			else if(z==27){menu();} //27 sama dengan ESC, tombol ESC untuk keluar ke menu
			//password hanya boleh huruf dan angka, case sensitive
			else {
				for (j=65;j<91;j++){
					if(z==j||z==j+32||(z==j-17&&z<58)){ //untuk menginput hanya huruf kecil, besar, dan angka
						password[i] = z;
						printf("*");
						i++;
						break;
					}
				}
			}
		}
		for (i=0; i<strlen(password); i++){
			if (i<strlen(password)/2){x+=password[i]-23;} //mengambil setengah angka awal
			else {y+=password[i]-23;} //mengambil setengah angka terakhir
		}
		for (i=0; i<strlen(cari); i++){
			if (i%2==0){cari[i]-=cari[i]*x;} //genap
			else {cari[i]-=cari[i]*y;} //ganjil
			for (j=0; j<33; j++){
				if (cari[i]==j){cari[i]+=33;break;} //supaya angka spesial seperti spasi, tab, dll tidak masuk dalam hasil enkripsi
			}
		}
		b = fopen("user.bin", "r");
		for (i=1; fscanf(b, "%s ", password)!=EOF; i++){
			if(strcmp(password, cari)==0){ //ada data yang sama
				fclose(b);
				data_user=i; //menyimpan index data user mulai dari 1, karena 0 menandakan dia tidak ada data dan tidak login, jadi data_user adalah index yang menandakan posisi akun dia
				system("cls");
				printf("Selamat login anda berhasil!\nSelamat mengeksplor hal lebih :)\n");
				system("pause");
				menu(); //kembali ke menu
			}
		}
		fclose(b);
		printf("\nMaaf username atau password yang anda masukkan salah, silahkan masukkan kembali\nJika anda ingin keluar dari menu login silahkan tekan tombol ESC saat berada di mode input password\n");
		system("pause");
		login_logout(); //kembali ke mode login
	}
	else {
		//fungsi untuk logout
		char *pilih_menu[3];
		pilih_menu[0]="apakah anda yakin ingin logout?";
		pilih_menu[1]="YA (logout)\n";
		pilih_menu[2]="TIDAK (kembali ke menu utama) (ESC)";
		switch (arrow_menu(3, pilih_menu, 3)){
			case 0:
				break;
			case 1:
				menu();
		}
		data_user=0; //menghapus lokasi data si user dan menandakan dia tidak login
		system("cls");
		printf("Logout berhasil!\n\n");
		printf("\033[1;31m");
		printf("Anda akan dialihkan ke menu utama secara otomatis\n\n");
		printf("\033[0m");
		system("pause");
		menu();
	}
}

void daftar(){ //fungsi untuk mendaftar
	system("cls");
	char password[100]={};
	int x=1, y=1;
	char z;
	printf("Silahkan masukkan user name anda :");
	scanf("%[^\n]%*c", &cari);
	if (strlen(cari)==0){login_logout();}
	password:
	printf("Silahkan masukkan password anda *password hanya berisikan huruf dan angka dengan case sensitive* :");
	i=0;
	while(1){
    	z=getch();
		if(z==13&&strlen(password)!=0){break;} //sama dengan enter, password masuk
		else if(z==8){ //8 sama dengan backspace, delete yang salah
			if(strlen(password)!=0){
				i--;
				password[i]=0;
				printf("\b \b");
			}
		}
		else if(z==27){menu();} //27 sama dengan ESC, tombol ESC untuk keluar ke menu
		//password hanya boleh huruf dan angka, case sensitive
		else {
			for (j=65;j<91;j++){
				if(z==j||z==j+32||(z==j-17&&z<58)){
					password[i] = z;
					printf("*");
					i++;
					break;
				}
			}
		}
	}
	if(strlen(password)<6){printf("\n\nMaaf password harus mempunyai panjang minimal 6 karakter, silahkan masukkan kembali\n");system("pause");system("cls");goto password;}
	for (i=0; i<strlen(password); i++){
		if (i<strlen(password)/2){x+=password[i]-23;} //mengambil setengah angka awal
		else {y+=password[i]-23;} //mengambil setengah angka terakhir
	}
	for (i=0; i<strlen(cari); i++){
		if (i%2==0){cari[i]-=cari[i]*x;} //genap
		else {cari[i]-=cari[i]*y;} //ganjil
		for (j=0; j<33; j++){
			if (cari[i]==j){cari[i]+=33;break;} //supaya angka spesial seperti spasi, tab, dll tidak masuk dalam hasil enkripsi
		}
	}
	b = fopen("user.bin", "a+"); //kumpulan seluruh user name yang telah dienkripsi
	while (fscanf(b, "%s ", password)!=EOF){
		if (strcmp(password, cari)==0){
			//pilihan mau login atau daftar lagi atau gak jadi
			fclose(b);
			char *pilih_menu[5];
			pilih_menu[0]=NULL;
			pilih_menu[1]="Maaf username dan password sudah terdaftar";
			pilih_menu[2]="1. mencoba mendaftar lagi\n";
			pilih_menu[3]="2. melakukan login\n";
			pilih_menu[4]="3. batal mendaftar (kembali ke menu utama) (ESC)\n";
			switch (arrow_menu(5, pilih_menu, 2)){
				case 0:
					daftar();
				case 1:
					login_logout();
				case 2:
					menu();
			}
		}
	}
	fprintf(b, "%s ", cari);
	fclose(b);
	system("cls");
	printf("Selamat akun anda berhasil dibuat :)\n\n");
	printf("\033[1;31m");
	printf("Anda akan dialihkan ke menu login secara otomatis\n\n");
	printf("\033[0m");
	system("pause");
	login_logout();
}

//---------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------//
//---------------------------------------------- AKHIR FUNGSI AKUN ----------------------------------------------//
//---------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------//



//---------------------------------------------------------------------------------------------------------------//
//                                                                                                               //
//                                          ----------------------------------                                   //
//                                          ||	FUNGSI UNTUK ADMINISTRATOR	||                                   //
//                                          ----------------------------------                                   //
//                                                                                                               //
//---------------------------------------------------------------------------------------------------------------//

//----------------------//
//                      //
//      ----------      //
//      ||  RAK ||      //
//      ----------      //
//                      //
//----------------------//

void tambah_rak(){
	//program untuk menambah data rak ke array "nama_rak"
	system("cls");
	printf("berapa banyak rak yang ingin anda tambah?\n");
	scanf("%d", &j);
	j = j+rak;
	for (rak; rak<j; rak++){
		i=1;
		//untuk memasukkan nama rak ke file
		printf("masukkan nama rak ke-%d\n", j-rak);
		scanf("%*c%[^\n]", nama_rak); //untuk membuat input spasi juga dibaca dalam array
		b = fopen("nama rak.bin","a+");
		while (fscanf(b, "%[^\n]%*c\n", cari)!=EOF){
			if (strcmp(nama_rak, cari)==0){ //supaya tidak menyimpan data rak yang sudah dibuat sebelumnya
				printf("Maaf nama rak yang anda masukkan sudah terdaftar, silahkan coba masukkan nama rak yang lain atau dengan menambahkan angka dibelakang nama rak\n");
				system("pause");
				rak--;
				i=0;
				break;
			}
		}
		if (i!=0){fprintf(b, "%s\n", nama_rak);fclose(b);}
	}
	printf("selamat rak berhasil ditambahkan!\n");
	system("pause");
	menu();
}

void ubah_rak(){
	//fungsi untuk mengubah nama rak
	system("cls");
	j = 0;
	fflush(stdin);
	printf("rak mana yang ingin anda ubah?\n");
	scanf("%[^\n]%*c", cari);
	FILE *d;
	b = fopen("nama rak.bin","r");
	d = fopen("bentar", "w");
	while(fscanf(b, "%[^\n]%*c\n", nama_rak)!=EOF){
		fprintf(d, "%s\n", nama_rak);
	}
	fclose(b);
	fclose(d);
	d = fopen("nama rak.bin","r");
	c = fopen("simpan","w"); //untuk menyimpan sementara data yang diubah
	while (fscanf(d, "%[^\n]%*c\n", nama_rak)!=EOF){
		if (strcmp(cari, nama_rak)==0){
			printf("rak ditemukan!\n");
			system("pause");
			lagi:
			system("cls");
			printf("silahkan masukkan nama rak yang baru\n");
			scanf("%[^\n]%*c", nama_rak);
			b = fopen("bentar", "r");
			while (fscanf(b, "%[^\n]%*c\n", nama_buku)!=EOF){
				if (strcmp(nama_rak, nama_buku)==0){
					fclose(b);
					char *pilih_menu[5];
					pilih_menu[0]=NULL;
					pilih_menu[1]="maaf nama rak yang baru sudah terdaftar, silahkan coba lagi";
					pilih_menu[2]="1. memasukkan ulang nama rak baru\n";
					pilih_menu[3]="2. cek seluruh data rak\n";
					pilih_menu[4]="3. batal mengubah rak (kembali ke menu utama) (ESC)\n";
					switch (arrow_menu(5, pilih_menu, 2)){
						case 0:
							goto lagi;
						case 1:
							cek_rak();
							char *pilih_menu[3];
							pilih_menu[0]="apakah anda ingin mencoba memasukkan data rak baru lagi?";
							pilih_menu[1]="YA (mencoba lagi)";
							pilih_menu[2]="TIDAK (kembali ke menu utama) (ESC)";
							switch (arrow_menu(3, pilih_menu, 3)){
								case 0:
									goto lagi;
								case 1:
									fclose(d);
									fclose(c);
									remove("bentar");
									menu();
							}
						case 2:
							fclose(d);
							fclose(c);
							remove("bentar");
							menu();
					}
				}
			}
			fclose(b);
			char *pilih_menu[4];
			char aad [100];
			snprintf(aad, sizeof(aad), "apakah anda yakin ingin mengubah data rak %s menjadi %s?", cari, nama_rak);
			pilih_menu[0]=aad;
			pilih_menu[1]="1. lanjutkan mengubah data";
			pilih_menu[2]="2. memasukkan ulang nama rak yang baru";
			pilih_menu[3]="3. kembali ke menu utama (ESC)";
			switch (arrow_menu(4, pilih_menu, 3)){
				case 0:
					system("cls");printf("pengubahan sedang diproses\n");j = 1;system("pause");break;
				case 1:
					fflush(stdin);goto lagi;
				case 2:
					fclose(d);
					fclose(c);
					remove("simpan");remove("bentar");
					menu();
			}
		}
		fprintf(c, "%s\n", nama_rak);
	}
	remove("bentar");
	fclose(d);
	fclose(c);
	if (j==1){
		remove("nama rak.bin");
		rename("simpan", "nama rak.bin");
		char *pilih_menu[4];
		pilih_menu[0]=NULL;
		char aad [100];
		snprintf(aad, sizeof(aad), "pengubahan data rak %s sukses!", cari);
		pilih_menu[1]=aad;
		pilih_menu[2]="1. mengubah data rak yang lain\n";
		pilih_menu[3]="2. kembali ke menu utama (ESC)\n";
		switch (arrow_menu(4, pilih_menu, 2)){
			case 0:
				ubah_rak();
			case 1:
				menu();
		}
	}
	else{
		remove("simpan");
		char *pilih_menu[5];
		pilih_menu[0]=NULL;
		pilih_menu[1]="maaf data rak tidak ditemukan, silahkan coba lagi";
		pilih_menu[2]="1. memasukkan nama rak lagi\n";
		pilih_menu[3]="2. cek seluruh data rak\n";
		pilih_menu[4]="3. batal mengubah rak (kembali ke menu utama) (ESC)\n";
		switch (arrow_menu(5, pilih_menu, 2)){
			case 0:
				ubah_rak();
			case 1:
				cek_rak();
				char *pilih_menu[3];
				pilih_menu[0]="apakah anda ingin mencoba mengubah data rak lagi?";
				pilih_menu[1]="YA (mencoba lagi)";
				pilih_menu[2]="TIDAK (kembali ke menu utama) (ESC)";
				switch (arrow_menu(3, pilih_menu, 3)){
					case 0:
						ubah_rak();
					case 1:
						menu();
				}
			case 2:
				menu();
		}
	}
}

void hapus_rak(){
	//fungsi untuk menghapus rak
	j=0;
	char *pilih_menu[3];
	pilih_menu[0]="PERINGATAN!!!\n\t\tJika anda menghapus rak, maka anda akan menghapus seluruh data yang ada di dalam rak tersebut\n\n\t\tapakah anda yakin ingin melanjutkan?";
	pilih_menu[1]="YA (melanjutkan)";
	pilih_menu[2]="TIDAK (kembali ke menu utama) (ESC)";
	switch (arrow_menu(3, pilih_menu, 3)){
		case 0:
			break;
		case 1:
			menu();
	}
	hapus:
	system("cls");
	fflush(stdin);
	printf("rak mana yang ingin anda hapus?\n");
	scanf("%[^\n]%*c", cari);
	b = fopen("nama rak.bin","r");
	c = fopen("simpan","w");
	//fungsi untuk menghapus satu rak
	for (i=0; fscanf(b, "%[^\n]%*c\n", nama_rak)!=EOF; i++){
		if (strcmp(cari, nama_rak) == 0){
			printf("rak ditemukan!\n");
			system("pause");
			char *pilih_menu[3];
			char aad [70+strlen(nama_rak)];
			snprintf(aad, sizeof(aad), "apakah anda yakin ingin menghapus data rak %s beserta seluruh bukunya?", nama_rak);
			pilih_menu[0]=aad;
			pilih_menu[1]="YA (melanjutkan)";
			pilih_menu[2]="TIDAK (kembali ke menu utama) (ESC)";
			switch (arrow_menu(3, pilih_menu, 3)){
				case 0:
					system("cls");
					printf("penghapusan sedang diproses\n");
					system("pause");
					a = i; //untuk menyimpan index rak yang dihapus dalam a
					j = 1;
					continue;
				case 1:
					fclose(b);
					fclose(c);
					remove("simpan");
					menu();
			}
		}
		fprintf(c, "%s\n", nama_rak);
	}
	fclose(b);
	fclose(c);
	if(j==1){
		remove("nama rak.bin");
		rename("simpan", "nama rak.bin");
		//fungsi untuk menghapus seluruh buku di dalamnya
		b = fopen("nama buku.bin","r");
		c = fopen("simpan","w");
		while (fscanf(b, "%d %d %d %d %[^\n]%*c\n", &pinjam, &waktu, &i, &lembar, nama_buku)!=EOF){
			if (i==a){continue;} //supaya data yang ingin dihapus tidak tersimpan ke file simpan
			else if (i>a){i--;} //supaya index buku selanjutnya naik menyesuaikan dengan raknya yang otomatis naik karena terdapat rak yang dihapus
			fprintf(c, "%d %d %d %d %s\n", pinjam, waktu, i, lembar, nama_buku);
		}
		fclose(b);
		fclose(c);
		//untuk mengembalikan data dari file simpan, dengan data di file simpan sudah tidak terdapat data yang ingin dihapus
		remove("nama buku.bin");
		rename("simpan", "nama buku.bin");
		char *pilih_menu[4];
		pilih_menu[0]=NULL;
		char aad [100];
		snprintf(aad, sizeof(aad), "penghapusan data rak %s sukses!", cari);
		pilih_menu[1]=aad;
		pilih_menu[2]="1. menghapus data rak yang lain\n";
		pilih_menu[3]="2. kembali ke menu utama (ESC)\n";
		switch (arrow_menu(4, pilih_menu, 2)){
			case 0:
				hapus_rak();
			case 1:
				menu();
		}
	}
	else{
		remove("simpan");
		char *pilih_menu[5];
		pilih_menu[0]=NULL;
		pilih_menu[1]="maaf data rak tidak ditemukan, silahkan coba lagi";
		pilih_menu[2]="1. memasukkan nama rak lagi\n";
		pilih_menu[3]="2. cek seluruh data rak\n";
		pilih_menu[4]="3. batal menghapus rak (kembali ke menu utama) (ESC)\n";
		switch (arrow_menu(5, pilih_menu, 2)){
			case 0:
				goto hapus;
			case 1:
				cek_rak();
				char *pilih_menu[3];
				pilih_menu[0]="apakah anda ingin mencoba menghapus data rak lagi?";
				pilih_menu[1]="YA (hapus data lagi)";
				pilih_menu[2]="TIDAK (kembali ke menu utama) (ESC)";
				switch (arrow_menu(3, pilih_menu, 3)){
					case 0:
						goto hapus;
					case 1:
						menu();
				}
			case 2:
				menu();
		}
	}
}

//--------------------------//
//                          //
//      --------------      //
//      ||   BUKU   ||      //
//      --------------      //
//                          //
//--------------------------//

void tambah_buku(){
	//program untuk menambah data buku ke dalam perpustakaan
	system("cls");
	printf("berapa banyak buku yang ingin anda tambah?\n");
	scanf("%d", &a);
	a += buku;
	c = fopen("nama buku.bin","a+");
	while (buku<a){
		//untuk memasukkan judul buku ke array, pertama adalah index buku, kedua judulnya
		system("cls");
		printf("masukkan nama rak yang akan digunakan untuk menyimpan buku ke-%d\n", a-buku);
		scanf("%*c%[^\n]", cari);
		j=0;
		b = fopen("nama rak.bin","r");
		for (i=0; fscanf(b, "%[^\n]%*c\n", nama_rak)!=EOF; i++){ //untuk membaca data tiap baris dari file sebagai variabel hasil
			if(strcmp(cari, nama_rak)==0){
				printf("masukkan judul buku\n");
				scanf("%*c%[^\n]", nama_buku); //untuk membuat input spasi juga dibaca dalam array
				printf("masukkan jumlah halaman buku\n");
				scanf("%d", &lembar);
				pinjam = 0; waktu = 0;
				fprintf(c, "%d %d %d %d %s\n", pinjam, waktu, i, lembar, nama_buku); //mencatat data buku ke "nama buku.bin" dengan format "index rak \n nama buku" dengan index rak untuk mencatat lokasi rak dari buku tersebut
				printf("penambahan buku sukses!\n\n");
				system("pause");
				j=1;
				buku++;
				break;
			}
		}
		fclose(b);
		if (j==0){
			char *pilih_menu[6];
			pilih_menu[0]=NULL;
			pilih_menu[1]="maaf nama rak tidak terdaftar, silahkan cek data rak atau tambahkan nama rak tersebut";
			pilih_menu[2]="1. memasukkan nama rak lagi\n";
			pilih_menu[3]="2. cek seluruh data rak\n";
			pilih_menu[4]="3. menambahkan rak\n";
			pilih_menu[5]="4. batal menambah buku (kembali ke menu utama) (ESC)\n";
			switch (arrow_menu(6, pilih_menu, 2)){
				case 0:
					break;
				case 1:
					cek_rak();
					*pilih_menu[3];
					pilih_menu[0]="apakah anda ingin mencoba menambah buku lagi?";
					pilih_menu[1]="YA (menambah buku lagi)";
					pilih_menu[2]="TIDAK (kembali ke menu utama) (ESC)";
					switch (arrow_menu(3, pilih_menu, 3)){
						case 0:
							system("cls");
							continue;
						case 1:
							fclose(c);
							menu();
					}
				case 2:
					tambah_rak();
					*pilih_menu[3];
					pilih_menu[0]="apakah anda ingin mencoba menambah buku lagi?";
					pilih_menu[1]="YA (menambah buku lagi)";
					pilih_menu[2]="TIDAK (kembali ke menu utama) (ESC)";
					switch (arrow_menu(3, pilih_menu, 3)){
						case 0:
							system("cls");
							continue;
						case 1:
							fclose(c);
							menu();
					}
				case 3:
					fclose(c);
					menu();
			}
		}
	}
	fclose(c);
	printf("penambahan semua buku telah sukses!\n");
	system("pause");
	menu();
}

void ubah_buku(){
	system("cls");
	j = 0;
	fflush(stdin);
	printf("buku apa yang ingin anda ubah?\n");
	scanf("%[^\n]%*c", cari);
	b = fopen("nama buku.bin","r");
	c = fopen("simpan","w");
	while (fscanf(b, "%d %d %d %d %[^\n]%*c\n", &pinjam, &waktu, &i, &lembar, nama_buku)!=EOF){
		if (strcmp(cari,nama_buku) == 0){
			printf("buku ditemukan!\n");system("pause");
			if (pinjam!=0){
				char *pilih_menu[3];
				char aad [100];
				snprintf(aad, sizeof(aad), "buku %s sedang dipinjam, apakah anda yakin ingin mengubah data buku tersebut?", cari);
				pilih_menu[0]=aad;
				pilih_menu[1]="YA (melanjutkan)";
				pilih_menu[2]="TIDAK (kembali ke menu utama) (ESC)";
				switch (arrow_menu(3, pilih_menu, 3)){
					case 0:
						break;
					case 1:
						fclose(b);
						fclose(c);
						remove("simpan");
						menu();
				}
			}
			system("cls");
			printf("silahkan masukkan judul buku pengganti\n");
			scanf("%[^\n]%*c", nama_buku);
			char *pilih_menu[3];
			char aad [100];
			snprintf(aad, sizeof(aad), "apakah anda yakin ingin mengubah buku %s menjadi %s?", cari, nama_buku);
			pilih_menu[0]=aad;
			pilih_menu[1]="YA (melanjutkan)";
			pilih_menu[2]="TIDAK (kembali ke menu utama) (ESC)";
			switch (arrow_menu(3, pilih_menu, 3)){
				case 0:
					system("cls");
					printf("masukkan jumlah halaman buku\n");
					scanf("%d", &lembar);
					printf("perubahan sedang diproses\n");
					system("pause");
					j = 1;
					break;
				case 1:
					fclose(b);
					fclose(c);
					remove("simpan");
					menu();
			}
		}
		fprintf(c, "%d %d %d %d %s\n", pinjam, waktu, i, lembar, nama_buku);
	}
	fclose(b);
	fclose(c);
	if (j==0){
		remove("simpan");
		char *pilih_menu[5];
		pilih_menu[0]=NULL;
		pilih_menu[1]="maaf judul buku tidak ditemukan, silahkan coba lagi";
		pilih_menu[2]="1. memasukkan judul buku lagi\n";
		pilih_menu[3]="2. cek seluruh data buku\n";
		pilih_menu[4]="3. kembali ke menu utama (ESC)\n";
		switch (arrow_menu(5, pilih_menu, 2)){
			case 0:
				ubah_buku();
			case 1:
				cek_buku();
				char *pilih_menu[3];
				pilih_menu[0]="apakah anda ingin mencoba mengubah buku lagi?";
				pilih_menu[1]="YA (mengubah buku lagi)";
				pilih_menu[2]="TIDAK (kembali ke menu utama) (ESC)";
				switch (arrow_menu(3, pilih_menu, 3)){
					case 0:
						ubah_buku();
					case 1:
						menu();
				}
			case 2:
				menu();
		}
	}
	remove("nama buku.bin");
	rename("simpan", "nama buku.bin");
	char *pilih_menu[4];
	pilih_menu[0]=NULL;
	char aad [100];
	snprintf(aad, sizeof(aad), "pengubahan judul buku %s sukses!", cari, nama_buku);
	pilih_menu[1]=aad;
	pilih_menu[2]="1. mengubah buku yang lain\n";
	pilih_menu[3]="2. kembali ke menu utama (ESC)\n";
	switch (arrow_menu(4, pilih_menu, 2)){
		case 0:
			ubah_buku();
		case 1:
			menu();
	}
}

void hapus_buku(){
	j = 0;
	fflush(stdin);
	system("cls");
	printf("buku apa yang ingin anda hapus?\n");
	scanf("%[^\n]%*c", cari);
	b = fopen("nama buku.bin","r");
	c = fopen("simpan","w");
	while (fscanf(b, "%d %d %d %d %[^\n]%*c\n", &pinjam, &waktu, &i, &lembar, nama_buku)!=EOF){
		if (strcmp(cari,nama_buku) == 0){
			printf("buku ditemukan!\n");system("pause");
			if (pinjam!=0){
				char *pilih_menu[3];
				char aad [181+strlen(cari)];
				snprintf(aad, sizeof(aad), "buku %s sedang dipinjam, apakah anda yakin ingin menghapus data buku tersebut?\n\t\tnote : menghapus data buku tersebut mengakibatkan data pinjaman pada buku tersebut juga akan terhapus", cari);
				pilih_menu[0]=aad;
				pilih_menu[1]="YA (melanjutkan)";
				pilih_menu[2]="TIDAK (kembali ke menu utama) (ESC)";
				switch (arrow_menu(3, pilih_menu, 3)){
					case 0:
						break;
					case 1:
						fclose(b);
						fclose(c);
						remove("simpan");
						menu();
				}
			}
			char *pilih_menu[3];
			char aad [100];
			snprintf(aad, sizeof(aad), "apakah anda yakin ingin menghapus buku %s?", cari);
			pilih_menu[0]=aad;
			pilih_menu[1]="YA (melanjutkan)";
			pilih_menu[2]="TIDAK (kembali ke menu utama) (ESC)";
			switch (arrow_menu(3, pilih_menu, 3)){
				case 0:
					system("cls");
					printf("penghapusan sedang diproses\n");
					system("pause");
					j = 1;
					continue;
				case 1:
					fclose(b);
					fclose(c);
					remove("simpan");
					menu();
			}
		}
		fprintf(c, "%d %d %d %d %s\n", pinjam, waktu, i, lembar, nama_buku);
	}
	fclose(b);
	fclose(c);
	if (j==0){
		remove("simpan");
		char *pilih_menu[5];
		pilih_menu[0]=NULL;
		pilih_menu[1]="maaf judul buku tidak ditemukan, silahkan coba lagi";
		pilih_menu[2]="1. memasukkan judul buku lagi\n";
		pilih_menu[3]="2. cek seluruh data buku\n";
		pilih_menu[4]="3. kembali ke menu utama (ESC)\n";
		switch (arrow_menu(5, pilih_menu, 2)){
			case 0:
				hapus_buku();
			case 1:
				cek_buku();
				char *pilih_menu[3];
				pilih_menu[0]="apakah anda ingin mencoba menghapus buku lagi?";
				pilih_menu[1]="YA (menghapus buku lagi)";
				pilih_menu[2]="TIDAK (kembali ke menu utama) (ESC)";
				switch (arrow_menu(3, pilih_menu, 3)){
					case 0:
						hapus_buku();
					case 1:
						menu();
				}
			case 2:
				menu();
		}
	}
	remove("nama buku.bin");
	rename("simpan", "nama buku.bin");
	char *pilih_menu[4];
	pilih_menu[0]=NULL;
	char aad [100];
	snprintf(aad, sizeof(aad), "penghapusan buku %s sukses!", cari);
	pilih_menu[1]=aad;
	pilih_menu[2]="1. menghapus buku lagi\n";
	pilih_menu[3]="2. kembali ke menu utama (ESC)\n";
	switch (arrow_menu(4, pilih_menu, 2)){
		case 0:
			hapus_buku();
		case 1:
			menu();
	}
}

//---------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------//
//------------------------------------------ AKHIR FUNGSI ADMINISTRATOR -----------------------------------------//
//---------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------//



//---------------------------------------------------------------------------------------------------------------//
//                                                                                                               //
//                                          ----------------------------------                                   //
//                                          ||	FUNGSI UNTUK MELIHAT DATA   ||                                   //
//                                          ----------------------------------                                   //
//                                                                                                               //
//---------------------------------------------------------------------------------------------------------------//



void search (){
	//fungsi untuk mencari buku
	system("cls");
	printf("silahkan masukkan judul buku yang ingin anda cari\n");
	scanf("%[^\n]%*c", cari);
	a=0;
	system("cls");
	b = fopen("nama buku.bin","r");
	while (fscanf(b, "%d %d %d %d %[^\n]%*c\n", &pinjam, &waktu, &i, &lembar, nama_buku)!=EOF){
		if (strcasecmp(cari, nama_buku)==0){ //strcasecmp adalah fungsi dari string.h untuk membandingkan string dengan case insenitive
			c = fopen("nama rak.bin","r");
			for (j=0; fscanf(c, "%[^\n]%*c\n", nama_rak)!=EOF; j++){
				if (i==j){
					if (a==0){printf("buku ditemukan!\n\n");}
					printf("kategori rak\t: rak %s\n", nama_rak);
					printf("judul buku\t: %s\n", nama_buku);
					printf("jumlah halaman\t: %d halaman\n\n", lembar);
					printf("status buku\t: ");
					if (pinjam==0){printf("tersedia di perpustakaan\n");}
					else {printf("sedang dipinjam dengan maksimal waktu peminjaman sampai %d\n", waktu);} //proses waktu dulu jadi tahun, bulan, tanggal, jam
					a=1;
					break;
				}
			}
			fclose(c);
		}
	}
	fclose(b);
	if (a==1){
		system("pause");
		menu();
	}

	char *pilih_menu[5];
	pilih_menu[0]=NULL;
	pilih_menu[1]="maaf buku tidak tersedia atau nama buku salah, silahkan coba lagi";
	pilih_menu[2]="1. memasukkan judul buku lagi\n";
	pilih_menu[3]="2. cek seluruh data buku\n";
	pilih_menu[4]="3. kembali ke menu utama (ESC)\n";
	switch (arrow_menu(5, pilih_menu, 2)){
		case 0:
			search();
		case 1:
			cek_buku();
			search();
		case 2:
			menu();
	}
}

//--------------------------//
//                          //
//      --------------      //
//      ||   BUKU   ||      //
//      --------------      //
//                          //
//--------------------------//

void cek_buku(){
	//fungsi untuk print semua buku
	system("cls");
	b = fopen("nama buku.bin","r");
    for (i=1; fscanf(b, "%d %d %d %d %[^\n]%*c\n", &pinjam, &waktu, &a, &lembar, nama_buku)!=EOF; i++){ //untuk membaca data tiap baris dari file sebagai variabel nama_rak
		if (i==1){printf("Judul seluruh buku yang ada di dalam perpustakaan :\n\n");}
		printf("%d. %s\n\n", i, nama_buku);
	}
	if (i==1){printf("maaf sedang tidak ada buku di perpustakaan atau admin belum menginput data perpustakaannya\nsilahkan hubungi admin perpustakaan untuk info lebih lanjut\n");}
	fclose(b);
	printf("\n");
	system("pause");
}

void cek_buku_full(){
	//fungsi untuk print semua buku
	system("cls");
	b = fopen("nama buku.bin","r");
    for (i=1; fscanf(b, "%d %d %d %d %[^\n]%*c\n", &pinjam, &waktu, &a, &lembar, nama_buku)!=EOF; i++){ //untuk membaca data tiap baris dari file sebagai variabel nama_rak
		c = fopen("nama rak.bin","r");
		for (j=0; fscanf(c, "%[^\n]%*c\n", nama_rak)!=EOF; j++){
			if (a==j){
				printf("%d.\tjudul buku\t: %s\n", i, nama_buku);
				printf("\tkategori rak\t: %s\n", nama_rak);
				printf("\tjumlah halaman\t: %d halaman\n", lembar);
				printf("\tstatus buku\t: ");
				if (pinjam==0){printf("tersedia di perpustakaan\n\n");}
				else {printf("sedang dipinjam dengan maksimal waktu peminjaman sampai tanggal %d bulan %d tahun %d\n\n", localtime(&waktu)->tm_mday, localtime(&waktu)->tm_mon, localtime(&waktu)->tm_year+1900);} //proses waktu dulu jadi tahun, bulan, tanggal, jam
			}
		}
		fclose(c);
	}
	if (i==1){printf("maaf sedang tidak ada buku di perpustakaan atau admin belum menginput data perpustakaannya\nsilahkan hubungi admin perpustakaan untuk info lebih lanjut\n");}
	fclose(b);
	system("pause");
}

//----------------------//
//                      //
//      ----------      //
//      ||  RAK ||      //
//      ----------      //
//                      //
//----------------------//

void cek_rak(){
	//fungsi untuk print semua rak
	system("cls");
	b = fopen("nama rak.bin","r");
    for (i=1; fscanf(b, "%[^\n]%*c\n", nama_rak)!=EOF; i++){ //untuk membaca data tiap baris dari file sebagai variabel nama_rak
		if (i==1){printf("Data rak yang ada di dalam perpustakaan :\n\n");}
		printf("%d. %s\n\n", i, nama_rak);
	}
	if (i==1){printf("maaf sedang tidak ada rak di perpustakaan atau admin belum menginput data perpustakaannya\nsilahkan hubungi admin perpustakaan untuk info lebih lanjut\n");}
	fclose(b);
	printf("\n");
	system("pause");
}

void cek_rak_full(){
	system("cls");
	b = fopen("nama rak.bin","r");
    for (i=1; fscanf(b, "%[^\n]%*c\n", nama_rak)!=EOF; i++){ //untuk membaca data tiap baris dari file sebagai variabel nama_rak
		printf("%d. rak %s\n", i, nama_rak);
		c = fopen("nama buku.bin","r");
		j=1;
		while (fscanf(c, "%d %d %d %d %[^\n]%*c\n", &pinjam, &waktu, &a, &lembar, nama_buku)!=EOF){ //untuk membaca data tiap baris dari file sebagai variabel nama_rak
			if (a==i-1){
				if (j==1){printf("   daftar buku dalam rak %s :\n", nama_rak);}
				printf("   %d. buku %s\n", j, nama_buku);
				j++;
			}
		}
		if (j==1){printf("   tidak ada buku dalam rak ini\n");}
		fclose(c);
		printf("\n");
	}
	if (i==1){printf("maaf sedang tidak ada rak di perpustakaan atau admin belum menginput data perpustakaannya\nsilahkan hubungi admin perpustakaan untuk info lebih lanjut\n");}
	fclose(b);
	printf("\n");
	system("pause");
}

//---------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------//
//--------------------------------------- AKHIR FUNGSI UNTUK MELIHAT DATA ---------------------------------------//
//---------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------//

void minjam(){
	if (data_user!=0){
		printf("Silahkan masukkan judul buku yang ingin anda pinjam (maksimal peminjaman hanya 2 buku): ");
		scanf("%[^\n]%*c", cari);
		a=0;
		b = fopen("nama buku.bin", "r");
		while (fscanf(b, "%d %d %d %d %[^\n]%*c\n", &pinjam, &waktu, &i, &lembar, nama_buku)!=EOF){
			if (pinjam==data_user){a++;}
		}
		fclose(b);
		if (a>=2){
			char *pilih_menu[4];
			pilih_menu[0]=NULL;
			pilih_menu[1]="maaf batas peminjaman adalah 2 buku, silahkan kembalikan buku    |\n  |\tyang sedang anda pinjam terlebih dahulu sebelum meminjam lagi";
			pilih_menu[2]="1. mengembalikan buku\n";
			pilih_menu[3]="2. kembali ke menu utama (ESC)\n";
			switch (arrow_menu(4, pilih_menu, 2)){
				case 0:
					balikin(); //fungsi mengembalikan buku, lalu lanjut minjam atau ke menu utama
				case 1:
					menu();
			}
		}
		b = fopen("nama buku.bin", "r");
		c = fopen("simpan", "w");
		a = 0;
		while (fscanf(b, "%d %d %d %d %[^\n]%*c\n", &pinjam, &waktu, &i, &lembar, nama_buku)!=EOF){
			if (strcmp(cari, nama_buku)==0 && pinjam==0){
				waktu = time(NULL);
				waktu += 604800; //waktu sekarang ditambah dengan 7 hari
				char *pilih_menu[3];
				char aad [100];
				snprintf(aad, sizeof(aad), "apakah anda yakin ingin meminjam buku %s sampai tanggal %d bulan %d?", cari, localtime(&waktu)->tm_mday, localtime(&waktu)->tm_mon);
				pilih_menu[0]=aad;
				pilih_menu[1]="YA (melanjutkan)";
				pilih_menu[2]="TIDAK (kembali ke menu utama) (ESC)";
				switch (arrow_menu(3, pilih_menu, 3)){
					case 0:
						pinjam = data_user;
						a = 1;
						break;
					case 1:
						fclose(b);
						fclose(c);
						remove("simpan");
						menu();
				}
			}
			else if (strcmp(cari, nama_buku)==0 && pinjam!=0){
				fclose(b);
				fclose(c);
				char *pilih_menu[3];
				char aad [100];
				snprintf(aad, sizeof(aad), "Maaf buku %s sedang dipinjam hingga tanggal %d bulan %d, apakah anda ingin meminjam buku yang lain?", cari, localtime(&waktu)->tm_mday, localtime(&waktu)->tm_mon);
				pilih_menu[0]=aad;
				pilih_menu[1]="YA (meminjam buku lain)";
				pilih_menu[2]="TIDAK (kembali ke menu utama) (ESC)";
				switch (arrow_menu(3, pilih_menu, 3)){
					case 0:
						minjam();
					case 1:
						remove("simpan");
						menu();
				}
			}
			fprintf(c, "%d %d %d %d %s\n", pinjam, waktu, i, lembar, nama_buku);
		}
		fclose(c);
		fclose(b);
		if (a==0){
			//tidak ditemukan bukunya
			remove("simpan");
			char *pilih_menu[5];
			pilih_menu[0]=NULL;
			pilih_menu[1]="maaf judul buku tidak ditemukan, silahkan coba lagi";
			pilih_menu[2]="1. memasukkan judul buku lagi\n";
			pilih_menu[3]="2. cek seluruh data buku\n";
			pilih_menu[4]="3. kembali ke menu utama (ESC)\n";
			switch (arrow_menu(5, pilih_menu, 2)){
				case 0:
					minjam();
				case 1:
					cek_buku();
					char *pilih_menu[3];
					pilih_menu[0]="apakah anda ingin mencoba meminjam buku lagi?";
					pilih_menu[1]="YA (meminjam buku lagi)";
					pilih_menu[2]="TIDAK (kembali ke menu utama) (ESC)";
					switch (arrow_menu(3, pilih_menu, 3)){
						case 0:
							minjam();
						case 1:
							menu();
					}
				case 2:
					menu();
			}
		}
		remove("nama buku.bin");
		rename("simpan", "nama buku.bin");
		printf("selamat anda berhasil meminjam buku %s, waktu peminjaman adalah 1 minggu, harap mengembalikan buku maksimal pada tanggal %d", cari);
		printf("apakah anda ingin meminjam buku lagi?");

	}
	else {
		//pilihan untuk login atau daftar atau ke menu
		char *pilih_menu[5];
		pilih_menu[0]=NULL;
		pilih_menu[1]="Maaf anda harus login terlebih dahulu atau mendaftar jika belum memiliki akun sebelum meminjam buku";
		pilih_menu[2]="1. login\n";
		pilih_menu[3]="2. daftar\n";
		pilih_menu[4]="3. kembali ke menu utama (ESC)\n";
		switch (arrow_menu(5, pilih_menu, 2)){
			case 0:
				login_logout();
			case 1:
				daftar();
				char *pilih_menu[3];
				pilih_menu[0]="apakah anda ingin mencoba meminjam buku lagi?";
				pilih_menu[1]="YA (meminjam buku lagi)";
				pilih_menu[2]="TIDAK (kembali ke menu utama) (ESC)";
				switch (arrow_menu(3, pilih_menu, 3)){
					case 0:
						minjam();
					case 1:
						menu();
				}
			case 2:
				menu();
		}
	}
}

void balikin(){
	
}

void lihat_pinjam(){
	if (data_user!=0){
		j = 1;
		system("cls");
		b = fopen("nama buku.bin", "r");
		while (fscanf(b, "%d %d %d %d %[^\n]%*c\n", &pinjam, &waktu, &i, &lembar, nama_buku)!=EOF){
			if (data_user==pinjam){
				if (j==1){printf("Buku yang sedang anda pinjam adalah :\n\n");}
				printf("%d. %s (dipinjam sampai tanggal %d, bulan %d, tahun %d)\n\n", j, nama_buku, localtime(&waktu)->tm_mday, localtime(&waktu)->tm_mon, localtime(&waktu)->tm_year+1900);
				j++;
			}
		}
		fclose(b);
		if (j==1){
			char *pilih_menu[4];
			pilih_menu[0]=NULL;
			pilih_menu[1]="Anda belum melakukan peminjaman buku";
			pilih_menu[2]="1. meminjam buku\n";
			pilih_menu[3]="2. kembali ke menu utama (ESC)\n";
			switch (arrow_menu(4, pilih_menu, 2)){
				case 0:
					minjam();
				case 1:
					menu();
			}
		}
	}
	else {
		char *pilih_menu[4];
		pilih_menu[0]=NULL;
		pilih_menu[1]="Maaf anda harus login terlebih dahulu untuk melihat data diri anda";
		pilih_menu[2]="1. login\n";
		pilih_menu[3]="2. kembali ke menu utama (ESC)\n";
		switch (arrow_menu(4, pilih_menu, 2)){
			case 0:
				login_logout();
			case 1:
				menu();
		}
	}
	system("pause");
	menu();
}

void keluar(){
	char *pilih_menu[3];
	if(data_user!=0){pilih_menu[0]="*note: jika anda tidak melakukan logout, maka akun anda akan tetap login saat anda memulai aplikasi\n\t\tApakah anda yakin ingin keluar?";}
	else {pilih_menu[0]="Apakah anda yakin ingin keluar?";}
	pilih_menu[1]="YA (keluar dari aplikasi)";
	pilih_menu[2]="TIDAK (kembali ke menu utama) (ESC)";
	switch (arrow_menu(3, pilih_menu, 3)){
		case 0:
			b = fopen("nama buku.bin", "a+");
			fprintf(b, "%d\n", (data_user*-1)-1);
			fclose(b);
			break;
		case 1:
			menu();
	}
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\tyaaahhh :(");
	sleep(1);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\tyaudah deh");
	sleep(1);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\tnanti pakai aplikasi ini lagi ya ;)");
	sleep(2);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\tterima kasih");
	for (i=0; i<3; i++){
		printf(" ;)");
		Sleep(500);
	}
	printf(" :)\n\n\n\n\n\n\n\n\n\n\n\n\n");
	exit(0);
}

void judul(){
	printf("\t\t\t================================================================\n");
    printf("\t\t\t||                                                            ||\n");
    printf("\t\t\t||                           PIJUK!!                          ||\n");
    printf("\t\t\t||                        PINJAM YUK!!                        ||\n");
    printf("\t\t\t||                                                            ||\n");
    printf("\t\t\t================================================================\n\n");
}


void judul_menu(){
	printf("\t\t\t\t      =================================\n");
	printf("\t\t\t\t      |                               |\n");
    printf("\t\t\t\t      |           Menu Utama          |\n");
    printf("\t\t\t\t      |                               |\n");
    printf("\t\t\t\t      =================================\n\n");
}

//untuk mencetak sub menu dengan posisi selalu di tengah
void submenu(char *list_menu, int z){
	if (z==0){
		z = strlen(list_menu);
		if (z>100){z/=2;}
		
		printf("\t\t\t\t\t\t   ");
		for(i=0; i<z/2; i++){
			printf("\b \b");
		}
		printf("=========");
		for(i=0; i<z; i++){
			printf("=");
		}
		printf("========\n");

		printf("\t\t\t\t\t\t   ");
		for(i=0; i<z/2; i++){
			printf("\b \b");
		}
		printf("|               ");
		for(i=0; i<z; i++){
			printf(" ");
		}
		printf("|\n");

		printf("\t\t\t\t\t\t   ");
		for(i=0; i<z/2; i++){
			printf("\b \b");
		}
		printf("|        %s       |\n", list_menu);

		printf("\t\t\t\t\t\t   ");
		for(i=0; i<z/2; i++){
			printf("\b \b");
		}
		printf("|               ");
		for(i=0; i<z; i++){
			printf(" ");
		}
		printf("|\n");

		printf("\t\t\t\t\t\t   ");
		for(i=0; i<z/2; i++){
			printf("\b \b");
		}
		printf("=========");
		for(i=0; i<z; i++){
			printf("=");
		}
		printf("========\n\n");
	}
	else{
		z = strlen(list_menu);
		if (z>100){z/=2;z-=5;}
		
		printf("  ======");
		for(i=0; i<z; i++){
			printf("=");
		}
		printf("=====\n");
		printf("  |     %s    |\n", list_menu);
		printf("  ======");
		for(i=0; i<z; i++){
			printf("=");
		}
		printf("=====\n\n");
	}
}



//UNTUK MENGHILANGKAN UNDERSCORE KEDIP-KEDIP YANG BIASA ADA DI BAWAH CMD
void underscore_kedip(int z){
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE); //VARIABEL OUT UNTUK PENGHUBUNG DENGAN CONSOL(CMD)
    CONSOLE_CURSOR_INFO kedip; //DECLARE VARIABEL KEDIP
    GetConsoleCursorInfo(out, &kedip); //MENGAMBIL DATA UNDERSCORE SAAT INI KEDALAM VARIABEL KEDIP
    kedip.bVisible = z; //UNTUK MENGATUR UNDERSCORE KEDIP-KEDIP YANG ADA DI VARIABEL KEDIP (0 TIDAK DITAMPILKAN, 1 DITAMPILKAN)
    SetConsoleCursorInfo(out, &kedip); //MENGEMBALIKAN DATA UNDERSCORE KEDIP YANG TELAH DIMODIFIKASI DALAM VARIABEL KEDIP
}
