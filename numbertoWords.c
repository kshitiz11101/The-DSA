
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *ones[]={"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char *ten_special[]={"","ten","eleven", "twelve", "thirteen","fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char *tens[]= {"","", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy","eighty","ninety"};
char *tens_power[] = {"","","","hundred", "thousand", "million","billion"}; 

void print(char *num)
{
	int n, n2, n3;
	int len = strlen(num);
	if (len == 1)
    {
        n = num[0] - 48;
        printf("%s ", ones[n]);

    }



    
    if (len == 2 && num[0]==49)
    {
        n = (num[0]-48) + (num[1] - 48);
        printf("%s ", ten_special[n]);
    }

    else if (len==2 && num[1] == 48)
    {
        n = (num[0]-48) + (num[1] - 48);
        printf("%s ", tens[n]);      
        
    }
    else if (len==2)
    {
        n=num[0]-48;
        n2=num[1] - 48;
        printf("%s %s ", tens[n], ones[n2]);       

    }




    if (len==3 && num[1]==48 && num[2]==48)
    {
        n=num[0] - 48;
        printf("%s %s ", ones[n],tens_power[len]);   

    }
    else if (len==3 && num[1]==48)
    {
        n=num[0] - 48;
        printf("%s %s ", ones[n],tens_power[len]);
        n2=num[2] - 48;
        printf("%s ", ones[n2]);
    }
    else if (len==3 && num[2]==48)
    {
        n=num[0] - 48;
        printf("%s %s ", ones[n],tens_power[len]);
        n2=(num[1]-48) + (num[2] - 48);
        printf("%s ", tens[n2]);
    }
    else if (len==3 && num[1]==49)
    {
        n=num[0] - 48;
        printf("%s %s ", ones[n],tens_power[len]);
        n2=(num[1]-48) + (num[2] - 48);
        printf("%s ", ten_special[n2]);
    }
    else if (len==3)
    {
        n=num[0] - 48;
        printf("%s %s ", ones[n],tens_power[len]);
        n2=num[1]-48;
        n3=num[2]-48;
        printf("%s %s ", tens[n2], ones[n3]);        
    }
}

int main()
{
	char num[20],temp[20];
	long long int number,temporary=0;
	
	printf("Enter a number: ");
    scanf("%lld", &number);

	sprintf(num, "%lld", number);

	int length=strlen(num);
	
	if (length >12)
	{
		printf("\nError: Enter number less than a trillion!");
		exit(0);
	}

	if (number==0)
	{
		printf("zero");
		exit(0);
	}
	
	if (number >= 1000000000)
	{
		if (length == 12)
		{
			temporary=number/1000000000;
			
		sprintf(temp, "%lld", temporary);
		print(temp);
		
		
		}	

		else if (length==11)
		{
			temporary=number/1000000000;
		sprintf(temp, "%lld", temporary);
		print(temp);
		
		}

		else
		{
			temporary=number/1000000000;
			sprintf(temp, "%lld", temporary);
			print(temp);
			
		}
		printf("billion ");
	}

	
	length=9;
	number=number % 1000000000;
	temporary=0;
	sprintf(num, "%lld", number);
	

	if (number >= 1000000)
	{
		if (length==9)
		{
			temporary=number/1000000;
		
		sprintf(temp, "%lld", temporary);
		print(temp);
		}
		
		else if (length ==8)
		{
			temporary=number/1000000;
		
		sprintf(temp, "%lld", temporary);
		print(temp);
		}

		else
		{
			temporary=number/1000000;
		
		sprintf(temp, "%lld", temporary);
		print(temp);
		}
		printf("million ");	
	}

	 

	length=6;
	number=number % 1000000;
	temporary=0;
	sprintf(num, "%lld", number);

	if (number >= 1000 )
	{
		if (length==6)
		{
			temporary=number/1000;
		
		
		sprintf(temp, "%lld", temporary);
		print(temp);
		}

		else if (length==5)
		{
			temporary=number/1000;
		
		
		sprintf(temp, "%lld", temporary);
		print(temp);
		}

		else{
			temporary=number/1000;
		
		
		sprintf(temp, "%lld", temporary);
		print(temp);
		}
		printf("thousand ");
	}
	
	length=3;
	number=number % 1000;
	temporary=0;
	sprintf(num, "%lld", number);
	

	
	if (length==3 || length==2 || length ==1)
	{
		print(num);
	}




	else 
	printf("Enter postive value! ");

	printf("\n");

	return 0;
}