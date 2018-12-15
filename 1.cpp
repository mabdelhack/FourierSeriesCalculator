#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#define N 1000000
using namespace std;
 static double a=0,n=0;
 static double L=0;


class func{

public:
	double st,end;
	int sign;
	char part[15];

	func(){
		st=0;end=0;sign=0;
		int i;
		for (i=0;i<15;i++){
			part[i]='\0';}
	}
	int signdetect(char sg,int i){
		if(sg=='+'){sign=1;}
		else if(sg=='-'){sign=-1;}
		else {return 0;}
		return 1;
	}
	int setpart(char c,int v){
		if(c!='+'&&c!='-'){
			part[v]=c;
			return 1;
		}
		else{return 0;}
	}
	double fourier(double f(double farg),double a,double b,char choice,int x){
		double h,sumodd, sumeven;
		int i;
		h=(b-a)/N;
		sumodd=0;
		sumeven=0;
		if(choice=='0'){
			for(i=2;i<=N;i+=2){sumodd+=f(a+(i-1)*h);}
			for(i=2;i<=N-2;i+=2){sumeven+=f(a+i*h);}
			return ((1/(2*L))*((h/3)*(f(a)+f(b)+4*sumodd+2*sumeven)));
		}
		else if(choice=='a'){
			for(i=2;i<=N;i+=2){sumodd+=(f(a+(i-1)*h)*(cos(x*3.14*(a+(i-1)*h)/L)));}
			for(i=2;i<=N-2;i+=2){sumeven+=(f(a+i*h)*(cos(x*3.14*(a+i*h)/L)));}
			return ((1/L)*((h/3)*(f(a)+f(b)+4*sumodd+2*sumeven)));
		}
		else if(choice=='b'){
			for(i=2;i<=N;i+=2){sumodd+=(f(a+(i-1)*h)*(sin(x*3.14*(a+(i-1)*h)/L)));}
			for(i=2;i<=N-2;i+=2){sumeven+=(f(a+i*h)*(sin(x*3.14*(a+i*h)/L)));}
			return ((1/L)*((h/3)*(f(a)+f(b)+4*sumodd+2*sumeven)));
		}
	}
	void polynomial(int xloc,double x){
		if(xloc==0){a=1;}
		else{a=atof(part);}
		if(part[xloc+1]!='^'){n=1;}
		else{n=atof(part+xloc+2);}
	}
	static double polynomial1(double x){
		return (a*pow(x,n));}
	static double constant1(double farg){
		return a;
	}
	void constant(){
		a= atof(part);
	}
	void exponential(int xloc,int eloc,double x){
		if(eloc==0){a=1;}
		else{a=atof(part);}
		if(xloc==eloc+3){n=1;}
		else{n=atof(part+eloc+3);}
	}
	static double exponential1(double x){
		return (a*exp(n*x));}
	void sine(int xloc,int sloc,double x){
		double a,n;
		if(sloc==0){a=1;}
		else{a=atof(part);}
		if(xloc==sloc+4){n=1;}
		else{n=atof(part+sloc+4);}
	}
	static double sine1(double x){
		return (a*sin(n*x));}
	void cosine(int xloc,int cloc,double x){
		double a,n;
		if(cloc==0){a=1;}
		else{a=atof(part);}
		if(xloc==cloc+4){n=1;}
		else{n=atof(part+cloc+4);}
		}
	static double cosine1(double x){
		return (a*cos(n*x));}
	double dist(char choice,int x){
		int xloc=-1,eloc=-1,sloc=-1,cloc=-1;
		int i;
		for (i=0;part[i]!='\0';i++){
			if (part[i]=='t'){
				xloc=i;
				break;
			}
		}
		if (xloc==-1){
			constant();
			return fourier(constant1,st,end,choice,x);
		}
		else{
			for (i=0;part[i]!='\0';i++){
				if(part[i]=='e'){
					eloc=i;
					break ;
				}
			}
			if (eloc!=-1){
				exponential(xloc,eloc,x);
				return fourier(exponential1,st,end,choice,x);
			}
			else{
				for (i=0;part[i]!='\0';i++){
					if (part[i]=='s'){
						sloc=i;
						break;
					}
				}
				if(sloc!=-1){
					sine(xloc,sloc,x);
					return fourier(sine1,st,end,choice,x);
				}
				else{
					for (i=0;part[i]!='\0';i++){
						if(part[i]=='c'){
							cloc=i;
							break;
						}
					}
					if(cloc!=-1){
						cosine(xloc,cloc,x);
						return fourier(cosine1,st,end,choice,x);
					}
					else{
						polynomial(xloc,x);
						return fourier(polynomial1,st,end,choice,x);
					}
				}
			}
		}
	}
};
void intro(){
	int q;
printf("%c",201);
for (q=0;q<32;q++){
	printf("%c",205);
}
printf("%c\n",187);
printf("%c",186);
for(q=0;q<32;q++){
	cout<<" ";
}
printf("%c\n",186);
printf("%c",186);
cout<<"   Fourier Series Calculator    ";
printf("%c\n",186);
printf("%c",186);
for(q=0;q<32;q++){
	cout<<" ";
}
printf("%c\n",186);
printf("%c",200);
for (int q=0;q<32;q++){
	printf("%c",205);
}
printf("%c\n",188);
cout<<"Enter number of intervals: ";
}
int main(){
	double totan[20]={0.0},totbn[20]={0.0},tota0=0;
	int intno=0,intno1=0,expansion=0,v=0,m=0;
	double st[10]={0.0},end[10]={0.0};
	intro();
	cin>>intno;
	char f[10][100]={"\0","\0","\0","\0","\0","\0","\0","\0","\0","\0"};
		cout<<"Interval "<<(intno1+1)<<":"<<endl;
		cout<<"Starting point: ";
		cin>>st[intno1];
		cout<<"Ending point: ";
		cin>>end[intno1];
		st[intno1+1]=end[intno1];
		cout<<"f(t)= ";
		cin>>f[intno1];
	for (intno1=1;intno1<intno;intno1++){
		cout<<"Interval "<<intno1+1<<":"<<endl;
		cout<<"Ending point: ";
		cin>>end[intno1];
		st[intno1+1]=end[intno];
		cout<<"f(t)= ";
		cin>>f[intno1];
	}
	L=(end[(intno-1)]-st[0])/2;
	cout<<"Number of n terms of expression: ";
	cin>>expansion;
	func parts[10][50];
	for (intno1=0;intno1<intno;intno1++){
		v=0;
		for(int i=0;f[intno1][i]!='\0';i++){
			parts[intno1][v].st=st[intno1];
			parts[intno1][v].end=end[intno1];
			v+=parts[intno1][v].signdetect(f[intno1][i],i);
			m*=(1-parts[intno1][v-1].signdetect(f[intno1][i],i));
			m+=parts[intno1][v-1].setpart(f[intno1][i],m);
		}
 		for(int i=0;parts[intno1][i].part[0]!='\0';i++){
			int x=0;
			tota0+=(parts[intno1][i].sign*parts[intno1][i].dist('0',x));
			for (x=0;x<=expansion;x++){
				totan[x]+=(parts[intno1][i].sign*parts[intno1][i].dist('a',x+1));
				totbn[x]+=(parts[intno1][i].sign*parts[intno1][i].dist('b',x+1));
			}
		}
	}
	cout<<"Fourier Series of Expression\n";
	cout<<"f(t)= ("<<fixed<<setprecision(2)<<tota0;
	for (int x=0;x<expansion;x++){
		cout<<") + ("<<fixed<<setprecision(2)<<totan[x]<<"cos("<<(3.14*(x+1)/L)<<"x)";
	}
	for (int x=0;x<expansion;x++){
		cout<<") + ("<<fixed<<setprecision(2)<<totbn[x]<<"sin("<<(3.14*(x+1)/L)<<"x)";
	}
	cout<<")";
	cout<<endl;
	system("pause");
	return 0;
}