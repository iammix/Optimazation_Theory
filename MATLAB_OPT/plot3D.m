clf;
%plot 3D vector

A1=[1,0,2];
A2=[4,3,-1];
A3=[6,3,1];
scatter3(A1,A2,A3,'filled');
fill3(A1,A2,A3,[1 0 1]);
hold on;
grid on;

B1=[-2,3,4];
B2=[-4,5,6];
B3=[-6,8,10];
scatter3(B1,B2,B3,'filled');
fill3(B1,B2,B3,[0 1 0]);
legend('U set','V set');



x=-10:1:10;
y=x;
[X Y]=meshgrid(x,y);
z=(3*X-3*Y+23)/2;

%plot3(X,Y,z);
surf(X,Y,z);
grid on;

