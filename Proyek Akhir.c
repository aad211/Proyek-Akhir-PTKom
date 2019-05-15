//BACA BUKU
//PINJAM YUK
//BACA YUK

//menyimpan data nomor pegawai untuk membuat akun kepegawaian yang digunakan untuk mengakses administrator aplikasi
//memindahkan buku ke rak lain, 1. satu-satu 2. sekaligus banyak ke satu rak
//ganti arrow menu, biar gak selalu arrownya ada di atas, nambahin variabel buat naro arrow ada di mana, bukan dideclare dalam arrow
//bikin arrow lagi buat dia saat gak di main menu, supaya tulisan back dan main menu nya ada di bawah
//kalau nambah lagi pada saat bukunya atau raknya udah ada
//kalau rak sudah terdaftar gak bisa nambah dengan nama yang sama, harus berbeda
//kalau buku sudah terdaftar masih bisa menambah buku dengan nama yang sama lagi
//untuk pendaftaran member baru harus memasukkan foto dirinya, foto ktpnya dan foto dirinya bersama ktp
//nanti dari fotonya akan saling dicocokkan dari foto dirinya doang dengan foto ktpnya dan foto dirinya bersama ktp
//lalu membaca alamat dari foto ktp yang dikirimkan

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>

int a, i, j;
int rak=0; //untuk mencatat banyaknya rak*/
int buku=1; //banyaknya buku saat ini*/
int lembar;
int data_user;

char user_name[100];
char peminjam[100]; //array untuk daftar peminjam, 2 dimensi, pertama isinya nama peminjam, di nama peminjam diisi dengan judul buku yang dipinjam
//char data_rak[100]; //pertama index rak, kedua index buku dalam rak ke-n, isinya adalah index buku general yang berpatok pada index di nama_buku
char nama_rak[100]; //pertama index rak, kedua nama rak, isinya nama rak perkarakter
char nama_buku[100]; //pertama index buku, kedua judul buku, isinya judul buku perkarakter
//char password[100];
char cari[100];
FILE *b;
FILE *c;
int login=0, pinjam; //untuk default saat mulai aplikasi dia belum login

int  arrow_menu();
void judul();
void judul_menu();
void menu_login_daftar();
void login_logout();
void daftar();
void lihat();
void menu();
void menu_buku_rak();
void menu_rak();
void menu_buku();

void search();
void salah();

void tambah_rak();
void ubah_rak();
void hapus_rak();

void ubah_buku();
void tambah_buku();
void hapus_buku();

void cek_buku();
void cek_buku_full();
void cek_rak();
void cek_rak_full();

void tiktik();

//---------------------------------------------------------------------------------------------------------------//
//                                                                                                               //
//                                    --------------------------------------                                     //
//                                    ||   FUNGSI UNTUK OPENING APLIKASI  ||                                     //
//                                    --------------------------------------                                     //
//                                                                                                               //
//---------------------------------------------------------------------------------------------------------------//

