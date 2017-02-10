[u,v]=meshgrid(-5:.1:5);
w=u.^4-4*u.*u.*v-9*u.*u+4*v.*v-8*u+20*v+41;
figure;
mesh(w);
title('Opt HW5 Q2');