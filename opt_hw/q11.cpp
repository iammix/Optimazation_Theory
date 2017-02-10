// q11 for Dichotomous search method

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <time.h>
using namespace std;

double theta(double lamla)       //function occupied by sys > <
{
	double e=exp(1);
	return 7000*exp(-2*lamla)+6*pow(lamla,2);
}

double theta_plus(double lamla)       //function occupied by sys > <
{
	double e=exp(1);
	return -14000*exp(-2*lamla)+12*lamla;
}

double theta_pp(double lamla)       //function occupied by sys > <
{
	double e=exp(1);
	return 28000*exp(-2*lamla)+12;
}

void Dichotomous_search(double a1,double b1, double l, double sigma)
{
	time_t a_time,b_time;
	time(&a_time);

	int Num;
	Num=100;
	double lamla[Num],mu[Num],a[Num],b[Num],cache_theta_lamla[Num],cache_theta_mu[Num];
	memset(lamla,0,sizeof(lamla));
	memset(mu,0,sizeof(mu));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(cache_theta_mu,0,sizeof(cache_theta_mu));
	memset(cache_theta_lamla,0,sizeof(cache_theta_lamla));

	int k,theory_iteration,i;
	theory_iteration=ceil(log((b1-a1-2*sigma)/(l-2*sigma))/log(2));
	k=1;
	a[1]=a1;b[1]=b1;


	
	while(b[k]-a[k]>l)
	{
		lamla[k]=(a[k]+b[k])/2-sigma;
		mu[k]=(a[k]+b[k])/2+sigma;
		cache_theta_lamla[k]=theta(lamla[k]);
		cache_theta_mu[k]=theta(mu[k]);

		 if(cache_theta_lamla[k]<cache_theta_mu[k])
		 	{
		 		a[k+1]=a[k];
		 	    b[k+1]=mu[k];
		 	}
		 	else
		 		{
		 			a[k+1]=lamla[k];
		 	        b[k+1]=b[k];
		 	    }
		k++; 	    

	}
	
	

    cout<<"____Dichotomous Search Method with parameter:"<<"interval ("<<a1<<','<<b1<<"), l="<<l<<" ,sigma="<<sigma<<". ____________________________________"<<endl;
	cout<<"Itrn   a_k   b_k  lamla_k  mu_k  theta(lamla_k)  theta(mu_k)"<<endl;
	cout<<"__________________________________________________________________________________________________"<<endl;
	for(i=1;i<k;i++)
	{
		cout<<"# "<<i<<" #"<<"  "<<a[i]<<"    "<<b[i]<<"    "<<lamla[i]<<"    "<<mu[i]<<"    "<<cache_theta_lamla[i]<<"    "<<cache_theta_mu[i]<<endl;

	}

	time(&b_time);
	//cout<<"Overall time is: "<<b_time-a_time<<endl;	
	printf( "Overall time is %ld s\n",b_time-a_time);
	cout<<"____________________________________________Final Result_________________________________________________"<<endl;
	cout<<"the theory_iteration is "<<theory_iteration<<endl;
	cout<<"the approximate minimum is about "<<cache_theta_lamla[k-1]<<", when lamla is about  "<<lamla[k-1]<<endl;

}


