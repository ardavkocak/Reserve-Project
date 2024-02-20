#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <graphics.h>

//220202079 Berk Karaoglu
//220202008 Arda Kocak

float alanHesaplama(int sekil[][2],int kenarSayisi) //Bu fonksiyonda gelen sekil koordinatlarina gore alan hesabi yapilir.
{
    int i = 0;
    float alan = 0;
    float hesaplama = 0;
    int olcek = 16;

    for(i = 0; i < kenarSayisi - 1 ; i++)
    {
        hesaplama = hesaplama + ((sekil[i][0] * sekil[i + 1][1]) + (sekil[i + 1][0] * sekil[i][1] * -1));
        alan = hesaplama / 2;
    }
    
    alan = abs(alan) / (olcek * olcek);
    return alan;
}

int indisDegeriniBul(char *txtBelgesi,char *satirBilgisi,int txtBelgesiUzunlugu,int satirUzunlugu)
{
    int deger;
    int i = 0;

    if(satirBilgisi[1] != '\0')     //satirBilgisi dizisinin 1. indisi NULL degilse girilen satir bilgisi 2 basamaklidir.Eger NULL ise girilen satir bilgisi 1 basamaklidir.
    {
        while(i != txtBelgesiUzunlugu)
        {
            if(txtBelgesi[i] == satirBilgisi[0])
            {
                if(txtBelgesi[i + 1] == satirBilgisi[1])
                {
                    if(txtBelgesi[i + 2] == 'B')
                    {
                        deger = i + 3;
                        break;
                    }
                }
            }
            i++;
        }
    }
    else        //Eger bu kisim calisirsa girilen satir bilgisi tek basamakli bir sayidir.
    {
        while(i != txtBelgesiUzunlugu)
        {
            if(txtBelgesi[i] == satirBilgisi[0])
            {
                if(txtBelgesi[i + 1] == 'B')
                {
                    deger = i + 2;
                    break;
                }
            }
            i++;
        }
    }
    return deger;
}

