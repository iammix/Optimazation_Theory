#include <stdio.h>
#include <iostream>
#include <cmath>
#include <time.h>
using namespace std;

double theta_orignal(double u,double v)
{
	return pow(u,4)-4*u*u*v-9*u*u+4*v*v-8*u+20*v+41;
}

double theta(double lamla,double u,double v,int mode)       
{
	if(mode==1)
		{
			u+=lamla;  
		}  
	else
		{
			v+=lamla ;
		}
	return pow(u,4)-4*u*u*v-9*u*u+4*v*v-8*u+20*v+41;
}

double theta_plus(double lamla,double u,double v,int mode)      
{
	if(mode==1)
		{
			u+=lamla; 
			return 4*pow(u,3)-8*u*v-18*u+20*v-8; 
		}  
	else
		{
			v+=lamla ;
			return -4*u*u+8*v+20;
		}
	
}

double theta_pp(double lamla,double u,double v,int mode)      
{
	if(mode==1)
		{
			u+=lamla; 
			return 12*u*u-8*v-18; 
		}  
	else
		{
			//v+=lamla ;
			return 8;
		}
	
}





double Newton(double sigma,double lamla_start,double u,double v,int mode)   //include theta theta_plus theta_pp
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
		cache_theta_lamla[k]=theta(lamla[k],u,v,mode);
		cache_theta_plus_lamla[k]=theta_plus(lamla[k],u,v,mode);
		cache_theta_pp_lamla[k]=theta_pp(lamla[k],u,v,mode);

		lamla[k+1]=lamla[k]-cache_theta_plus_lamla[k]/cache_theta_pp_lamla[k];
		delta=abs(lamla[k+1]-lamla[k]);
		 	    
		k++; 	    

	}
	time(&b_time);
	

    return lamla[k-1];
}


double norm(double x11,double x12, double x21, double x22 )
{
	return pow(x21-x11,2)+pow(x22-x12,2);	
}



void ccm(double u_start,double v_start,double sigma)    // start at (u,v)
{
//	u[j]=x[0][j];
//	v[j]=x[0][j];
	// by theory 2 loop, to put it simple, only iteration loop here, alter coordinate just by sequence
	
	int i,k,Num;
	Num=100;
	double N_sigma,lamla_start,u[Num],v[Num],lamla[2][Num];

	N_sigma=0.001;
	lamla_start=1.0;   //default, could be better
	memset(lamla,0,sizeof(lamla));
	memset(u,0,sizeof(u));
	memset(v,0,sizeof(v));


	u[1]=u_start;
	v[1]=v_start;
	u[0]=10000;
	v[0]=10000;
	k=1;

	while(norm(u[k],v[k],u[k-1],v[k-1])>sigma)    
  {
	lamla[0][k]=Newton(N_sigma,lamla_start,u[k],v[k],1);  //MOST IMPORTANT HERE!
    u[k+1]=u[k]+lamla[0][k];
	
	lamla[1][k]=Newton(N_sigma,lamla_start,u[k+1],v[k],2); 
    v[k+1]=v[k]+lamla[1][k];

	k++;
   }

   //************************************

   cout<<"_____________Cyclic coordinate method with starting pt ("<<u_start<<','<<v_start<<"), sigma="<<sigma<<". _________________"<<endl;
   cout<<"Itrn k    x_k/f(x_k)   j   d_j    y_j   lamla_j   y_j+1 "<<endl;
   cout<<"________________________________________________________________________"<<endl;
   for(i=1;i<k;i++)
   {
   	cout<<"# "<<i<<" #      ("<<u[i]<<','<<v[i]<<")*     1     (1.0 0.0)   ("<<u[i]<<','<<v[i]<<")    "<<lamla[0][i]<<"*    ("<<u[i+1]<<','<<v[i]<<") "<<endl;
   	cout<<"           >"<<theta_orignal(u[i+1],v[i+1])<<"<   2     (0.0 1.0)  ("<<u[i+1]<<','<<v[i]<<")  "<<lamla[1][i]<<"*  ("<<u[i+1]<<','<<v[i+1]<<")* "<<endl;

   } 




}



int main(int argc, char const *argv[])
{
  // Dichotomous_search(0,5,0.01,0.001);
//	Bisection_search(0,5,0.01);  //  assume l=0.01
    ccm(0,0,0.001);
	

	return 0;
}