void Newton(double sigma,double lamla_start)
{
	time_t a_time,b_time;
	time(&a_time);

	int Num;
	Num=100;
	double lamla[Num],cache_theta_lamla[Num],cache_theta_plus_lamla[Num],cache_theta_pp_lamla[Num],delta;
	
	memset(lamla,0,sizeof(lamla));
	memset(cache_theta_pp_lamla,0,sizeof(cache_theta_pp_lamla));
	memset(cache_theta_plus_lamla,0,sizeof(cache_theta_plus_lamla));
	memset(cache_theta_lamla,0,sizeof(cache_theta_lamla));

	int k,i;
	
	k=1;
	lamla[1]=lamla_start;
	  //assum here
	delta=10000;


	
	while(delta>sigma)  //orz
	{
		cache_theta_lamla[k]=theta(lamla[k]);
		cache_theta_plus_lamla[k]=theta_plus(lamla[k]);
		cache_theta_pp_lamla[k]=theta_pp(lamla[k]);

		lamla[k+1]=lamla[k]-cache_theta_plus_lamla[k]/cache_theta_pp_lamla[k];
		delta=abs(lamla[k+1]-lamla[k]);
		 	    
		k++; 	    

	}
	
	

    cout<<"____Newton Method with parameter: sigma= "<<sigma<<", start lamla= "<<lamla_start<<" ._____________________________"<<endl;
	cout<<"Itrn    lamla_k  theta_plus_(lamla_k)  theta_pp(lamla_k) lamla_k+1  delta  theta(lamla) "<<endl;
	cout<<"__________________________________________________________________________________________________"<<endl;
	for(i=1;i<k;i++)
	{
		cout<<"# "<<i<<" #"<<"  "<<lamla[i]<<"    "<<cache_theta_plus_lamla[i]<<"    "<<cache_theta_pp_lamla[i]<<"  "<<lamla[i+1]<<"  "<<abs(lamla[i+1]-lamla[i])<<"  "<<cache_theta_lamla[i]<<endl;

	}

	time(&b_time);
	//cout<<"Overall time is: "<<b_time-a_time<<endl;	
	printf( "Overall time is %ld s\n",b_time-a_time);
	cout<<"____________________________________________Final Result_________________________________________________"<<endl;

	cout<<"the approximate minimum is about "<<cache_theta_lamla[k-1]<<", when lamla is about  "<<lamla[k-1]<<endl;

}

void Bisection_search(double a1,double b1, double l)
{
	time_t a_time,b_time;
	time(&a_time);

	int Num;
	Num=100;
	double lamla[Num],a[Num],b[Num],cache_theta_lamla[Num],cache_theta_plus_lamla[Num];
	memset(lamla,0,sizeof(lamla));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(cache_theta_plus_lamla,0,sizeof(cache_theta_plus_lamla));
	memset(cache_theta_lamla,0,sizeof(cache_theta_lamla));

	int k,theory_iteration,i;
	theory_iteration=ceil(log((b1-a1)/l)/log(2));
	k=1;
	a[1]=a1;b[1]=b1;


	
	while(k<=theory_iteration)
	{
		lamla[k]=(a[k]+b[k])/2;
		cache_theta_lamla[k]=theta(lamla[k]);
		cache_theta_plus_lamla[k]=theta_plus(lamla[k]);

		 if(cache_theta_plus_lamla[k]>0)
		 	{
		 		a[k+1]=a[k];
		 	    b[k+1]=lamla[k];
		 	}
		 	else if(cache_theta_plus_lamla[k]<0)
		 		{
		 			a[k+1]=lamla[k];
		 	        b[k+1]=b[k];
		 	    }
		 	    
		k++; 	    

	}
	
	

    cout<<"____Bisection Search Method with parameter:"<<"interval ("<<a1<<','<<b1<<"), l="<<l<<" ._____________________________"<<endl;
	cout<<"Itrn   a_k   b_k  lamla_k  theta_plus_(lamla_k)  theta(lamla_k)"<<endl;
	cout<<"__________________________________________________________________________________________________"<<endl;
	for(i=1;i<k;i++)
	{
		cout<<"# "<<i<<" #"<<"  "<<a[i]<<"    "<<b[i]<<"    "<<lamla[i]<<"    "<<cache_theta_plus_lamla[i]<<"    "<<cache_theta_lamla[i]<<endl;

	}

	time(&b_time);
	//cout<<"Overall time is: "<<b_time-a_time<<endl;	
	printf( "Overall time is %ld s\n",b_time-a_time);
	cout<<"____________________________________________Final Result_________________________________________________"<<endl;
	cout<<"the theory_iteration is "<<theory_iteration<<endl;
	cout<<"the approximate minimum is about "<<cache_theta_lamla[k-1]<<", when lamla is about  "<<lamla[k-1]<<endl;

}



int main(int argc, char const *argv[])
{
  // Dichotomous_search(0,5,0.01,0.001);
//	Bisection_search(0,5,0.01);  //  assume l=0.01
    Newton(0.01,1);
	

	return 0;
}