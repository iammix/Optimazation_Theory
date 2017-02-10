% Q5

A_x=[60,  85.5,64.8,61.5,87,  110.1,108, 82.8,69,93,  51,81];
A_y=[18.4,16.8,21.6,20.8,23.6,19.2 ,17.6,22.4,20,20.8,22,20];
B_x=[52.8,64.8,43.2,84,  49.2,59.4,66,  47.4,33,  51,63];
B_y=[20.8,17.2,20.4,17.6,17.6,16,  18.4,16.4,18.8,14,14.8];

axis([0 24 0 112]);

figure(2);

scatter(A_y,A_x,'b','filled');        % default blue
grid on;
hold on;
scatter(B_y,B_x,'r','filled');
title('scatter figure of Income and Lot size');
legend('Owner','No Owner','Location','NorthWest');
