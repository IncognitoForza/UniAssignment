#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int n, t, flag ,n, t, n1, n2, i;
long int e[50], d[50], temp[50], j, en[50],m[50];
char msg[100];
int IsPrime(int num);
void encryptionkey();
long int cd(long int li);
void encrypt();
void decrypt();

int main(){
	printf("Please enter the first prime number:\n");
	scanf("%d", &n1);
	printf("\nPlease enter the second prime number:\n");
	scanf("%d", &n2);
	printf("Please enter the string to be encrypted: \n");
	scanf("%s", &msg);
	
	for(i=0;msg[i]!=NULL;i++){
		m[i]=msg[i];
	}
	
	if(IsPrime(n1)==0 || IsPrime(n2)==0){
		printf("\nA number is not prime\n");
		exit(0);
	}else{
		printf("\nBoth numbers are prime\n");
	}
	
	n = n1 * n2;
	t = (n1-1) * (n2-1);
	
	encryptionkey();
	
	printf("\nPOSSIBLE VALUES OF e AND d ARE\n");
  	for(i = 0; i < j-1; i++){
  		printf("\n%ld\t%ld", e[i], d[i]);
	}
  	encrypt();
  	decrypt();
	return 0;
}

int IsPrime(int num){
	int i;
	j=sqrt(num);
	for(i=2; i<num; i++){
		if (num % i == 0 && i != num) return 0;
	}
	return 1;
}

void encryptionkey(){
	int k;
  	k = 0;
  	for(i = 2; i < t; i++)
  {
    if(t % i == 0)
     continue;
    flag = IsPrime(i);
    if(flag == 1 && i != n1 && i != n2)
    {
     e[k] = i;
     flag = cd(e[k]);
    if(flag > 0)
    {
     d[k] = flag;
     k++;
    }
   if(k == 99)
    break;
   }
 }
}

long int cd(long int li){
	long int k = 1;
  	while(1)
  	{
    	k = k + t;
    	if(k % li == 0){
    		return(k / li);
		}
  }
}
void encrypt(){
	long int pt, ct, key = e[0], k, len;
  	i = 0;
  	len = strlen(msg);
  	while(i != len)
  	{
    	pt = m[i];
    	pt = pt - 96;
    	k = 1;
    	for(j = 0; j < key; j++)
    	{
     		k = k * pt;
     		k = k % n;
    	}
   		temp[i] = k;
   		ct = k + 96;
   		en[i] = ct;
   		i++;
  	}
  	en[i] = -1;
  	printf("\n\nEncrypted Message: \n");
  	for(i = 0; en[i] != -1; i++)
    printf("%c", en[i]);
	
}
void decrypt(){
	long int pt, ct, key = d[0], k;
  	i = 0;
  	while(en[i] != -1)
  	{
    	ct = temp[i];
    	k = 1;
    	for(j = 0; j < key; j++)
    	{
      		k = k * ct;
      		k = k % n;
    	}
   		pt = k + 96;
   		m[i] = pt;
   		i++;
  	}
  	m[i] = -1;
  	printf("\n\nDecrypted Message\n");
  	for(i = 0; m[i] != -1; i++)
   	printf("%c", m[i]);
  	printf("\n");
}

// With the help of internet and a lot of self-brainstorming ... thanks Stackoverflow, google and youtube san//
