

a=[-5,5];
b=[-5,5];
[u,v]=meshgrid(-5:0.01:5);
for i=1:length(a)
 for j=1:length(b)
  w=u^4-4*u*u*v-9*u*u+4*v*v-8*u+20*v+41;
  mesh(u,v,w); 
  hold on;
 end
end