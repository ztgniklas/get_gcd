#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MS 1000 

void minus(int n1[],int n2[],int len1,int len2){ //减一次 
	int i,j,k;
	if(len1==len2){
		for(i=len1-1;i>=0;i--){
			n1[i] = n1[i] - n2[i];
			for(k=i;k>=0;k--){
				if(n1[k]<0){
					n1[k] += 10;
					n1[k-1]--;
				} 
			}
		}	
	}
	else if (len1>len2){
		for(i=len1-1,j=len2-1;j>=0;i--,j--){
			n1[i] = n1[i] - n2[j];
			for(k=i;k>=0;k--){
				if(n1[k]<0){
					n1[k] += 10;
					n1[k-1]--;
				} 
			}	
		}
	}
}

int delete_zero(int n[],int len,int Ms){ //清除前导零 
	int i,j,k,sum=0;
	for(i=0;i<Ms;i++){
		if(n[i]==0) sum++;
		if(n[i]!=0) break;
	} 
	for(j=i;j<len;j++){
		n[j-sum]=n[j];
	}
	if(len==sum) len = 1;
	else len = len - sum;
	for(k=len;k<Ms;k++) n[k]=0;
	return len;
}

int compare(int n1[],int n2[],int len1,int len2){ //比较两数（组）大小,第一个大1，第二个大-1，相等为0 
	int i;
	if(len1>len2) return 1;
	else if(len1==len2){
		for(i=0;i<len1;i++){
			if(n1[i]>n2[i]) return 1;
			else if(n1[i]<n2[i]) return -1;
		}
		return 0;
	}
	else return -1;
}

void gcd(int a[],int b[],int lena,int lenb,int Ms){
	int i,j=0;
	if(b[0]==0){ 
		for(i=0;i<lena;i++){
			printf("%d",a[i]);
		}
	} 
	else{
		while(compare(a,b,lena,lenb)!=-1){
			minus(a,b,lena,lenb);
			lena = delete_zero(a,lena,Ms);
			lenb = delete_zero(b,lenb,Ms);
			
		}
		
		gcd(b,a,lenb,lena,Ms);
		
	}
	
}

int main(int argc, char *argv[]) { //主函数 
	char c1[MS],c2[MS];
	int n1[MS],n2[MS],i,j;
	int lena,lenb;
	printf("请输入两个一千位以内的正整数，要求第一个不小于第二个... ...\n第一个数：");
	gets(c1);
	printf("第二个数：") ;
	gets(c2);
	lena = strlen(c1);
	lenb = strlen(c2);
	
	for (i = 0; i<MS; i++) {//初始化
        n1[i] = 0;
        n2[i] = 0;
    }
    for (i = lena - 1; i >= 0; i--)
        n1[i] = c1[i] - '0';//将字符数组元素所对应数字存入整形数组
    for (i = lenb - 1; i >= 0; i--)
        n2[i] = c2[i] - '0';
    printf("两数的最大公约数是：");
	gcd(n1,n2,lena,lenb,MS);
	printf("\n");
	system("pause");
	return 0;
}
