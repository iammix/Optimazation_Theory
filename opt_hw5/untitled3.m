u=-5:0.01:5;
v=-5:0.01:5;
for i=1:1:size(u);
    for j=1:1:size(v);
        w(i,j)=u(i)^4-4*u(i)*u(i)*v(j)-9*u(i)*u(i)+4*v(j)*v(j)-8*u(i)+20*v(j)+41;
    end
end
mesh(u,v,w); 