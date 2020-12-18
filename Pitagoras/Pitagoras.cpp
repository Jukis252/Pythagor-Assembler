#include <iostream>
#include <fstream>

using namespace std;

bool Pirminis(int n) 
{
	int i;
	bool isPrime = true;
	// 0 and 1 are not prime numbers
	if (n == 0 || n == 1) {
		isPrime = false;
	}
	else 
	{
		for (i = 2; i <= n / 2; ++i) 
		{
			if (n % i == 0) 
			{
				isPrime = false;
				break;
			}
		}
	}
	if (isPrime)
	{
		return true;
	}		
	else
	{
		return false;
	}
}

int main()
{
	remove("Pitagoras.txt");
	int kiekis = 0; // kieki yra reiksmiu
	float x[4]; // x verte
	float y[4]; // y verte
	float z[4]; // z verte
	float sub[4]; // skirtumas
	ofstream fr;
	fr.open("Pitagoras.txt");
	fr << "Pitagoras" << endl;
	fr << "Intervalas nuo 1 iki 1000" << endl;

	for (float i = 1; i <= 1000; i += 4)
	{
		x[0] = i, x[1] = i + 1, x[2] = i + 2, x[3] = i + 3;

		for (float j = i + 1; j <= 1000; j++)
		{
			y[0] = j, y[1] = j + 1, y[2] = j + 2, y[3] = j + 3;

			_asm {
				movups xmm0, x // Surasomos visos x reiksmes i xmm0
				movups xmm1, y // Surasomos visos y reiksmes i xmm1

				// mulps = daugyba
				mulps xmm0, xmm0
				mulps xmm1, xmm1 

				// addps = sudetis
				addps xmm0, xmm1

				// sqrtps = saknis
				sqrtps xmm1, xmm0 

				// roundps = apvalinimas 
				roundps xmm1, xmm1, 1
				movups[z], xmm1
				mulps xmm1, xmm1 // panaikinti sakni

				// subps = atimtis
				subps xmm0, xmm1 
				movups[sub], xmm0 // pervedam atimta verte
			}
			for (int k = 0; k < 4; k++)
			{
				if (sub[k] == 0) // Patikrinam, ar atimti skaciai lygu 0
				{
					/*if (/*Pirminis(x[k]) and Pirminis(y[k]) and Pirminis(z[k]))
					{
						
					}*/
					fr << x[k] << "^  " << y[k] << "  " << z[k] << endl;
					kiekis++;
				}
			}
		}
	}
	fr << endl << "Isviso : " << kiekis;
	fr.close();
	cout << "Viskas faile" << endl;
}