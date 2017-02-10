#include <stdio.h>
#include <iostream>
#include <cmath>
#include <time.h>
using namespace std;

double f(double u,double v)
{
	return pow(u-8-pow(v-6,3),2)+3*pow(u-2-v,4);
}

double f_p1(double u,double v)
{
	return 2*(u-8-pow(v-6,3))+12*pow(u-2-v,3);
}

double f_p2(double u,double v)
{
	return 6*pow(v-6,5)-6*(u-8)*(v-6)*(v-6)-12*pow(u-2-v,3);
}



double theta(double lamla,double u,double v)     // mono-varable theta
{
	double pu,pv;
	pu=f_p1(u,v);
	pv=f_p2(u,v);
	u+=lamla*pu;
	v+=lamla*pv;
	return pow(u-8-pow(v-6,3),2)+3*pow(u-2-v,4);
}






double theta_plus(double lamla,double u,double v)      
{
	double pu,pv;
	pu=f_p1(u,v);
	pv=f_p2(u,v);
    return  2*pu*(u+lamla*pu-8)-2*( pu*pow(v+lamla*pv-6,3) + (u+lamla*pu-8)*3*pow(v+lamla*pv-6,2) )+6*pv*pow(v+lamla*pv-6,5)+12*(pu-pv)*pow(u-v+lamla*(pu-pv),3); 	
}

double theta_pp(double lamla,double u,double v)      
{
	double pu,pv;
	pu=f_p1(u,v);
	pv=f_p2(u,v);      //any possible reduce cal
	return 2*pu*pu-2*(6*pu*pv*pow(v+lamla*pv-6,2)+6*pv*pv*(u+lamla*pu-8)*(v+lamla*pv-6)+30*pv*pv*pow(v+lamla*pv-6,4))+36*(pu-pv)*(pu-pv)*pow(u-v+lamla*(pu-pv),2);	
}





void Newton(double sigma,double lamla_start,double u,double v)   //include theta theta_plus theta_pp
{
	time_t a_time,b_time;                                           // u v cofficence exactly determin the theta_lamla
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


	cout<<"begin"<<endl;
	//while(delta>sigma)  //orz
	for(k=1;k<200;k++)
	{
		cache_theta_lamla[k]=theta(lamla[k],u,v);
		cache_theta_plus_lamla[k]=theta_plus(lamla[k],u,v);
		cache_theta_pp_lamla[k]=theta_pp(lamla[k],u,v);

		lamla[k+1]=lamla[k]-cache_theta_plus_lamla[k]/cache_theta_pp_lamla[k];
		delta=abs(lamla[k+1]-lamla[k]);
		 	    
		//k++; 	

		cout<<cache_theta_lamla[k]<<"    "<<cache_theta_plus_lamla[k]<<"     "<<cache_theta_pp_lamla[k]<<endl;
		cout<<"    >"<<lamla[k+1]<<endl;
		

	}
	time(&b_time);
	

//    return lamla[k-1];
}


double norm(double x11,double x12, double x21, double x22 )
{
	return sqrt(pow(x21-x11,2)+pow(x22-x12,2));	
}

double norm(double x11,double x12 )   //overloading
{
	return sqrt(x11*x11+x12*x12);	
} 


/*
void steep(double u_start,double v_start,double sigma)    // start at (u,v)
{
//	u[j]=x[0][j];
//	v[j]=x[0][j];
	// by theory 2 loop, to put it simple, only iteration loop here, alter coordinate just by sequence
	
	int i,k,Num;
	Num=100;
	double N_sigma,lamla_start,u[Num],v[Num],pu[Num],pv[Num],lamla[Num];

	N_sigma=0.1;
	lamla_start=1.0;   //default, could be better
	memset(lamla,0,sizeof(lamla));
	memset(u,0,sizeof(u));
	memset(v,0,sizeof(v));
	memset(pu,0,sizeof(pu));
	memset(pv,0,sizeof(pv));


	u[1]=u_start;
	v[1]=v_start;
	u[0]=1000;
	v[0]=1000;
	
	k=1;

	while(norm(u[k],v[k],u[k-1],v[k-1])>sigma)    
  {
  	pu[k]=f_p1(u[k],v[k]);
  	pv[k]=f_p2(u[k],v[k]);

	lamla[k]=Newton(N_sigma,lamla_start,u[k],v[k]);  //MOST IMPORTANT HERE!
    u[k+1]=u[k]-lamla[k]*pu[k];
    v[k+1]=v[k]-lamla[k]*pv[k];


	k++;

	if(k>50)
		{cout<<"OVERLOAD at STEEP!"<<endl;
	    cout<<k<<endl;} else{}
   }


 //  cout<<"_____________Deepest method with starting pt ("<<u_start<<','<<v_start<<"), sigma="<<sigma<<". _________________"<<endl;
  // cout<<"Itrn k    x_k/f(x_k)    f_p     |f_p|      lamla_k    x_j+1 "<<endl;
 //  cout<<"________________________________________________________________________"<<endl;
   for(i=1;i<k;i++)
   {
//   	cout<<"# "<<i<<" #      ("<<u[i]<<','<<v[i]<<")*  "<<" ("<<pu[i]<<','<<pv[i]<<")    > "<<norm(pu[i],pv[i])<<"       "<<lamla[i]<<"   ("<<u[i+1]<<','<<v[i+1]<<')'<<endl;
//  	cout<<"           >"<<f(u[i],v[i])<<"<  "<<endl;
   	cout<<u[i]<<','<<v[i]<<"       "<<pu[i]<<','<<pv[i]<<"         .lamla= "<<lamla[i]<<endl;
   }   
}

*/

int main(int argc, char const *argv[])
{
  // Dichotomous_search(0,5,0.01,0.001);
//	Bisection_search(0,5,0.01);  //  assume l=0.01
 //   steep(8.1,6,0.1);
	Newton(0.01,1.0,7,1);
	

	return 0;
}