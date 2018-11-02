
/*

  * Author    : Dizor, Aldrin O.
								Ferrer, Edrian Jose D.G.

  * Section   : BSCoE 1-5
  * Date      : August 22, 2018
  * Professor : Engr. Pedrito Tenerife Jr.
  * Version   : Final Version

*/
#include <stdio.h>



int main() {
	float Pera;
	int Money;


	printf("This program computes for the denomination of you money in Philippine Peso. \n");
	printf("Note: Please do not input letters and special characters. \n");
	printf("Please enter an amount to calculate its denomination: ");
	scanf("%f",&Pera);
	printf("\n%f\n",Pera);


	if((int)Pera == 0)
	{
		printf("ERROR: INVALID INPUT");
	}
	else
	{
		if(Pera < 0)
			printf("You have entered an invalid amount");
		else
		{
			printf("Your money is: P %.2f and its denominations are:\n",Pera);
			if(Pera >= 1000)
				{
					Money = Pera / 1000;
					Pera -= (Money * 1000);
					if(Money > 1)
						{
							printf("%d pieces of P 1,000.00 \n",Money);
						}
					else
						{
							printf("%d piece of P 1,000.00 \n",Money);
						}
				}
			if(Pera >= 500)
				{
					Money = Pera / 500;
					Pera -= (Money * 500);
					printf("%d piece of P 500.00 \n", Money);
				}
			if(Pera >= 200)
				{
					Money = Pera / 200;
					Pera -= (Money * 200);
					if(Money > 1)
						{
							printf("%d pieces of P 200.00 \n",Money);
						}
					else
						{
							printf("%d piece of P 200.00 \n",Money);
						}
				}
			if(Pera >= 100)
				{
					Money = Pera / 100;
					Pera -= (Money * 100);
					printf("%d piece of P 100.00 \n",Money);
				}
			if(Pera >= 50)
				{
					Money = Pera / 50;
					Pera -= (Money * 50);
					printf("%d piece of P 50.00 \n",Money);
				}
			if(Pera >= 20)
				{
					Money = Pera / 20;
					Pera -= (Money * 20);
					if(Money > 1)
						{
							printf("%d pieces of P 20.00 \n",Money);
						}
					else
						{
							printf("%d piece of P 20.00 \n",Money);
						}
				}
			if(Pera >= 10)
				{
					Money = Pera / 10;
					Pera -= (Money * 10);
					printf("%d piece of P 10.00 \n",Money);
				}
			if(Pera >= 5)
				{
					Money = Pera / 5;
					Pera -= (Money * 5);
					printf("%d piece of P 5.00 \n",Money);
				}
			if(Pera >= 1)
				{
					Money = Pera / 1;
					Pera -= (Money * 1);
					if(Money > 1)
						{
							printf("%d pieces of P 1.00 \n",Money);
						}
					else
						{
							printf("%d piece of P 1.00 \n",Money);
						}
				}
			if(Pera >= 0.25)
				{
					Money = Pera / 0.25;
					Pera -= (Money * 0.25);
					if(Money > 1)
						{
							printf("%d pieces of P 0.25 \n",Money);
						}
					else
						{
							printf("%d piece of P 0.25 \n",Money);
						}
				}
			if(Pera >= 0.05)
				{
					Money = Pera / 0.05;
					Pera -= (Money * 0.05);
					if(Money > 1)
						{
							printf("%d pieces of P 0.05 \n",Money);
						}
					else
						{
							printf("%d piece of P 0.05 \n",Money);
						}
				}
			if(Pera >= 0.01)
				{
					Money = Pera / 0.01;
					Pera -= (Money * 0.01);
					if(Money > 1)
						{
							printf("%d pieces of P 0.01 \n",Money);
						}
					else
						{
							printf("%d piece of P 0.01 \n",Money);
						}
				}
			if(Pera != 0)
				printf("Note: The remaining amount is not avaible on current denomination.");
		}
	}
	return 0;
}
