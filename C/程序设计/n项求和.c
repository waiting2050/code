 #include <stdio.h>
 
 int main()
 {
 	int N;
 	scanf("%d", &N);
 	double a=2.0;
 	double b=1.0;
 	int cnt=0;
 	double c=0.0;
 	double sum=0.0;
 	int d;
 	
	 for(; cnt<N; cnt++){
	 	c=a/b;
	 	d=a;
	 	a+=b;
	 	b=d;
	 	sum+=c;
	 }
 	printf("%.2f", sum);
 	
 	
 	return 0;
}
