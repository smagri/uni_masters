

c1 circle(3);
c2 circle(4);
c3 circle(5);


ptr to c1 is?

&c1  is the address of object c1
&c2  is the address of object c2

Shape *shape_array[6];

shape_array[0] = &c1;
shape_array[0]->setCentre(2.0, 1.0);

shape_array[1] = &c2;
shape_array[2] = &c3;
shape_array[3] = &c1;...


shape_array[0] = &r1;
shape_array[1] = &r2;
shape_array[2] = &r3;
shape_array[3] = &r1;...

double x=0=y=0;

double total_area =
  shape_functions::getAreaOfBoundingShapes(shape_array, array_size, x, y);


cout << Total area of shapes which bound the point
     << x << "," << y << " ] is " << total_area << endl;

return 0;

