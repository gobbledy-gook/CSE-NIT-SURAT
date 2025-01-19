//Q1
//#include <stdio.h>
//
//int main(){
//	int a, b, c, d, k, x;
//	printf("F(x) = ax^3 - bx^2 + cx - d,  if x > k\n");
//	printf("F(x) = 0,                     if x = k\n");
//	printf("F(x) = -ax^3 + bx^2 - cx +d,  if x < k\n");
//	printf("a = ");
//	scanf("%d", &a);
//	printf("b = ");
//	scanf("%d", &b);
//	printf("c = ");
//	scanf("%d", &c);
//	printf("d = ");
//	scanf("%d", &d);
//	printf("x = ");
//	scanf("%d", &x);
//	int F;
//	F = a*(x*x*x) - b*(x*x)+ c*x - d;
//	printf("F(x) = %d", F);
//}


//Q2
//#include <stdio.h>
//int main(){
//	int marks;
//	printf("Enter Your Marks - ");
//	scanf("%d", &marks);
//	if ((marks>=0) && (marks<=35))
//		printf("Fail");
//	else if ((marks>35) && (marks <= 59))
//	    printf("Second Class");
//	else if ((marks>59) && (marks <= 79))
//	    printf("First Class");
//	else if ((marks > 79) && (marks <= 100))
//	    printf("Distinction");
//	else
//	    printf("Invalid Input");				
//}


//Q3
//#include <stdio.h>
//int main(){
//	float a, b;
//	printf("1st Number - ");
//	scanf("%f", &a);
//	printf("2nd Number - ");
//	scanf("%f", &b);
//	int c = a/b;
//	printf("%d", c);
//}

//#include <stdio.h>
//int main(){
//	int a;
//	float b;
//	printf("1st -ve Integer - ");
//	scanf("%d", &a);
//	printf("2nd +ve Floating Number - ");
//	scanf("%f", &b);
//	int c = a/b;
//	printf("Division of 1st by 2nd is %d", c);
//}

//#include <stdio.h>
//int main(){
//	float a;
//	int b;
//	printf("1st +ve Floating Number - ");
//	scanf("%f", &a);
//	printf("2nd -ve Integer - ");
//	scanf("%d", &b);
//	float c = a/b;
//	printf("Division of 1st by 2nd is %f", c);
//}


// Q4
// #include <stdio.h>
// int main(){
// 	int pamt, netamt, dis;
// 	char cloth;
// 	printf("For Mill Cloth Press M or m & for Handloom items Press H or h\n");
// 	scanf("%c", &cloth);
	
// 	if ((cloth == 'M') || (cloth == 'm')){
		
// 		printf("Enter the Purchase Amount - ");
// 		scanf("%d", &pamt);
		
// 		if ((pamt>=0) && (pamt<=100)){
// 		    dis = pamt*(0.0);
// 	    	netamt = pamt - dis;	
// 	    }
	    
// 	    else if ((pamt>=101) && (pamt<=200)){
// 		    dis = pamt*(0.05);
// 	    	netamt = pamt - dis;
// 	    }
// 	    else if ((pamt >= 201) && (pamt <= 300)){
// 	    	dis = pamt*(0.075);
// 	    	netamt = pamt - dis;
// 		}
		
// 	    else if (pamt >= 301){
// 	        dis = pamt*(0.1);
// 	    	netamt = pamt - dis;	
// 		}
// 	    printf("Discount Amount = %d \n", dis);
// 	    printf("Total Amount after discount = %d \n", netamt);	
//    }
//    else if ((cloth == 'H') || (cloth == 'h')){
//    	printf("Enter the Purchase Amount - ");
// 		scanf("%d", &pamt);
		
// 		if ((pamt>=0) && (pamt<=100)){
// 		    dis = pamt*(0.05);
// 	    	netamt = pamt - dis;	
// 	    }
	    
// 	    else if ((pamt>=101) && (pamt<=200)){
// 		    dis = pamt*(0.075);
// 	    	netamt = pamt - dis;
// 	    }
// 	    else if ((pamt >= 201) && (pamt <= 300)){
// 	    	dis = pamt*(0.1);
// 	    	netamt = pamt - dis;
// 		}
		
// 	    else if (pamt >= 301){
// 	        dis = pamt*(0.15);
// 	    	netamt = pamt - dis;	
// 		}
// 		printf("Discount Amount = %d \n", dis);
// 	    printf("Total Amount after discount = %d \n", netamt);
// 	}
// 	else{
// 		printf("Invalid Input !");
// 	}
// }


//Q5
#include <stdio.h>
int main(){
	int amt, comm;
	printf("Enter the Policy Amount - ");
	scanf("%d", &amt);
	if (amt <= 10000 ){
		comm = 0.005*amt;
		printf("Commission due to Sales Woman - %d", comm);
	}
	else if ((amt>10000) && (amt<25000)){
		comm = 50 + (amt - 10000)*0.006;
		printf("Commission due to Sales Woman - %d", comm);
	}
	else if (amt>=25000){
		comm = 140 + (amt - 25000)*0.0075;
		printf("Commission due to Sales Woman - %d", comm);
	}
	else{
		printf("Invalid Input !");
	}
}
























