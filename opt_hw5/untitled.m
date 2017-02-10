lamla=0:0.001:5;
y=7000*exp(-2*lamla)+6*lamla.^2;
subplot(2,1,1);
plot(lamla,y);
grid on;
title('\theta(\lambda)');


lamla_2=2.96:0.001:3.00;
y_2=7000*exp(-2*lamla_2)+6*lamla_2.^2;
subplot(2,1,2);
plot(lamla_2,y_2);
grid on;
title('\theta(\lambda) detail');
