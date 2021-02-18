#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <string.h>
using namespace std;
const unsigned char  enter=13;
const  unsigned char ekstra=224;
const unsigned char yukari=72;
const unsigned char asagi=80;
unsigned char giris1,giris2;
string _metin1,_metin2;
int anlik_sayfa,miktar,son_sayfa,sayfa_sayisi,deger;


/*
0 = farklý deger girildi
1 = enter
2 = yukarý tuþ
3 = aþaðý tuþ
*/
unsigned char basilan_tus(){
	giris1=getch();
	// entera basýlýp basýlmadýðýný kontrol ediyoruz
	if(giris1==enter){
		return 1;
	}
	// yukarý aþþaðý çift deðerli diye kontrol ediyoruz
	else if(giris1==ekstra){
		giris2=getch();
		if(giris2==yukari){
			return 2;
		}
		else if(giris2==asagi){
			return 3;
		}
		else{
			return 0;
		}
	}
	else{
		return 0;
	}
}
string menuyaz(string menu[],int menu_sayisi,int secim,int tip,int carpan){
		string yaz;
if(tip==1 or tip==3) yaz=_metin1+"\n";
else yaz="";
	for(int i=0; i<menu_sayisi;i++){
		if(i==secim)
		yaz = yaz + " --> " + menu[i+carpan] + "\n";
		else
		yaz = yaz + "\t" + menu[i+carpan] + "\n";
	}
	if(tip==2 or tip==3)
	yaz=yaz+"\n"+_metin2;
return yaz;
}

int secili_sira(int son_secim,int menu_sayisi,bool durum,int miktar_gir,int anlik_sayfa_gir, int son_sayfa_gir, int sayfa_sayisi_gir){
unsigned char  anlik= basilan_tus();
if(anlik==1){
return -1;}
else if(anlik==0){
	return son_secim;}
else{
	if(anlik==3){
		if(durum==true){
			if(anlik_sayfa_gir==sayfa_sayisi_gir){
			if(son_secim==son_sayfa_gir-1){
	anlik_sayfa=0;
		return 0;}
		else
		return ++son_secim;	
			}// en son sayfa
		else{
					if(son_secim==miktar_gir-1){
			anlik_sayfa++;
		return 0;}
		else
		return ++son_secim;	
			}// normal sayfa durmu
		}// coklu sayfa
		
	else{
		if(son_secim==menu_sayisi-1)
		return 0;
		else
		return ++son_secim;}
	}// durum sonu
	else{
	if(durum==true){
			if(anlik_sayfa_gir==0){
		if(son_secim==0){
		anlik_sayfa=sayfa_sayisi_gir;
		return son_sayfa-1;
	}
		else
		return --son_secim;
			}// en son sayfa
				else if(anlik_sayfa_gir==sayfa_sayisi_gir){
		if(son_secim==0){
		anlik_sayfa--;
		deger=miktar;
		return son_sayfa-1;
	}
		else
		return --son_secim;
			}// en son sayfa
		else{
			if(son_secim==0){
			anlik_sayfa--;
		return menu_sayisi-1;
	}
		else
		return --son_secim;
			}// normal sayfa durmu
		}// coklu sayfa
		else{
		
			if(son_secim==0)
		return menu_sayisi-1;
		else
		return --son_secim;
	}
	}// asagý durumu
	}// yukarý aþaðý durumu
}//fonksiyon sonu

int menu_olus(string menu[], int menu_sayisi,int tip,bool coklu,int miktar_gir){
	miktar=miktar_gir;
	int secim=0;
	sayfa_sayisi=menu_sayisi/miktar;
	son_sayfa=menu_sayisi-(sayfa_sayisi*miktar);
	anlik_sayfa=0;
	if(son_sayfa==0){
	sayfa_sayisi--;
	son_sayfa=miktar;
	}
	deger=miktar;
	if(coklu==false){
		deger=menu_sayisi;
	}
system("CLS");
	cout<<menuyaz(menu,deger,secim,tip,0);
	int durum=-2;
	while(true){
durum=secili_sira(secim,menu_sayisi,coklu,miktar,anlik_sayfa,son_sayfa,sayfa_sayisi);
		if(durum==-1)
		return secim+(anlik_sayfa*miktar);
		else secim=durum;
		system("CLS");
		if(anlik_sayfa==sayfa_sayisi)
		deger=son_sayfa;
		else
		deger=miktar;
		if(coklu==false)
		deger=menu_sayisi;
		cout<<menuyaz(menu,deger,secim,tip,anlik_sayfa*miktar);
	}
}

// önde yazi olan hali
int menu_yap(string yazi,string menu[], int menu_sayisi){
	_metin1 = yazi; 
	return menu_olus(menu,menu_sayisi,1,false,menu_sayisi);}
// arkada yazi olan hali
int menu_yap(string menu[], int menu_sayisi,string yazi){
	_metin2 = yazi; 
	return menu_olus(menu,menu_sayisi,2,false,menu_sayisi);}
	// hem önde hem arkada yazi olan hali
int menu_yap(string yazi,string menu[], int menu_sayisi,string yazi2){
	_metin1 = yazi; _metin2 = yazi2; 
	return menu_olus(menu,menu_sayisi,3,false,menu_sayisi);}
	// yazýsýz hali
int menu_yap(string menu[], int menu_sayisi){
	return menu_olus(menu,menu_sayisi,0,false,menu_sayisi);}
// yazýsýz coklu
int menu_yap(string menu[], int menu_sayisi,int miktar_gir){
	return menu_olus(menu,menu_sayisi,0,true,miktar_gir);}
// önde yazi olan hali çoklu
int menu_yap(string yazi,string menu[], int menu_sayisi,int miktar_gir){
	_metin1 = yazi; 
	return menu_olus(menu,menu_sayisi,1,true,miktar_gir);}
// arkada yazi olan hali çoklu
int menu_yap(string menu[], int menu_sayisi,int miktar_gir,string yazi){
	_metin2 = yazi; 
	return menu_olus(menu,menu_sayisi,2,true,miktar_gir);}
	// hem önde hem arkada yazi olan hali çoklu
int menu_yap(string yazi,string menu[], int menu_sayisi,int miktar_gir,string yazi2){
	_metin1 = yazi; _metin2 = yazi2; 
	return menu_olus(menu,menu_sayisi,3,true,miktar_gir);}