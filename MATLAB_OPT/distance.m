% cal distance 
d=zeros(1,9);

d(1)=pdist2(A1,B1,'euclidean');
d(2)=pdist2(A1,B2,'euclidean');
d(3)=pdist2(A1,B3,'euclidean');
d(4)=pdist2(A2,B1,'euclidean');
d(5)=pdist2(A2,B2,'euclidean');
d(6)=pdist2(A2,B3,'euclidean');
d(7)=pdist2(A3,B1,'euclidean');
d(8)=pdist2(A3,B2,'euclidean');
d(9)=pdist2(A3,B3,'euclidean');