int main (){ 
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
printf("\n\n\t\t\t\t\t    Selamat datang di Pinjam Yuk,");
printf("\n\t\t\t\t    aplikasi perpustakaan online yang terintegrasi");
	printf("\n\t\t\t\t       dengan banyak perpustakaan di Indonesia\n\n\n\n\t\t\t\t\t    ");
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

int arrow_menu(int banyak_menu, char *list_menu[banyak_menu+2]){
	int pilih=0;
	int z=2;
	banyak_menu+=2;
	if (z==1){//mainmenu
		pilih=2;
		for (i=banyak_menu-1; i>=0; i--){
			list_menu[i]=list_menu[i-2];
		}
		
		if (login==1){
			list_menu[0]="Main menu\t\t\t\t\t\t\t\t\t\t\t\t      ";
			list_menu[1]="Logout\n\n";
		}
		else {
			list_menu[0]="Main menu\t\t\t\t\t\t\t\t\t\t\t\t";
			list_menu[1]="Login/Daftar\n\n";
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
					//printf("\033[1;31m");
					printf("%s", list_menu[i]);
					//printf("\033[0m");
				}
			}
		    switch ( getch() ) {
		    case '\r': //enter
		    	if (pilih==0){
		    		menu();
				}
	   			else if (pilih==1){
	   				if (login==0){
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
				printf("terima kasih :)");
				exit(0);
			}
		}
	}
	else if (z==2){//submenu
		pilih=0;
		//for (i=banyak_menu-1; i>=0; i--){
		//	list_menu[i]=list_menu[i-2];
	
		while (1) {
		  	system("cls");
		  	judul();
		  	judul_menu();
		  	for (i=0; i<banyak_menu; i++){
				if (pilih==i){printf("--> ");}
				else {printf("   ");}
				if (i<banyak_menu-2){
					printf("%s\n", list_menu[i]);
				}
				else {
					//printf("\033[1;31m");
					printf("%s", list_menu[i]);
					//printf("\033[0m");
				}
				if (pilih==banyak_menu-2){
					list_menu[banyak_menu-2]="Back\t\t\t\t\t\t\t\t\t\t\t\t";
					list_menu[banyak_menu-1]="Main Menu\n\n";
				}
				else {
					list_menu[banyak_menu-2]="Back\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
					list_menu[banyak_menu-1]="Main Menu\n\n";
				}
			}
		    switch ( getch() ) {
		    case '\r': //enter
		    	if (pilih==banyak_menu-1){
		    		menu();
				}
	   			else {
		    		for (i=0; i<banyak_menu; i++){
						if (pilih==i){
			    			return i;
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
				printf("terima kasih :)");
				exit(0);
			}
		}
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
	menu_utama[3]="4. mencari data pinjaman\n";
	menu_utama[4]="5. melihat seluruh data di perpustakaan\n";
	menu_utama[5]="6. melihat data diri\n";
	menu_utama[6]="0. exit program\n";
	switch (arrow_menu(7, menu_utama)){
   		case 0:
			menu_buku_rak();
		case 1:
			search();
		case 2:
			if (login==1){
				printf("Silahkan masukkan judul buku yang ingin anda pinjam: ");
			}
			else {
				printf("Maaf anda harus login terlebih dahulu atau mendaftar jika belum memiliki akun sebelum meminjam buku");
			}
			system("pause");
			menu();
		case 4:
			lihat();
			
			/*aad = nama_rak
			printf("%d\n", strlen(nama_rak));
			for(i=0; i<rak; i++){
				for(j=1; j<strlen(data_rak[i]); j++){
					printf("%d\n\n", /*strlen(data_rak[i])*data_rak[i][j]);
				}
			}
			for(i=0; i<buku; i++){
				printf("%s\n", nama_buku[i]);
			}*/
			break;
		case 5:
			break;
		case 6:
			printf("terima kasih :)");
			exit(0);
	}
}

void menu_login_daftar(){
	char *menu_login_daftar[2];
	menu_login_daftar[0]="1. login\n";
	menu_login_daftar[1]="2. daftar\n";
	switch (arrow_menu(2, menu_login_daftar)){
		case 0:
			login_logout();
		case 1:
			daftar();
	}
}

void menu_buku_rak(){
	char *menu_buku_rak[2];
	menu_buku_rak[0]="1. mengubah data rak\n";
	menu_buku_rak[1]="2. mengubah data buku\n";
	switch (arrow_menu(2, menu_buku_rak)){
		case 0:
			menu_rak();
		case 1:
			menu_buku();
	}
	/*system("cls");
	printf("apa yang ingin anda lakukan?\n");
	printf("1. mengubah data rak\n");
	printf("2. mengubah data buku\n");
	printf("0. kembali ke menu sebelumnya\n");
	scanf("%d", &a);
	//printf("\n%d\n\n", a);
	if (a==1){menu_rak();}
	else if (a==2){menu_buku();}
	else if (a==0){menu();}
	else {salah();}*/
}

void menu_rak(){
	system("cls");
	printf("apa yang ingin anda lakukan?\n");
	printf("1. menghapus rak\n");
	printf("2. menambahkan rak\n");
	printf("3. mengubah nama rak\n");
	printf("0. kembali ke menu sebelumnya\n");
	scanf("%d", &a);
	if (a==1){hapus_rak();}
	else if (a==2){tambah_rak();}
	else if (a==3){ubah_rak();}
	else if (a==0){menu_buku_rak();}
	else {salah();}
}

void menu_buku(){
	system("cls");
	printf("apa yang ingin anda lakukan?\n");
	printf("1. menghapus data buku\n");
	printf("2. menambahkan data buku\n");
	printf("3. mengubah data buku yang sudah ada\n");
	printf("0. kembali ke menu sebelumnya\n");
	scanf("%d", &a);
	if (a==1){hapus_buku();}
	else if (a==2){tambah_buku();}
	else if (a==3){ubah_buku();}
	else if (a==0){menu_buku_rak();}
	else {salah();}
}

void lihat(){
	//judul buku, hanya judul saja
	//daftar rak, seluruh nama rak saja
	//data buku, seluruh buku beserta jumlah halaman, pengarang penerbit, tahun terbit, sinopsis(satu paragraf tanpa enter), dll
	//data rak dan buku, menampilkan seluruh rak dengan setiap raknya akan menampilkan data bukunya satu persatu..misal rak "a" bukunya a, b, c, d rak "b" bukunya e, f, g, h..dst
	char *liat[4];
	liat[0]="1. judul buku\n";
	liat[1]="2. daftar rak\n";
	liat[2]="3. data buku\n";
	liat[3]="4. data rak dan buku\n";
	switch (arrow_menu(4, liat)){
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
	if (login==0){
		//fungsi untuk login
		printf("Silahkan masukkan user name anda :");
		scanf("%s", &cari);
		password:
		printf("Silahkan masukkan password anda :");
		char password[100]={};
		int x=1, y=1;
		char z;
		i=0;
		while(1){
	    	z=getch();
			if(z==13){break;} //sama dengan enter, password masuk
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
		if(strlen(password)<=3){printf("Maaf password harus mempunyai panjang minimal 6 karakter, silahkan masukkan kembali\n");system("pause");goto password;}
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
		printf("\n%s\n", cari);
		system("pause");
		b = fopen("user.bin", "r");
		for (i=1; fscanf(b, "%s ", password)!=EOF; i++){
			if(strcmp(password, cari)==0){ //ada data yang sama
				fclose(b);
				data_user=i; //menyimpan index data user mulai dari 1, karena 0 menandakan dia tidak ada data
				system("cls");
				printf("Selamat login anda berhasil!\nSelamat mengeksplor hal lebih :)\n");
				system("pause");
				login=1; //untuk menandakan bahwa dia sudah login
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
		printf("apakah anda yakin ingin logout?\n");
		data_user=0; //menghapus lokasi data si user
		login=0; //untuk menandakan dia belum login
		menu();
	}
}

void daftar(){ //fungsi untuk mendaftar
	system("cls");
	char password[100]={};
	printf("Silahkan masukkan user name anda :");
	scanf("%s", &user_name);
	b = fopen("username.bin", "r");
	while(fscanf(b, "%s ", cari)!=EOF){
		if (user_name==cari){
			printf("Maaf user name %s sudah terdaftar, silahkan login atau gunakan user name yang lain\n", cari);
			menu();
		}
	}
	fclose(b);
	password:
	printf("Silahkan masukkan password anda *password hanya berisikan huruf dan angka dengan case sensitive* :");
	int x=1, y=1;
	char z;
	i=0;
	while(1){
    	z=getch();
		if(z==13){break;} //sama dengan enter, password masuk
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
	if(strlen(password)<=3){printf("Maaf password harus mempunyai panjang minimal 6 karakter, silahkan masukkan kembali\n");system("pause");goto password;}
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
	//nama lengkap, 
	/*b = fopen("datauser.bin", "a+"); //untuk menyimpan data user
	
	b = fclose(b);*/
	b = fopen("username.bin", "a+"); //kumpulan seluruh user name tanpa enkripsi, harusnya masukin ke dalam datauser.bin
	fprintf(b, "%s\n", user_name);
	fclose(b);
	b = fopen("user.bin", "a+"); //kumpulan seluruh user name yang telah dienkripsi
	fprintf(b, "%s ", cari);
	fclose(b);
	menu();
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
	printf("berapa banyak rak yang ingin anda tambah?\n");
	scanf("%d", &a);
	a = a+rak;
	b = fopen("nama rak.bin","a+");
	for (rak; rak<a; rak++){
		i=1;
		//untuk memasukkan nama rak ke array, pertama adalah index rak, kedua namanya
		printf("masukkan nama rak\n");
		scanf("%*c%[^\n]", nama_rak); //untuk membuat input spasi juga dibaca dalam array
		while (fscanf(b, "%[^\n]%*c\n", cari)!=EOF){
			if (nama_rak==cari){ //supaya tidak menyimpan data rak yang sudah dibuat sebelumnya
				printf("Maaf nama rak yang anda masukkan sudah terdaftar, silahkan coba masukkan nama rak yang lain atau dengan menambahkan angka dibelakang nama rak\n");
				system("pause");
				rak--;
				i=0;
				break;
			}
		}
		if (i!=0){fprintf(b, "%s\n", nama_rak);}
	}
	printf("selamat rak berhasil ditambahkan!\n");
	fclose(b);
	system("pause");
	menu();
}

void ubah_rak(){
	//fungsi untuk mengubah nama rak
	j = 0;
	printf("rak mana yang ingin anda ubah?\n");
	scanf("%*c%[^\n]", cari);
	b = fopen("nama rak.bin","r");
	c = fopen("simpan","w"); //untuk menyimpan sementara data yang diubah
	while (fscanf(b, "%[^\n]%*c\n", nama_rak)!=EOF){
		printf("%s\n", cari);
		printf("%s\n", nama_rak);
		if (strcmp(cari, nama_rak)==0){
			printf("rak ditemukan!\n");
			printf("silahkan masukkan nama rak yang baru\n");
			scanf("%*c%[^\n]", nama_rak);
			printf("apakah anda yakin ingin mengubah data rak %s menjadi %s?\n1. ya\n2. tidak\n", cari, nama_rak);
			scanf("%d", &a);
			if(a==1){printf("pengubahan sedang diproses\n");j = 1;}
			else if(a==2){
				fclose(b);
				fclose(c);
				remove("simpan");
				menu();
			}
			else{
				salah();
			}
		}
		fprintf(c, "%s\n", nama_rak);
	}
	fclose(b);
	fclose(c);
	if (j==1){
		b = fopen("nama rak.bin","w");
		c = fopen("simpan","r");
		while (fscanf(c, "%[^\n]%*c\n", nama_rak)!=EOF){
			fprintf(b, "%s\n", nama_rak);
		}
		fclose(b);
		fclose(c);
		remove("simpan");
		printf("Perubahan data rak %s sukses!\n", cari);
		system("pause");
		menu();
	}
	else{
		remove("simpan");
		printf("maaf data rak tidak ditemukan, silahkan coba lagi\n1. memasukkan nama rak lagi\n2. cek data rak\n3. kembali ke menu utama\n");
		scanf("%d", &a);
		if (a==1){
			ubah_rak();
		}
		else if (a==2){
			cek_rak();
			printf("apakah anda ingin mencoba mengubah data rak lagi?\n1. ya\n2. tidak\n");
			scanf("%d", &a);
			if (a==1){ubah_rak();}
			else if (a==2){menu();}
			else {salah();}
		}
		else if (a==3){
			menu();
		}
		else {
			salah();
		}
	}
}

void hapus_rak(){
	//fungsi untuk menghapus rak
	j=0;
	printf("PERINGATAN!!!\nJika anda menghapus rak, maka anda akan menghapus seluruh data yang ada di dalam rak tersebut\n\n");
	printf("apakah anda yakin ingin melanjutkan?\n1. ya\n2. tidak\n");
	scanf("%d", &a);
	if(a==2){
		menu();
	}
	else if(a!=1&&a!=2){
		salah();
	}
	printf("rak mana yang ingin anda hapus?\n");
	scanf("%*c%[^\n]", cari);
	b = fopen("nama rak.bin","r");
	c = fopen("simpan","w");
	//fungsi untuk menghapus satu rak
	for (i=0; fscanf(b, "%[^\n]%*c\n", nama_rak)!=EOF; i++){
		if (strcmp(cari,nama_rak) == 0){
			printf("rak ditemukan!\n");
			printf("apakah anda yakin ingin menghapus data rak %s beserta seluruh bukunya?\n1. ya\n2. tidak\n", nama_rak);
			scanf("%d", &a);
			if(a==1){
				printf("penghapusan sedang diproses\n");
				a = i; //untuk menyimpan index rak yang dihapus dalam a
				j = 1;
				continue;
			}
			else if(a==2){
				fclose(b);
				fclose(c);
				remove("simpan");
				menu();
			}
			else{
				fclose(b);
				fclose(c);
				remove("simpan");
				salah();
			}
		}
		fprintf(c, "%s\n", nama_rak);
	}
	fclose(b);
	fclose(c);
	if(j==1){
		b = fopen("nama rak.bin","w");
		c = fopen("simpan","r");
		while (fscanf(c, "%[^\n]%*c\n", nama_rak)!=EOF){
			fprintf(b, "%s\n", nama_rak);
		}
		fclose(b);
		fclose(c);
		remove("simpan");
		//fungsi untuk menghapus seluruh buku di dalamnya
		b = fopen("nama buku.bin","r");
		c = fopen("simpan","w");
		while (fscanf(b, "%d %d %[^\n]%*c\n", &i, &lembar, nama_buku)!=EOF){
			if (i==a){continue;} //supaya data yang ingin dihapus tidak tersimpan ke file simpan
			else if (i>a){i--;} //supaya index buku selanjutnya naik menyesuaikan dengan raknya yang otomatis naik karena terdapat rak yang dihapus
			fprintf(c, "%d %d %s\n", i, lembar, nama_buku);
		}
		fclose(b);
		fclose(c);
		//untuk mengembalikan data dari file simpan, dengan data di file simpan sudah tidak terdapat data yang ingin dihapus
		b = fopen("nama buku.bin","w");
		c = fopen("simpan","r");
		while (fscanf(c, "%d %d %[^\n]%*c\n", &i, &lembar, nama_buku)!=EOF){
			fprintf(b, "%d %d %s\n", i, lembar, nama_buku); 
		}
		fclose(b);
		fclose(c);
		remove("simpan");
		printf("Penghapusan rak %s sukses!\n", cari);
		system("pause");
		menu();
	}
	else{
		remove("simpan");
		printf("maaf data rak tidak ditemukan, silahkan coba lagi\n1. memasukkan nama rak lagi\n2. cek data rak\n3. kembali ke menu utama\n");
		scanf("%d", &a);
		if (a==1){
			hapus_rak();
		}
		else if (a==2){
			cek_rak();
			printf("apakah anda ingin mencoba menghapus data rak lagi?\n1. ya\n2. tidak\n");
			scanf("%d", &a);
			if (a==1){hapus_rak();}
			else if (a==2){menu();}
			else {salah();}
		}
		else if (a==3){
			menu();
		}
		else {
			salah();
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
	printf("berapa banyak buku yang ingin anda tambah?\n");
	scanf("%d", &a);
	a += buku;
	c = fopen("nama buku.bin","a+");
	while (buku<a){
		//untuk memasukkan judul buku ke array, pertama adalah index buku, kedua judulnya
		printf("masukkan nama rak yang akan digunakan untuk menyimpan buku\n");
		scanf("%*c%[^\n]", cari);
		j=0;
		b = fopen("nama rak.bin","r");
		for (i=0; fscanf(b, "%[^\n]%*c\n", nama_rak)!=EOF; i++){ //untuk membaca data tiap baris dari file sebagai variabel hasil
			if(strcmp(cari, nama_rak)==0){
				printf("masukkan judul buku\n");
				scanf("%*c%[^\n]", nama_buku); //untuk membuat input spasi juga dibaca dalam array
				printf("masukkan jumlah halaman buku\n");
				scanf("%d", &lembar);
				fprintf(c, "%d %d %s\n", i, lembar, nama_buku); //mencatat data buku ke "nama buku.bin" dengan format "index rak \n nama buku" dengan index rak untuk mencatat lokasi rak dari buku tersebut
				printf("penambahan buku sukses!\n\n");
				j=1;
				buku++;
				break;
			}
		}
		fclose(b);
		if (j==0){
			printf("maaf nama rak tidak terdaftar, silahkan cek data rak atau tambahkan nama rak tersebut\n1. cek data rak\n2. tambah rak\n3. batal menambah buku\n");
			scanf("%d", &j);
			if (j==1){
				cek_rak();
				printf("apakah anda ingin mencoba menambah buku lagi?\n1. ya\n2. tidak(kembali ke menu utama)\n");
				scanf("%d", &j);
				if (j==1){continue;}
				else if (j==2){menu();}
				else {salah();}
			}
			else if (j==2){
				tambah_rak();
				printf("apakah anda ingin mencoba menambah buku lagi?\n1. ya\n2. tidak(kembali ke menu utama)\n");
				scanf("%d", &j);
				if (j==1){continue;}
				else if (j==2){menu();}
				else {salah();}
			}
			else if (j==3){fclose(c);menu();}
			else{salah();}
		}
	}
	fclose(c);
	printf("penambahan buku sukses!\n");
	system("pause");
	menu();
}

void ubah_buku(){
	j = 0;
	printf("buku apa yang ingin anda ubah?\n");
	scanf("%*c%[^\n]", cari);
	b = fopen("nama buku.bin","r");
	c = fopen("simpan","w");
	while (fscanf(b, "%d %d  %[^\n]%*c\n", &i, &lembar, nama_buku)!=EOF){
		if (strcmp(cari,nama_buku) == 0){
			printf("buku ditemukan!\nsilahkan masukkan judul buku pengganti\n");
			scanf("%*c%[^\n]", nama_buku);
			printf("apakah anda yakin ingin mengubah buku %s menjadi %s?\n1. ya\n2. tidak", cari, nama_buku);
			scanf("%d", &a);
			if(a==1){printf("perubahan sedang diproses\n");j = 1;}
			else if(a==2){
				fclose(b);
				fclose(c);
				remove("simpan");
				menu();
			}
			else{
				fclose(b);
				fclose(c);
				remove("simpan");
				salah();
			}
		}
		fprintf(c, "%d %d %s\n", i, lembar, nama_buku);
	}
	fclose(b);
	fclose(c);
	if (j==0){
		remove("simpan");
		printf("maaf judul buku tidak ditemukan, silahkan coba lagi\n1. memasukkan judul buku lagi\n2. cek seluruh data buku\n3. kembali ke menu utama\n");
		scanf("%d", &a);
		if (a==1){
			ubah_buku();
		}
		else if (a==2){
			cek_buku();
		}
		else if (a==3){
			menu();
		}
		else {
			salah();
		}
	}
	b = fopen("nama buku.bin","w");
	c = fopen("simpan","r");
	while (fscanf(c, "%d %d %[^\n]%*c\n", &i, &lembar, nama_buku)!=EOF){
		fprintf(b, "%d %d %s\n", i, lembar, nama_buku);
	}
	fclose(b);
	fclose(c);
	remove("simpan");
	printf("Perubahan judul buku sukses!\n", cari);
}

void hapus_buku(){
	j = 0;
	printf("buku apa yang ingin anda hapus?\n");
	scanf("%*c%[^\n]", cari);
	b = fopen("nama buku.bin","r");
	c = fopen("simpan","w");
	while (fscanf(b, "%d %d %[^\n]%*c\n", &i, &lembar, nama_buku)!=EOF){
		if (strcmp(cari,nama_buku) == 0){
			printf("buku ditemukan!\n");
			printf("apakah anda yakin ingin menghapus buku %s?\n1. ya\n2. tidak\n", cari);
			scanf("%d", &a);
			if(a==1){printf("penghapusan sedang diproses\n");j = 1;continue;}
			else if(a==2){
				fclose(b);
				fclose(c);
				remove("simpan");
				menu();
			}
			else{
				fclose(b);
				fclose(c);
				remove("simpan");
				salah();
			}
		}
		fprintf(c, "%d %d %s\n", i, lembar, nama_buku);
	}
	fclose(b);
	fclose(c);
	if (j==0){
		remove("simpan");
		printf("maaf judul buku tidak ditemukan, silahkan coba lagi\n1. memasukkan judul buku lagi\n2. cek seluruh data buku\n3. kembali ke menu utama\n");
		scanf("%d", &a);
		if (a==1){
			hapus_buku();
		}
		else if (a==2){
			cek_buku();
		}
		else if (a==3){
			menu();
		}
		else {
			salah();
		}
	}
	b = fopen("nama buku.bin","w");
	c = fopen("simpan","r");
	while (fscanf(c, "%d %d %[^\n]%*c\n", &i, &lembar, nama_buku)!=EOF){
		fprintf(b, "%d %d %s\n", i, lembar, nama_buku);
	}
	fclose(b);
	fclose(c);
	remove("simpan");
	printf("Penghapusan buku %s sukses!\n", cari);
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
	while (fscanf(b, "%d %d %[^\n]%*c\n", &i, &lembar, nama_buku)!=EOF){
		if (strcmp(cari, nama_buku)==0){
			c = fopen("nama rak.bin","r");
			for (j=0; fscanf(c, "%[^\n]%*c\n", nama_rak)!=EOF; j++){
				if (i==j){
					if (a==0){printf("buku ditemukan!\n\n");}
					printf("kategori rak\t: rak %s\n", nama_rak);
					printf("judul buku\t: %s\n", nama_buku);
					printf("jumlah halaman\t: %d halaman\n\n", lembar);
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
	printf("maaf data buku tidak ditemukan atau nama buku salah, silahkan coba lagi\n");
	system("pause");
	
	char *menu_cari[2];
	menu_cari[0]="1. memasukkan judul buku lagi\n";
	menu_cari[1]="2. cek seluruh data buku\n";
	menu_cari[2]="3. kembali ke menu utama\n";
	switch (arrow_menu(3, menu_cari)){
		case 0:
			search();
		case 1:
			cek_buku();
		case 2:
			menu();
	}
	
	/*scanf("%d", &a);
	if (a==1){search();}
	else if (a==2){cek_buku();}
	else if (a==3){menu();}
	else{salah();}*/
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
    for (i=1; fscanf(b, "%d %d %[^\n]%*c\n", &lembar, &lembar, nama_buku)!=EOF; i++){ //untuk membaca data tiap baris dari file sebagai variabel nama_rak
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
    for (i=1; fscanf(b, "%d %d %[^\n]%*c\n", &a, &lembar, nama_buku)!=EOF; i++){ //untuk membaca data tiap baris dari file sebagai variabel nama_rak
		c = fopen("nama rak.bin","r");
		for (j=0; fscanf(c, "%[^\n]%*c\n", nama_rak)!=EOF; j++){
			if (a==j){
				printf("%d.\tjudul buku\t: %s\n", i, nama_buku);
				printf("\tkategori rak\t: %s\n", nama_rak);
				printf("\tjumlah halaman\t: %d halaman\n\n", lembar);
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
		while (fscanf(c, "%d %d %[^\n]%*c\n", &a, &lembar, nama_buku)!=EOF){ //untuk membaca data tiap baris dari file sebagai variabel nama_rak
			if (a==i){
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

void salah(){
	printf("maaf angka yang anda masukkan salah, silahkan coba lagi\n");
	system("pause");
	menu();
}

void judul()
{
	printf("\t\t\t================================================================\n");
    printf("\t\t\t||                                                            ||\n");
    printf("\t\t\t||                                                            ||\n");
    printf("\t\t\t||                       PINJAM YUK!!                         ||\n");
    printf("\t\t\t||                                                            ||\n");
    printf("\t\t\t||                                                            ||\n");
    printf("\t\t\t================================================================\n");
}

void judul_menu()
{
	printf("\t\t\t\t      =================================\n");
    printf("\t\t\t\t      |           Menu Utama          |\n");
    printf("\t\t\t\t      =================================\n\n");
}

void tiktik(char* x, int y)
{
	for(i=0;i<strlen(x);i++)
	{
		printf("%c",x[i]);
		Sleep(y);
		
	}
}
