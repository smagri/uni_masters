smagri@gyan1:/lu1/smagri/uni/subj/pms/assignments/ass2/build%make
Scanning dependencies of target ranger
[ 11%] Building CXX object CMakeFiles/ranger.dir/rangerFusion.cpp.o
In file included from /lu1/smagri/uni/subj/pms/assignments/ass2/rangerFusion.h:7:0,
                 from /lu1/smagri/uni/subj/pms/assignments/ass2/rangerFusion.cpp:4:
/lu1/smagri/uni/subj/pms/assignments/ass2/ranger.h: In member function ‘virtual std::vector<std::vector<double> > RangerFusion::getRawRangeData()’:
/lu1/smagri/uni/subj/pms/assignments/ass2/ranger.h:72:18: error: ‘std::vector<double> Ranger::rawData_’ is protected
   vector<double> rawData_;
                  ^
/lu1/smagri/uni/subj/pms/assignments/ass2/rangerFusion.cpp:40:19: error: within this context
   rangers_.at(0)->rawData_;
                   ^
CMakeFiles/ranger.dir/build.make:62: recipe for target 'CMakeFiles/ranger.dir/rangerFusion.cpp.o' failed
make[2]: *** [CMakeFiles/ranger.dir/rangerFusion.cpp.o] Error 1
CMakeFiles/Makefile2:67: recipe for target 'CMakeFiles/ranger.dir/all' failed
make[1]: *** [CMakeFiles/ranger.dir/all] Error 2
Makefile:83: recipe for target 'all' failed
make: *** [all] Error 2
smagri@gyan1:/lu1/smagri/uni/subj/pms/assignments/ass2/build%emacs -nw output.accessRawDataFromgetRawRangeData
smagri@gyan1:/lu1/smagri/uni/subj/pms/assignments/ass2/build%ll
