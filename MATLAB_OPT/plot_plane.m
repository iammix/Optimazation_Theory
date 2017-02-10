clf;
figure;
x=-10:1:10;
y=x;
[X Y]=meshgrid(x,y);
z=(3*X-3*Y+23)/2;

%plot3(X,Y,z);
surf(X,Y,z);
grid on;