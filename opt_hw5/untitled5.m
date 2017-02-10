[u,v]=meshgrid(-.5:.04:.5);
w=(u-8-(v-6).^3).^2+3*(u-2-v).^4;
figure;
mesh(w);
title('Opt HW5 Q3');