int main() {
    FILE *dosya;
    int indisDegeri = 0;
    char satirBilgisi[3];
    int satirUzunlugu = 0;
    char txtBelgesi[2000];
    int i = 0;
    int j = 0;
    int txtBelgesiUzunlugu = 0;
    char okunanKarakter;
	int koordinatlar[41][2];
	int koordinatSayaci = 0;
	int kenarKontrol = 0;
	int sekilKontrol = 0;
	int x,y;
	int sekilSayisi = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	float toplamAlan = 0;
	float rezervdegeri=0;
	float sondajMaliyeti=0;
	float platformMaliyeti=0;
	
	system("curl https://bilgisayar.kocaeli.edu.tr/prolab1/prolab1.txt > prolab1.txt");
	
	dosya = fopen("prolab1.txt","r");
	
    if (dosya == NULL)
    {
        printf("Dosya acma hatasi\n");
        return 1;
    }

    printf("Cizdirilecek satir bilgisini girin: ");
    fgets(satirBilgisi, sizeof(satirBilgisi), stdin);
    satirBilgisi[strcspn(satirBilgisi, "\n")] = '\0'; //satirBilgisi dizisini sonlandirmak icin dizinin sonuna '\0' elemaini ekler.
    
	printf("Sondaj Maliyetini Giriniz:");
    scanf("%f",&sondajMaliyeti);
    while(sondajMaliyeti  < 0 || sondajMaliyeti > 10)
    {
    	printf("Yanlis deger girdiniz.");
    	printf("\nSondaj Maliyetini Giriniz: ");
    	scanf("%f",&sondajMaliyeti);
	}
	printf("Platform Maliyeti Giriniz:");
	scanf("%f",&platformMaliyeti);

    while ((okunanKarakter = fgetc(dosya)) != EOF)
    {
        txtBelgesi[i] = okunanKarakter;
        txtBelgesiUzunlugu++;
        i++;
    }

    fclose(dosya);
	
	indisDegeri = indisDegeriniBul(txtBelgesi,satirBilgisi,txtBelgesiUzunlugu,satirUzunlugu);
	
	char *ptr = &txtBelgesi[indisDegeri];

    while (*ptr != 'F')
    {
        if (*ptr == '(')
        {
            int x, y;
            if (sscanf(ptr, "(%d,%d)", &x, &y) == 2)
            {
				koordinatlar[koordinatSayaci][0] = x;
				koordinatlar[koordinatSayaci][1] = y;
				koordinatSayaci++;
            }
        }
        ptr++;
    }

	/*for(i = 0; i < koordinatSayaci; i++)
	{
		printf("%d - %d\n",koordinatlar[i][0],koordinatlar[i][1]);
	}*/
	
	int xKontrol = koordinatlar[0][0];
	int yKontrol = koordinatlar[0][1];
	
	for(i = 1 ; i < koordinatSayaci ; i++)
	{
		if(xKontrol == koordinatlar[i][0] && yKontrol == koordinatlar[i][1])		//Sekilsayisini bulan kisim.
		{
			sekilSayisi++;
			i++;
			xKontrol = koordinatlar[i][0];
			yKontrol = koordinatlar[i][1];
		}
	}
	
	//printf("\n\n%d",sekilSayisi);
	
	int kenarSayisi[3] = {0,0,0};
	sekilKontrol = 0;
		
	xKontrol = koordinatlar[0][0];
	yKontrol = koordinatlar[0][1];
	i = 0;

	while(i < koordinatSayaci)
	{
		xKontrol = koordinatlar[i][0];
		yKontrol = koordinatlar[i][1];
		int sonX,sonY;
		kenarKontrol = 0;

		for(j = i + 1 ; j < koordinatSayaci;j++)		//Her bir seklin kenar sayisini bulup kenarSayisi dizisine atayan kisim.
		{
			sonX = koordinatlar[j][0];
			sonY = koordinatlar[j][1];

			if(xKontrol == sonX && yKontrol == sonY)
			{
				kenarSayisi[sekilKontrol] = kenarKontrol + 2;
				sekilKontrol++;
				i = j + 1;
				break;
			}
			else
			{
				kenarKontrol++;
			}
		}
	}
	
	//printf("%d - %d - %d",kenarSayisi[0],kenarSayisi[1],kenarSayisi[2]);
		
	a = kenarSayisi[0];
	b = kenarSayisi[1];
	c = kenarSayisi[2];

	int sekil1[a][2];
	int sekil2[b][2];
	int sekil3[c][2];

	if(sekilSayisi == 1)		//Cizdirilecek sekil sayisina gore gerekli if-else if blogu calisir
	{
		for(i = 0 ; i < a ; i++)
		{
			sekil1[i][0] = koordinatlar[i][0] * 16;
			sekil1[i][1] = koordinatlar[i][1] * 16;
		}
	}

	else if(sekilSayisi == 2)
	{
		for(i = 0 ; i < a ; i++)
		{
			sekil1[i][0] = koordinatlar[i][0] * 16;
			sekil1[i][1] = koordinatlar[i][1] * 16;
		}

		for(i = 0; i < b; i++)
		{
			sekil2[i][0] = koordinatlar[a + i][0] * 16;
			sekil2[i][1] = koordinatlar[a + i][1] * 16;
		}
	}
	else if(sekilSayisi == 3)
	{
		for(i = 0 ; i < a ; i++)
		{
			sekil1[i][0] = koordinatlar[i][0] * 16;
			sekil1[i][1] = koordinatlar[i][1] * 16;
		}

		for(i = 0; i < b; i++)
		{
			sekil2[i][0] = koordinatlar[a + i][0] * 16;
			sekil2[i][1] = koordinatlar[a + i][1] * 16;
		}
		for(i = 0; i < c ; i++)
		{
			sekil3[i][0] = koordinatlar[a + b + i][0] *16;
			sekil3[i][1] = koordinatlar[a + b + i][1] *16;
		}
	}
	
	/*for(i = 0; i < c; i++)
	{
		printf("%d - %d\n",sekil2[i][0] / 16,sekil2[i][1]/ 16);
	}*/
	
	if(sekilSayisi == 1)	//Hesaplanan sekilSayisi degerine gore gerekli alan bulma fonksiyonu calisir.
	{
		toplamAlan = alanHesaplama(sekil1,a);
		printf("Toplam Alan Degeri : %.3f",toplamAlan);
		rezervdegeri=toplamAlan*10;
		printf("\nToplam Rezerv Degeri : %.3f",rezervdegeri);
	}
	else if(sekilSayisi == 2)
	{
		toplamAlan = alanHesaplama(sekil1,a);
		toplamAlan = toplamAlan + alanHesaplama(sekil2,b);
		rezervdegeri=toplamAlan*10;
		printf("Toplam Alan Degeri :%.3f",toplamAlan);
		printf("\nToplam Rezerv Degeri : %.3f",rezervdegeri);
		
	}
	else if(sekilSayisi == 3)
	{
		toplamAlan = alanHesaplama(sekil1,a);
		toplamAlan = toplamAlan + alanHesaplama(sekil2,b);
		toplamAlan = toplamAlan + alanHesaplama(sekil3,c);
		rezervdegeri=toplamAlan*10;
		printf("Toplam Alan Degeri :%.3f",toplamAlan);
		printf("\nToplam Rezerv Degeri : %.3f",rezervdegeri);
	}
	
	initwindow(2560,1600);		//1. penceredeki yesil koordinat duzlemini olusturan kisim.
	
		int cizgiX;
		int cizgiY;
	
	for(cizgiX = 0; cizgiX <= 2240;) //Dikey cizgiler olusturan kisim.
	{
		setcolor(2);
		setlinestyle(0,0,2);
		line(cizgiX,0,cizgiX,1760);
		cizgiX = cizgiX + 16;
	}
	for(cizgiY = 0 ;cizgiY <= 1760;) //Yatay cizgiler olusturan kisim.
	{
		setcolor(2);
		setlinestyle(0,0,2);
		line(0,cizgiY,2240,cizgiY);
		cizgiY = cizgiY + 16;
	}
	
	if(sekilSayisi == 1)		//sekilSayisi degerine gore sekilleri koordinat duzleminde gosteren kisim.
	{
		setfillstyle(SOLID_FILL,BLUE);
		fillpoly(a,(int *)sekil1);
		setlinestyle(0,0,2);
		setcolor(WHITE);
		drawpoly(a,(int *)sekil1);
		getch();
		closegraph();
	}
	if(sekilSayisi==2)
	{
		setfillstyle(SOLID_FILL,BLUE);
		fillpoly(a,(int *)sekil1);
		fillpoly(b,(int *)sekil2);
		setlinestyle(0,0,2);
		setcolor(WHITE);
		drawpoly(a,(int *)sekil1);
		drawpoly(b,(int *)sekil2);
		getch();
		closegraph();
		
	}
	if(sekilSayisi==3)
	{
		setfillstyle(SOLID_FILL,BLUE);
		fillpoly(a,(int *)sekil1);
		fillpoly(b,(int *)sekil2);
		fillpoly(c,(int *)sekil3);
		setlinestyle(0,0,2);
		setcolor(WHITE);
		drawpoly(a,(int *)sekil1);
		drawpoly(b,(int *)sekil2);
		drawpoly(c,(int *)sekil3);
		getch();
		closegraph();
	}
	
	initwindow(2560,1600);
	
	if(sekilSayisi == 1) //sekilSayisi bilgisine gore 2. pencerede sekilleri gosteren kisim.
	{
		setfillstyle(SOLID_FILL,BLUE);
		fillpoly(a,(int *)sekil1);
		setlinestyle(0,0,2);
		setcolor(WHITE);
		drawpoly(a,(int *)sekil1);
	}
	else if(sekilSayisi==2)
	{
		setfillstyle(SOLID_FILL,BLUE);
		fillpoly(a,(int *)sekil1);
		fillpoly(b,(int *)sekil2);
		setlinestyle(0,0,2);
		setcolor(WHITE);
		drawpoly(a,(int *)sekil1);
		drawpoly(b,(int *)sekil2);
	}
	else if(sekilSayisi==3)
	{
		setfillstyle(SOLID_FILL,BLUE);
		fillpoly(a,(int *)sekil1);
		fillpoly(b,(int *)sekil2);
		fillpoly(c,(int *)sekil3);
		setlinestyle(0,0,2);
		setcolor(WHITE);
		drawpoly(a,(int *)sekil1);
		drawpoly(b,(int *)sekil2);
		drawpoly(c,(int *)sekil3);
	}	
	
	//2. pencerede sekilleri es karelere ayiran kisim.
	
	for(cizgiX = 0; cizgiX <= 2240;) //Dikey cizgiler olusturan kisim.
	{
		setcolor(BLACK);
		setlinestyle(0,0,3);
		line(cizgiX,0,cizgiX,1760);
		cizgiX = cizgiX + 16;
	}
	for(cizgiY = 0 ;cizgiY <= 1760;) //Yatay cizgiler olusturan kisim.
	{
		setcolor(BLACK);
		setlinestyle(0,0,3);
		line(0,cizgiY,2240,cizgiY);
		cizgiY = cizgiY + 16;
	}
		getch();
		closegraph();	
}
