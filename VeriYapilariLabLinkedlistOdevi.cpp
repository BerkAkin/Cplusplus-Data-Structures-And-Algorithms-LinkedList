//191307012 BERK AKIN
#include <iostream>
#include <locale>
using namespace std;

struct düğüm
{
	int değer;
	düğüm* sonraki;
};

düğüm* basa_ekleme(düğüm* baş, int giriş)
{
	if (baş == NULL)  //ilk düğüm oluşturma kontrolü
	{
		düğüm* geçici = new düğüm();
		geçici->değer = giriş;
		geçici->sonraki = NULL;
		baş = geçici;
		cout << "İlk düğüm açılıyor, değeri: " << geçici->değer << endl;
	}
	else
	{
		düğüm* geçici = new düğüm();
		geçici->değer = giriş;
		geçici->sonraki = baş;
		baş = geçici;
		cout << "Başa yeni bir düğüm ekleniyor, değeri: " << geçici->değer << endl;
	}
	return baş;
}
düğüm* baştan_silme(düğüm* baş)
{
	if (baş == NULL)
	{
		cout << "Düğüm yok\n";
	}
	else
	{
		if (baş->sonraki == NULL)
		{
			delete baş;
			baş = NULL;
		}
		else
		{
			düğüm* geçici = baş->sonraki;
			delete baş;
			baş = geçici;
		}
	}
	return baş;
}
düğüm* araya_ekleme(düğüm* baş, int a, int b)
{
	düğüm* geçici = new düğüm();
	düğüm* geçici2 = new düğüm();
	geçici2->değer = b;
	geçici = baş;
	while (geçici->değer != a)
	{
		geçici = geçici->sonraki;
	}
	düğüm* geçici3 = new düğüm();
	geçici3 = geçici->sonraki;
	geçici->sonraki = geçici2;
	geçici2->sonraki = geçici3;
	return baş;
}
düğüm* sondan_silme(düğüm* baş)
{
	if (baş == NULL)
	{
		cout << "Düğüm yok" << endl;
	}
	else
	{
		if (baş->sonraki == NULL)
		{
			delete baş;
			baş = NULL;
		}
		else
		{
			düğüm* geçici = baş->sonraki;
			while (geçici->sonraki->sonraki != NULL)
			{
				geçici = geçici->sonraki;
			}
			düğüm* geçici2 = geçici;
			delete geçici->sonraki;
			geçici2->sonraki = NULL;
		}
	}
	return baş;
}
düğüm* aradan_silme(düğüm* baş, int q)
{
	if (baş == NULL)
	{
		cout << "Düğüm yok\n";
	}
	else
	{
		if (baş->değer == q)
		{
			baş = baştan_silme(baş);
		}
		düğüm* ilk = NULL;
		düğüm* son = NULL;
		düğüm* geçici = NULL;
		geçici = baş;
		while (geçici->sonraki->değer != q)
		{
			geçici = geçici->sonraki;
		}
		if (geçici->sonraki == NULL)
		{
			baş = sondan_silme(baş);
		}
		ilk = geçici;
		son = geçici->sonraki->sonraki;
		free(geçici->sonraki);
		ilk->sonraki = son;
	}
	return baş;
}

düğüm* sona_ekleme(düğüm* baş, int giriş)
{
	if (baş == NULL)
	{
		düğüm* geçici = new düğüm();
		geçici->değer = giriş;
		geçici->sonraki = NULL;
		baş = geçici;
		cout << "İlk düğüm açılıyor, değeri: " << geçici->değer << endl;
	}
	else
	{
		düğüm* geçici = new düğüm();
		geçici->değer = giriş;
		geçici->sonraki = NULL;

		düğüm* geçici2 = baş;
		while (geçici2->sonraki != NULL)
		{
			geçici2 = geçici2->sonraki;
		}
		geçici2->sonraki = geçici;
		cout << "Sona yeni bir düğüm ekleniyor., değeri: " << geçici->değer << endl;
	}
	return baş;
}

void yazdir(düğüm* baş)
{
	düğüm* geçici = baş;
	while (geçici != NULL)
	{
		cout << geçici->değer << endl;
		geçici = geçici->sonraki;
	}
}
void ara(düğüm* baş)
{
	if (baş == NULL)
	{
		cout << "Liste boş" << endl;
	}
	else
	{
		düğüm* geçici = baş;
		while (geçici != NULL)
		{
			if (geçici->değer % 3 == 0)
			{
				cout << "Üçe bölünebilen sayı: " << geçici->değer << endl;
			}
			geçici = geçici->sonraki;
		}
	}
}



int main()
{
	setlocale(LC_ALL, "Turkish");
	düğüm* baş = NULL;

	baş = basa_ekleme(baş, 9);
	baş = basa_ekleme(baş, 19);
	baş = basa_ekleme(baş, 29);
	baş = basa_ekleme(baş, 39);
	baş = basa_ekleme(baş, 49);
	cout << "Liste: " << endl;
	yazdir(baş);

	baş = sona_ekleme(baş, 1);
	baş = sona_ekleme(baş, 21);
	baş = sona_ekleme(baş, 31);
	baş = sona_ekleme(baş, 41);
	baş = sona_ekleme(baş, 51);
	cout << "Liste: " << endl;
	yazdir(baş);

	cout << "Araya değerler ekleniyor: \n";
	araya_ekleme(baş, 1, 5);
	araya_ekleme(baş, 1, 15);
	araya_ekleme(baş, 1, 25);
	araya_ekleme(baş, 1, 35);
	araya_ekleme(baş, 1, 45);
	cout << "Liste:\n";
	yazdir(baş);

	ara(baş);

	cout << "Baştan ilk 3 eleman siliniyor.";
	baş = baştan_silme(baş);
	baş = baştan_silme(baş);
	baş = baştan_silme(baş);
	cout << "Liste:\n ";
	yazdir(baş);

	cout << "Sondan 3 eleman siliniyor.\n";
	sondan_silme(baş);
	sondan_silme(baş);
	sondan_silme(baş);
	cout << "Liste:\n";
	yazdir(baş);

	cout << "Aradan 3 eleman siliniyor.\n";
	baş = aradan_silme(baş, 5);
	baş = aradan_silme(baş, 15);
	baş = aradan_silme(baş, 25);
	cout << "Liste:\n";
	yazdir(baş);
	return 0;
}