#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
int id;
char isim[50];
int vize;
int finall;
float ortalama;
}ogrenci;

void ogrenciekle(int n,ogrenci o[n]);
void ortalamahesapla(int n,ogrenci o[n]);
void listele(int n,ogrenci o[n]);
void dosyayakaydet(int n,ogrenci o[n]);
void dosyadanokuma(int n,ogrenci o[n]);
void arama(int n,ogrenci o[n]);


int main()

{

int n;
printf("kac adet ogrenci olsun: ");
scanf("%d",&n);

ogrenci o[n];
int secim=-1;
while(secim!=0){
printf("\n0-programdan cikis yapiliyor...\n");
printf("1-ogrenci ekle\n");
printf("2-listele\n");
printf("3-ogrenci ara\n");
printf("4-ortalama hesapla\n");
printf("5-dosyaya kaydet\n");
printf("6-dosyadan oku\n");
printf("lutfen 0-6 arasinda sayi seciniz: ");
scanf("%d",&secim);

switch(secim){

case 0: printf("\nprogramdan cikis yapiliyor...\n");
break;

case 1: ogrenciekle(n,o);
break;

case 2: listele(n,o);
break;

case 3: arama(n,o);
break;

case 4: ortalamahesapla(n,o);
break;

case 5: dosyayakaydet(n,o);
break;

case 6: dosyadanokuma(n,o);
break;

default : printf("\nhatali sayi girdiniz!!!\n");
break;
}
}

    return 0;
}



void ogrenciekle(int n,ogrenci o[n]){
int i;
printf("lutfen ogrencilerin bilgilerini giriniz:\n");
for(i=0;i<n;i++){

printf("\n%d.ogrencinin id'si: ",i+1);
scanf("%d",&o[i].id);
getchar();

printf("%d.ogrencinin adi: ",i+1);
fgets(o[i].isim,sizeof(o[i].isim),stdin);
o[i].isim[strcspn(o[i].isim,"\n")]=0;

printf("%d.ogrencinin vize notu: ",i+1);
scanf("%d",&o[i].vize);

printf("%d.ogrencinin final notu: ",i+1);
scanf("%d",&o[i].finall);
}
}

void ortalamahesapla(int n,ogrenci o[n]){
int i;
for(i=0;i<n;i++){
o[i].ortalama=o[i].vize*0.4+o[i].finall*0.6;
printf("\n%d.ogrencinin ortalamasi:%.1f\n",i+1,o[i].ortalama);
}
}

void listele(int n,ogrenci o[n]){
int i;
for(i=0;i<n;i++){
printf("\n%d.ogrencinin id'si:%d\n",i+1,o[i].id);
printf("%d.ogrencinin adi:%s\n",i+1,o[i].isim);
printf("%d.ogrencinin vize notu:%d\n",i+1,o[i].vize);
printf("%d.ogrencinin final notu:%d\n",i+1,o[i].finall);
printf("%d.ogrencinin ortalamasi:%.1f\n",i+1,o[i].ortalama);
}
}

void dosyayakaydet(int n,ogrenci o[n]){
FILE *dosya;
dosya=fopen("jhin.txt","w");
if(dosya==NULL){
printf("dosya acilamadi");
return ;
}
int i;
for(i=0;i<n;i++){
fprintf(dosya,"\n%d.ogrencinin id'si:%d\n",i+1,o[i].id);
fprintf(dosya,"%d.ogrencinin adi:%s\n",i+1,o[i].isim);
fprintf(dosya,"%d.ogrencinin vize notu:%d\n",i+1,o[i].vize);
fprintf(dosya,"%d.ogrencinin final notu:%d\n",i+1,o[i].finall);
fprintf(dosya,"%d.ogrencinin ortalamasi:%.1f\n",i+1,o[i].ortalama);
}
fclose(dosya);
printf("\ndosyaya yazma gerceklestirildi\n");

}

void dosyadanokuma(int n,ogrenci o[n]){
FILE *dosya;
dosya=fopen("jhin.txt","r");
if(dosya==NULL){
printf("dosya acilamadi");
return ;
}
char metin[100];
while(fgets(metin,sizeof(metin),dosya)){
printf("%s",metin);
}
fclose(dosya);
}

void arama(int n,ogrenci o[n]){
int i,kimlik,bulundu=0;
printf("\naramak istediginiz id bilgisini giriniz: ");
scanf("%d",&kimlik);
getchar();

for(i=0;i<n;i++){
if(o[i].id==kimlik){
printf("ogrenci bulundu\n");
printf("\nOgrenci Bulundu: %s (Vize: %d, Final: %d)\n", o[i].isim, o[i].vize, o[i].finall);
bulundu=1;
break;
}
}
if(bulundu==0){
printf("ogrenci bulunamadi\n");
}
}

