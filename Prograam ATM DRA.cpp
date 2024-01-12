#include<stdio.h>
#include<windows.h>
struct akun{
	int rekening;
	int pin;
	int saldo;
};
banner(){
	printf("===========================================");
	printf("\n------------PT BANK DIO BERSAMA------------");
	printf("\n===========================================\n");
 }	
int main() {
	system("color 1F");
	struct akun pengguna = {1234, 9099, 1000000};
	int kesempatan = 0, nominal, pilih, rekeningtuju, transfer, setor, keluar;
	banner();
	printf("\nMasukkan Nomor Rekening Anda\n> ");
	scanf("%d",&pengguna.rekening);	
	system("cls");
	banner();
	printf("\nMasukkan PIN ATM Anda\n> ");
	pin:
    scanf("%d", &pengguna.pin);
    	if (pengguna.pin == 9099){	
    	menu:
	    	system("cls");
			banner();
	    	printf("\nPilih Jenis Transaksi,\n");
	    	printf("1. Tarik Tunai\n");
	    	printf("2. Transfer\n");
	    	printf("3. Setor Tunai\n");
	    	printf("4. Cek Saldo\n");
	    	printf("5. Keluar\n");
	    	printf("Pilih > ");
	    	scanf("%d",&pilih);
	    	switch (pilih){
	    		case 1:
	    			system("cls");
					banner();
	    		pilih_nominal:	
	    			printf("\nPilih Nominal\n");
	    			printf("1. Rp. 50000\n");
			    	printf("2. Rp. 100000\n");
			    	printf("3. Rp. 200000\n");
			    	printf("4. Rp. Nominal Lain\n");
			    	printf("Pilih > ");
	    			scanf("%d",&nominal);
			    	if (nominal == 1)
			    		keluar = 50000;
					else if (nominal == 2)
			    		keluar = 100000;
					else if (nominal == 3)
			    		keluar = 200000;
					else if ( nominal == 4){
						system("cls");
						banner();
						input_nominal:							
							printf("\nMasukkan Nominal Yang Ingin Anda Ambil (Kelipatan 50000)\nRp. ");
							scanf("%d",&keluar);
							if (keluar % 50000 != 0){
								system("cls");
								banner();
								printf("\nNominal Yang Anda Masukkan Bukan Kelipatan 50000\n\n");
								goto input_nominal;
					}
				}
					else {
					system("cls");
					banner();
					printf("\nPilihan salah\nSilahkan pilih kembali\n\n");
					goto pilih_nominal;
					}
					if (keluar > pengguna.saldo){
						system("cls");
						banner();
						printf("\nTransaksi Gagal\nSaldo Tidak Mencukupi");
						goto konfirmasi;
					}
					else {
						system("cls");
						banner();
						pengguna.saldo = pengguna.saldo - keluar;
						printf("\nTransaksi Berhasil, Saldo Anda\nRp. %d",pengguna.saldo);
						goto konfirmasi;
					}
			    	break;
			    case 2:
		    		system("cls");
					banner();
					printf("\nMasukkan Nomor Rekening Yang Ingin Dituju\n> ");
					scanf("%d",&rekeningtuju);
					printf("Masukkan Nominal Yang Ingin Anda Transfer\n> Rp. ");
					scanf("%d",&transfer);
					if (transfer > pengguna.saldo){
						system("cls");
						banner();
						printf("Transaksi gagal,\n");
						printf("Saldo Anda tidak mencukupi\n\n");
						goto konfirmasi;
					}
					else {
						system("cls");
						banner();
						pengguna.saldo = pengguna.saldo - transfer;
						printf("\nTransaksi Berhasil, Saldo Anda\nRp. %d",pengguna.saldo);
						goto konfirmasi;
					}
						break;
				case 3:
					system("cls");
					banner();
					inputsetor:
						printf("\nMasukkan Nominal Yang Ingin Anda Setor, \nDan Merupakan Kelipatan 50000\nRp. ");
						scanf("%d",&setor);
						if (setor % 50000 != 0){
							system("cls");
							banner();
							printf("\nNominal yang anda masukkan bukan Kelipatan 50000\n\n");
							goto inputsetor;
						} 
						else{
						system("cls");
						banner();
						printf("\nTransaksi Berhasil\n");
						pengguna.saldo = pengguna.saldo + setor;
						printf("\nTotal Saldo Anda Menjadi\nRp. %d\n",pengguna.saldo);
						goto konfirmasi;
						}
						break;
				case 4:
					system("cls");
					banner();
					printf("\nSaldo Anda\nRp. %d\n",pengguna.saldo);
					goto konfirmasi;
					break;
				case 5:
					goto end;
					break;
				default:
					system("cls");
					banner();
					printf("\nPilihan Menu Salah,\nSilahkan Pilih Kembali\n");
					goto menu;
					break;		
		} 
	}
	else{
		while (kesempatan < 3){ 
			system("cls");
			banner();
			printf("\nPIN ATM Yang Anda Masukkan Salah,");
			printf("\nSilahkan Masukkan PIN ATM Dengan Benar\n> ");
			scanf("%d",&pengguna.pin);
			if (pengguna.pin == 9099){
			goto menu;
			}
			kesempatan++;
			if (kesempatan == 2){
				system("cls");
				banner();
				printf("\nSelamat Rekening Anda Telah Diblokir.\nSilahkan Hubungi Admin.\n\n");
				system("pause");
				goto end;
				}
		}
	}
	konfirmasi:
		printf("\nIngin Melakukan Transaksi Lagi ?\n");
		printf(" 1. Ya\n");
		printf(" 2. Tidak\n");
		printf("Pilih : ");
		scanf("%d", &pilih);
		if (pilih == 1){
			system("cls");
			banner();
			goto menu;
		}
		else if (pilih == 2)
			goto end;
		else{
			printf("Pilihan Anda Salah,\nSilahkan Pilih Kembali\n\n");
			goto konfirmasi;
		}
	end:
		system("cls");
		banner();
		printf("\n\t\tTERIMA KASIH:)\n\n");
return 0;
}
